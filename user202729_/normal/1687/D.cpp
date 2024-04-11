// somehow this algorithm seems to have some "smaller than expected" time complexity
// quite worried about the second half though. But can hope??? (for FST???????)

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
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	

	int64_t offset {};
	struct CuteIter{
		int64_t left=1, rightInclusive=2;
		void advance(){
			auto const delta=rightInclusive-left;
			*this={.left=rightInclusive+delta+1, .rightInclusive=rightInclusive+delta*2+2};
		}
		bool has(int64_t value)const{
			return left<=value and value<=rightInclusive;
		}

	};
	struct Segment{
		int leftOriginal;
		mutable int rightInclusiveOriginal;
		mutable CuteIter cute;
		bool operator<(Segment other) const{
#if LOCAL
			if(leftOriginal==other.leftOriginal){
				assert(rightInclusiveOriginal==other.rightInclusiveOriginal);
				return false;
			}
			if(rightInclusiveOriginal<other.leftOriginal) return true;
			if(other.rightInclusiveOriginal<leftOriginal) return false;
			assert(false);
#else
			return leftOriginal<other.leftOriginal;
#endif
		}
	};
	std::vector<Segment> segments;
	CuteIter lastCute {};
	for(int _=number; _--;){
		int const x=read<int>();


		if(not segments.empty()){
			auto& lastSegment=*segments.rbegin();
			assert(lastSegment.leftOriginal <= x); // because a[i] is increasing
			if(lastSegment.leftOriginal==x) continue;
			if(x<=lastSegment.cute.rightInclusive){
				lastSegment.rightInclusiveOriginal=x;
				continue;
			}
		}

		while(lastCute.rightInclusive<x) lastCute.advance();
		segments.insert(segments.end(), Segment{.leftOriginal=x, .rightInclusiveOriginal=x, .cute=lastCute});
	}

	// now segments has at most 2000 elements or something like that



	// okay, this part. I'm not entirely sure...
	// it could use a priority queue somehow...
	// but.........

	while(true){
		auto const oldOffset=offset;
		std::vector<Segment> nextIteration {};
		CuteIter lastCute {};
		for(auto [leftOriginal, rightInclusiveOriginal, cute]: segments){

			if(cute.left<lastCute.left) cute=lastCute;

			while(not nextIteration.empty() and leftOriginal+offset<=nextIteration.back().cute.rightInclusive){
				// merge last segment with this segment
				auto [leftOriginal1, rightInclusiveOriginal1, cute1]=nextIteration.back(); nextIteration.pop_back();
				leftOriginal=leftOriginal1;
			}

			while(true){
				if(leftOriginal+offset<cute.left){
					offset+=cute.left-(leftOriginal+offset);
				}
				if(rightInclusiveOriginal+offset>cute.rightInclusive){
					cute.advance();
				}else{
					// okay it fits in
					break;
				}
			}

			lastCute=cute;
			nextIteration.push_back({leftOriginal, rightInclusiveOriginal, cute});
		}
		if(oldOffset==offset){
			break;
		}
		segments=std::move(nextIteration);
	}


	std::cout<<offset<<'\n';
	
}

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1687/problem/D