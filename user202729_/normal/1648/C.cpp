// time-limit: 2000
// problem-url: https://codeforces.com/contest/1648/problem/C

// that was really close.

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library read ====

template<class T> T read(){
	T result; std::cin>>result; return result;
}

// } ==== End library read ====

// { ==== Begin library range ====

template<class T>
struct int_iter{
	//using iterator_category = std::random_access_iterator_tag;
	using iterator_category = std::random_access_iterator_tag;
	using value_type = T;
	//using difference_type = std::ptrdiff_t;
	using difference_type = T;
	using pointer = T*;
	using reference = T&;

	T x;
	constexpr int_iter(T x):x{x}{}
	T operator*()const{return x;}
	int_iter& operator++(){ ++x; return *this; }
	int_iter& operator--(){ --x; return *this; }

#define operation(op) \
	int_iter& operator op##=(difference_type y){ x op##= y; return *this; } \
	int_iter friend operator op(int_iter x, difference_type y){ return x op##= y; }
	operation(+) operation(-)
#undef operation
	int_iter friend operator+(difference_type y, int_iter x){ return x += y; }

#define operation(op) \
	auto operator op(int_iter const& other) const{return x op other.x;}
	operation(-) operation(<) operation(>) operation(<=) operation(>=) operation(==) operation(!=)
#undef operation

	T operator[](difference_type y)const{ return x+y; }
};

struct unreachable_iter{
	template<class T, class U,
		class=std::enable_if<
			std::is_same<T, unreachable_iter>::value xor std::is_same<U, unreachable_iter>::value, int>
	> friend bool operator!=(T const& first, U const& sec){ return true; }
};

template<class T> auto range(T first, T last);


template<class A, class B=A>
struct Range{
	A first; B last;
	constexpr Range(A first, B last):first{std::move(first)},last{std::move(last)}{}

	/*
	template<class Container> Range(Container&& container):
		first(std::begin(std::forward<Container>(container))), last(std::end(std::forward<Container>(container))){}
		*/

	// make sure container is not a temporary (TODO?)
	template<class Container> Range(Container& container):
		first(std::begin(container)), last(std::end(container)){}

	constexpr A const& begin() const{return first;}
	constexpr B const& end() const{return last;}
	constexpr auto size() const{ return last-first; }

	Range take(std::size_t len)const{
		return Range{first, std::next(first, len)};
	}
	Range drop(std::size_t len)const{
		return Range{std::next(first, len), last};
	}

	Range const& sort    () const{ std::sort(first, last); return *this; }
	template<class F> Range const& sort_by (F const& compare) const{ std::sort(first, last, compare); return *this; }
	template<class F> Range const& sort_key(F const& key) const{
		std::sort(first, last, [&](auto const& first, auto const& sec){
			return key(first)<key(sec);
		});
		return *this;
	}

	template<class T> Range const& shuffle(T&& engine) const{ std::shuffle(first, last, engine); return *this; }
	Range& unique() { last=std::unique(first, last); return *this; }
	//Range const& reverse() const{ std::reverse(first, last); return *this; }
	auto reverse() const{
		return range(
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
				);
		/*
		return Range<
				typename std::decay<decltype(std::make_reverse_iterator(last))>::type,
				typename std::decay<decltype(std::make_reverse_iterator(first))>::type
		>{
				std::make_reverse_iterator(last),
				std::make_reverse_iterator(first)
		};
		*/
	}

	auto const& assign(Range other) const{
		assert(size()==other.size());
		std::copy(other.first, other.last, first);
		return *this;
	}
	auto const& copy_to(A const& iterator) const{
		std::copy(first, last, iterator);
		return *this;
	}
	auto const& copy_to(Range const& range) const{
		std::copy(first, last, range.first);
		return *this;
	}

