// time-limit: 3000
// problem-url: https://codeforces.com/contest/1523/problem/E

// ...

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library ModularComb.h ====
/*
 * Usage:

#include"ModularComb.h"

using modular=Modular<1000000007>;
auto const comb=makeComb<modular>(1000);

comb(5, 3) // -> 10

*/

// { ==== Begin library ModularInverseFact.h ====


// { ==== Begin library ModularInverse.h ====

template<class modular>
std::vector<modular> inverseF(int limit){
	std::vector<modular> inverse(limit);
	inverse[1]=1;
	for(unsigned i=2;i<inverse.size();++i){
		assert(modular::MOD()%i!=0    or not "Mod is not prime, i is not invertible mod mod");
		inverse[i]=inverse[modular::MOD()%i]*modular::raw(modular::MOD()-modular::MOD()/i);
	}
	return inverse;
}

// } ==== End library ModularInverse.h ====
template<class modular>
std::vector<modular> inverseFactF(int limit, std::vector<modular> inverse={}){
	if(inverse.empty()) inverse=inverseF<modular>(limit);
	else assert((int)inverse.size()==limit);

	inverse[0]=1;
	for(int index=3; index<(int)inverse.size(); ++index)
		inverse[index]*=inverse[index-1];
	return inverse;
}


// } ==== End library ModularInverseFact.h ====

// { ==== Begin library ModularFact.h ====


// { ==== Begin library Modular.h ====

template<class F, bool comparable=false> struct Modular_ {
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

#define COMPAREOP(OP) \
	template <bool _=comparable> \
	[[nodiscard]] std::enable_if_t<_, bool> operator OP(Modular_ b) const { return val OP b.val; }
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
template<class modular>
std::vector<modular> factF(int limit){
	std::vector<modular> fact(limit);
	fact[0]=1;
	for(int i=1; i<(int)fact.size(); ++i)
		fact[i]=fact[i-1]*i;
	return fact;
}

// } ==== End library ModularFact.h ====
template<class modular, bool tolerant> struct Comb_internalStructure{
	std::vector<modular> fact, inverseFact;
	modular operator()(int a, int b)const{
		if(tolerant and (b<0 or b>a)) return 0;
		return fact[a]*inverseFact[b]*inverseFact[a-b];
	}
	modular inverseComb(int a, int b)const{
		if(b<0 or b>a) { assert(false); __builtin_unreachable(); }
		return inverseFact[a]*fact[b]*fact[a-b];
	}
	modular walk(int a, int b) const{
		return (*this)(a+b, b);
	}
};

template<class modular, bool tolerant=false>
Comb_internalStructure<modular, tolerant> makeComb(int limit){
	Comb_internalStructure<modular, tolerant> result;
	result.fact=factF<modular>(limit);
	result.inverseFact=inverseFactF<modular>(limit);
	return result;
}

template<class modular>
Comb_internalStructure<modular, true> makeTolerantComb(int limit){ return makeComb<modular, true>(limit); }

// } ==== End library ModularComb.h ====
int const endN=
#if LOCAL
41
#else
(int)1e5+1
#endif
;


using modular=Modular<1000000007>;
auto const comb=makeTolerantComb<modular>(endN*2);


void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int n; std::cin>>n;
	int k; std::cin>>k;
	assert(n<endN);

	modular result{};
	for(int x=1; x<=n; ++x){

		auto const q=x-1, p=n-k*(x-2)-1+q;
		if(p<0) break;


		//assert(std::cerr<<x<<' '<<p<<' '<<q<<'\n');
		result+=comb(p, q)*comb.inverseComb(n, x-1);
	}
	std::cout<<(int)result<<'\n';
}