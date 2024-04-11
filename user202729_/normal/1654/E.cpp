// hopefully fast enough

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
#if LOCAL
int const maxDelta=1;
//#warning "test" // already tested
#else
int const maxDelta=314;
#endif
// inclusive

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();

	// single test
	if(number<=2){
		std::cout<<"0\n";
		return 0;
	}


	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	auto const limit=*std::max_element(begin(a), end(a));

	int maxCount=2; // number of numbers on an arithmetic progression
	{
		std::vector<int> count(limit+1+(number-1)*maxDelta);
		for(int const delta: range(0, maxDelta+1)){

			auto const work=[&](auto f){
				for(int const index: range(0, number)){
					maxCount=std::max(maxCount, ++count[f(index)]);
				}
				for(int const index: range(0, number)){
					count[f(index)]=0;
				}
			};

			// positive slope
			work([&](auto const& it){ return a[it]+delta*it; });
			
			// negative slope
			work([&](auto const& it){ return a[it]+delta*(number-1-it); });
		}
	}

	// consider larger delta values
	struct T{int delta, right;
		auto tie() const{return std::tie(delta);}
		#define D(op) bool operator op(T const& other) const{return tie() op other.tie();}
		D(==) D(!=)
			D(<) D(>) D(<=) D(>=)
		#undef D
	};

	std::vector<std::vector<T>> jumps(number);
	for(int const left: range(0, number)){
		// compute jumps[left]
		for(int const right: range(left+1, number)){
			if(1+(right-left)*(maxDelta+1)>limit) break;
			auto const diff=a[right]-a[left];
			if(diff%(right-left)==0){
				auto const delta=diff/(right-left);
				jumps[left].push_back({delta, right});
			}
		}

		// sort by delta for fast lookup
		std::sort(begin(jumps[left]), end(jumps[left]), [&](auto const& first, auto const& sec){
			return std::tie(first.delta, first.right)<std::tie(sec.delta, sec.right);
		});

		// only keep the one with smallest right value
		jumps[left].erase(std::unique(begin(jumps[left]), end(jumps[left])), jumps[left].end());
	}

	for(int const left: range(0, number)){
		for(auto [delta, right]: jumps[left]) if(right>=0){
			int count=2, pos=right;
			while(true){
				auto iter=std::lower_bound(begin(jumps[pos]), end(jumps[pos]), T{delta, 0});
				if(iter!=jumps[pos].end() and iter->delta==delta) {
					count++;
					assert(iter->right>=0);
					std::tie(pos, iter->right)=std::make_pair(iter->right, -1);
				}else{
					// cannot jump anymore
					break;
				}
			}
			maxCount=std::max(maxCount, count);
			
		}
	}

	std::cout<<number-maxCount<<'\n';




		
	
}


// time-limit: 5000
// problem-url: https://codeforces.com/contest/1654/problem/E