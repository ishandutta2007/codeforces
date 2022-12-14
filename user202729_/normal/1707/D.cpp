// time-limit: 2000
// problem-url: https://codeforces.com/contest/1707/problem/D

// weird bug.
// A little optimization

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

// { ==== Begin library modular ====


// { ==== Begin library modmultiply64 ====

// identical to kactl's ModMulLL

int64_t modmultiply64(int64_t a, int64_t b, int64_t mod){
	uint64_t result=
		(uint64_t)a*(uint64_t)b-
		uint64_t((long double)a*b/mod)*(uint64_t)mod;
	result+=mod;
	if(result>=uint64_t(mod)){
		result-=mod;
		if(result>=uint64_t(mod)) result-=mod;
	}
	return int64_t(result);
}

// } ==== End library modmultiply64 ====

// { ==== Begin library extended_gcd ====

/**
 * input: (x, y)
 *
 * return (a, ax) such that a=ax*x+ay*y for some ay
 */
template<class T> struct extended_gcd_result { T a, ax; };
template<class T> extended_gcd_result<T> extended_gcd(T x, T y){
	static_assert(std::is_signed<T>::value, ""); // otherwise ax will fail...
	T a=x,b=y, ax=1,bx=0;
	while(b!=0){
		T q=a/b, t=a%b;
		a=b; b=t;
		t=T(ax-bx*q); ax=bx; bx=t;
	}
	
	return {a, ax};
}

// } ==== End library extended_gcd ====

// { ==== Begin library codecrunch_patch ====

#if __GNUC__<=4  // oops, codecrunch version is too old
#define IFCONSTEXPR__ if
#else
#define IFCONSTEXPR__ if constexpr
#endif

#if __cplusplus<=201199
#define CONSTEXPRIASSIGN__
#else
#define CONSTEXPRIASSIGN__ constexpr
#endif

// } ==== End library codecrunch_patch ====
template<class F, bool comparable=false> struct Modular_ {
	static auto MOD()
#define MOD (F::get())
	->decltype(MOD){ return MOD; }
	using T=typename std::decay<decltype(MOD)>::type;

	T val;
	explicit operator T() const { return val; }
	Modular_():val(){
		assert(MOD>0);
		#if hasdebugprint
		assert(gdbgetstr(*this));
		#endif
	}
	#if hasdebugprint
	DEFINEGETSTR(Modular_)
	#endif

	template<class U> static auto check_can_mod_mod()->decltype(std::declval<U>()%MOD, void());
	template<class U
		, class=decltype(check_can_mod_mod<U>()) // sfinae
		> Modular_(U v)
		{
			assert(MOD>0);
			IFCONSTEXPR__ (std::is_unsigned<T>::value){
				assert(v>=0);
			}

			/*
			val=T(v%MOD);
			if(val<0)val+=MOD;
			*/
			val=T(v%MOD);
			if(val<0)val+=MOD;
		}

	template<class U> static Modular_ raw(U value){ // for micro-optimizations
		assert(0<=value); assert(value<MOD);
		Modular_ result; result.val=value; return result;
	}

#define COMPAREOP(OP) \
	template <bool _=comparable> \
	[[nodiscard]] typename std::enable_if<_, bool>::type operator OP(Modular_ b) const { return val OP b.val; }
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] Modular_ operator+() const{ return *this; }
	[[nodiscard]] friend Modular_ operator-(Modular_ x) { x.val=x.val?MOD-x.val:0; return x; }
	Modular_& operator+=(Modular_ m) { if ((val += m.val) >= MOD) val -= MOD; return *this; }
	Modular_& operator-=(Modular_ m) {
		if(std::is_signed<T>::value){
			if ((val -= m.val) < 0) val += MOD;
		}else{
			if (val < m.val) val+=MOD; 
			val-=m.val;
		}
		return *this;
	}
	Modular_& operator*=(Modular_ m) {
		//if(__builtin_constant_p(m.val)){
		//	switch(m.val){
		//		case 1: return *this;
		//		case 2: return *this+=*this;
		//		case 3: return *this+=*this+*this;
		//		case 0: return *this=0;
		//		case -1: return *this=-*this;
		//	}
		//}else if(__builtin_constant_p(val)){
		//	return *this=m**this;
		//}


		IFCONSTEXPR__(std::is_same<T, int>::value){
			val = int((int64_t)val*m.val%MOD);
		}else IFCONSTEXPR__(std::is_same<T, int64_t>::value){
			val=modmultiply64(val, m.val, MOD);
		}else{
			// TODO?
			val*=m.val;
			val%=MOD;
			//assert(false);
		}
		return *this;
	}
	template<class U>
	[[nodiscard]] Modular_ pow(U p) const {
		IFCONSTEXPR__(std::is_signed<U>::value) assert(p>=0);
		Modular_ a=*this;
		Modular_ ans = 1; for (; p; p >>= 1, a *= a) if (p&1) ans *= a;
		return ans;
	}
	[[nodiscard]] Modular_ inv() const {
		auto tmp=extended_gcd(val, T(MOD));
		assert(tmp.a==1);
		if(tmp.ax<0)tmp.ax+=MOD;
		return raw(tmp.ax);
	}
	Modular_& operator/=(Modular_ m) { return (*this) *= m.inv(); }
	friend std::ostream& operator<<(std::ostream& stream, Modular_ m) {
		// debug only
		if(m.val>MOD/2){
			return stream<<'-'<<MOD-m.val<<'_';
		}else{
			return stream<<m.val<<'_';
		}
	}

	

