/*!
	@file nandsxfevt.tcc
	@brief The prototype file for NandsXFeVt template class.
	@details This is the prototype file for NandsXFeVt template class.
	@author M.A.Hakim Newton hakim.newton@nicta.com.au
	@author Duc Nghia Pham duc-nghia.pham@nicta.com.au
	@date 16.11.2009 QRL NICTA www.nicta.com.au
*/



#ifndef NandsXFeVtTccIncluded
#define NandsXFeVtTccIncluded



#include "cbls/funcs/fevs/aggfevt.tcc"



openKangarooSpace



/*!
	@class NandsXFeVt
	@brief A class to represent nand (satisfaction) fevs.
	@details This class represents nand (satisfaction) fevs.
*/
template <typename pxt, typename fvt>
class NandsXFeVt : public AggFeVt<fvt>
{
	public:
		static Hdl def(Fss const theFss, Hdl const hdlSys,
												Prm * thePrms, Dim const PrmCount);		//!< Definition.

		static NandsXFeVt<pxt,fvt> & refm(Hdl const hdlSys, Hdl const hdlFunc);			//!< Reference.
		static NandsXFeVt<pxt,fvt> * ptrm(Hdl const hdlSys, Hdl const hdlFunc);			//!< Pointer.
		static NandsXFeVt<pxt,fvt> const & refc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Reference.
		static NandsXFeVt<pxt,fvt> const * ptrc(Hdl const hdlSys, Hdl const hdlFunc);	//!< Pointer.

		//! @name Casting
		//! @{

		static NandsXFeVt<pxt,fvt> const & cast(Term const & theTerm);	//!< Perform casting.
		static NandsXFeVt<pxt,fvt> const * cast(Term const * theTerm);	//!< Perform casting.
		static NandsXFeVt<pxt,fvt> & cast(Term & theTerm);				//!< Perform casting.
		static NandsXFeVt<pxt,fvt> * cast(Term * theTerm);				//!< Perform casting.

		static Bll suit(Term const & theTerm);						//!< Suits casting?
		static Bll suit(Term const * theTerm);						//!< Suits casting?
		static Bll suit(Term & theTerm);							//!< Suits casting?
		static Bll suit(Term * theTerm);							//!< Suits casting?

		//! @}

	private:

		~NandsXFeVt();														//!< Destructor.
		NandsXFeVt(NandsXFeVt<pxt,fvt> const & that);						//!< Duplicator.
		NandsXFeVt(Fss const theFss, Hdl const hdlSys,
									Prm * thePrms, Dim const PrmCount);		//!< Constructor.
		NandsXFeVt const & operator = (NandsXFeVt<pxt,fvt> const & that);	//!< Assigner.

		//! @name Computations
		//! @{

		virtual void compConst();					//!< Compute the term.
		virtual void execAnew();					//!< Execute the term.
		virtual void simulAnew();					//!< Simulate the term.
		virtual void execIncr();					//!< Execute the term.
		virtual void simulIncr();					//!< Simulate the term.
		#if CompLazy
		virtual void execBklg();					//!< Execute the term.
		virtual void emulBklg();					//!< Emulate the term.
		virtual void undoEval(Pos const thePos);	//!< Perform eval undo.
		#endif

		//! @}

	private:

		b1<EvalRec<pxt> const *, kmm> mPxRecs;		//!< Parameter records.
		Dim	cExecFalse;								//!< Execution cache false count.
		#if SimulDnwdCache
		Dim	cSimulFalse;							//!< Simulation cache false count.
		#endif
		#if CompLazy
		Dim	cEmulFalse;								//!< Emulation cache false count.
		#endif
};



