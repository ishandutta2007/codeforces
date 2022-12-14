// time-limit: 3000
// problem-url: https://codeforces.com/contest/1641/problem/D

// doesn't seem right...

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
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	int const m=read<int>();

	std::map<int, int> compression;
	std::vector<std::vector<int>> indices; // [compressed value] -> list of indices (after data is sorted by weight) that it appear in

	struct Row{
		std::vector<int> a; // at most 5 values
		int weight;
	};
	std::vector<Row> data(number, 
			Row{
				std::vector<int>(m),
				0
			}
			);

	for(int const index: range(0, number)){
		for(int const j: range(0, m)){
			int const value=read<int>();
			auto const [iterator, inserted]=compression.insert({value, int(indices.size())});
			if(inserted){
				indices.push_back({});
			}

			data[index].a[j]=iterator->second;
		}
		data[index].weight=read<int>();
	}

	std::sort(begin(data), end(data), [&](auto const& first, auto const& sec){
		return first.weight<sec.weight;
	});
	for(int const index: range(0, number)){
		for(auto z: data[index].a){
			indices[z].push_back(index);
		}
	}



	compression.clear(); // no need for the compression map anymore
	int minResult=INT_MAX;

	assert(int(data.size())==number);
	std::vector<uint64_t> have(indices.size()); // [compressed value] -> bitmask of something
	for(int index=0; index<number; index+=64){

		for(int const j: range(index, std::min(index+64, number))){
			for(auto k: data[j].a){
				have[k]|=uint64_t(1)<<(j-index);
			}
		}

		for(int const j: range(index+1, number)){
			uint64_t mask {};
			for(auto k: data[j].a) mask|=have[k];
			if(j-index<64){
				// ensure the off bits in mask is strictly less than position j-index
				mask|=uint64_t(-1)<<(j-index);
			}
			if(mask!=uint64_t(-1)){
				// there's some off bit
				int k=index+__builtin_ctzll(~mask);
				// so (j, k) is independent
				minResult=std::min(minResult, data[j].weight+data[k].weight);
			}

			if(data[j].weight+data[index].weight>=minResult){
				// no point searching anymore
				break;
			}
		}

		// restore have[] array
		for(int const j: range(index, std::min(index+64, number))){
			for(auto k: data[j].a){
				have[k]=0;
			}
		}
	}
		

	std::cout<<(minResult==INT_MAX ? -1: minResult)<<'\n';
}