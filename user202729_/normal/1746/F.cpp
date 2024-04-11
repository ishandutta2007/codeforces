// time-limit: 3000
// problem-url: https://codeforces.com/contest/1746/problem/F

// I definitely have had too much of sublinear algorithm lately somehow

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


// { ==== Begin library splitmix64 ====
uint64_t splitmix64(uint64_t x) {
	// http://xorshift.di.unimi.it/splitmix64.c
	x += 0x9e3779b97f4a7c15;
	x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
	x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
	return x ^ (x >> 31);
}

// } ==== End library splitmix64 ====

//  hopefully this is random enough?

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


// { ==== Begin library BITSum.h ====

template<class T>
struct Tree{
	std::vector<T> data;
	Tree(int number=0): data(number){}
	void reset(int number){data.clear(); data.resize(number);}
	void assign(int number){reset(number);}

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


auto const random_offset=std::uniform_int_distribution<int64_t>(0, INT64_MAX/2)(engine);

struct H{
	std::array<int, 40> data;
	int& operator[](int index){return data[index];}
	void operator+=(H other) {
		for(int const i: range(0, int(data.size()))){
			data[i]+=other[i];
		}
	}
	void operator-=(H other) {
		for(int const i: range(0, int(data.size()))){
			data[i]-=other[i];
		}
	}
	friend H operator-(H h) {
		for(auto& x: h.data) x=-x;
		return h;
	}
	friend H operator+(H first, H sec) { first+=sec; return first; }
	friend H operator-(H first, H sec) { first-=sec; return first; }
};

H makeHash(int a){
	auto r=splitmix64(a+random_offset);
	H result;
	for(auto& x: result.data){
		x=int(r&1);
		r>>=1;
	}
	return result;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const len=read<int>();
	int const numQuery=read<int>();
	std::vector<int> a(len);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	Tree<H> tree(len);
	for(int const i: range(0, len)){
		tree.add(i, makeHash(a[i]));
	}

	for(int _=numQuery; _--;){
		char type; std::cin>>type;
		if(type=='1'){
			int const index=read<int>()-1;
			int const value=read<int>();
			tree.add(index, makeHash(value)-makeHash(a[index]));
			a[index]=value;
		}else{
			assert(type=='2');
			int const left=read<int>()-1;
			int const right=read<int>();
			int const k=read<int>();
			H h=tree.sum(left, right);
			std::cout<<(
					std::all_of(begin(h.data), end(h.data), [&](auto const& it){
						return it%k==0;
					})
					? "YES\n": "NO\n"
					);
		}
	}
}