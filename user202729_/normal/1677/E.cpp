// ><

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
//#include"//debug"

// { ==== Begin library SegmentTree.h ====

/*
Usage:

#include"SegmentTree.h"
struct Node{ ... };
struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left, Node& right, int layer){
        // implement push. Can be omitted.
    }

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
    }

	// other methods
	void set(int left, int right){
		if(left==right) return;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		forRange(left, right, [&](Node& node){ ... });
		combineAll(left); combineAll(right-1);
	}

	void set(int index){
		index+=offset();
		pushAll(index);
		...
		combineAll(index);
	}

	int get(int left, int right){
		if(left==right) return 0;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		return reduceRange(left, right, 0, [&](int result, Node const& node){ ... });
	}

	int operator[](int index){
		index+=offset();
		pushAll(index);
		return data[index];
	}

};

It's necessary to implement push for both children at once if the operation modifies parent.

Some callback functions can choose to take layer as last argument.
Layer 0: leaf (tree size=1), layer 1: parent of leaf, etc.

SPECIAL CASE: if Node=bool, then replace `Node&` with `auto`.

*/

// { ==== Begin library InvocableCheck.h ====

// replacement for std::is_invocable_v before C++17
/* usage: 
decltype(invocable_1(f, x))::value
*/

template <class F, class... X>
auto invocable_1(F&& f, X&&... x) -> decltype(void(std::forward<F>(f)(std::forward<X>(x)...)), std::true_type());

std::false_type invocable_1(...);

// } ==== End library InvocableCheck.h ====

// { ==== Begin library IsTrue.h ====

// helper function

bool evaluatesToTrue(auto const& fn){ // fn is always evaluated
	if constexpr(std::is_same<decltype(fn()),void>::value){
		fn(); return false;
	}else{
		return fn();
	}
}
#define IS_TRUE(expr...) evaluatesToTrue([&]{ return (expr); })

// } ==== End library IsTrue.h ====
template <bool first, class Detail, class Data>
auto combineCanTakeLayer(Data& data, int layer) -> decltype(void(
			Detail::template combine<first>(data, data, data, layer)
			), std::true_type());
template <bool first, class Detail>
std::false_type combineCanTakeLayer(...);



template <class Node, class Detail>
struct SegmentTreeTemplate{
	std::vector<Node> data;

	SegmentTreeTemplate(){}
	SegmentTreeTemplate(int number){ assign(number); }
	SegmentTreeTemplate(std::size_t number){ assign(number); }
	SegmentTreeTemplate(auto&& container){ assign(container.begin(), container.end()); }
	template<class First, class Last, class=decltype(std::declval<First>()[0])>
	SegmentTreeTemplate(First first, Last last){ assign(first, last); }
	SegmentTreeTemplate(int number, Node const& node){ assign(number, node); }
	//SegmentTreeTemplate(int number, auto const& generator){ assign(number, generator); }

	// size=number, empty
	void assign(int number){
		assign(number, Node{});
	}
	void assign(int number, Node const& node){ assign(number, [&]{ return node; }); }
	void assign(int number, auto const& generator){
		data.reserve(number*2); data.resize(number);
		for(int i=0; i<number; ++i) {
			if(data.size()>=data.capacity()) __builtin_unreachable();
			if constexpr(decltype(invocable_1(generator, 0))::value){
				data.push_back(generator(i));
			}else{
				data.push_back(generator());
			}
		}
		for(int i=number; --i;) combineAt<true>(i);
	}
	template<class First, class Last>
	void assign(First first, Last last){
		assign(int(last-first), [&](int index){ return first[index]; });
	}

	private:

	template<class F, class T>
	static decltype(auto) invokeWithOptionalLayer(F const& f, T&& t, int layer) {
		if constexpr(decltype(invocable_1(f, std::forward<T>(t)))::value) return f(std::forward<T>(t));
		else {
			assert(layer>=0);
			return f(std::forward<T>(t), layer);
		}
	}

