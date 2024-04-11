// time-limit: 4000
// problem-url: https://codeforces.com/contest/1737/problem/D

// hopefully correct?




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


// { ==== Begin library debug ====



// rarely useful, usually gdb print is sufficient

// { ==== Begin library IntegerSequenceMock.h ====


#if __cplusplus >= 201400

using std::integer_sequence;
using std::index_sequence;
using std::make_integer_sequence;
using std::make_index_sequence;

#else

template<class T, T... values>
struct integer_sequence{
	friend std::ostream& operator<<(std::ostream& stream, integer_sequence const&){
		std::initializer_list<T> data{values...};
		for(auto item: data) stream<<item<<' ';
		return stream;
	}
};

template<std::size_t... values> using index_sequence=integer_sequence<std::size_t, values...>;

template<class T, T first, T... rest>
integer_sequence<T, first, rest...> integer_sequence_concat_helper(
	integer_sequence<T, rest...>
	);

template<class T, bool first_ge_last, T first, T last>
struct make_integer_sequence_range_{};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, true, first, last>{
	using type=integer_sequence<T>;
};

template<class T, T first, T last>
struct make_integer_sequence_range_<T, false, first, last>{
	using type=
		decltype(integer_sequence_concat_helper<T, first>(typename make_integer_sequence_range_<T, first+1>=last, first+1, last>::type{}));
};

template<class T, T first, T last> using make_integer_sequence_range=typename make_integer_sequence_range_<T, first>=last, first, last>::type;
template<std::size_t first, std::size_t last> using make_index_sequence_range=typename make_integer_sequence_range_<std::size_t, first>=last, first, last>::type;

template<class T, T last> using make_integer_sequence=make_integer_sequence_range<T, 0, last>;
template<std::size_t last> using make_index_sequence=make_integer_sequence<std::size_t, last>;

#endif

// } ==== End library IntegerSequenceMock.h ====


#ifndef LOCALPRETTY

#if LOCAL
#define LOCALPRETTY 1
#else
#define LOCALPRETTY 0
#endif

#endif

#if LOCALPRETTY
#define ifpretty(a, b) a
#else
#define ifpretty(a, b) b
#endif

#define prettyseparator ifpretty(", ", ' ')
#define prettybracket(x) ifpretty(stream<<x;,)


template<class T> std::ostream& operator<<(std::ostream& stream, std::vector<T> const& data){
	prettybracket('[')
	if(not data.empty()){
		stream<<data[0];
		for(auto iter=std::next(data.begin()); iter!=data.end(); ++iter)
			stream<<prettyseparator<<*iter;
	}
	prettybracket(']')
	return stream;
}

template<class T, std::size_t N> std::ostream& operator<<(std::ostream& stream, std::array<T, N> const& data){
	prettybracket('[')
	if(not data.empty()){
		stream<<data[0];
		for(auto iter=std::next(data.begin()); iter!=data.end(); ++iter)
			stream<<prettyseparator<<*iter;
	}
	prettybracket(']')
	return stream;
}

template<class A, class B> std::ostream& operator<<(std::ostream& stream, std::pair<A, B> const& data){
	prettybracket('(')
	return stream<<data.first<<prettyseparator<<data.second ifpretty(<<')',);
}

template<class... Types, std::size_t... Is>
void tuple_print_helper(std::ostream& stream, std::tuple<Types...> const& data,
		index_sequence<Is...>
		){
	std::initializer_list<int>({
		(
		 stream<<prettyseparator<<std::get<Is+1>(data)
		 , 0)...
	});
}

template<class... Types> std::ostream& operator<<(std::ostream& stream, std::tuple<Types...> const& data){
	if(sizeof...(Types)==0){
		prettybracket("()")
	}else{
		prettybracket('(')
		stream<<std::get<0>(data);
		tuple_print_helper(stream, data, make_index_sequence<sizeof...(Types)-1>{});
		prettybracket(')')
	}
	return stream;
}

#undef LOCALPRETTY
#undef ifpretty
#undef prettyseparator
#undef prettybracket

#define debug1(x) assert(std::cerr<<#x " = "<<(x));