/*!
	Whether a term is suitable for casting.
*/
template <typename pxt, typename fvt>
inline Bll NandsXFeVt<pxt,fvt>::suit(Term const & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< NandsXFeVt<pxt,fvt> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template <typename pxt, typename fvt>
inline Bll NandsXFeVt<pxt,fvt>::suit(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< NandsXFeVt<pxt,fvt> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template <typename pxt, typename fvt>
inline Bll NandsXFeVt<pxt,fvt>::suit(Term & theTerm)
{
	WatchError
	return theTerm.TermCls == TermStub< NandsXFeVt<pxt,fvt> >::TermCls;
	CatchError
}



/*!
	Whether a term is suitable for casting.
*/
template <typename pxt, typename fvt>
inline Bll NandsXFeVt<pxt,fvt>::suit(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);

	return theTerm->TermCls == TermStub< NandsXFeVt<pxt,fvt> >::TermCls;
	CatchError
}



/*!
	Perform casting of a term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> const & NandsXFeVt<pxt,fvt>::cast(Term const & theTerm)
{
	WatchError
	Wchk(theTerm.TermCls != TermStub< NandsXFeVt<pxt,fvt> >::TermCls) Wtxt(eWrongCls);

	return scast<NandsXFeVt<pxt,fvt> const &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> const * NandsXFeVt<pxt,fvt>::cast(Term const * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Wchk(theTerm->TermCls != TermStub< NandsXFeVt<pxt,fvt> >::TermCls) Wtxt(eWrongCls);

	return scast<NandsXFeVt<pxt,fvt> const *>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> & NandsXFeVt<pxt,fvt>::cast(Term & theTerm)
{
	WatchError
	Wchk(theTerm.TermCls != TermStub< NandsXFeVt<pxt,fvt> >::TermCls) Wtxt(eWrongCls);

	return scast<NandsXFeVt<pxt,fvt> &>(theTerm);
	CatchError
}



/*!
	Perform casting of a term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> * NandsXFeVt<pxt,fvt>::cast(Term * theTerm)
{
	WatchError
	Warn(!theTerm, eNullPointer);
	Wchk(theTerm->TermCls != TermStub< NandsXFeVt<pxt,fvt> >::TermCls) Wtxt(eWrongCls);

	return scast<NandsXFeVt<pxt,fvt> *>(theTerm);
	CatchError
}



/*!
	Refer to a conjunction fev term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> & NandsXFeVt<pxt,fvt>::refm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refm(hdlSys).refmFunc(hdlFunc));
	CatchError
}



/*!
	Point to a conjunction fev term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> * NandsXFeVt<pxt,fvt>::ptrm(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrm(hdlSys)->ptrmFunc(hdlFunc));
	CatchError
}



/*!
	Refer to a conjunction fev term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> const & NandsXFeVt<pxt,fvt>::refc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::refc(hdlSys).refcFunc(hdlFunc));
	CatchError
}



/*!
	Point to a conjunction fev term.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt> const * NandsXFeVt<pxt,fvt>::ptrc(Hdl const hdlSys, Hdl const hdlFunc)
{
	WatchError
	return cast(Sys::ptrc(hdlSys)->ptrcFunc(hdlFunc));
	CatchError
}



/*!
	The destructor.
*/
template <typename pxt, typename fvt>
inline NandsXFeVt<pxt,fvt>::~NandsXFeVt()
{
	WatchError
	//	nothing to be done.
	CatchError
}



/*!
	Define a conjunction fev term.
*/
template <typename pxt, typename fvt>
Hdl NandsXFeVt<pxt,fvt>::def(Fss const theFss, Hdl const hdlSys,
			Prm * thePrms, Dim const PrmCount)
{
	WatchError
	Warn(PrmCount < 2 || PrmCount > MaxDim, eParamCount2(2, MaxDim));

	NandsXFeVt<pxt,fvt> * tFeV = new NandsXFeVt<pxt,fvt>(theFss, hdlSys, thePrms, PrmCount);
	Hdl const tHdl = tFeV->defSysFunc();
	if (tHdl != InvHdl) { delete tFeV; return tHdl; }

	EvalTbl<pxt> const & tPxtTbl = EvalTbl<pxt>::refc(hdlSys);
	EvalTbl<fvt> & tFvtTbl = EvalTbl<fvt>::refm(hdlSys);

	b1<Term *,kmm> const & tPrmTerms = tFeV->mPrmTerms;
	b1<Pss,kmm> const & tPrmSpecs = tFeV->mPrmSpecs;

	for(Pos tPos = 0; tPos < PrmCount; ++tPos)
	{
		Loc const tPxLoc = getPxLoc(theFss, tPrmTerms[tPos],tPrmSpecs[tPos]);
		tFeV->mPxRecs[tPos] = tPxtTbl.ptrcEvalRec(tPxLoc);
	}
	tFvtTbl.setEvalRec(tFeV->mValueRec, tFeV->mValueLoc);

	tFeV->performCompConst();
	tFeV->defSysRoot();
	return tFeV->TermHdl;
	CatchError
}



/*!
	The constructor.
*/
template <typename pxt, typename fvt>
NandsXFeVt<pxt,fvt>::NandsXFeVt(Fss const theFss, Hdl const hdlSys,
			Prm * thePrms, Dim const PrmCount) :
		AggFeVt<fvt>(hdlSys, PrmCount), mPxRecs(PrmCount)
{
	WatchError
	this->setTermCls(TermStub< NandsXFeVt<pxt,fvt> >::TermCls);
	this->setParams(theFss, thePrms, PrmCount, Unordered);
	this->setTermHvl(this->calcTermHvl());
	CatchError
}



/*!
	The duplicator.
*/
template <typename pxt, typename fvt>
NandsXFeVt<pxt,fvt>::NandsXFeVt(NandsXFeVt const & that) : AggFeVt<fvt>(that), mPxRecs(0)
{
	WatchError
	Throw(eUndefDuplicator);
	CatchError
}



/*!
	The assigner.
*/
template <typename pxt, typename fvt>
NandsXFeVt<pxt,fvt> const & NandsXFeVt<pxt,fvt>::operator = (NandsXFeVt<pxt,fvt> const & that)
{
	WatchError
	Throw(eUndefAssigner);
	CatchError
}



/*!
	Compute the term.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::compConst()
{
	WatchError
	if (!this->updatable())
	{
		cExecFalse = 0;
		for(Pos tPos = 0; tPos < mPxRecs.itemCount(); ++tPos)
			if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->CurrData())) ++cExecFalse;
		this->mValueRec->finalise(castB(cExecFalse));
	}
	CatchError
}



/*!
	Compute the term in execution mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::execAnew()
{
	WatchError
	cExecFalse = 0;
	for(Pos tPos = 0; tPos < mPxRecs.itemCount(); ++tPos)
	{
		#if ExecDnwd
		Term::performExecAnew(this->mPrmTerms[tPos]);
		#endif
		if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->CurrData())) ++cExecFalse;
	}
	this->mValueRec->initCurr(castB(cExecFalse));
	#if ExecUpwdLazy
	this->runPostExecAnew();
	#endif
	CatchError
}



/*!
	Compute the term in simulation mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::simulAnew()
{
	WatchError
	Dim tSimulFalse = 0;
	for(Pos tPos = 0; tPos < mPxRecs.itemCount(); ++tPos)
	{
		#if SimulDnwd
		Term::performSimulAnew(this->mPrmTerms[tPos]);
		#endif
		if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->NextData(this->mTermSys.SimulClk())))
			++tSimulFalse;
	}
	this->mValueRec->updtNext(this->mTermSys.SimulClk(), castB(tSimulFalse));
	#if SimulUpwd
	this->runPostSimulAnew();
	#endif
	CatchError
}



#if CompLazy
/*!
	Perform eval undo for the parameter.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::undoEval(Pos const thePos)
{
	WatchError
	if (!tc<pxt,Bll>::iof(mPxRecs[thePos]->PrevData(this->mTermSys.ExecClk())))
		--cExecFalse;
	CatchError
}
#endif //CompLazy


/*!
	Compute the term in execution mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::execIncr()
{
	WatchError
	#if ExecUpwd
	if (this->mExecChgdPrms.tagCount())
	{
		for(Idx tIdx = 0; tIdx < this->mExecChgdPrms.tagCount(); ++tIdx)
		{
			Pos const tPos = this->mExecChgdPrms.serial(tIdx);
			EvalRec<pxt> const * tPxRec = mPxRecs[tPos];
			if (tPxRec->PrevDiff(this->mTermSys.ExecClk()))
				(!tc<pxt,Bll>::iof(tPxRec->CurrBuff)) ? ++cExecFalse : --cExecFalse;
		}
		this->mValueRec->updtCurr(this->mTermSys.ExecClk(), castB(cExecFalse));
		this->runPostExecIncr();
	}
	#endif	//ExecUpwd
	#if ExecDnwd
	#if CompLazy
	if (!this->backlog())
	{
	#endif //CompLazy
		if (this->needExecCandComp()) this->listCandParams();
		if (this->mBlkCandPrms->itemCount())
		{
			for(Idx tIdx = 0; tIdx < this->mBlkCandPrms->itemCount(); ++tIdx)
			{
				Pos const tPos = this->mBlkCandPrms->item(tIdx);
				Term::performExecIncr(this->mPrmTerms[tPos]);
				EvalRec<pxt> const * tPxRec = mPxRecs[tPos];
				if (tPxRec->PrevDiff(this->mTermSys.ExecClk()))
					(!tc<pxt,Bll>::iof(tPxRec->CurrBuff)) ? ++cExecFalse : --cExecFalse;
			}
			this->mValueRec->updtCurr(this->mTermSys.ExecClk(), castB(cExecFalse));
		}
	#if CompLazy
	}
	else
	{
		if (this->needExecCandComp()) this->markCandParams();
		for(Idx tIdx = 0; tIdx < this->mBlkCandPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkCandPrms->item(tIdx);
			Term::performExecIncr(this->mPrmTerms[tPos]);
			EvalRec<pxt> const * tPxRec = mPxRecs[tPos];

			if (this->mEvalUndonePrms->tagged(tPos))
				{ if (!tc<pxt,Bll>::iof(tPxRec->CurrData())) ++cExecFalse; }
			else if (tPxRec->PrevDiff(this->mTermSys.ExecClk()))
				(!tc<pxt,Bll>::iof(tPxRec->CurrBuff)) ? ++cExecFalse : --cExecFalse;
		}

		for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
		{
			Pos const tPos = this->mBacklogPrms.serial(tIdx);
			if (this->mLblCandPrms.tagged(tPos)) continue;
			Term::performExecBklg(this->mPrmTerms[tPos]);
			EvalRec<pxt> const * tPxRec = mPxRecs[tPos];

			if (this->mEvalUndonePrms->tagged(tPos))
				{ if (!tc<pxt,Bll>::iof(tPxRec->CurrData())) ++cExecFalse; }
			else if (tPxRec->PrevDiff(this->mTermSys.ExecClk()))
				(!tc<pxt,Bll>::iof(tPxRec->CurrBuff)) ? ++cExecFalse : --cExecFalse;
		}

		this->mValueRec->updtCurr(this->mTermSys.ExecClk(), castB(cExecFalse));
	}
	this->runPostExecIncr();
	#endif //CompLazy
	#endif //ExecDnwd
	CatchError
}



#if CompLazy
/*!
	Compute the term in execution mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::execBklg()
{
	WatchError
	for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
	{
		Pos const tPos = this->mBacklogPrms.serial(tIdx);
		Term::performExecBklg(this->mPrmTerms[tPos]);
		EvalRec<pxt> const * tPxRec = mPxRecs[tPos];

		if (this->mEvalUndonePrms->tagged(tPos))
			{ if (!tc<pxt,Bll>::iof(tPxRec->CurrData())) ++cExecFalse; }
		else if (tPxRec->PrevDiff(this->mTermSys.ExecClk()))
			(!tc<pxt,Bll>::iof(tPxRec->CurrBuff)) ? ++cExecFalse : --cExecFalse;
	}

	this->mValueRec->updtCurr(this->mTermSys.ExecClk(), castB(cExecFalse));
	this->runPostExecBklg();
	CatchError
}
#endif //CompLazy


/*!
	Compute the term in simulation mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::simulIncr()
{
	WatchError
	#if SimulUpwd
	if (this->mSimulChgdPrms.tagCount())
	{
		Dim tSimulFalse = cExecFalse;
		for(Idx tIdx = 0; tIdx < this->mSimulChgdPrms.tagCount(); ++tIdx)
		{
			Pos const tPos = this->mSimulChgdPrms.serial(tIdx);
			EvalRec<pxt> const * tPxRec = mPxRecs[tPos];
			if (tPxRec->NextDiff(this->mTermSys.SimulClk()))
				(!tc<pxt,Bll>::iof(tPxRec->NextBuff)) ? ++tSimulFalse : --tSimulFalse;
		}
		this->mValueRec->updtNext(this->mTermSys.SimulClk(), castB(tSimulFalse));
		this->runPostSimulIncr();
	}
	#endif	//SimulUpwd
	#if SimulDnwd
	#if CompLazy
	if (!this->backlog())
	{
	#endif //CompLazy
		#if SimulFlexi
		if (this->needSimulFlexiComp()) this->listFlexiParams();
		#endif
		#if SimulFixedFlexi
		if (this->needSimulFixedComp())
			this->enumFixedParams(this->mBlkFlexiPrms->itemCount());
		#elif SimulFixedOnly
		if (this->needSimulFixedComp()) this->listFixedParams();
		#endif

		#if SimulFixed
		if (this->needSimulCacheComp())
		{
			cSimulFalse = cExecFalse;
			for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
			{
				Pos const tPos = this->mBlkFixedPrms->item(tIdx);
				if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->CurrData())) --cSimulFalse;
			}
		}
		#endif//SimulFixed

		#if SimulFixedFlexi
		if (this->mBlkFixedPrms->itemCount() || this->mBlkFlexiPrms->itemCount())
		#elif SimulFixedOnly
		if (this->mBlkFixedPrms->itemCount())
		#elif SimulFlexiOnly
		if (this->mBlkFlexiPrms->itemCount())
		#endif
		{
			#if SimulFixed
			Dim tSimulFalse = cSimulFalse;
			#else
			Dim tSimulFalse = cExecFalse;
			#endif

			#if SimulFixed
			for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
			{
				Pos const tPos = this->mBlkFixedPrms->item(tIdx);
				Term::performSimulIncr(this->mPrmTerms[tPos]);
				if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->NextData(this->mTermSys.SimulClk())))
					++tSimulFalse;
			}
			#endif//SimulFixed

			#if SimulFlexi
			for(Idx tIdx = 0; tIdx < this->mBlkFlexiPrms->itemCount(); ++tIdx)
			{
				Pos const tPos = this->mBlkFlexiPrms->item(tIdx);

				#if SimulFixed
				if (this->mLblFixedPrms.tagged(tPos)) continue;
				#endif

				Term::performSimulIncr(this->mPrmTerms[tPos]);

				EvalRec<pxt> const * tPxRec = mPxRecs[tPos];
				if (tPxRec->NextDiff(this->mTermSys.SimulClk()))
					(!tc<pxt,Bll>::iof(tPxRec->NextBuff)) ? ++tSimulFalse : --tSimulFalse;
			}
			#endif//SimulFlexi

			this->mValueRec->updtNext(this->mTermSys.SimulClk(), castB(tSimulFalse));
		}
	#if CompLazy
	}
	else	//	backlog
	{
		#if SimulFlexi
		if (this->needSimulFlexiComp()) this->listFlexiParams();
		#endif
		#if SimulFixed
		if (this->needSimulFixedComp()) this->markFixedParams();
		#endif

		if (this->needSimulCacheComp())
		{
			if (!this->chgdEmulClk())
			{
				cSimulFalse = cEmulFalse;
				#if SimulFixed
				for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
				{
					Pos const tPos = this->mBlkFixedPrms->item(tIdx);
					if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->LateData(this->mTermSys.EmulClk())))
						--cSimulFalse;
				}
				#endif//SimulFixed
			}
			else
			{
				cSimulFalse = cExecFalse;
				#if SimulFixed
				for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
				{
					Pos const tPos = this->mBlkFixedPrms->item(tIdx);
					if (!this->mEvalUndonePrms->tagged(tPos))
						if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->CurrData()))
							--cSimulFalse;
				}
				#endif//SimulFixed
				for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
				{
					Pos const tPos = this->mBacklogPrms.serial(tIdx);

					#if SimulFixed
					if (this->mLblFixedPrms.tagged(tPos)) continue;
					#endif

					Term::performEmulBklg(this->mPrmTerms[tPos]);
					EvalRec<pxt> const * tPxRec = mPxRecs[tPos];

					if (this->mEvalUndonePrms->tagged(tPos))
					{
						if (!tc<pxt,Bll>::iof(tPxRec->LateData(this->mTermSys.EmulClk())))
							++cSimulFalse;
					}
					else if (tPxRec->LateDiff(this->mTermSys.EmulClk()))
						(!tc<pxt,Bll>::iof(tPxRec->LateBuff)) ? ++cSimulFalse : --cSimulFalse;
				}
			}
		}

		Dim tSimulFalse = cSimulFalse;

		#if SimulFixed
		for(Idx tIdx = 0; tIdx < this->mBlkFixedPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFixedPrms->item(tIdx);
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			if (!tc<pxt,Bll>::iof(mPxRecs[tPos]->NextData(this->mTermSys.SimulClk()))) ++tSimulFalse;
		}
		#endif//SimulFixed

		#if SimulFlexi
		for(Idx tIdx = 0; tIdx < this->mBlkFlexiPrms->itemCount(); ++tIdx)
		{
			Pos const tPos = this->mBlkFlexiPrms->item(tIdx);

			#if SimulFixed
			if (this->mLblFixedPrms.tagged(tPos)) continue;
			#endif

			Term::performEmulBklg(this->mPrmTerms[tPos]);
			Term::performSimulIncr(this->mPrmTerms[tPos]);
			EvalRec<pxt> const * tPxRec = mPxRecs[tPos];
			if (tPxRec->LtNxDiff(this->mTermSys.EmulClk(), this->mTermSys.SimulClk()))
			 (!tc<pxt,Bll>::iof(tPxRec->NextData(this->mTermSys.SimulClk()))) ? ++tSimulFalse : --tSimulFalse;
		}
		#endif//SimulFlexi

		this->mValueRec->updtNext(this->mTermSys.SimulClk(), castB(tSimulFalse));
	}
	#endif	//	CompLazy
	#endif	//	SimulDnwd
	CatchError
}


#if CompLazy
/*!
	Compute the term in simulation mode.
*/
template <typename pxt, typename fvt>
void NandsXFeVt<pxt,fvt>::emulBklg()
{
	WatchError
	 cEmulFalse = cExecFalse;
	for(Idx tIdx = 0; tIdx < this->mBacklogPrms.tagCount(); ++tIdx)
	{
		Pos const tPos = this->mBacklogPrms.serial(tIdx);
		Term::performEmulBklg(this->mPrmTerms[tPos]);
		EvalRec<pxt> const * tPxRec = mPxRecs[tPos];

		if (this->mEvalUndonePrms->tagged(tPos))
			{ if (!tc<pxt,Bll>::iof(tPxRec->LateData(this->mTermSys.EmulClk()))) ++cEmulFalse; }
		else if (tPxRec->LateDiff(this->mTermSys.EmulClk()))
			(!tc<pxt,Bll>::iof(tPxRec->LateBuff)) ? ++cEmulFalse : --cEmulFalse;
	}
	this->mValueRec->updtLate(this->mTermSys.EmulClk(), castB(cEmulFalse));
	CatchError
}
#endif	//CompLazy


closeKangarooSpace


#endif//NandsXFeVtTccIncluded
