#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// { ==== Begin library read ====
#pragma once
template<class T> T read(){
	T result; std::cin>>result; return result;
}

// } ==== End library read ====

// { ==== Begin library range ====
#pragma once

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

// { ==== Begin library PairCompareFirst.h ====
template<class T, class U> struct PairCompareFirst{
	T first; U second;
	PairCompareFirst(T first={}, U second={}): first(std::move(first)), second(std::move(second)){}
	
#define D(op) bool operator op(PairCompareFirst const& other) const{return first op other.first;}
D(==) D(!=)
	D(<) D(>) D(<=) D(>=)
#undef D
};

// } ==== End library PairCompareFirst.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const n=read<int>();
	int const k=read<int>();
	std::vector<int> a(n);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	auto values=a;
	std::sort(begin(values), end(values));
	values.erase(std::unique(begin(values), end(values)), end(values)); // this is redundant......... >< read statement carefully 2

	using P=PairCompareFirst<int, std::pair<int, int>>;
	P result{INT_MAX, {}};

	std::vector<int> valueCount(values.size());
	for(auto it: a){
		valueCount[
		int(std::lower_bound(begin(values), end(values), it)-begin(values))
		]++;
	}


	int right=0;
	int countInside=0;

	auto const extendRight=[&]{
		countInside+=valueCount[right++];
	};
	auto const removeLeft=[&](int left){
		countInside-=valueCount[left];
	};
	auto const satisfied=[&]{
		return countInside-(n-countInside)>=k;
	};

	for(int const left: range(0, n)){
		while(not satisfied()) {
			if(right==int(values.size())){
				goto break_outer;
			}
			extendRight();
		}
		assert(left<right);
		result=std::min(result, P{
			values[right-1]-values[left],
				{
					values[left],
					values[right-1]
				}});
		
		removeLeft(left);
	}
break_outer:

	auto [rangeLeft, rangeRight]=result.second;
	std::cout<<rangeLeft<<' '<<rangeRight<<'\n';
	auto const inRange=[&](int x){
		return rangeLeft<=x and x<=rangeRight;
	};


	int degree=0;
	int left=0;
	int numSegmentPrinted=0;
	if(numSegmentPrinted==k-1){ // annoying
		std::cout<<left+1<<' '<<n<<'\n';
	}else
	for(int right=1;; right++){
		degree+=inRange(a[right-1]) ? 1: -1;
		if(degree==1){
			std::cout<<left+1<<' '<<right<<'\n';
			degree=0;
			left=right;
			++numSegmentPrinted;
			if(numSegmentPrinted==k-1){
				std::cout<<left+1<<' '<<n<<'\n';
				break;
			}
		}
	}

	//assert(std::cout<<'\n');



	
}
// time-limit: 2000
// problem-url: https://codeforces.com/contest/1630/problem/B