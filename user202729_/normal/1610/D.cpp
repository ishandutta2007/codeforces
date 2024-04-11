// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/D

// .........
// (also why did I test with n=30 but not n=32)

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library Modular.h ====

template<class F> struct Modular_ {
	static auto MOD(){ return
#define MOD (F::get())
		MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){}

	template<class U> static auto check_can_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_can_mod_mod<U>()) // sfinae
		> Modular_(U v)
		{
			/*
			val=T(v%MOD);
			if(val<0)val+=MOD;
			*/
			v%=MOD;
			if(v<0)v+=MOD;
			val=T(v);
		}

	template<class U> static Modular_ raw(U value){ // for micro-optimizations
		using V=std::common_type_t<U, decltype(MOD)>;
		assert(0<=value); assert((V)value<(V)MOD);
		Modular_ result; result.val=value; return result;
	}

#define COMPAREOP(OP) [[nodiscard]] bool operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] Modular_ operator+() const{ return *this; }
	[[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_& operator-=(Modular_ m) {
		if(std::is_signed_v<T>){
			if ((val -= m.val) < 0) val += MOD;
		}else{
			if (val < m.val) val+=MOD; 
			val-=m.val;
		}
		return *this;
	}
	Modular_& operator*=(Modular_ m) {
		//if(__builtin_constant_p(m.val)){
		//	switch(m.val){
		//		case 1: return *this;
		//		case 2: return *this+=*this;
		//		case 3: return *this+=*this+*this;
		//		case 0: return *this=0;
		//		case -1: return *this=-*this;
		//	}
		//}else if(__builtin_constant_p(val)){
		//	return *this=m**this;
		//}

		if constexpr(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else if constexpr(std::is_same<T, int64_t>::value){
			uint64_t result=
				(uint64_t)val*(uint64_t)m.val-
				uint64_t((long double)val*m.val/MOD)*(uint64_t)MOD;
			result+=MOD;
			if(result>=MOD){
				result-=MOD;
				if(result>=MOD) result-=MOD;
			}
			val=result;
		}else{
			// TODO?
			val*=m.val;
			val%=MOD;
			//assert(false);
		}
		return *this;
	}
	template<class U>
	[[nodiscard]] Modular_ pow(U p) const {
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ inv() const {
		T a=val,b=MOD, ax=1,bx=0;
		while(b!=0){
			T q=a/b, t=a%b;
			a=b; b=t;
			t=T(ax-bx*q); ax=bx; bx=t;
		}
		assert(a==1);
		if(ax<0)ax+=MOD;
		return ax;
	}
	Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'M'; }

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>; // warning: must use global variable (with linkage)
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>; // warning: must use global variable (with linkage)

// } ==== End library Modular.h ====
using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int len; std::cin>>len;
	std::array<int, 31> count{};
#if LOCAL
	std::vector<int> a(len);
#endif
	for(int i=0; i<len; ++i){
		int ai; std::cin>>ai;
		assert((a[i]=ai));
		count[__builtin_ctz(ai)]++;
	}

	std::vector<modular> pow2(len+1);
	pow2[0]=1;
	for(int i=1; i<(int)pow2.size(); ++i)
		pow2[i]=pow2[i-1]*2;

	int tmp=len-count[0];

	modular result {};
	result+=
		(pow2[count[0]]-1) // nonempty odd
		*pow2[tmp] // any even
		;

	for(int i=1; i<(int)count.size(); tmp-=count[i], ++i) if(count[i]>=2){
		// i: ord2 of gcd of selected
		// tmp: sum count [ i]
		
		result+=
			(pow2[count[i]-1]-1)* // nonempty even-sized count=[i]
			pow2[tmp-count[i]]; // larger any
	}

	assert(([&]{
		return true;

		
		int tmp{};
		for(int mask=1; mask<(1<<len); ++mask){
			int64_t offset{};
			int64_t gcdAll {};
			for(int i=0; i<len; ++i) if(mask>>i&1){
				if(a[i]%2==0) offset+=a[i]>>1;
				gcdAll=std::gcd(gcdAll, a[i]);
			}
			assert(gcdAll!=0);
			assert(offset*2%gcdAll==0);
			if(offset%gcdAll==0) tmp++;
		}
		assert(result==tmp);
		return true;
	}()));

	std::cout<<(int)result<<'\n';
}