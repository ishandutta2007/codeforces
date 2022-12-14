// :(
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


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
	template<class U>
	[[nodiscard]] Modular_ constexpr pow(U p) const {
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

using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string string; std::cin>>string;
	int count{};
	std::vector<int> values;
	for(auto ch: string) {
		if(ch=='0'){
			++count;
		}else{
			values.push_back(count);
			count=0;
		}
	}

	if(values.size()==0){
		assert(count==(int)string.size());
		std::cout<<count<<'\n'; return 0; //<MOD
	}
	auto const multiplier=modular(count+1)*(values[0]+1);
	values.erase(values.begin());

	modular result=1;
	std::vector<modular> add;
	modular fix=1;
	for(auto value: values){
		while((int)add.size()<=value) add.push_back(0);

		modular more{};
		for(int i=0; i<=value; ++i){
			auto const vi=fix+add[i];
			add[i]=-fix;
			more+=vi;
			result+=vi;
		}
		fix+=more;
	}

	result*=multiplier;
	std::cout<<(int)result<<'\n';
}