	public:
	static void forAncestorIndexDown(int node,auto const& fn){
		for(int shift=31^__builtin_clz(node);shift>=0;--shift)
			if(IS_TRUE(fn(node>>shift))) break;
	}
	static void forStrictAncestorIndexDown(int node,auto const& fn
            // fn(node, nodeLayer)  returns true to break loop
            ){
		for(int shift=31^__builtin_clz(node);shift;--shift)
			if(IS_TRUE(invokeWithOptionalLayer(fn, node>>shift, shift))) break;
	}
	static void forAncestorIndexUp(int node,auto const& fn){
		for(int y=node;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}
	static void forStrictAncestorIndexUp(int node,auto const& fn){
		forAncestorIndexUp(node>>1, fn);
	}
	static void forRangeIndex_(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
		// leftfn is called from left to right on left nodes
		// rightfn is called from right to left on right nodes

		// leftfn, rightfn signature: (int (node index), [layer])  bool (true: break)
		assert(leftNode<=rightNode);
		if(leftNode==rightNode) return;
		int layer=0;
		while(leftNode<rightNode){
			if(leftNode&1) if(IS_TRUE(invokeWithOptionalLayer(leftfn, leftNode++, layer))) break;
			if(rightNode&1) if(IS_TRUE(invokeWithOptionalLayer(rightfn, --rightNode, layer))) break;
			leftNode>>=1;rightNode>>=1; ++layer;
		}
	}
	void forRangeIndex(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn)const{
		// leftfn, rightfn signature: (int (node index), [layer])  bool (true: break)
		assert(leftNode>=offset());
		assert(rightNode>=offset());
		forRangeIndex_(leftNode, rightNode, leftfn, rightfn);
	}
	int layerOf(int node) const{
		// layer 0: leaf, layer 1: parent of leaf, etc.
		assert(node<(int)data.size());
		int layer=std::max(0, (31^__builtin_clz((int)data.size()))-(31^__builtin_clz(node))-1);
		if((node<<layer)<offset()) ++layer;
		assert((node<<layer)>=offset());
		assert((node<<layer)<(int)data.size());
		return layer;
	}
	int leftLeaf(int node) const{
		return node<<layerOf(node);
	}
	int rightLeaf(int node) const{
		return ((node+1)<<layerOf(node))-1;
	}

	auto rangeIterate(int left, int right){ struct Result{ int node, left1; };
		// one-step iterate over the left..right range. -> {node, range (left1..right)}
		// first used https://codeforces.com/contest/1648/problem/D
		assert(offset()<=left);
		assert(left<right);
		assert(right<=offset()*2);

		auto bit=left&-left;
		if(left+bit<=right){
			return Result{left>>__builtin_ctz(bit), left+bit};
		}
		int pos=31^__builtin_clz(left xor right);
		return Result{left>>pos, left+(1<<pos)};
	}

	void forRangeIndexOrdered(int leftNode, int rightNode, auto f){
		int tmp=leftNode;
		while(tmp!=rightNode){
			//int node;
			//std::tie(node, tmp)=rangeIterate(tmp, rightNode);
			auto [node, tmpx]=rangeIterate(tmp, rightNode);
			tmp=tmpx;
			f(node);
		}
	}

	// consider using the method below instead
	std::vector<int> rangeIndices(int leftNode, int rightNode)const{
		std::vector<int> left, right;
		forRangeIndex(leftNode, rightNode, [&](auto const& it){
			left.push_back(it);
		}, [&](auto const& it){
			right.push_back(it);
		});
		left.insert(left.end(), right.rbegin(), right.rend());
		return left;
	}

	auto rangeIndicesWithLayer(int leftNode, int rightNode)const{
		struct Item{int node, layer;};
		std::vector<Item> left, right;

		forRangeIndex(leftNode, rightNode, [&](int nodeIndex, int layer){
			left.push_back({nodeIndex, layer});
		}, [&](int nodeIndex, int layer){
			right.push_back({nodeIndex, layer});
		});
		left.insert(left.end(), right.rbegin(), right.rend());
		return left;
	}

#undef IS_TRUE

	// return array index, -1 if not found
	// TODO for now not const callable (need to push)
	int leftmostSatisfy(int leftNode, int rightNode, auto const& func /* : nodeIndex -> bool */){
		if(leftNode==rightNode) return -1;
		pushAll(leftNode); pushAll(rightNode-1);
		int result=-1;
		forRangeIndex(leftNode, rightNode, [&](int node){
			if(func(node)) { result=node; return true; }
			return false;
		}, [&](int node){
			if(func(node)) result=node;
		});
		if(result<0) return -1;
		while(result<offset()){
			pushAt(result);
			result<<=1;
			if(not func(result)) ++result;
		}
		return result-offset();
	}
	int rightmostSatisfy(int leftNode, int rightNode, auto const& func /* : nodeIndex -> bool */){
		if(leftNode==rightNode) return -1;
		pushAll(leftNode); pushAll(rightNode-1);
		int result=-1;
		forRangeIndex(leftNode, rightNode, [&](int node){
			if(func(node)) result=node;
		}, [&](int node){
			if(func(node)) { result=node; return true; }
			return false;
		});
		if(result<0) return -1;
		while(result<offset()){
			pushAt(result);
			result<<=1;
			if(func(result+1)) ++result;
		}
		assert(result>=0);
		return result-offset();
	}
	void forRangeIndex(int leftNode, int rightNode, auto const& fn){
		forRangeIndex(leftNode,rightNode,fn,fn);
	}
	int size()const{ return int(data.size()/2u); }
	int offset()const{ return size(); }

	// default push function, does nothing. Child should override this.
	static void push(Node&, Node&, Node&, int /* layerOf parent */){
    }

	void pushAt(int node, int nodeLayer){
		assert(1<=node); assert(node<offset());
		static_cast<Detail*>(this)->push(data[node], data[node<<1], data[node<<1|1], nodeLayer);
	}

	void pushAt(int node){
        pushAt(node, layerOf(node));
    }

	void pushAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexDown(node, [&](int node, int layer){
			pushAt(node, layer);
		});
	}

