// time-limit: 2000
// problem-url: https://codeforces.com/contest/1684/problem/F

// well there are always ICPC problemset to practice
// more time consuming though

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
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const number=read<int>();
	int  numSegment=read<int>();
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	std::vector<std::pair<int, int>> segments(numSegment);
	for(auto& [left, right]: segments){
		std::cin>>left>>right;
		--left;
	}
	
	std::sort(begin(segments), end(segments), [&](auto const& first, auto const& sec){
		return 
			std::make_pair(first.first, -first.second)
			<
			std::make_pair(sec.first, -sec.second)
			;
	});
	{
		auto out=segments.begin();
		for(auto& [left, right]: segments){
			if(out==segments.begin() or right>out[-1].second){
				*out++={left, right};
			}
		}
		segments.erase(out, end(segments));
		numSegment=-1;
	}

	auto const maxLeftF=[&](std::vector<int> a, std::vector<std::pair<int, int>> segments){

		auto const anySegmentContainBoth=[&](int index1, int index2)->bool{
			assert(index1<index2);
			auto const leftmostSegmentContainIndex2=std::upper_bound(begin(segments), end(segments), index2, [&](auto const& first, auto const& sec){
				return first<sec.second;
			});
			// actually it might not contain if index2<its first, but that case is covered anyway
			return leftmostSegmentContainIndex2!=segments.end() and leftmostSegmentContainIndex2->first<=index1;
		};

		for(int const index: range(1, int(segments.size()))){
			assert(segments[index-1].first<segments[index].first);
			assert(segments[index-1].second<segments[index].second);
		}

		std::map<int, int> lastIndex;
		for(int const index: range(0, int(a.size()))){
			auto const [iterator, inserted]=lastIndex.insert({a[index], index});
			if(not inserted){
				if(anySegmentContainBoth(iterator->second, index)){
					return index;
				}
				iterator->second=index;
			}
		}

		return INT_MAX;
	};

	auto const maxLeft=maxLeftF(a, segments);
	if(maxLeft==INT_MAX){
		std::cout<<"0\n";
		return;
	}

	auto const minRight=[&]{
		auto reversedA=a;
		std::reverse(begin(reversedA), end(reversedA));
		std::vector<std::pair<int, int>> reversedSegments(segments.size());
		for(int const index: range(0, int(segments.size()))){
			reversedSegments.rbegin()[index]={
				number-segments[index].second,
				number-segments[index].first,
			};
		}
		return number-maxLeftF(reversedA, reversedSegments);
	}();

	std::map<int, std::vector<int>> occurrences;
	for(int const index: range(0, int(a.size()))){
		occurrences[a[index]].push_back(index);
	}


	int right=minRight;
	int result=INT_MAX;
	for(int left=0;; left++){

		// consider (left, right)
		assert(right>left);
		result=std::min(result, right-left);

		if(left==maxLeft) break;
		// consider a[left] no longer included
		auto const leftmostSegmentNotContainLeft=std::upper_bound(begin(segments), end(segments), left, [&](auto const& first, auto const& sec){
			return first<sec.first;
		});
		if(leftmostSegmentNotContainLeft!=segments.begin()){
			auto const rightmostSegmentContainLeft=std::prev(leftmostSegmentNotContainLeft);
			assert(rightmostSegmentContainLeft->first<=left);
			if(rightmostSegmentContainLeft->second>left){
				// it indeed does contain
				auto rightmostSameValueInSegment=*--std::lower_bound(begin(occurrences.at(a[left])), end(occurrences.at(a[left])),
						rightmostSegmentContainLeft->second);
				assert(rightmostSameValueInSegment>=left);
				assert(a[rightmostSameValueInSegment]==a[left]);
				right=std::max(right, rightmostSameValueInSegment+1);
			}
		}
	}

	// hopefully correct
	// complicated code...

	std::cout<<result<<'\n';
}