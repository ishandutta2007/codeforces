#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



std::vector<int> minFactorF(int const limit){
	std::vector<int> minFactor(limit);
	for(int p=2; p<(int)minFactor.size(); ++p) if(minFactor[p]==0){
		minFactor[p]=p;
		if((int64_t)p*p<(int)minFactor.size())
			for(int j=p*p; j<(int)minFactor.size(); j+=p)
				if(minFactor[j]==0)
					minFactor[j]=p;
	}
	return minFactor;
}

template<class F> auto computeMultiplicativeFunction(F f, std::vector<int> const& minFactor_){
	// f: (prime, exponent, product) -> value -- return type=return type of f
	std::vector<decltype(f(2, 1, 2))> result(minFactor_.size(), 1);
	for(int prime=2; prime<(int)result.size(); ++prime) if(minFactor_[prime]==prime){
		for(auto [exponent, product]=std::pair(1, (int64_t)prime); product<(int)result.size(); product*=prime, exponent++) [&]{
			auto const value=f(prime, exponent, (int)product);
			for(int k=0;; ++k)
			for(int f=1; f<prime; ++f){
				auto const x=(prime*k+f)*product;
				if(x>=(int)result.size()) return;
				result[x]*=value;
			}
		}();
	}
	// * n log n, slow?
	return result;
}

#define MakeFunction(N, E) \
auto N(std::vector<int> const& minFactor_){ \
	return computeMultiplicativeFunction([&]( \
				[[maybe_unused]] int prime, [[maybe_unused]] int exponent, [[maybe_unused]] int product){ \
		return E; \
	}, minFactor_); \
} \
auto N(int limit){ return N(minFactorF(limit)); }


MakeFunction(MobiusF, (signed char)(exponent>=2 ? 0: -1))
MakeFunction(phiF, int(product/prime*(prime-1)))


std::vector<char> isCompositeF(int const limit){
	std::vector<char> isComposite(limit);
	std::vector<int> exponents;
	for(int p=2; p<(int)isComposite.size(); ++p) if(not isComposite[p]){
		if((int64_t)p*p<limit)
		for(int j=p*p; j<(int)isComposite.size(); j+=p)
			isComposite[j]=true;
	}
	return isComposite;
}

std::vector<int> primesF(int const limit){
	std::vector<int> primes;
	auto const isComposite=isCompositeF(limit);
	for(int p=2; p<limit; ++p)
		if(not isComposite[p]) primes.push_back(p);
	return primes;
}

template<class F> struct Modular_ {
	static auto MOD(){ return
#define MOD (F::get())
		MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){}

	template<class U> static auto check_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_mod_mod<U>()) // sfinae
		> Modular_(U v):val(T(v%MOD)){ if(val<0)val+=MOD; }

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
	Modular_& operator-=(Modular_ m) { if ((val -= m.val) < 0) val += MOD; return *this; }
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
			t=ax-bx*q; ax=bx; bx=t;
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


int mod;
using modular=ModularP<mod>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n; std::cin>>n;
	std::cin>>mod;
	
	/*
	std::vector<modular> f(n+1), sum(n+1);
	f[1]=sum[1]=1;
	for(int x=2; x<=n; ++x){
		int y=x;
		modular result=sum[x-1];
		while(y!=1){
			// remaining: 2..=y
			int old=y;
			int tmp=y=x/y;
			y++;
			y=x/y;

			// consider segment y+1..=old with quotient=tmp
			result+=f[tmp]*(old-y);
		}

		f[x]=result;
		sum[x]=sum[x-1]+f[x];
	}
	std::cout<<(int)f[n]<<'\n';
	*/

	auto const minFactor=minFactorF(n+1);

	std::vector<modular> f(n+1);
	f[1]=1; f[2]=2;
	for(int x=3; x<=n; ++x){
		std::vector<int> factors_x{1};
		int tmp=x;
		while(tmp!=1){
			int p=minFactor[tmp], exponent=0;
			do{tmp/=p; exponent++;}while(
					tmp%p==0
					// minFactor[tmp]==p
					);

			int const N=(int)factors_x.size();
			factors_x.reserve(N*(exponent+1));
			for(int i=0; i<N*exponent; ++i)
				factors_x.push_back(factors_x.end()[-N]*p);

			assert((int)factors_x.size()==N*(exponent+1));
		}

		f[x]=2*f[x-1];

		assert(factors_x[0]==1);
		for(int d: factors_x) if(d!=1) f[x]+=f[x/d]-f[(x-1)/d];
	}
	std::cout<<(int)f[n]<<'\n';
	
}