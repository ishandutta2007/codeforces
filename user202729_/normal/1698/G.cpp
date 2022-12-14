// time-limit: 2000
// problem-url: https://codeforces.com/contest/1698/problem/G

// more template test
// well, preparing these templates doesn't help for ICPC though


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

	template<class Container> Container collect() const{return Container(first, last);}

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


// { ==== Begin library babyGiantStep ====


// also ModLog.h in KACTL

template<class Value,
	class Count=int64_t, 
	class ValueLess=std::less<>,
	class SmallJump, class LargeJump
	>

// returns the (nonzero) number of steps.
Count babyGiantStep(

		Value initial,
		Value target,
		int blockSize,
		SmallJump smallJump, // (value)  next value
		LargeJump largeJump // (value, value after smallJump blockSize times)  next value

		){
	// side note, int blockSize: iterating over >2e9 values doesn't sound good anyway, so int
	std::map<Value, int, ValueLess> smallJumps;

	Value tmp=initial;
	for(int const i: range(0, blockSize)){
		smallJumps[tmp]=i; // allow overriding
		tmp=smallJump(tmp);
	}
	auto const largeJumpValue=std::move(tmp);

	Value cur=target;
	Count pos=0;
	while(true){
		cur=largeJump(cur, largeJumpValue);
		pos+=blockSize;
		auto iter=smallJumps.find(cur);
		if(iter!=smallJumps.end()){
			return pos-iter->second;
		}
	}
}


// } ==== End library babyGiantStep ====


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::string s=read<std::string>();
	for(auto& ch: s) ch-='0';

	auto const iter=std::find(begin(s), end(s), 1);
	if(iter==s.end()){
		std::cout<<"-1\n";
		return 0;
	}

	auto const firstIndex=int(iter-s.begin());
	s.erase(s.begin(), iter);
	while(s.back()==0) s.pop_back();

	auto const blockSize=
	#if LOCAL
	1<<10
	#else
	1<<17 // 35  2?
	#endif
	;

	using U=uint64_t;

	U mod {};
	for(auto ch: s) mod=mod<<1|ch;  // forward or backward doesn't actually matter

	assert(s[0]==1);
	assert(s.back()==1);

	auto const L=int(s.size())-1;
	auto const two_pow_L=(U(1)<<L);
	assert(mod>=two_pow_L);
	assert(mod<two_pow_L*2);

	using UU=unsigned __int128;

	auto const reduce=[&](UU result, int max)->U{
		for(int i=max; i--;)
			if(result>>(i+L)&1){
				result^=UU(mod)<<i;
			}
		assert(result<two_pow_L);
		return U(result);
	};

	auto const multiply=[&](U first, U sec){
		assert(first<two_pow_L);
		assert(sec<two_pow_L);

		UU result{};
		for(int const i: range(0, L)){
			if(first>>i&1){
				result^=UU(sec)<<i;
			}
		}

		return reduce(result, L);
	};

	// it's rather inefficient to use this for one-step multiplication actually

	auto const r2=U(reduce(2, 3));
	auto const multiply2=[&](U value){
		return multiply(value, r2);
	};

	std::cout<<firstIndex+1<<' '<<firstIndex+
		babyGiantStep(
				reduce(1, 3),
				reduce(1, 3),
				blockSize,
				multiply2,
				multiply
				)
		+1<<'\n';
}