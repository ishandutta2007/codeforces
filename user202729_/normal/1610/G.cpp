// time-limit: 1000
// problem-url: https://codeforces.com/contest/1610/problem/G
#if not LOCAL
#define NDEBUG 1
#endif

#include<bits/stdc++.h>
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
			val=T(v%MOD);
			if(val<0)val+=MOD;
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

// { ==== Begin library HashSegment.h ====


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
template<class modular>
struct HashSegment{
	static const std::vector<modular> basePow;
	static const modular base;

	static auto computeBasePow(int maxLen){
		std::vector<modular> basePow(maxLen+1);
		basePow[0]=1;
		for(int index=0; index<maxLen; ++index)
			basePow[index+1]=basePow[index]*base;
		return basePow;
	}

	modular hash; int len;

	static HashSegment empty(){return HashSegment{0, 0};}
	static HashSegment single(modular ch){return HashSegment{ch, 1};}
	static HashSegment combine(HashSegment a, HashSegment b){
		return HashSegment{
			.hash=a.hash*basePow[b.len]+b.hash,
				.len=a.len+b.len
		};
	}
	HashSegment removePrefix(HashSegment prefix) const{
		assert(prefix.len<=len);
		return HashSegment{
			.hash=hash-prefix.hash*basePow[len-prefix.len],
			.len=len-prefix.len
		};
	}

};

template<class modular>
struct HashPrefixes{
	std::vector<modular> data{0};
	// store an extra 0...

	HashSegment<modular> prefix(int prefixLen) const{
		return{data[prefixLen], prefixLen};
	}
	HashSegment<modular> segment(int left, int right) const{
		return prefix(right).removePrefix(prefix(left));
	}

	void push_back(modular value){
		data.push_back(data.back()*HashSegment<modular>::base+value);
	}
	auto size() const{assert(not data.empty()); return data.size()-1;}
	bool empty() const{return size()==0;}
	void pop_back(){assert(not empty()); data.pop_back();}
	void clear(){data.clear(); data.push_back(0);}
	void append(auto first, auto last){
		std::for_each(first, last, [&](auto const& it){
			push_back(it);
		});
	}
};

template<class modular> modular const HashSegment<modular>::base=
#if LOCAL
100
#else
std::uniform_int_distribution{2, modular::MOD()-2}(engine)
#endif
	;

/* example usage

using modular=Modular<1000000007>;
template<> std::vector<modular> const HashSegment<modular>::basePow=HashSegment<modular>::computeBasePow((int)3e5+1);

*/

// } ==== End library HashSegment.h ====
using modular=Modular<1000000007>;
template<> std::vector<modular> const HashSegment<modular>::basePow=HashSegment<modular>::computeBasePow((int)3e5+1);

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s; std::cin>>s;

	std::vector<int> data{0}; // prefix length, stored in reverse order
	HashPrefixes<modular> hash;
	
	for(int index=(int)s.size(); index--;){
		assert(not data.empty());
		if(s[index]=='('){
			data.back()++;
			hash.push_back('(');
			assert(data.back()==(int)hash.size());
			if(data.size()>1){
				int const a=data.back(), b=data.end()[-2], commonLen=b;
				assert(b<a);
				int commonPrefix=0;
				if(commonLen)
				for(int step=1<<(31^__builtin_clz(commonLen)); step; step>>=1){
					if([&](int prefix){
						if(prefix>commonLen) return false;
						return (int)hash.segment(a-prefix, a).hash==(int)hash.segment(b-prefix, b).hash;
					}(commonPrefix+step)) commonPrefix+=step;
				}

				// segment from b <segment from a
				if(commonPrefix==commonLen or
						(int)hash.segment(b-commonPrefix-1, b-commonPrefix).hash
						<
						(int)hash.segment(a-commonPrefix-1, a-commonPrefix).hash
				  ){
					for(int _=0; _<a-b; ++_)
						hash.pop_back();
					data.pop_back();
				}else{
					data.end()[-2]=data.back();
					data.pop_back();
				}
			}
		}else{
			assert(s[index]==')');
			hash.push_back(')');
			data.push_back(data.back()+1);
			assert(data.back()==(int)hash.size());
		}
	}


	
	for(int index=(int)hash.size(); index--;)
		std::cout<<(char)(int)hash.segment(index, index+1).hash;
	std::cout<<'\n';
}