// time-limit: 1000
// problem-url: https://codeforces.com/contest/1696/problem/F

// more spam submitting
// ... maybe I should not have put that __builtin_trap() line in...?

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


void up(){
	int const number=read<int>();
	if(number==2){
		std::string word;
		std::cin>>word;
		if(word=="00"){
			std::cout<<"Yes\n1 2\n";
		}else{
			std::cout<<"No\n";
		}
		return;
	}

	std::vector<std::vector<std::string>> data(number);
	for(int const i: range(0, number)){
		data[i].resize(i);
	}

	for(int const i: range(0, number-1)){
		for(int const j: range(i+1, number)){
			auto& word=data[j][i];
			std::cin>>word;
		}
	}

	auto const findPath=[&](int i, int j){ // known i and j are separated by 1, reconstruct the whole tree and print out

		//Graph<> g(number); g.addEdgeUndirected(i, j);

		std::vector<std::vector<int>> distance(number, std::vector<int>(number, INT_MAX/2));

		for(int const k: range(0, number)){
			distance[k][k]=0;
		}

		distance[i][j]=distance[j][i]=1;

		std::vector<char> seen(number, false);
		seen[i]=seen[j]=true;

		auto const work=makeYComb([&](auto work, int par, int child)->void{
			for(int const next: range(0, number)){
				if(not seen[next] and data[std::max(par, next)][std::min(par, next)][child]=='1'){
					//g.addEdgeUndirected(child, next);
					seen[next]=true;
					distance[child][next]=distance[next][child]=1;
					work(child, next);
				}
			}
		});
		work(i, j);
		work(j, i);

		if(not std::all_of(begin(seen), end(seen), [&](auto const& it){
			return it;
		})){
			std::cout<<"No\n";
			return;
		}

		// since each even item is set once on the dfs from one component, the result must be a tree

		// now Floyd on distance
		for(int const k: range(0, number)){
			for(int const i: range(0, number)){
				for(int const j: range(0, number)){
					distance[i][j]=std::min(distance[i][j], distance[i][k]+distance[k][j]);
				}
			}
		}

		// double check
		for(int const i: range(0, number-1)){
			for(int const j: range(i+1, number)){
				auto& word=data[j][i];
				for(int const k: range(0, number)){
					if(
							(distance[i][k]==distance[k][j])+'0'
							!=word[k]){
						std::cout<<"No\n";
						return;
					}
				}
			}
		}

		// okay done, print out edges
		std::cout<<"Yes\n";
		for(int const i: range(0, number-1)){
			for(int const j: range(i+1, number)){
				if(distance[i][j]==1){
					std::cout<<i+1<<' '<<j+1<<'\n';
				}
			}
		}
						
		

	};

	std::vector<int> isUniqueCenter(number);
	for(int const i: range(0, number-1)){
		for(int const j: range(i+1, number)){
			auto& word=data[j][i];
			auto num1=std::count(begin(word), end(word), '1');
			if(num1==1){
				auto index=int(std::find(begin(word), end(word), '1')-word.begin());
				if(index!=i and index!=j){
					isUniqueCenter[index]++;
				}
			}
		}
	}

	auto index=int(std::find(begin(isUniqueCenter), end(isUniqueCenter), 1)-isUniqueCenter.begin());
	if(index!=int(isUniqueCenter.size())){
		// then node at index has degree 2, and one of them is a leaf
		
		// find the 2 (i, j) nodes
		for(int const i: range(0, number-1)){
			for(int const j: range(i+1, number)){
				auto& word=data[j][i];
				auto num1=std::count(begin(word), end(word), '1');
				if(num1==1){
					if(index!=i and index!=j and index==int(std::find(begin(word), end(word), '1')-word.begin())){
						findPath(i, index);
						return;
					}
				}
			}
		}

		// such a node must exist, this line cannot be reachable
		__builtin_trap();
	}

	for(int const i: range(0, number-1)){
		for(int const j: range(i+1, number)){
			auto& word=data[j][i];
			auto num1=std::count(begin(word), end(word), '1');
			if(num1==number-2){
				// we know that i and j are 2 leaves attached to the same node, call this `center`
				std::vector<int> kValues;
				for(int const k: range(0, number)){
					if(k!=i and k!=j and data[std::max(i, k)][std::min(i, k)][j]=='1'){
						kValues.push_back(k);
					}
				}

				// kValues are all other nodes attached to center
				for(int const center: range(0, number)){
					if(center!=i and center!=j and 
							std::all_of(begin(kValues), end(kValues), [&](auto const& k){
								return data[std::max(i, k)][std::min(i, k)][center]=='1';
							})){
						// this is the correct center node
						findPath(i, center);
						return;
					}
				}
				std::cout<<"No\n";
				return;
			}
		}
	}

	std::cout<<"No\n";
	return;
}