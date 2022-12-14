// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/B

// how did that pass sample test case >.<

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}
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

// { ==== Begin library RandomEngine.h ====
std::mt19937 engine(
#if LOCAL
		123456
#else
		std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::steady_clock::now().time_since_epoch()).count()
#endif
		);

// } ==== End library RandomEngine.h ====
using modular=Modular< 1000123819 >;
modular const base=
#if LOCAL
10
#else
std::uniform_int_distribution(2, modular::MOD()-1)(engine)
#endif
	;

std::vector<modular> basePower{1};

std::vector<modular> hashPrefixExclusive(auto it, int len){
	std::vector<modular> result(len+1);
	assert(result[0]==0);
	for(int i=1; i<=len; ++i)
		result[i]=result[i-1]*base+(it[i-1]);
	return result;
}

modular getHash(std::vector<modular> const& hash, int left, int right){
	return hash[right]-hash[left]*basePower[right-left];
}

void up(){
	int len; std::cin>>len;
	std::vector<int> a(len);
	for(auto& it: a) {
		std::cin>>it; --it;
	}
	
	while((int)basePower.size()<=len) basePower.push_back(basePower.back()*base);

	auto hash=hashPrefixExclusive(a.begin(), len);
	auto hashReverse=hashPrefixExclusive(a.rbegin(), len);

	
	std::vector<std::vector<int>> indices(len);
	for(int index=0; index<len; ++index)
		indices[a[index]].push_back(index);

	for(auto const& v: indices) if(not v.empty()){

		modular hashR{}, hashReverseR{}, powReverse=1;

		auto const addSegment=[&](int left, int right){
			auto p=basePower[right-left];
			hashR=hashR*p+getHash(hash, left, right);
			hashReverseR+=powReverse*getHash(hashReverse, len-right, len-left);
			powReverse*=p;
		};

		int last=0;
		for(auto i: v){
			addSegment(last, i);
			last=i+1;
		}
		addSegment(last, len);

		if(hashR==hashReverseR){
			std::cout<<"YES\n";
			return;
		}
	}
	std::cout<<"NO\n";

	
}