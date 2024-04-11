#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

#include<type_traits>

template<class F> // mod = F{}(). F must be default-constructible and cheap to construct
struct Modular_ {
#define MOD (F{}())

	using T=typename std::decay<decltype(MOD)>::type;
	T val;
	explicit constexpr operator T() const { return val; }
	constexpr Modular_():val(){}
#if 1 // slightly less efficient to construct, easier to implement
	constexpr Modular_(auto v):val(T(v%MOD)){ if(val<0)val+=MOD; }
#else
	constexpr Modular_(T v):val(v){
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

		bool constexpr is_int=std::is_same<T, int>::value;
		bool constexpr is_int64_t=std::is_same<T, int64_t>::value;
		static_assert(is_int or is_int64_t, "Mod type not supported");

		if(is_int){
			val = int((int64_t)val*m.val%MOD);
		}else{
			uint64_t result=
				(uint64_t)val*(uint64_t)m.val-
				uint64_t((long double)val*m.val/MOD)*(uint64_t)MOD;
			result+=MOD;
			if(result>=MOD){
				result-=MOD;
				if(result>=MOD) result-=MOD;
			}
			val=result;
		}
		return *this;
	}
	[[nodiscard]] Modular_ constexpr pow(int p) const {
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ constexpr inv() const {
		T a=val,b=MOD, ax=1,bx=0;
		while(b){
			T q=a/b, t=a%b;
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

template<int MOD> using Modular=Modular_<std::integral_constant<int, MOD>>;

template<class T, T const& x> struct TPointerGetter{ T operator()() const{ return x; } };
template<int const& x> using IntPointerGetter=TPointerGetter<int, x>;
template<int const& MOD> using ModularP=Modular_<IntPointerGetter<MOD>>;

int mod;
using modular=ModularP<mod>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numForbid; std::cin>>numForbid>>mod;

	std::vector<std::vector<int>> allowedByGcd(mod+1);
	std::vector<char> forbid(mod);
	for(int _=0; _<numForbid; ++_){
		int value; std::cin>>value;
		assert(not forbid[value]);
		forbid[value]=true;
	}

	for(int value=0; value<mod; ++value)
		if(not forbid[value])
			allowedByGcd[std::gcd(value, mod)].push_back(value);
	assert(allowedByGcd[0].empty()); // gcd(mod, 0)==mod

	struct Entry{
		int gcd, maxLength, trace; // trace: last gcd value (0: none)
	};
	std::vector<Entry> values; // (gcd value, maximum sequence length)
	Entry result{};

	auto const process=[&](int gcd){
		if(not allowedByGcd[gcd].empty()){
			Entry entry{};
			for(auto [lastGcd, lastLength, _]: values) if(gcd%lastGcd==0 and lastLength>=entry.maxLength){
				entry.maxLength=lastLength; entry.trace=lastGcd;
			}
			entry.gcd=gcd;

			entry.maxLength+=(int)allowedByGcd[gcd].size();

			if(entry.maxLength>=result.maxLength) result=entry;
			values.push_back(entry);
		}
	};

	for(int gcd=1; gcd<=mod; ++gcd) process(gcd);

	std::cout<<result.maxLength<<'\n';
	std::vector<Entry> chain{result};
	while(chain.back().trace!=0) chain.push_back(*std::find_if(begin(values), end(values),
				[x=chain.back().trace](auto it){return it.gcd==x;}));

	modular last=1;
	static int lastModOverGcd=mod;
	int lastGcd=1;
	using modular1=ModularP<lastModOverGcd>;
	std::for_each(chain.rbegin(), chain.rend(),[&](auto it){
		for(auto const value: allowedByGcd[it.gcd]){
			//std::cout<<value/last<<' ';

			assert(std::gcd((int)last, mod)==lastGcd);
			assert(lastGcd*lastModOverGcd==mod);

			assert(value%lastGcd==0);
			assert((int)last%lastGcd==0);

			std::cout<<int(modular1(value/lastGcd)/((int)last/lastGcd))<<' ';
	
			last=value; lastModOverGcd=mod/it.gcd;
			lastGcd=it.gcd;
			assert(std::gcd((int)last, mod)==it.gcd);
		}
	});
	std::cout<<'\n';

}