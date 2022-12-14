// time-limit: 2000
// problem-url: https://codeforces.com/contest/1586/problem/G

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library Modular.h ====

template<class F, bool comparable=true> struct Modular_ {
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

// { ==== Begin library BIT.h ====

template<class T>
struct Tree{
	std::vector<T> data;
	Tree(int number=0): data(number){}
	void reset(int number){data.clear(); data.resize(number);}

	T operator[](int index)const{
		assert(0<=index); assert(index<(int)data.size());
		T result{};
		while(index<(int)data.size()){
			result+=data[index];
			index|=index+1;
		}
		return result;
	}

	template<int minAllowedI=0> // can pass INT_MIN to disable check, or -1
	void addPrefixInclusive(int index, T delta){
		assert(index>=minAllowedI);
		++index;
		while(index>0){
			data[index-1]+=delta;
			index&=index-1;
		}
	}
	void add(int left, int right, T delta){
		assert(0<=left); assert(left<=right); assert(right<=(int)data.size());
		addPrefixInclusive(right-1, delta);
		addPrefixInclusive(left-1,-delta);
	}
};

// } ==== End library BIT.h ====
// seems correct (also brute forced, but still...)
//

using modular=Modular<1000000007>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int number; std::cin>>number;

	struct Task{int a, b; bool required;};
	std::vector<Task> tasks(number);
	for(auto& [a, b, required]: tasks){
		std::cin>>a>>b;
		//--a; --b;
	}
	{
		int t; std::cin>>t;
		for(int _=0; _<t; ++_){
			int s; std::cin>>s; --s;
			tasks[s].required=true;
		}
	}

	std::sort(begin(tasks), end(tasks), [&](auto const& first, auto const& sec){
		return first.b<sec.b;
	});


	for(int maxRequiredA=INT_MIN, i=(int)tasks.size(); i--;){
		if(tasks[i].required)
			maxRequiredA=std::max(maxRequiredA, tasks[i].a);
		else if(tasks[i].a<maxRequiredA)
			tasks[i].required=true;
	}

	//modular NONE; NONE.val=-1;

	//std::vector<modular> c(number*2+1);
	Tree<modular> c(number*2+1);
	//c[0]=0;
	number=-1;
	modular x=0;

	std::set<int> usedA;
	usedA.insert(0);

	int xceil=0; // smallest index such that c[xceil]!=NONE and  (by real value) x
	int k=0;

	auto print=[&](){
		for(int i=0; i<(int)c.data.size(); ++i)
			std::cerr<<c[i]<<' ';
		std::cerr<<'\n';
	};
	
	for(auto const [a, b, required]: tasks){
		int i=a-1;
		//while(c[i]==NONE) i--;
		i=*--usedA.upper_bound(i);

		if((int)usedA.size()<30){
			assert(([&]{
				for(auto z: usedA) if((int)c[z]>=(int)x){
					assert(z==xceil);
					break;
				}
				return true;
			}()));
		}

		//int k=(int)c.size()-1;
		//while(c[k]==NONE) k--;

		//assert(c[a]==NONE);
		auto [iterator, inserted]=usedA.insert(a);
		assert(inserted);

		c.add(a, a+1, c[k]+1-c[a]);
		assert((int)c[a]==(int)(c[k]+1));

		auto const delta=c[k]+1-c[i];
		if(a<k)
			c.add(a+1, k+1, delta);

		if(required){
			if(
					//x<=c[i] /* TODO */
					xceil<=i
					) {
				x=c[a];
				xceil=a;
			}
			else {
				x+=delta;
			}
		}else{
			if(xceil>i) xceil=a;
		}

		k=std::max(k, a);
	}

	std::cout<<(int)x<<'\n';

	
}