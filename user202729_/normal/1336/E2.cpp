// I had to read the editorial.
// Key idea: the H transform of the large table only has a small number of nonzero entries.
// I did not think of doing that since that table is 2^53 entries long so it would be infeasible to iterate through that.
// H transform the intermediate DP states would (probably) not end up with something usable.
//
// I still have some ideas left to optimize the slower solution
// (memory usage. The runtime fits in the time limit already) -- but there's no point in doing that.

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>





template<class T> // mod = T{}(). T must be default-constructible and cheap to construct
struct Modular_ {
#define MOD (T{}())

	int val;
	explicit constexpr operator int() const { return val; }
	constexpr Modular_():val(){}
#if 1 // slightly less efficient to construct, easier to implement
	constexpr Modular_(auto v):val(int(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr Modular_(int v):val(v){
		assert(0<=v and v<MOD);
	}
#endif

#define COMPAREOP(OP) [[nodiscard]] bool constexpr operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] friend Modular_ constexpr operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_ constexpr& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_ constexpr& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += MOD; return *this; }
	Modular_ constexpr& operator*=(Modular_ m) {
		if(__builtin_constant_p(m.val)){
			switch(m.val){
				case 1: return *this;
				case 2: return *this+=*this;
				case 3: return *this+=*this+*this;
				case 0: return *this=0;
				case -1: return *this=-*this;
			}
		}else if(__builtin_constant_p(val)){
			return *this=m**this;
		}
		val = int((int64_t)val*m.val%MOD);
		return *this;
	}
	[[nodiscard]] Modular_ constexpr pow(int p) const {
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p /= 2, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ constexpr inv() const {
		int a=val,b=MOD, ax=1,bx=0;
		while(b){
			int q=a/b, t=a%b;
			a=b; b=t;
			t=ax-bx*q; ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	Modular_ constexpr& operator/=(Modular_ m) { return (*this) *= m.inv(); }

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ constexpr operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<int x> struct IntConstGetter{ int operator()() const{ return x; } };
template<int MOD> using Modular=Modular_<IntConstGetter<MOD>>;

using modular=Modular<998244353>;




std::vector<int64_t> values;
std::array<int, 64> backtrackResult;

void backtrack(int index, int64_t value){
	if(index==(int)values.size()){ backtrackResult[__builtin_popcountll(value)]+=1; return; }
	backtrack(index+1, value);
	backtrack(index+1, value xor values[index]);
}



int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numBit; std::cin>>number>>numBit;
	std::vector<int64_t> numbers(number);for(auto & it: numbers) std::cin>>it;

	// Gaussian elimination -- multiplier=modular(2).pow(number of free dimensions, values=linear basis generators
	int64_t special=0;
	modular multiplier=1;
	for(int pos=0;pos<number;++pos) if(auto const value=numbers[pos]){
		auto const lastbit=value&-value;
		for(auto & it: numbers) if(it&lastbit) it^=value;
		for(auto & it: values) if(it&lastbit) it^=value;
		assert(numbers[pos]==0);
		values.push_back(value);
		special|=lastbit;
	} else multiplier+=multiplier;
	numbers.clear();
	// special=columns (bit positions) in values such that there's exactly one bit set

#if 1 // backtrack
	if(values.size()<=27){
		backtrackResult.fill(0);
		backtrack(0, 0);
		std::for_each(backtrackResult.begin(), backtrackResult.begin()+numBit+1,[&](auto it){
			std::cout<<int(multiplier*it)<<' ';
		});
		std::cout<<'\n';
		return 0;
	}
#endif

	// compute basis for H transform of A
	std::vector<int64_t> complement;
	for(int pos=0;pos<numBit;++pos) if(not(special>>pos&1)){
		auto value=(int64_t)1<<pos;
		for(auto generator: values){
			assert(__builtin_popcountll(generator&special)==1);
			if(generator>>pos&1)
				value|=generator&special;
		}
		complement.push_back(value);
	}

	assert(int(complement.size()+values.size())==numBit);
	assert(__builtin_popcountll(special)==(int)values.size());


	values=std::move(complement); // used by backtrack
	backtrackResult.fill(0);
	backtrack(0, 0);

	std::array<std::array<std::array<modular, 64>, 64>, 64> maskH{};
	// maskH[dimension][maskCount][count] = H(mask{dimension, maskCount})[p], for any p: popcount(p)==count

	for(int dimension=0;dimension<(int)maskH.size();++dimension) {
		for(int count=0;count<=dimension;++count)
			maskH[dimension][0][count]=1;

		for(int maskCount=1;maskCount<=dimension;++maskCount) 
			for(int count=0;count<=dimension;++count) {
				auto value1=[&]{
					return maskH[dimension-1][maskCount][count-1]-maskH[dimension-1][maskCount-1][count-1];
				};
				auto const value2=[&]{
					return maskH[dimension-1][maskCount][count]+maskH[dimension-1][maskCount-1][count];
				};
				if(count!=dimension and count!=0) assert(value1()==value2());
				maskH[dimension][maskCount][count]=count==0 ? value2(): value1();
			}
	}

	multiplier*=(modular(1)/2).pow((int)values.size()); // now values.size() is number of dimensions of H(A)
	for(int maskCount=0;maskCount<=numBit;++maskCount) {
		modular curResult{};
		for(int count=0;count<=numBit;++count)
			curResult+=backtrackResult[count]*maskH[numBit][maskCount][count];
		std::cout<<int(curResult*multiplier)<<' ';
	}
	std::cout<<'\n';
}