#define ARITHBINARYOP(OP) [[nodiscard]] friend Modular_ operator OP(Modular_ a, Modular_ b) { return a OP##= b; }
	ARITHBINARYOP(+) ARITHBINARYOP(-) ARITHBINARYOP(*) ARITHBINARYOP(/)
#undef ARITHBINARYOP

#undef MOD
};

template<class T, T x> struct TGetter{ static T get(){ return x; } };
template<int MOD> using Modular=Modular_<TGetter<int, MOD>>;
template<int64_t MOD> using Modular64=Modular_<TGetter<int64_t, MOD>>;
template<int MOD> using ModularComparable=Modular_<TGetter<int, MOD>, true>;
template<int64_t MOD> using ModularComparable64=Modular_<TGetter<int64_t, MOD>, true>;
template<int const& MOD> using ModularP=Modular_<TGetter<int const&, MOD>>; // warning: must use global variable (with linkage)
template<int64_t const& MOD> using ModularP64=Modular_<TGetter<int64_t const&, MOD>>; // warning: must use global variable (with linkage)

// } ==== End library modular ====

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

// { ==== Begin library Fraction.h ====

template<class T=int, class U=T, class V=std::common_type_t<T, U, int64_t>, bool always_simplify=true>
struct Fraction{
	T numer; U denom;

	// construct fraction from int
	constexpr Fraction(T x={}): numer(x), denom(1) {}

	// construct fraction as a ratio. Use raw() may be faster if always_simplify
	constexpr Fraction(T a, U b): numer(a), denom(b) {
		if constexpr(std::is_signed<U>::value){
			if(denom<0){ numer=-numer; denom=-denom; }
		}
		if constexpr(always_simplify) *this=this->_simplify();
	}

	static Fraction rawx(T a, U b){
		// "true raw", only used internally
		Fraction result; result.numer=a; result.denom=b; return result;
	}

	template<bool X=always_simplify>
	static Fraction raw(T a, U b){
		// construct a raw fraction from numer and denom, faster if known to be coprime
		static_assert(X==always_simplify and X, "if not always_simplify just use constructor?");
		assert(std::__gcd(a, b)==1 and b>0);
		return rawx(a, b);
	}

	void constexpr check() const{
		assert(denom>0);
		if constexpr(always_simplify)
			assert(std::__gcd(numer, denom)==1);
	}

#define COMPAREOP(OP) [[nodiscard]] bool constexpr operator OP(Fraction other)const{\
		check(); other.check();                                                     \
		return (V)numer*other.denom OP (V)other.numer*denom;                \
	}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	template<class W> explicit operator W() const{
		static_assert(not std::is_integral<W>::value);
		return W(numer)/W(denom);
	}

	private:
	[[nodiscard]] Fraction _simplify() const{
		auto g=std::__gcd(numer, denom);
		if constexpr(std::is_signed<U>::value){
			assert(g>0);
			assert(denom>0);
		}
		return rawx(numer/g, denom/g);
	}
	public:

	template<bool X=always_simplify> // technically not very well-formed? Not sure, will check
	[[nodiscard]] Fraction simplify() const{
		static_assert(X==always_simplify and not X, "no need to simplify if always_simplify is on");
		return _simplify();
	}

	[[nodiscard]] Fraction operator*(Fraction other)const{ return Fraction{numer*other.numer, denom*other.denom}; }
	[[nodiscard]] Fraction operator/(Fraction other)const{ return Fraction{numer*other.denom, denom*other.numer}; }

	[[nodiscard]] Fraction operator+(Fraction other)const{ return Fraction{numer*other.denom+denom*other.numer, denom*other.denom}; }
	[[nodiscard]] Fraction operator-(Fraction other)const{ return Fraction{numer*other.denom-denom*other.numer, denom*other.denom}; }

#define ASSIGNOP(OP) Fraction& operator OP##=(Fraction other){ return *this=*this OP other; }
	ASSIGNOP(+) ASSIGNOP(-) ASSIGNOP(*) ASSIGNOP(/)
#undef ASSIGNOP

	friend std::ostream& operator<<(std::ostream& stream, Fraction const& f){
		if(f.denom==1){
			return stream<<f.numer;
		}else{
			return stream<<f.numer<<'/'<<f.denom;
		}
	}
};

// } ==== End library Fraction.h ====

// { ==== Begin library ModularComb.h ====
/*
 * Usage:

#include"ModularComb.h"

using modular=Modular<1000000007>;
auto const comb=makeComb<modular>(1000);

comb(5, 3) // -> 10

*/


