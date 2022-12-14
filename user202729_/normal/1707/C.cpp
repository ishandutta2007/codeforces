// time-limit: 1000
// problem-url: https://codeforces.com/contest/1707/problem/C

// nonmonotonic contest

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

// { ==== Begin library GraphDfs.h ====


// overengineered template/library...

/*

// In tree mode, obviously will visit the whole tree.
// In graph node, will **always visit the whole graph**.
example

int const root=0;
auto tmp=Dfs<decltype(g)::EdgeWeight,
	 true, // par
	 true, // depth
	 false, // subtreeSize
	 false, // visited (**required** if is graph)
	 false, // orderOf
	 false, // low
	 false, // postorder
	 false // lastOrderOf
>{g, root};
auto const par=std::move(tmp.par);
auto const depth=std::move(tmp.depth);
auto const jump=makeJumpTable(par, <combiner>);

int w=lca(jump, depth, u, v);

Edge e=moveUp(jump, u, depth[u]-depth[w], combine, E{-1, INT_MAX}),

*/

template<class EdgeWeight,
	bool par_,
	bool depth_,
	bool subtreeSize_,
	bool visited_=false,
	bool orderOf_=false,
	bool low_=false,
	bool postorder_=false,
	bool lastOrderOf_=false,
	class Custom=Empty  // in case this is insufficient
	>
struct Dfs{
	Graph<EdgeWeight> const& graph;
	using Edge=typename Graph<EdgeWeight>::Edge;

	static bool constexpr custom_=not std::is_same<Custom, Empty>::value;

	std::conditional_t<par_        , std::vector<Edge>, Empty> par        ;
	std::conditional_t<depth_      , std::vector<int> , Empty> depth      ;
	std::conditional_t<subtreeSize_, std::vector<int> , Empty> subtreeSize;
	std::conditional_t<visited_    , std::vector<char>, Empty> visited    ;
	std::conditional_t<orderOf_    , std::vector<int> , Empty> orderOf    ;
	std::conditional_t<lastOrderOf_, std::vector<int> , Empty> lastOrderOf;
	std::conditional_t<orderOf_    , int              , Empty> lastOrder  ;
	std::conditional_t<low_        , std::vector<int> , Empty> low        ;
	std::conditional_t<postorder_  , std::vector<int> , Empty> postorder  ;  // list of nodes

	typename std::conditional<custom_, std::vector<Custom>, Empty>::type custom;

	Dfs(Graph<EdgeWeight> const& graph, int root=-1): graph(graph){
		if constexpr(par_) {
			static_assert(not visited_);
			par.assign(graph.size(), {-1, {}});
			par[root]={-1, {}};
		}
		if constexpr(depth_) {
			depth.assign(graph.size(), 0);
			//depth[root]=0;
		}
		if constexpr(subtreeSize_) subtreeSize.assign(graph.size(), 1);
		if constexpr(visited_) visited.assign(graph.size(), false);
		if constexpr(orderOf_){ orderOf.resize(graph.size(), -1); lastOrder=0; }
		if constexpr(lastOrderOf_){ lastOrderOf.resize(graph.size(), -1); lastOrder=0; }
		if constexpr(postorder_) postorder.reserve(graph.size());
		static_assert(not (visited_ and orderOf_), "orderOf can be used to deduce visited");
		if constexpr(low_){
			static_assert(orderOf_, "cannot compute low without orderOf");
			low.resize(graph.size());
		}

		if constexpr(custom_){
			// TODO
			custom.assign(graph.size(), {});
		}

		if constexpr(visited_){
			assert(root==-1);
			for(int node=0; node<(int)graph.size(); ++node){
				if(not visited[node]) runInternal(node);
			}
		}else{
			runInternal(root);
		}
	}


	void runInternal(int node){ // should not be invoked directly
		// caller is responsible for filling *[node]
		if constexpr(subtreeSize_) subtreeSize[node]=1;
		if constexpr(visited_){
			assert(not visited[node]);
			visited[node]=true;
		}
		if constexpr(orderOf_){
			assert(orderOf[node]==-1);
			orderOf[node]=lastOrder++;
		}
		if constexpr(low_){
			low[node]=lastOrder;
		}
		for(auto [child, weight]: graph.add[node]) {
			if constexpr(visited_){
				if(visited[child]) {
					continue;
				}
			}else if constexpr(par_)
				if(child==par[node].node) continue;

			if constexpr(par_) par[child]={node, weight};
			if constexpr(depth_) depth[child]=depth[node]+1;
			if constexpr(custom_) {
				// TODO
			}

			runInternal(child);
			
			if constexpr(subtreeSize_) subtreeSize[node]+=subtreeSize[child];
		}
		if constexpr(lastOrderOf_) lastOrderOf[node]=lastOrder;
		if constexpr(postorder_) postorder.push_back(node);
	}


};


