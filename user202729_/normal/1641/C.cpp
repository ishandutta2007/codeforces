// :(

// time-limit: 1500
// problem-url: https://codeforces.com/contest/1641/problem/C


//#define NAIVE 0

#if not LOCAL
#define NAIVE 0
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
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	[[maybe_unused]] int const numPeople=read<int>();
	int const numQuery=read<int>();

#if NAIVE
	std::vector<int> zero(numPeople);
	std::vector<std::pair<int, int>> possible;
#endif

	using P=PairCompareFirst<int, int>;
	struct Tmp{
		int x;
	};
	struct Comparator{
		using is_transparent=void;
		bool operator()(P a, P b) const{return a<b;}
		bool operator()(P a, Tmp b) const{return a.second<b.x;}
		bool operator()(Tmp a, P b) const{return a.x<b.second;}
	};
	std::set<P, Comparator> zeroSegment, // strictly non-overlapping
		possibleSegment; // no segment contain other (the larger one is redundant)

	auto const check=[&]{
		{
		auto const tmp=[&]{
			// ======== debug only
			int last=INT_MIN;
			for(auto [a, b]: zeroSegment){
				assert(a>last);
				last=a;
			}

			last=INT_MIN;
			for(auto [a, b]: possibleSegment){
				assert(b>last);
				last=b;

				for(auto [c, d]: zeroSegment){
					assert(not(c<=a and a<d and d<=b)); // otherwise this segment could be pruned
					assert(not(a<=c and c<b and b<=d));
				}
			}
			// ========
			return true;
		}; assert(tmp());}
	};

	auto const addPossibleSegment=[&](int left, int right)->void{
		assert(left<right);
		auto iter=possibleSegment.lower_bound(left);
		if(iter!=possibleSegment.end() and iter->second<=right){
			// segment in iter is strictly smaller than the current segment, this segment is redundant
			return;
		}

		// prune this segment
		iter=zeroSegment.lower_bound(right);
		if(iter!=zeroSegment.begin()){
			--iter;
			if(iter->second>=right){
				right=std::min(right, iter->first);
			}
		}
		iter=zeroSegment.upper_bound(left);
		if(iter!=zeroSegment.begin()){
			--iter;
			assert(iter->first<=left);
			left=std::max(left, iter->second);
		}

		// delete segments larger than this
		iter=possibleSegment.upper_bound(left);
		while(iter!=possibleSegment.begin()){
			--iter;
			assert(iter->first<=left);
			if(right<=iter->second){
				iter=possibleSegment.erase(iter);
			} else break;
		}

		possibleSegment.insert(iter, {left, right});
		
	};
	
	for(int _=numQuery; _--;){
		char type; std::cin>>type;
		if(type=='0'){
			int left=read<int>()-1;
			int right=read<int>();
			std::cin>>type;
			if(type=='0'){
#if NAIVE
				for(int const x: range(left, right)){
					zero[x]=true;
				}
#endif
				
				// add to zeroSegment
				auto iter=zeroSegment.lower_bound(left);
				while(iter!=zeroSegment.end() and iter->first<=right){
					right=std::max(right, iter->second);
					left=std::min(left, iter->first);
					iter=zeroSegment.erase(iter);
				}
				while(iter!=zeroSegment.begin() and left<=(--iter)->second){
					right=std::max(right, iter->second);
					left=std::min(left, iter->first);
					iter=zeroSegment.erase(iter);
				}
				zeroSegment.insert(iter, {left, right});

				/*
				// prune possibleSegment
				// first handle those with ->left>=left
				iter=possibleSegment.lower_bound(left);
				while(iter!=possibleSegment.end() and iter->first<right){
					// can prune
					auto const iterRight=iter->second;
					assert(iter->first>=left);
					assert(iter->second>right); // the given data is consistent, so this possibleSegment cannot be strictly inside this zeroSegment
					iter=possibleSegment.erase(iter);
					if(iter!=possibleSegment.end() and iter->first<=right){
						// after pruning the old segment will be strictly smaller than this one anyway, no need to add it back
					}else{
						// otherwise add it back
						possibleSegment.insert(iter, {right, iterRight});
						break;
					}
				}


				// then the other side
				while(iter!=possibleSegment.begin() and (--iter)->second>left){
				*/

				iter=possibleSegment.lower_bound(left);
				if(iter!=possibleSegment.end() and iter->first<right){
					addPossibleSegment(right, iter->second);
				}

				iter=possibleSegment.upper_bound(Tmp{right});
				if(iter!=possibleSegment.begin() and (--iter)->second>left){
					addPossibleSegment(iter->first, left);
				}
			}else{

#if NAIVE
				possible.push_back({left, right});
#endif

				assert(type=='1');
				addPossibleSegment(left, right);
			}
		}else{
			assert(type=='1');
			int const pos=read<int>()-1;

#if NAIVE
			if(zero[pos]){
				std::cout<<"NO\n";
			}else{
				for(auto& [a, b]: possible){
					while(zero[a]) ++a;
					while(zero[b-1]) --b;
					if(a==pos and b==pos+1){
						std::cout<<"YES\n";
						goto done;
					}
				}
				std::cout<<"N/A\n";
done:;
			}

#else

			auto iter=zeroSegment.upper_bound(pos);
			if(iter!=zeroSegment.begin() and (--iter)->second>pos){
				std::cout<<"NO\n";
			}else{
				iter=possibleSegment.lower_bound(pos);
				if(iter!=possibleSegment.end() and iter->second==pos+1){
					std::cout<<"YES\n";
				}else{
					std::cout<<"N/A\n";
				}
			}
#endif
		}
		check();
	}
}