// { ==== Begin library ModularInverseFact.h ====


// { ==== Begin library ModularInverse.h ====

template<class modular>
std::vector<modular> inverseF(int limit){
	std::vector<modular> inverse(limit);
	inverse[1]=1;
	for(unsigned i=2;i<inverse.size();++i){
		if constexpr(std::is_floating_point<modular>::value){
			// this case only happen in local debugging
			inverse[i]=1/modular(i);
		}else{
			assert(modular::MOD()%i!=0    or not "Mod is not prime, i is not invertible mod mod");
			inverse[i]=inverse[modular::MOD()%i]*modular::raw(modular::MOD()-modular::MOD()/i);
		}
	}
	return inverse;
}

// } ==== End library ModularInverse.h ====
template<class modular>
std::vector<modular> inverseFactF(int limit, std::vector<modular> inverse={}){
	if(inverse.empty()) inverse=inverseF<modular>(limit);
	else assert((int)inverse.size()==limit);

	inverse[0]=1;
	for(int index=3; index<(int)inverse.size(); ++index)
		inverse[index]*=inverse[index-1];
	return inverse;
}


// } ==== End library ModularInverseFact.h ====

// { ==== Begin library ModularFact.h ====


template<class modular>
std::vector<modular> factF(int limit){
	std::vector<modular> fact(limit);
	fact[0]=1;
	for(int i=1; i<(int)fact.size(); ++i)
		fact[i]=fact[i-1]*i;
	return fact;
}

// } ==== End library ModularFact.h ====
template<class modular, bool tolerant> struct Comb_internalStructure{
	std::vector<modular> fact, inverseFact;
	modular operator()(int a, int b)const{
		if(tolerant and (b<0 or b>a)) return 0;
		return fact[a]*inverseFact[b]*inverseFact[a-b];
	}
	modular inverseComb(int a, int b)const{
		if(b<0 or b>a) { assert(false); __builtin_unreachable(); }
		return inverseFact[a]*fact[b]*fact[a-b];
	}
	modular walk(int a, int b) const{
		return (*this)(a+b, b);
	}
};

template<class modular, bool tolerant=false>
Comb_internalStructure<modular, tolerant> makeComb(int limit){
	Comb_internalStructure<modular, tolerant> result;
	result.fact=factF<modular>(limit);
	result.inverseFact=inverseFactF<modular>(limit);
	return result;
}

template<class modular>
Comb_internalStructure<modular, true> makeTolerantComb(int limit){ return makeComb<modular, true>(limit); }

// } ==== End library ModularComb.h ====
int mod;
using modular=ModularP<mod>;

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	std::cin>>mod;

	auto const comb=makeComb<modular>(number);

	Graph<> g;
	g.readUndirected(number, number-1);
	
	int const root=0;
	auto tmpa=Dfs<decltype(g)::EdgeWeight,
		 true, // par
		 false, // depth
		 false, // subtreeSize
		 false, // visited (**required** if is graph)
		 false, // orderOf
		 false, // low
		 true, // postorder
		 false // lastOrderOf
	>{g, root};
	auto const par=std::move(tmpa.par);
	auto const postorder=std::move(tmpa.postorder);

	for(int const node: range(0, number)) if(node!=root){
		g[node].erase(std::find_if(begin(g[node]), end(g[node]), [&](auto const& it){
			return it.node==par[node].node;
		}));
	}


	std::vector<std::vector<modular>> f(number-1, std::vector<modular>(number));


	std::vector<modular> result(number-1);

	using F=Fraction<modular, modular, modular, false>;

	std::vector<modular> hPrefix(number), hSuffix(number), tmp(number);

	for(auto node: postorder){

		modular sh {};
		std::fill(tmp.begin(), tmp.begin()+g[node].size(), modular {});

		for(int const max: range(0, number-1)){

			hPrefix[0]=hSuffix[g[node].size()]=1;
			for(int const i: range(0, int(g[node].size()))){
				hPrefix[i+1]=hPrefix[i]*f[max][g[node][i].node];
			}
			for(int i=int(g[node].size()); i--;)
				hSuffix[i]=hSuffix[i+1]*f[max][g[node][i].node];
	

			sh+=hSuffix[0];
			f[max][node]+=sh*(1-int(g[node].size()));

			for(int const i: range(0, int(g[node].size()))){
				auto const largeChild=g[node][i].node;
				tmp[i] += hPrefix[i]*hSuffix[i+1];
				f[max][node]+= f[max][largeChild] * tmp[i];
			}
		}
	}

	for(int const max: range(0, number-1)){
		modular result_=1;
		for(auto [child, _]: g[root]) result_*=f[max][child];

		for(int const max1: range(0, max)){
			result_-=comb(max+1, max1+1)*result[max1];
		}

		result[max]=result_;

		std::cout<<
			int(result_)
			<<' ';
	}
	std::cout<<'\n';
}