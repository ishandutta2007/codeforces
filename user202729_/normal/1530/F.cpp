// time-limit: 7000
// problem-url: https://codeforces.com/contest/1530/problem/F


#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


//using T=uint16_t;  using modular=Modular_<TGetter<T, 31607>>;
//using T=int;  using modular=Modular_<TGetter<T, 31607>>;
//using T=double; using modular=double;


int main(){
	/*
	std::cout<<modular(1)/10000<<'\n';
	return 0;
	*/

	/*
#define assertEqual(a, b) assert(assertEqual_(a, b))
	auto const assertEqual_=[&](auto a, auto b){
		if(a!=b){
			std::cerr<<"a="<<a<<'\n';
			std::cerr<<"b="<<b<<'\n';
			return false;
		}
		return true;
	};
	assertEqual(modular(-1), modular(31607-1));
	assertEqual(modular(0)-modular(1), modular(-1));
	assertEqual(modular(0)-modular(-1), modular(1));
	assertEqual(modular(-1)+modular(-1), modular(-2));
	*/


	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	int const maxN=
#if LOCAL
		3
#else
		21
#endif
		; assert(n<=maxN);

	int const MOD=31607;
	uint16_t const inverse_10000=3973;
	assert(inverse_10000*10000%MOD==1);

	std::array<std::array<uint16_t, maxN>, maxN> a {};
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j) {
			int a_; std::cin>>a_;
			a[i][j]=uint16_t(a_*inverse_10000%MOD);
		}

	using BufferType=std::array<uint16_t, 1<<(maxN+3)>;
	int const
		numMask=1<<(n+2),
		DIAGONAL_BIT=0,
		ANTIDIAGONAL_BIT=1,
		COLUMN_BIT_OFFSET=2;
		//CURRENT_ROW_BIT=n+2

	BufferType result {};

	// calculate the probability of losing drop the winning states

	result[numMask-1]=1;

	// first n: (column 0..n)
	// 1: all winning so far

	// therefore each state result[mask] can only update to next[newMask] 
	// where newMask<=mask
	// processing masks in increasing order will ensure correctness without another array
	
	BufferType probabilityCur2On, probabilityCur2Off;

	for(int row=0;; ++row){

		int probabilityRowOn=1;
		BufferType oldResult=result;

		for(int col=0; col<n; ++col){
			int filter=~0;
			//filter&=~(1<<CURRENT_ROW_BIT);
			filter&=~(1<<(col+COLUMN_BIT_OFFSET));
			if(row==col)
				filter&=~(1<<DIAGONAL_BIT);
			if(row+col==n-1)
				filter&=~(1<<ANTIDIAGONAL_BIT);


			// now result does not count this cell
			// compute result := (does count this cell)

			int const probabilityOn=a[row][col];
			probabilityRowOn=probabilityRowOn*probabilityOn%MOD;

			// TODO slow part
			if(filter==~(1<<(col+COLUMN_BIT_OFFSET))){
				int const d=1<<(col+COLUMN_BIT_OFFSET);
				for(int mask_large=0; mask_large<numMask; mask_large+=(2<<(col+COLUMN_BIT_OFFSET))){
					int const numMaskSmall=1<<(col+COLUMN_BIT_OFFSET);

#define F for(int mask_small=0; mask_small<numMaskSmall; ++mask_small)
#define A result[mask_large+mask_small]
#define B result[mask_large+d+mask_small]
#define POn probabilityCur2On[mask_small]
#define POff probabilityCur2Off[mask_small]

					/*
					F POn = B*probabilityOn%MOD;
					F POff = B - POn; // -MOD .. MOD-1
					F B = POn;
					F A += POff;
					F if(A>=MOD) A-=MOD;
					F if(A<0) A+=MOD;
					*/

					F {
						POn = B*probabilityOn%MOD;
						POff = B - POn + MOD; // -MOD .. MOD-1
						if(POff>=MOD) POff-=MOD;
						B = POn;
						A += POff;
						if(A>=MOD) A-=MOD;
					}
				}
			}else{
				for(int mask=0; mask<numMask; ++mask){
					auto cur=result[mask];
					if(cur==0) continue;

					// *result[mask] become next[mask] here

					// this cell is on. Whatever is winning remains winning
					// (later: if whole row is on then drop)
					int const probabilityCurOn=cur*probabilityOn%MOD;
					result[mask]=uint16_t(probabilityCurOn);

					// this cell is off. Some parts of the mask might become off
					int newMask=mask&filter;

					int tmp=result[newMask]+cur-probabilityCurOn;

					if(tmp>=MOD) tmp-=MOD;
					else if(tmp<0) tmp+=MOD;

					result[newMask]=uint16_t(tmp);
				}
			}
		}

		for(int mask=0; mask<numMask; ++mask){
			// subtract the probability that the whole row is on.
			result[mask]=uint16_t((result[mask]+oldResult[mask]*(MOD-probabilityRowOn))%MOD);
		}

		if(row==n-1){
			std::cout<<(1+MOD-result[0])%MOD<<'\n';
			break;
		}
	}

}