// } ==== End library GraphDfs.h ====
// useless template >< not tested enough
//(which reminds me that I still haven't made the upper/lower hull template and others)

// { ==== Begin library Dsu.h ====


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
					data[b].data,
					data[a].data,
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

// } ==== End library Dsu.h ====
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numNode=read<int>();
	int const numEdge=read<int>();

	auto dsu=Dsu();
	dsu.assign(numNode);
	
	Graph<> spanTree(numNode);

	std::vector<std::pair<int, int>> nonspanEdges; nonspanEdges.reserve(numEdge-(numNode-1));
	for(int _=numEdge; _--;){
		int const first=read<int>()-1;
		int const sec=read<int>()-1;
		
		if(dsu.join(first, sec).just_joined()){
			spanTree.addEdgeUndirected(first, sec);
		}else{
			nonspanEdges.push_back({first, sec});
		}
	}

	int const root=
#if LOCAL
		//std::min(8, numNode-1)
		0
#else
		0
#endif
		;
	auto tmp=Dfs<decltype(spanTree)::EdgeWeight,
		 true, // par
		 false, // depth
		 false, // subtreeSize
		 false, // visited (**required** if is graph)
		 true, // orderOf
		 false, // low
		 false, // postorder
		 true, // lastOrderOf
		 Empty
	>{spanTree, root};

	auto const orderOf=std::move(tmp.orderOf);
	auto const lastOrderOf=std::move(tmp.lastOrderOf);
	auto const par=std::move(tmp.par);

	for(int const node: range(0, numNode)) if(node!=root) {
		assert(orderOf[node]<lastOrderOf[node]);
		spanTree[node].erase(std::find_if(begin(spanTree[node]), end(spanTree[node]), [&](auto const& it){
			return it.node==par[node].node;
		}));
	}

	for(int const node: range(0, numNode)){
		std::sort(begin(spanTree[node]), end(spanTree[node]), [&](auto const& first, auto const& sec){
			return orderOf[first.node]<orderOf[sec.node];
		});

		if(not spanTree[node].empty())
		for(int const index: range(1, int(spanTree[node].size()))){
			assert(
					lastOrderOf[spanTree[node][index-1].node]
					==
					orderOf[spanTree[node][index].node]
					);
		}
	}

	std::vector<int> weight(numNode+1);
	for(auto [first, sec]: nonspanEdges){
		assert(first!=sec);
		assert(orderOf[first]!=orderOf[sec]);
		if(orderOf[first]>orderOf[sec]) std::swap(first, sec);
		if(lastOrderOf[first]>=lastOrderOf[sec]){
			// first is ancestor of sec

			auto const& children=spanTree[first];
			int index=0;
			for(int step=1<<(31^__builtin_clz(int(children.size())+1)); step; step>>=1){
				if(index+step<int(children.size()) and orderOf[children[index+step].node]<=orderOf[sec]) index+=step;
			}

			auto const w=children[index].node;
			assert(orderOf[w]<=orderOf[sec]);
			assert(lastOrderOf[w]>orderOf[sec]);

			weight[orderOf[sec]]++;
			weight[lastOrderOf[sec]]--;

			weight[orderOf[w]]--;
			weight[lastOrderOf[w]]++;
			weight[0]++;
		}else{
			assert(lastOrderOf[first]<=orderOf[sec]);
			weight[orderOf[first]]++;
			weight[lastOrderOf[first]]--;

			weight[orderOf[sec]]++;
			weight[lastOrderOf[sec]]--;
		}

	}

	weight.pop_back();
	std::partial_sum(begin(weight), end(weight), begin(weight));

	for(int const node: range(0, numNode)){
		std::cout<<char('0'+(weight[orderOf[node]]==int(nonspanEdges.size())));
	}
	std::cout<<'\n';
	
}

// too slow............