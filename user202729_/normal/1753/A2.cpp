// time-limit: 2000
// problem-url: https://codeforces.com/contest/1753/problem/A2

#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// { ==== Begin library read ====


template<class T> T read(){
	T result;
	std::cin>>result;
	assert(std::cin);
	return result;
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

// iterate over container backwards. Currently only support lvalue, avoid iterator invalidation etc.
template<class T> auto reverse_range(T& value){
	return range(value.rbegin(), value.rend());
}

//template<class Container> auto range(Container container){
//	return Range{ std::begin(container), std::end(container) };
//}

template<class T, class=std::enable_if<std::is_integral<T>::value, int>>
auto infinite_range(T first){return Range<int_iter<T>, unreachable_iter>{first, {}};}

template<class T> T&& identity(T&& x){ return x; }

// } ==== End library range ====


void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const len=read<int>();
	std::vector<int> a(len);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	if((std::accumulate(begin(a), end(a), 0)&1)!=0){
		std::cout<<"-1\n";
		return;
	}

	std::vector<std::pair<int, int>> f(len+1); // [i]  range of sum of elements at index  i, given [i] is added
	// range is (left, right), both inclusive, and they must have same parity

	f[len]={0, 0};
	f[len-1]={a.back(), a.back()};
	for(int i=len-2; i>=0; i--){
		auto [left1, right1]=f[i+1]; // assuming next sign is "+"
		auto [left2, right2]=f[i+2]; // assuming next sign is "-" then the next-next one must be "+"
		left2-=a[i+1];
		right2-=a[i+1];

		// compute union of [left1, right1] and [left2, right2]
		f[i]={std::min(left1, left2), std::max(right1, right2)};
		f[i].first+=a[i];
		f[i].second+=a[i];
	}

	auto const contains=[&](std::pair<int, int> range, int value){
		assert(range.first<=range.second);
		assert((range.first^range.second^1)&1);
		assert((value^range.second^1)&1);
		return range.first<=value and value<=range.second;
	};

	if(not contains(f[0], 0)){
		std::cout<<"-1\n";
		return;
	}

	// otherwise it must be even
	std::vector<char> positive(len);
	int sumLeft=0;
	int i=0;
	while(i<len){
		if(contains(f[i+1], sumLeft-a[i])){
			sumLeft-=a[i];
			positive[i]=true;
			i++;
		}else{
			assert(contains(f[i+2], sumLeft-a[i]+a[i+1]));
			sumLeft=sumLeft-a[i]+a[i+1];
			positive[i]=true;
			positive[i+1]=false;
			i+=2;
		}
	}

	assert(sumLeft==0);
	#if not NDEBUG
	auto tmp=0;
	for(int const i: range(0, len)){
		tmp+=positive[i] ? a[i]: -a[i];
	}
	assert(tmp==0);
	#endif
	std::cout<<std::accumulate(begin(positive), end(positive), 0)<<'\n';
	for(int const i: range(0, len)){
		if(not positive[i]) continue;
		std::cout<<i+1<<' '<<i+1+(i+1<len and not positive[i+1])<<'\n';
	}
}