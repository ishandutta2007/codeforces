// time-limit: 2000
// problem-url: https://codeforces.com/contest/1696/problem/D

// ... is this overcomplicated...?
// also hopefully correct...?



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

// { ==== Begin library RMQ.h ====
template<class T, class F> struct RMQ_{
	std::vector<std::vector<T>> data;
	F minFunction;

	/*
	RMQ_(std::vector<T> a, F minFunction): data{std::move(a)}, minFunction(std::move(minFunction)){
		for(int step=1; step<(int)data.back().size(); step<<=1){
			std::vector<T> tmp(data.back().begin(), data.back().end()-step);
			for(int i=0; i<(int)tmp.size(); ++i)
				tmp[i]=minFunction(tmp[i], data.back()[i+step]);
			data.push_back(std::move(tmp));
		}
	}
	*/

	RMQ_(std::vector<T> a, F minFunction): data{}, minFunction(std::move(minFunction)){
		data.push_back({});
		for(auto item: a)
			this->push_back({item});
	}

	void push_back(T item){
		data[0].push_back(std::move(item));
		for(int const layer: range(1, int(data.size()))){
			data[layer].push_back(minFunction(data[layer-1][data[layer].size()], data[layer-1].back()));
		}
		int newLayer=int(data.size());
		if((1<<(newLayer-1))<int(data.back().size())){
			data.push_back({minFunction(data.back()[0], data.back()[1<<(newLayer-1)])});
		}
		assert(std::cerr<<"");
	}
	
	void pop_back(){
		for(auto& item: data) item.pop_back();
		if(data.size()>1 and data.back().empty()) data.pop_back();
	}

	T operator()(int left, int right) const{
		assert(left<right);
		auto const layer=31^__builtin_clz(right-left);
		assert(left+(1<<layer)>=right-(1<<layer)); assert(right-(1<<layer)>=left);
		auto result=minFunction(
				data[layer][left], data[layer][right-(1<<layer)]);
		{
		auto const tmp=[&]{
			auto tmp=data[0][left];
			for(int const i: range(left, right)){
				tmp=minFunction(tmp, data[0][i]);
			}
			assert(tmp==result);
			return true;
		}; assert(tmp());}
		return result;
	}

};

// C++14
template<class T, class F> 
RMQ_<T, F> RMQ(std::vector<T> a, F minFunction){ return {std::move(a), std::move(minFunction)}; }

// simple case
template<class T>
auto RMQ(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::min(first, sec);
}); }

template<class T>
auto RMQ_max(std::vector<T> a){ return RMQ(std::move(a), [&](T const& first, T const& sec)->T const&{
	return std::max(first, sec);
}); }

// } ==== End library RMQ.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const number=read<int>();
	std::vector<int> a(number);
	for(auto& it: a) {
		std::cin>>it;
	}
	
	std::vector<int> distance(number); // index  distance to node 0
	distance[0]=0;
	std::vector<int> upper{0}, lower{0}; // list of indices, sorted in increasing index
	auto rupper=RMQ(std::vector<int>{0});  // contain distance values
	auto rlower=RMQ(std::vector<int>{0});
	for(int const index: range(1, number)){
		auto const value=a[index];


		if(a[index-1]<value){

			while(not upper.empty() and a[upper.back()]<value){
				upper.pop_back();
				rupper.pop_back();
			}

			// only elements in lower can match this item
			// find closest in upper with value > value
			int upperindex=-1;
			for(int step=1<<(31^__builtin_clz(int(upper.size())+1)); step; step>>=1){
				if(upperindex+step<int(upper.size()) and a[upper[upperindex+step]]>value) upperindex+=step;
			}

			// find first index in lower > this
			int aindex=upperindex<0 ? -1: upper[upperindex];
			auto lowerindex=int(std::upper_bound(begin(lower), end(lower), aindex)-begin(lower));

			distance[index]=rlower(lowerindex, int(lower.size()))+1;


		}else{
			
			while(not lower.empty() and a[lower.back()]>value){
				lower.pop_back();
				rlower.pop_back();
			}

			int lowerindex=-1;
			for(int step=1<<(31^__builtin_clz(int(lower.size())+1)); step; step>>=1){
				if(lowerindex+step<int(lower.size()) and a[lower[lowerindex+step]]<value) lowerindex+=step;
			}

			int aindex=lowerindex<0 ? -1: lower[lowerindex];
			auto upperindex=int(std::upper_bound(begin(upper), end(upper), aindex)-begin(upper));

			distance[index]=rupper(upperindex, int(upper.size()))+1;

		}

		upper.push_back(index);
		lower.push_back(index);
		rupper.push_back(distance[index]);
		rlower.push_back(distance[index]);
	}

	std::cout<<distance.back()<<'\n';
}