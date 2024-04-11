// somehow I still can't figure out B...

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

// { ==== Begin library Graph.h ====

#include<variant>
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
template<class EdgeWeight_=Empty>
struct Graph{
	using EdgeWeight=EdgeWeight_;

	static constexpr bool weightedEdge=not std::is_same<EdgeWeight, Empty>::value;

	struct Edge{
		int node; EdgeWeight weight;
	};
	std::vector<std::vector<Edge>> add;

	Graph(std::vector<std::vector<Edge>> add): add(std::move(add)){}
	Graph(int numNode): add(numNode){}
	Graph(){
		#if hasdebugprint
		assert(gdbgetstr(*this));
		#endif
	}
	#if hasdebugprint
	DEFINEGETSTR(Graph)
	#endif

	// wrapper over add
	auto& operator[](int index){ return add[index]; }
	auto const& operator[](int index) const{ return add[index]; }
	auto size() const{return add.size();}


	template<bool directed> void addEdge(int first, int sec, EdgeWeight weight={}){
		if constexpr(not directed)
			add[sec].push_back({first, weight});
		add[first].push_back({sec, std::move(weight)});
	}

	void addEdgeDirected(int first, int sec, EdgeWeight weight){ addEdge<true>(first, sec, std::move(weight)); }
	void addEdgeUndirected(int first, int sec, EdgeWeight weight){ addEdge<false>(first, sec, std::move(weight)); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void addEdgeDirected(int first, int sec){ addEdgeDirected(first, sec, {}); }

	template<bool okay=not weightedEdge, class=typename std::enable_if<okay, int>::type>
	void addEdgeUndirected(int first, int sec){ addEdgeUndirected(first, sec, {}); }

	template<bool directed> void read(int numNode, int numEdge){
		assert(add.empty()); add.resize(numNode);
		for(int _=0;_<numEdge;++_){
			int first, sec; std::cin>>first>>sec;
			--first;--sec;
			EdgeWeight weight{};
			if constexpr(weightedEdge){
				std::cin>>weight;
			}
			addEdge<directed>(first, sec, weight);
		}
	}

	void readUndirected(int numNode, int numEdge){ return read<false>(numNode, numEdge); }
	void readDirected(int numNode, int numEdge){ return read<true>(numNode, numEdge); }

	void readUndirected(){
		int numNode, numEdge; std::cin>>numNode>>numEdge;
		read<false>(numNode, numEdge);
	}

	// ======== miscellaneous helper functions
	void mapEdge(auto f /* (a, b, weight)  void */) const{
		for(int node=0; node<(int)add.size(); ++node)
			for(auto const& [target, weight]: add[node]){
				f(node, target, weight);
			}
	}

	template<bool reverse=false>
	auto transformEdge(auto f /* weight  weight' */) const{
		using ResultEdgeValue=std::decay_t<decltype(f(std::declval<EdgeWeight>()))>;
		Graph<ResultEdgeValue> result((int)add.size());
		mapEdge([&](int a, int b, auto const& weight){
			if(reverse) std::swap(a, b);
			result.addEdgeDirected(a, b, f(weight));
		});
		return result;
	}

	auto reverseEdge(auto f) const{
		return transformEdge<true>(f);
	}

	auto reverseEdge() const{
		return reverseEdge([&](auto const& it){
			return it;
		});
	}

	friend decltype(auto) operator<<(std::ostream& stream, Graph const& data){
		bool first=true;
		stream<<"Graph{";
		for(int node=0; node<(int)data.size(); ++node){
			for(auto [other, weight]: data.add[node]) {
				if(first) first=false; else stream<<", ";
				if constexpr(decltype(data)::weightedEdge){
					stream<<node<<" --("<<weight<<")-> "<<other;
				}else{
					stream<<node<<" -> "<<other;
				}
			}
		}
		return stream<<"}";
	}
};

// } ==== End library Graph.h ====

// { ==== Begin library YComb ====

template<class T> struct YComb_{
	//T const& f;
	T f; // will figure out later...
	YComb_(T const& f): f(f) {}
	template<class... Args> auto operator()(Args... args)const{
		return f(*this, std::forward<Args>(args)...);
	}
};

// C++14 compatibility
template<class T> YComb_<T> YComb(T f){ return {std::move(f)}; }
template<class T> YComb_<T> makeYComb(T f){ return {std::move(f)}; } // old code...

// } ==== End library YComb ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}
using Op=std::pair<int, int>;
struct Ops{
	// HACK: if children[0] is empty then list is {value}, else list is concatenate of children
	Op value;
	std::array<std::unique_ptr<Ops>, 2> children;
	// anyway
	void each(auto f){
		if(children[0]){
			children[0]->each(f);
			children[1]->each(f);
		}else{
			f(value);
		}
	}
};

void up(){
	int const numNode=read<int>();
	Graph<> graph; graph.readUndirected(numNode, numNode-1);

	struct cannotError {};
	std::vector<std::array<bool, 2>> cache(numNode);

	auto const work=makeYComb([&](auto work, int node, int par)->std::array<bool, 2>{
		// [root degree parity before remove] -> can?
		int a {}, b {}, c {};
		for(auto [child, _]: graph[node]) if(child!=par){
			auto [v0, v1]=work(child, node);
			if(v0 and not v1) a++;
			else if(v1 and not v0) b++;
			else{
				assert(v0 and v1);
				c++;
			}
		}

		assert(par>=0);
		assert(int(graph[node].size())-1==a+b+c);
		int total=int(graph[node].size());
		int numNeededOne=(total+1)>>1;
		int numNeededZero=total>>1;

		assert(numNeededOne+numNeededZero==total);

		auto const feasible=[&](int cannotOne, int cannotZero, int either)->bool{
			assert(total==cannotOne+cannotZero+either);
			int maxZero=total-cannotZero, maxOne=total-cannotOne;
			return maxZero>=numNeededZero and maxOne>=numNeededOne; // should be correct, right...?
		};

		bool v0=feasible(a+1, b, c);
		bool v1=feasible(a, b+1, c);
		if(not v0 and not v1){
			throw cannotError{};
		}
		return cache[node]={{v0, v1}};
	});


	auto const work2=makeYComb([&](auto work2, int node, int par, bool assigned)->Ops{
		assert(cache[node][assigned]);

		assert(par>=0);
		int total=int(graph[node].size());
		int numNeededOne=(total+1)>>1;
		int numNeededZero=total>>1;

		std::vector<Ops> zeros, ones;
		std::array<std::vector<Ops>*, 2> ref{{&zeros, &ones}};
		ref[assigned]->push_back(Ops{.value=Op{node, par}, .children={}});

		for(auto [child, _]: graph[node]) if(child!=par){
			if(cache[child][0] and not cache[child][1]){
				zeros.push_back(work2(child, node, 0));
			}else if(cache[child][1] and not cache[child][0]){
				ones.push_back(work2(child, node, 1));
			}else{
				assert(cache[child][0] and cache[child][1]);
			}
		}
		for(auto [child, _]: graph[node]) if(child!=par){
			if(cache[child][0] and cache[child][1]){
				if(int(zeros.size())<numNeededZero){
					zeros.push_back(work2(child, node, 0));
				}else{
					ones.push_back(work2(child, node, 1));
				}
			}
		}

		assert(int(zeros.size())==numNeededZero);
		assert(int(ones.size())==numNeededOne);
		
		while(not zeros.empty()){
			auto x=std::move(ones.back()); ones.pop_back();
			auto y=std::move(zeros.back()); zeros.pop_back();
			zeros.push_back(Ops{.value={}, .children={{
				std::make_unique<Ops>(std::move(y)),
				std::make_unique<Ops>(std::move(x)),
			}}});

			if(ones.empty()){
				assert(zeros.size()==1);
				return std::move(zeros[0]);
			}
			x=std::move(ones.back()); ones.pop_back();
			y=std::move(zeros.back()); zeros.pop_back();
			ones.push_back(Ops{.value={}, .children={{
				std::make_unique<Ops>(std::move(x)),
				std::make_unique<Ops>(std::move(y)),
			}}});
		}
		assert(ones.size()==1);
		return std::move(ones[0]);
	});

	int leaf=0;
	while(graph[leaf].size()!=1) leaf++;
	auto const other=graph[leaf][0].node;
	bool result;
	try{
		result=work(other, leaf)[1];
	}catch(cannotError){
		result=false;
	}
	std::cout<< (result ? "YES\n": "NO\n");
	if(not result) return;

	// now reconstruct the solution
	work2(other, leaf, 1).each([&](Op op){
		std::cout<<op.first+1<<' '<<op.second+1<<'\n';
	});
}

// time-limit: 2000
// problem-url: https://codeforces.com/contest/1667/problem/D