	template<bool first> void combineAt(int node, int layer){
		if constexpr(decltype(combineCanTakeLayer<first, Detail>(data[0], layer))::value){
			assert(layer==layerOf(node));
			Detail::template combine<first>(data[node], data[node<<1], data[node<<1|1], layer);
		}else{
			Detail::template combine<first>(data[node], data[node<<1], data[node<<1|1]);
		}
	}

	template<bool first> void combineAt(int node){
		combineAt<first>(node, layerOf(node));
	}

	void combineAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexUp(node, [&](int it){
			combineAt<false>(it);
		});
	}

    // these 2 are exactly the same, except for const-ness 
	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			// (Node, [layer])  bool (true: break)
			)const{
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return invokeWithOptionalLayer(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return invokeWithOptionalLayer(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn)const{
		forRange(leftNode,rightNode,fn,fn);
	}


	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn
			// (Node, [layer])  bool (true: break)
			){
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return invokeWithOptionalLayer(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return invokeWithOptionalLayer(rightfn, data[it], layer); });
	}

	void forRange(int leftNode, int rightNode, auto const& fn){
		forRange(leftNode,rightNode,fn,fn);
	}
    // ========


	static Node combined(Node const& left, Node const& right){
		// NOTE bad things may happen if there's lazy (propagation) data inside node
		Node result;
		Detail::template combine<true>(result, left, right);
		return result;
	}

	Node combinedRange1NoPush(int left, int right, Node leftMerge, Node rightMerge) const{
		// return leftMerge  [left..right]  right merge
		assert(0<=left); assert(left<=right); assert(right<=offset());

		auto leftNode=left+offset(), rightNode=right+offset();

		Node leftAnswer=leftMerge, rightAnswer=rightMerge;
        forRange(leftNode, rightNode,
                [&](Node node){ leftAnswer=combined(leftAnswer, node); },
                [&](Node node){ rightAnswer=combined(node, rightAnswer); }
                );
		return combined(leftAnswer, rightAnswer);
	}

	Node combinedRangeNoPush(int left, int right, Node identity) const{
		return combinedRange1NoPush(left, right, identity, identity);
	}

	// when there's no (trivial) identity...
	Node combinedRangeNoPush(int left, int right) const{
		assert(left<right);
		if(left+1==right) return data[left+offset()];
		return combinedRange1NoPush(left+1, right-1, data[left+offset()], data[right+offset()-1]);
	}

	Node combinedRange(int left, int right, Node identity) {
        if(left<right){
            pushAll(left+offset());
            pushAll(right-1+offset());
        }
        return combinedRangeNoPush(left, right, identity);
    }

	Node combinedRange(int left, int right) {
        if(left<right){
            pushAll(left+offset());
            pushAll(right-1+offset());
        }
        return combinedRangeNoPush(left, right);
    }

	template<class T> T reduceRange(int leftNode, int rightNode, T initial, auto const& function /* (T value, Node const& node)  T */) const {
		// Reduce function with nodes on the range in arbitrary order.
		// See combinedRange if combiner is not commutative.
		forRange(leftNode, rightNode, [&](Node const& node){ initial=function(std::move(initial), node); });
		return initial;
	}

	auto longestPrefixSatisfy(int const left, int right, Node identity, auto condition /* (Node)  bool */ ){
		struct{
			Node node;
			int len;
			int right; // not rightNode
		}result{identity, 0, 0};

		auto const nodes=rangeIndicesWithLayer(left+offset(), right+offset());
		assert(condition(identity));

		for(auto [x, layer]: nodes){
			assert(
					condition(combined(result.node, data[x]))==
					condition(combined(identity, combined(result.node, data[x])))
				  );
			if(condition(combined(result.node, data[x]))){
				result.node=combined(result.node, data[x]);
				result.len+=1<<layer;
			}else{
				while(layer){
					x<<=1; layer--;
					if(condition(combined(result.node, data[x]))){
						result.node=combined(result.node, data[x]);
						result.len+=1<<layer;
						x++;
						assert(not condition(combined(result.node, data[x])));
					}
				}
				assert(x>=offset());
				break;
			}
		}

		result.right=left+result.len;
		return result;
	}
};