	template<class F> auto any  (F const& function) const{ return std::any_of(first, last, function); }
	template<class F> auto all  (F const& function) const{ return std::all_of(first, last, function); }
	template<class F> auto none (F const& function) const{ return std::none_of(first, last, function); }
	template<class F> auto count(F const& function) const{ return std::count_if(first, last, function); }
	template<class F> auto find (F const& function) const{ return std::find_if(first, last, function); }
};


template <typename T>
auto dereferencable(const T& x) -> decltype(void(*x), std::true_type());

std::false_type dereferencable(...);

template<class T> auto range(T first, T last){
	if constexpr(std::is_integral<T>::value){
		assert(first<=last);  // otherwise won't work properly
		return Range<int_iter<T>>{first, last};
	}else{
		static_assert(decltype(dereferencable(first))::value, "value type is neither integral nor dereferencable");
		return Range<T>{first, last};
	}
}

template<class T> auto range(T&& value){
	using T1=typename std::decay<T>::type;
	if constexpr(std::is_integral<T1>::value)
		return Range<int_iter<T1>>{{{}}, std::forward<T>(value)};
	else
		return Range<typename std::decay<decltype(value.begin())>::type>{std::forward<T>(value)};
}


//template<class Container> auto range(Container container){
//	return Range{ std::begin(container), std::end(container) };
//}

template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto infinite_range(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }

// } ==== End library range ====

// { ==== Begin library BITSum.h ====

template<class T>
struct Tree{
	std::vector<T> data;
	Tree(int number=0): data(number){}
	void reset(int number){data.clear(); data.resize(number);}

	template<bool strict=true>
	T sumSuffix(int index)const{
		if(strict){
			assert(0<=index); assert(index<=(int)data.size());
		}
		T result{};
		while(index<(int)data.size()){
			result+=data[index];
			index|=index+1;
		}
		return result;
	}
	T sum(int left, int right) const{
		assert(0<=left); assert(left<=right); assert(right<=(int)data.size());
		return sumSuffix(left)-sumSuffix(right);
	}

	template<bool strict=true>
	void add(int index, T delta){
		if(strict){
			assert(0<=index); assert(index<(int)data.size());
		}
		++index;
		while(index>0){
			data[index-1]+=delta;
			index&=index-1;
		}
	}
};

// } ==== End library BITSum.h ====

// { ==== Begin library ModularFact.h ====


// { ==== Begin library Modular.h ====


// { ==== Begin library modmultiply64 ====

// identical to kactl's ModMulLL

int64_t modmultiply64(int64_t a, int64_t b, int64_t mod){
	uint64_t result=
		(uint64_t)a*(uint64_t)b-
		uint64_t((long double)a*b/mod)*(uint64_t)mod;
	result+=mod;
	if(result>=uint64_t(mod)){
		result-=mod;
		if(result>=uint64_t(mod)) result-=mod;
	}
	return int64_t(result);
}

// } ==== End library modmultiply64 ====

// { ==== Begin library extended_gcd ====

/**
 * input: (x, y)
 *
 * return (a, ax) such that a=ax*x+ay*y for some ay
 */
template<class T> struct extended_gcd_result { T a, ax; };
template<class T> extended_gcd_result<T> extended_gcd(T x, T y){
	static_assert(std::is_signed<T>::value); // otherwise ax will fail...
	T a=x,b=y, ax=1,bx=0;
	while(b!=0){
		T q=a/b, t=a%b;
		a=b; b=t;
		t=T(ax-bx*q); ax=bx; bx=t;
	}
	
	return {a, ax};
}

// } ==== End library extended_gcd ====
template<class F, bool comparable=false> struct Modular_ {
	static auto MOD()
#define MOD (F::get())
	->decltype(MOD){ return MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){
		#if hasdebugprint
		assert(gdbgetstr(*this));
		#endif
	}
	#if hasdebugprint
	DEFINEGETSTR(Modular_)
	#endif

	template<class U> static auto check_can_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_can_mod_mod<U>()) // sfinae
		> Modular_(U v)
		{
			if constexpr (std::is_unsigned<T>::value){
				assert(v>=0);
			}

			/*
			val=T(v%MOD);
			if(val<0)val+=MOD;
			*/
			val=T(v%MOD);
			if(val<0)val+=MOD;
		}

