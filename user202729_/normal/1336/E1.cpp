// :((

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int64_t> values;
std::array<int, 64> backtrackResult;

void backtrack(int index, int64_t value){
	if(index==(int)values.size()){ backtrackResult[__builtin_popcountll(value)]+=1; return; }
	backtrack(index+1, value);
	backtrack(index+1, value xor values[index]);
}

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



int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number, numBit; std::cin>>number>>numBit;
	std::vector<int64_t> numbers(number);for(auto & it: numbers) std::cin>>it;


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

#if 1
	if(values.size()<=20){
		backtrackResult.fill(0);
		backtrack(0, 0);
		std::for_each(backtrackResult.begin(), backtrackResult.begin()+numBit+1,[&](auto it){
			std::cout<<int(multiplier*it)<<' ';
		});
		std::cout<<'\n';
		return 0;
	}
#endif
			
	int64_t orAll=0;
	for(auto & it: values) {
		it&=~special;
		orAll|=it;
	}
	int const m=__builtin_popcountll(orAll);
	assert((int)values.size()+m<=numBit);

	for(auto & it: values) {
		int compressed=0;
		for(auto tmp=orAll; tmp; tmp-=tmp&-tmp)
			compressed=compressed<<1 | bool(it&(tmp&-tmp));
		assert(compressed<=(1<=m));
		it=compressed;
	}

	std::array<std::vector<modular>, 36> count;
	for(auto & it: count) it.resize(1<<m);


	count[0][0]=multiplier;
	for(auto const mask: values){
		for(auto numExisting=(int)count.size()-1; numExisting--;){
			for(int maskExisting=0;maskExisting<(1<<m);++maskExisting) 
				count[numExisting+1][maskExisting xor mask]+=count[numExisting][maskExisting];
		}
	}

	std::array<modular, 64> result;
	for(auto numExisting=(int)count.size(); numExisting--;){
		for(int maskExisting=0;maskExisting<(1<<m);++maskExisting) 
			result[__builtin_popcount(maskExisting)+numExisting]+=
				count[numExisting][maskExisting];
	}
	std::for_each(result.begin(), result.begin()+numBit+1,[&](auto it){ std::cout<<(int)it<<' '; });
	std::cout<<'\n';
}