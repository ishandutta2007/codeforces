// Not good...?
// still memory limit exceeded is a weird verdict (read from closed stdin?)

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


// { ==== Begin library Dsu ====



// { ==== Begin library ZeroSized.h ====


// some compiler extension to make code simple
struct Empty{ int _[0];
	bool operator==(Empty) const{return true;}
	bool operator!=(Empty) const{return false;}
};

std::ostream& operator<<(std::ostream& stream, Empty ){
	return stream<<"{}";
}

// } ==== End library ZeroSized.h ====


// the class, with CRTP for beforeChange()

template<class Data, class F, bool path_compression, bool union_by_rank, class ActualClass> struct Dsu__{

	void beforeChange(int /*node*/){}  // CRTP-virtual function, called before data[node] is changed



	struct Node{
		Data data;
		int par; //  0: have par, -1: is root, < -1: is root and have large rank and UNION_BY_RANK
	};
	std::vector<Node> data;
	F merge_function;

	Dsu__(F merge_function): data(), merge_function(merge_function) {
		static_assert(path_compression or union_by_rank);
	}

	Data dataRoot(int node){
		assert(isRoot(node));
		return data[node].data;
	}
	
	Data dataComponent(int node){
		return data[root(node)].data;
	}

	void assign(int n, auto starting_data /* (index)  Data */){
		data.clear(); data.reserve(n);
		for(int i=0; i<n; ++i){
			if(data.size()>=data.capacity()) __builtin_unreachable();
			data.push_back({starting_data(i), -1});
		}
	}

	void assign(int n){
		assign(n, [&](int /*index*/){ return Data {}; });
	}

	bool isRoot(int node) const{return data[node].par<0;}

	int root(int node)
//#if not PATH_COMPRESSION
//		const
//#endif
	{
		if(isRoot(node)
				) return node;
		if constexpr(path_compression){
			((ActualClass*) this)->beforeChange(node);
			return 
				data[node].par= root(data[node].par);
		}else{
			return 
				root(data[node].par);
		}
	}

	auto join(int a, int b){
		struct Result{
			bool already_joined;
			int newRoot;
			Data* data;
            
            bool just_joined() const{return not already_joined;}
		};

		a=root(a); b=root(b);

		if(a==b) return Result{true, b, &data[b].data};

		if(union_by_rank){
			if(data[a].par<data[b].par) std::swap(a, b);
			else if(data[a].par==data[b].par) --data[b].par;
		}

		beforeChange(a);
		data[a].par=b;
		if(not std::is_same<Empty, Data>::value){
			((ActualClass*) this)->beforeChange(b);
			data[b].data=merge_function(
					std::move(data[b].data),
					std::move(data[a].data),
					b,
					a);
		}

		return Result{false, b, &data[b].data};
	}
};

template<class Data, class F, bool path_compression, bool union_by_rank> struct Dsu_:
	Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>> {
	using Base=Dsu__<Data, F, path_compression, union_by_rank, Dsu_<Data, F, path_compression, union_by_rank>>;
	using Base::Base;
};

// public interface ========

// merge_function: used to merge data. On merge, called with
// (Data data_b, Data data_a, int b, int a)  Data
// where b is the new root

// join(a, b): if path_compression is false, b is the new root

// create a Dsu. Call with specified signature and template parameters.
template<
		class Data, // must be provided
		bool path_compression=true, bool union_by_rank=true, // optional

		class _F // auto deduced
		>
	Dsu_<Data, _F, path_compression, union_by_rank>
	Dsu(_F merge_function){ return {merge_function}; }

// create a "normal" Dsu.
template<bool path_compression=true, bool union_by_rank=true>
auto Dsu(){
	return Dsu<Empty, path_compression, union_by_rank>(
			[](Empty, Empty, int, int){return Empty {};}
			);
}

// } ==== End library Dsu ====


void up();
int main(){
	std::ios::sync_with_stdio(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const number=read<int>();
	std::vector<int> degree(number);
	for(auto& it: degree) {
		std::cin>>it;
	}
	
	auto const ask=[&](int node){
		assert(0<=node);
		assert(node<number);
		std::cout<<"? "<<node+1<<'\n';
		int const result=read<int>();
		assert(result>0);
		return result-1;
	};

	auto d=Dsu<int>([&](int data_b, int data_a, int, int){ // size merger
		return data_b+data_a;
	});
	d.assign(number, 
			[&](int){return 1;} // initial size for isolated component
			);

	std::vector<int> nodes(number);
	for(int const i: range(0, number)){
		nodes[i]=i;
	}

		
	std::sort(begin(nodes), end(nodes), [&](auto const& first, auto const& sec){
		return degree[first]>degree[sec];
	});
	for(auto node: nodes) {
		if(degree[node]>0 and d.isRoot(node) and d.dataRoot(node)==1){
			for(int _=degree[node]-1; _--;){
				auto t=ask(node);
				if(d.isRoot(t) and d.dataRoot(t)==1){
					auto tmp=d.join(t, node);
					assert(tmp.just_joined());
				}else{
					auto tmp=d.join(t, node);
					assert(tmp.just_joined());
					break;
				}
			}
		}
		assert(
				d.data[d.root(node)].data // size of this component
				>=
				degree[node]
			  );
	}



	std::cout<<'!';
	for(int const index: range(0, number)){
		std::cout<<' '<<
			d.root(index)+1
			;
	}
	std::cout<<'\n';
}

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1738/problem/F