	template<class U> static Modular_ raw(U value){ // for micro-optimizations
		assert(0<=value); assert(value<MOD);
		Modular_ result; result.val=value; return result;
	}

#define COMPAREOP(OP) \
	template <bool _=comparable> \
	[[nodiscard]] typename std::enable_if<_, bool>::type operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] Modular_ operator+() const{ return *this; }
	[[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_& operator-=(Modular_ m) {
		if(std::is_signed<T>::value){
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

#if __GNUC__<=4  // oops, codecrunch version is too old
#define CONSTEXPR__
#else
#define CONSTEXPR__ constexpr
#endif

		if CONSTEXPR__(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else if CONSTEXPR__(std::is_same<T, int64_t>::value){
			val=modmultiply64(val, m.val, MOD);
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
		if constexpr(std::is_signed<U>::value) assert(p>=0);
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ inv() const {
		auto tmp=extended_gcd(val, T(MOD));
		assert(tmp.a==1);
		if(tmp.ax<0)tmp.ax+=MOD;
		return raw(tmp.ax);
	}
	Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, Modular_ m) { return stream<<m.val<<'_'; }

	

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int64_t MOD> using Modular64=Modular_<TGetter<int64_t, MOD>>;
template<int MOD> using ModularComparable=Modular_<TGetter<int, MOD>, true>;
template<int64_t MOD> using ModularComparable64=Modular_<TGetter<int64_t, MOD>, true>;
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
using modular=Modular<998244353>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int const n=read<int>();
	int const m=read<int>();
	std::vector<int> s(n);
	for(auto& it: s) {
		std::cin>>it;
	}
	
	std::vector<int> t(m);
	for(auto& it: t) {
		std::cin>>it;
	}
	
	std::sort(begin(s), end(s));

	auto const fact=factF<modular>(int(s.size())+1);

	Tree<int> tree(*std::max_element(begin(s), end(s))+1);
	std::map<int, int> count; // this is a bit inefficient actually...
	// the data is mirror over the 2 data structures.
	for(auto item: s) {
		tree.add(item, 1);
		count[item]+=1;
	}

	modular globalMultiplier=1; // if s same-characters are made distinct, each permutation would be repeated this many times
	for(auto [key, value]: count) globalMultiplier*=fact[value];
	
#define m do not use
	while(t.size()<s.size()) t.push_back(-1);

	modular result {}, curMultiplier=1;
	for(int const index: range(0, int(s.size()))){
		int bound=t[index]+(index==int(s.size())-1 and s.size()<t.size()); // consider case where all previous characters are equal
		// and this character is strictly smaller than bound

		if(bound>=0){
			auto tmp=tree.sum(0, std::min(bound, int(tree.data.size())));
			if(tmp!=0){
				// there's some such configuration
				result+=fact[s.size()-index-1]*tmp*curMultiplier;
			}
		}

		auto iter=count.lower_bound(bound);
		if(iter!=count.begin()){
			// ?
		}

		if(iter==count.end() or iter->first>bound or index==int(s.size())-1){
			break; // equal prefix cannot be longer (in the last case the all-equal case is already considered)
		}

		curMultiplier*=iter->second;
		iter->second--;
		tree.add(bound, -1);
	}

	result/=globalMultiplier;
	std::cout<<int( result)<<'\n';

	{
	auto const tmp=[&]{
		int tmp {};

		std::sort(begin(s), end(s));
		while(t.back()==-1) t.pop_back();
		do{
			if(s<t) tmp++;
		}while(std::next_permutation(begin(s), end(s)));

		assert(tmp==int(result));
		return true;
	}; assert(tmp());}
		
}

// stress tested, seems okay
// fortunately sample test cases are strong