#define ifstartwithparen(x...) evalMA(getthird emptyM()(parentocomma x, getfirst, getsecond))
#define evalMA(x...) x
#define evalM(x...) x
#define evalM2(x...) evalM(evalM(evalM(evalM(x))))
#define evalM3(x...) evalM2(evalM2(evalM2(evalM2(x))))
#define evalM4(x...) evalM3(evalM3(evalM3(evalM3(x))))
#define evalME(x...) evalM4(evalM4(evalM4(evalM4(x))))
#define emptyM(...)
#define parentocomma(...) ,
#define getfirst(x, ...) x
#define getsecond(x, y, ...) y
#define getfirstA(x, ...) x
#define getsecondA(x, y, ...) y
#define getthird(x, y, z, ...) z
#define ifempty1(x) ifstartwithparen(x())(ifstartwithparen(x)(getsecondA, getfirstA), getsecondA)
#define ifempty(x, y...) ifempty1(x)

#define debuginnerdelay() debuginner
#define debuginner(x, y...) debug1(x) ifempty(y)( assert(std::cerr<<'\n'); , assert(std::cerr<<", "); debuginnerdelay emptyM emptyM()()()(y) )
#define debug(x...) {evalME(debuginner(x))}

/*
actually Boost already have such a macro, why don't I take it

correctly return true:
	ifempty()(true, false)

correctly return false:
	ifempty(abc)(true, false)
	ifempty(abc, def)(true, false)
	ifempty(())(true, false)

incorrectly return true:
	ifempty(, abc)(true, false)

error out: ignore
*/




#define hasdebugprint 1

std::string result_gdbgetstr;

void function_take_voidp(void const*){}

#define DEFINEGETSTR(T) \
friend char const* gdbgetstr(T const& data){ \
	std::stringstream stream; \
	stream<<data; \
	result_gdbgetstr=std::move(stream).str(); \
	return result_gdbgetstr.c_str(); \
}

//void can_gdbgetstr() const{ gdbgetstr(*this); }



/*usage example

======== add in constructor: (to instantiate the function)

#if hasdebugprint
assert(gdbgetstr(*this));
#endif

======== add in method body:

#if hasdebugprint
DEFINEGETSTR(Modular_)
#endif

======== make it `friend` to avoid the `<...>` part creeping into the name

*/

// } ==== End library debug ====


void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int const numNode=read<int>();
	int const numEdge=read<int>();
	std::vector<std::vector<int>> edgeDistance(numNode, std::vector<int>(numNode, INT_MAX/2));
	for(int const i: range(0, numNode)){
		edgeDistance[i][i]=0;
	}

	struct Edge{int u, v, weight;};
	std::vector<Edge> edges(numEdge);

	std::vector<int> minAdjacent(numNode, INT_MAX);

	for(int const index: range(0, numEdge)){
		int const u=read<int>()-1;
		int const v=read<int>()-1;
		int const w=read<int>();
		edges[index]={u, v, w};
		assert(u!=v);
		edgeDistance[u][v]=1;
		edgeDistance[v][u]=1;

		minAdjacent[u]=std::min(minAdjacent[u], w);
		minAdjacent[v]=std::min(minAdjacent[v], w);
	}

	// Floyd
	for(int const middle: range(0, numNode)){
		for(int const i: range(0, numNode)){
			for(int const j: range(0, numNode)){
				edgeDistance[i][j]=std::min(edgeDistance[i][j], edgeDistance[i][middle]+edgeDistance[middle][j]);
			}
		}
	}
	
	// the graph is connected, so...
	for(int const i: range(0, numNode)){
		for(int const j: range(0, numNode)){
			assert(edgeDistance[i][j]<=numNode);
		}
	}

	// compute result
	int64_t result=INT64_MAX;
	for(auto [u, v, weight]: edges){
		result=std::min(result, 
				int64_t(weight)*(std::min(
					edgeDistance[0][u]+edgeDistance.back()[v],
					edgeDistance[0][v]+edgeDistance.back()[u]
					)+1)
				);
		
	}

	for(int const t: range(0, numNode)){
		for(int const u: range(0, numNode)){
			result=std::min(result, 
					minAdjacent[u]*int64_t(edgeDistance[t][0]
						+edgeDistance[t].back()
						+edgeDistance[t][u]+2)
					);
		}
	}

	std::cout<<result<<'\n';
}