// can hope

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

// { ==== Begin library GraphDial.h ====


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
template<unsigned endDistance, class EdgeWeight, class DistanceT> struct GraphDial {
	Graph<EdgeWeight> const& g;

	std::vector<DistanceT> distance;
	std::array<std::vector<int>, endDistance> queue; // top is minimum distance

	GraphDial& add(int node, DistanceT nodeDistance={}){
		assert((unsigned)nodeDistance<endDistance);
		queue[nodeDistance].push_back(node);
		distance[node]=std::min(distance[node], nodeDistance);
		return *this;
	}

	GraphDial& run(auto edgeWeight /* (node, other, edgeLen)  weight (int) */){
		for(int nodeDistance=0, cell=0, consecutiveEmpty=0;;
				nodeDistance++,
				cell++,
				cell=cell==endDistance ? 0: cell
		   ){

			if(queue[cell].empty()){
				consecutiveEmpty++;
				if(consecutiveEmpty==endDistance) break;
				continue;
			}
			consecutiveEmpty=0;
			for(int index=0; index<(int)queue[cell].size(); ++index){  // handle the case that some edge length is 0
				auto const node=queue[cell][index];
				for(auto const& [other, edgeLen]: g.add[node]){
					assert((unsigned)edgeWeight(node, other, edgeLen)<endDistance);
					DistanceT const otherDistance=nodeDistance+edgeWeight(node, other, edgeLen);
					if(otherDistance<distance[other]){
						distance[other]=otherDistance;
						queue[otherDistance%endDistance].push_back(other);
					}
				}
			}
			queue[cell].clear();
		}
		return *this;
	}

	GraphDial& run(){
		return run([&](int , int , EdgeWeight const& edgeLen){
			if constexpr(g.weightedEdge){
				return edgeLen;
			}else{
				return 1;
			}
		});
	}

};

template<unsigned endDistance, class GraphT, class DistanceT> auto graph_dial(GraphT const& g_, DistanceT infiniteDistance){
	return GraphDial<endDistance, typename GraphT::EdgeWeight, DistanceT> {.g=g_,
		.distance=std::vector<DistanceT>(g_.add.size(), infiniteDistance),
		.queue={},
	};
}

/* example use
 
auto d=graph_dial<2>(g, INT64_MAX)
// INT64_MAX: infiniteDistance

.add(node, 0)
.add(node, 0)
// 0: initial distance, usually must be 0 (is default if not provided)


.run();

d.distance[node];
d.distance[node];


*/

// } ==== End library GraphDial.h ====
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();


	std::vector<char> isBase(number);
	for(int const index: range(0, number)){
		std::cin>>isBase[index];
		assert(isBase[index]=='0' or isBase[index]=='1');
		isBase[index]-='0';
	}

	Graph<Empty> g;
	g.readUndirected(number, number-1);
	auto tmpHeight=graph_dial<2>(g, INT_MAX);

	for(int const index: range(0, number)){
		if(isBase[index]){
			tmpHeight.add(index, 0);
		}
	}

	tmpHeight.run();
	auto const height=std::move(tmpHeight.distance);

	std::vector<int> levelHeights;
	for(int const i: range(0, number)){
		for(auto [j, _]: g[i]){
			if(height[i]==height[j]){
				levelHeights.push_back(height[i]);
			}
		}
	}

	std::sort(begin(levelHeights), end(levelHeights));
	levelHeights.erase(std::unique(begin(levelHeights), end(levelHeights)), end(levelHeights));
	
	// there are at most O(N) distinct heights of the level edges
	// for each one process in O(n)
	// (level==flat ground)
	
	std::vector<int> required; // reused

	auto minLevelReachable=height;
	for(auto const levelHeight: levelHeights){
		required.assign(number, INT_MAX); // minimum height to reach a level with height==level height
		struct State{
			int node;
			int distance; // I can't prove this is not redundant...
		};
		std::deque<State> nodes; // the bfs queue as usual
		
		for(int const i: range(0, number)){
			for(auto [j, _]: g[i]){
				if(height[i]==height[j] and height[i]==levelHeight){
					if(required[i]==INT_MAX){
						// graph is undirected, only need to consider i here
						nodes.push_back({i, required[i]=levelHeight});
					}
				}
			}
		}


		while(not nodes.empty()){
			auto [node, curRequired]=nodes.front(); nodes.pop_front();
			assert(curRequired>=height[node]);

			auto const update=[&](int other, int otherRequired){
				assert(otherRequired==curRequired or otherRequired==curRequired+1);
				assert(otherRequired>=height[other]);
				if(otherRequired<required[other]){
					if(otherRequired==curRequired)
						nodes.push_front({other, required[other]=otherRequired});
					else
						nodes.push_back({other, required[other]=otherRequired});
				}
			};

			//auto const curRequired=required[node];
			if(curRequired>required[node]) continue;
			assert(curRequired==required[node]);

			for(auto [other, _]: g[node]){
				if(height[other]>height[node]){
					update(other, std::max(height[other], curRequired));
				}else if(height[other]==height[node]){
					update(other, curRequired+1);
				}
			}
		}
		

		for(int const i: range(0, number)){
			assert(required[i]>=height[i]);
			if(required[i]==height[i]){
				minLevelReachable[i]=std::min(minLevelReachable[i], levelHeight);
			}
		}
	}

	for(int const i: range(0, number)){
		std::cout<<height[i]*2-minLevelReachable[i]<<' ';
	}
	std::cout<<'\n';

}


// time-limit: 5000
// problem-url: https://codeforces.com/contest/1654/problem/G