// } ==== End library SegmentTree.h ====

// { ==== Begin library Point.h ====

// (local note) see also: geometry.cpp

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
template<class T_,class U_>
struct Point_{
	using T=T_; using U=U_;

	T x,y;
	Point_ constexpr operator+(Point_ p)const{return {x+p.x,y+p.y};}
	Point_ constexpr operator-(Point_ p)const{return {x-p.x,y-p.y};}
	Point_ constexpr operator-()const{return {-x,-y};}
	Point_ constexpr operator*(T f)const{return {x*f,y*f};}
	friend Point_ constexpr operator*(T f, Point_ p){return p*f;}

	Point_ CONSTEXPRIASSIGN__& operator+=(Point_ p){return *this=*this+p;}
	Point_ CONSTEXPRIASSIGN__& operator-=(Point_ p){return *this=*this-p;}
	Point_ CONSTEXPRIASSIGN__& operator*=(T f    ){return *this=*this*f;}

	template<class T1,class U1>
	constexpr operator Point_<T1,U1>() const {T1 x1=x, y1=y; return {x1,y1};} // avoid narrowing warning but still warn if convert e.g. double  int

	template<class P>
	constexpr P castTo() const {return {(typename P::T)x,(typename P::T)y};} // explicit cast avoid warning entirely


#define COMPAREOP(OP) bool constexpr operator OP(Point_ p) const {return std::tie(x,y) OP std::tie(p.x,p.y);}
	COMPAREOP(==) COMPAREOP(!=) COMPAREOP(<) COMPAREOP(>) COMPAREOP(<=) COMPAREOP(>=)
#undef COMPAREOP

	[[nodiscard]] U constexpr cross(Point_ p)const{return x*(U)p.y-y*(U)p.x;}
	[[nodiscard]] U constexpr dot  (Point_ p)const{return x*(U)p.x+y*(U)p.y;}
	[[nodiscard]] U constexpr norm()const{return dot(*this);}
	[[nodiscard]] U constexpr squaredLength()const{return norm();}
	[[nodiscard]] U constexpr squaredDistance(Point_ p)const{return (*this-p).norm();}
	[[nodiscard]] double constexpr length()const{return std::sqrt(norm());}
	[[nodiscard]] double constexpr distance(Point_ p)const{return std::sqrt(squaredDistance(p));}

	friend U cross(Point_ a,Point_ b,Point_ c){
		return (b-a).cross(c-a);
	} // >0: ccw

	Point_ rotateRight() const{return {y, -x};}
	Point_ rotateLeft() const{return {-y, x};}

	friend std::istream& operator>>(std::istream& str,Point_& p){
		return str>>p.x>>p.y;
	}
	friend std::ostream& operator<<(std::ostream& str,Point_ const& p){
		return str<<"Point("<<p.x<<' '<<p.y<<')';
	}
};

// } ==== End library Point.h ====
using P=Point_<int64_t, int64_t>; // cheating but okay...


struct Node{
	P lazy{}, value_{};
	int size=1; // simplify implementation, difficult runtime, == 1<<layer
	P value() const{return lazy*size+value_;}
};


struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left, Node& right, int ){
		auto const l=parent.lazy; parent.lazy={};
		parent.value_+=l*parent.size;
		left.lazy+=l;
		right.lazy+=l;
    }

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		if(first) parent.size=left.size+right.size;
		parent.value_=left.value()+right.value();
    }

	void add(int left, int right, P delta){
		if(left==right) return;
		assert(left<=right);
		left+=offset(); right+=offset();
		//pushAll(left); pushAll(right-1);
		forRange(left, right, [&](Node& node){ 
			node.lazy+=delta;
		});
		combineAll(left); combineAll(right-1);
	}


	int64_t get(int left, int right, int r){
		if(left==right) return 0;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		auto node=combinedRange(left-offset(), right-offset());
		auto [x, y]=node.value();
		return x*r+y;
	}


};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const number=read<int>();
	int const numQuery=read<int>();
	std::vector<int> p(number);
	std::vector<int> pos(number+1);

	for(int const index: range(0, number)){
		p[index]=read<int>();
		pos[p[index]]=index;
	}

	std::vector<std::vector<std::pair<int, int>>> productPos(number+1);
	for(int const i: range(1, number+1)){
		for(int j=i+1; int64_t(j)*i<=number; j++){
			productPos[j*i].push_back({pos[i], pos[j]});
		}
	}

	std::set<int> seenPos{-1, number};


	struct Event{
		bool query;
		int y, x1, x2, delta;
		bool operator<(Event other) const{return y<other.y;}
		int& queryX(){return x1;}  int& queryIndex(){return x2;}  // !?!?
	};
	std::vector<Event> events;

	for(int i=number+1; i-->1;){
		auto [iter, _]=seenPos.insert(pos[i]);
		auto a=*std::prev(iter), b=pos[i], c=*std::next(iter);

		int const l1=a+1, r2=c;
		std::vector<std::pair<int, int>> items;
		for(auto [x, y]: productPos[i]){
			int l2=std::min({b, x, y})+1;
			int r1=std::max({b, x, y});
			if(l1>=l2 or r1>=r2){
				continue;
			}

			items.push_back({l2, r1});
		}

		std::sort(begin(items), end(items), [&](auto const& first, auto const& sec){
			return 
				std::make_pair(first.first, -first.second)
				<
				std::make_pair(sec.first, -sec.second)
				;
		});
		auto out=items.begin();
		for(auto [l2, r1]: items){
			while(out!=items.begin() and out[-1].second>=r1){
				--out;
			}
			*out++={l2, r1};
		}
		items.erase(out, items.end());


		int lasta=l1;
		for(auto [a, b]: items){

			int l1=lasta, l2=a;
			lasta=a;
			int r1=b;

			events.push_back({false, r1, l1, l2, 1});
			events.push_back({false, r2, l1, l2, -1});
		}


	}

			
	/*
	struct Query{};
	std::vector<Query> queries(numQuery);
	*/
	for(int const queryIndex: range(0, numQuery)){
		int const l=read<int>()-1;
		int const r=read<int>()-1;

		/*
		int64_t result {};
		for(int const l1: range(l, number)){
			for(int const r1: range(0, r+1)){
				result+=seen[r1][l1];
			}
		}
		std::cout<<result<<'\n';
		*/

		//queries[queryIndex]={l, r+1, queryIndex};
		events.push_back({true, r+1, l, queryIndex, 0});
		assert(events.back().queryIndex()==queryIndex);
	}

	std::sort(begin(events), end(events));

	std::vector<int64_t> result(numQuery);

	// sweep in increasing r value...
	SegmentTree tree(number);

	if(0){
		SegmentTree tree(8);
		tree.add(1, 5, P{1, -3});
		tree.add(1, 5, P{-1, 4});
		//debug(tree.get(0, 4, 5));
		return 0;
	}

	for(auto e: events){
		if(e.query){
			auto y=e.y;
			auto x=e.queryX();
			auto queryIndex=e.queryIndex();
			result[queryIndex]=tree.get(x, number, y);

			//debug(e.query, y, x, queryIndex, result[queryIndex]);
		}else{
			auto [_query, y, x1, x2, delta]=e;
			tree.add(x1, x2, P{delta, -y*delta});

			//debug(_query, y, x1, x2, delta);
		}
	}

	for(auto item: result) std::cout<<item<<'\n';

	
}


// time-limit: 4000
// problem-url: https://codeforces.com/contest/1677/problem/E