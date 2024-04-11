// time-limit: 5000
// problem-url: https://codeforces.com/contest/1648/problem/D

// bug...

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

// { ==== Begin library GlobalList.h ====
// efficient forward-linked list.

template<class Item> struct GlobalList{
	struct Data{Item item; int next;}; // -1: no next
	inline static std::vector<Data> data;

	struct Iterator{
		int index;

		bool operator==(Iterator other) const{return index==other.index;}
		bool operator!=(Iterator other) const{return index!=other.index;}
		
		Item const& operator*() const{
			return data[index].item;
		};
		Item& operator*(){return const_cast<Item&> (**(const Iterator*) this);}

		Item const* operator->() const{ return &**this; }
		Item* operator->() { return &**this; }

		int& next_(){return data[index].next;} // half-internal method
		Iterator operator++() {index=next_(); return *this;}
		Iterator operator++(int) {auto result=*this; ++*this; return result;}

		void erase_after_() {
			// NOTE if this is contained in a list, it may [make the before_end iterator incorrect]
			auto u=*this; ++u;
			next_()=u.next_();
		}
	};

	struct FreeNode{ // type-safe wrapper over iterator (represent a free node of course)
		Iterator i;

		// annoyingly explicit constructor is needed (in C++20?)
		FreeNode(Iterator i): i(i) {}

		// disallow copy
		FreeNode(FreeNode const&)=delete;
		FreeNode& operator=(FreeNode const&)=delete;

		// can still move
		FreeNode(FreeNode&&)=default;
		FreeNode& operator=(FreeNode&&)=default;
	};

	static FreeNode newItem(Item item){
		Iterator result{(int)data.size()};
		data.push_back({std::move(item), -1});
		return {result};
	}

	template<bool minSize=1> struct List{
		Iterator begin_, back_;

		List(FreeNode node){
			begin_=back_=node.i;
		}
		
		List(Item item): List(newItem(std::move(item))){}

		List(){
			static_assert(minSize==0);
			begin_=back_={-1};
		}

		void push_front(FreeNode node){
			if constexpr(minSize==0){
				if(empty()){
					*this=List{node};
					return;
				}
			}
			node.i.next_()=begin_.index;
			begin_=node.i;
		}
		void push_front(Item item){ push_front(newItem(std::move(item))); }

		void push_back(FreeNode node){
			node.i.next_()=-1;
			if constexpr(minSize==0){
				if(empty()){
					*this=List{std::move(node)};
					return;
				}
			}
			back_.next_()=node.i.index;
			back_=node.i;
		}
		void push_back(Item item){ push_back(newItem(std::move(item))); }

		template<int minSize_=minSize>
		std::enable_if_t<minSize_==0, bool> empty() const{
			return begin()==end();
		}

		bool size_equal(int n)const{
			// worst case time complexity is linear in n
			if constexpr(minSize==0){
				if(n==0) return empty();
			}
			assert(n>=1);
			auto tmp=begin_;
			while(n>1){
				if(tmp==back_) return false;
				++tmp; n--;
			}
			return tmp==back_;
		}

		FreeNode pop_front() {
			assert(not size_equal(minSize));
			return {begin_++};
		}

		void clear(){ // this does not actually save memory because of how GlobalList is implemented...
			while(not empty()) pop_front();
		}

		Iterator begin() const{return begin_;}
		Iterator before_end() const{return back_;}
		Iterator end() const{return {-1};}
		Item& front(){return *begin();} Item const& front()const{return *begin();}
		Item& back(){return *before_end();} Item const& back()const{return *before_end();}

		/*
		void for_each(auto f) const{
			// f: bool(Item)
			static_assert( std::is_invocable_r_v<bool, decltype(f), Item&> );
			assert(back_.next_()==-1);

			for(auto it=begin_;;){
				if(f(it)) break;
				if(it==back_) break;
				++it;
			}
		}
		*/
	};
};
//template<class Item> std::vector<typename GlobalList<Item>::Data> GlobalList<Item>::data;
//requires if not inline. Inline is (should be) safe as long as there's only one translation unit

/* some example:
struct I: GlobalList<int> {};
using L=GlobalList<int>::List<1>;
*/

// } ==== End library GlobalList.h ====

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
struct T{ // represent an auxiliary node. 
	int rightNode, cost;
	int64_t distance;
};

struct I: GlobalList<T> {};
using L=GlobalList<T>::List<0>;

struct Node{ 
	int64_t inDistance=INT64_MAX, outDistance=INT64_MAX;
	int innerCost=INT_MAX; // NOTE remember to check for INT_MAX-ness
	L other{};
};
struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	

	template<bool first>
	static void combine(Node& , Node const& , Node const& ){
    }

	/*
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

	*/
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int const numCol=read<int>();
	int const numOffer=read<int>();
	
	std::array<std::vector<int64_t>, 3> rows;
	for(auto& row: rows){
		row.resize(numCol);
		for(auto& item: row) item=read<int>();
	}

	std::partial_sum(begin(rows[0]), end(rows[0]), rows[0].begin());
	std::partial_sum(begin(rows[1]), end(rows[1]), rows[1].begin());
	std::partial_sum(rows[2].rbegin(), rows[2].rend(), rows[2].rbegin());

	std::vector<int64_t> a(numCol), b(numCol+1);
	for(int const right: range(1, numCol+1)){
		b[right]=rows[1][right-1]+rows[2][right-1];
	}

	a[0]=
		rows[0][0];
		//-rows[1][0-1]
	for(int const left: range(1, numCol)){
		a[left]=rows[0][left]-rows[1][left-1];
	}

	// ========
	// now find the minimum value of <cost to remove segment [left..right]> - a[left] - b[right]

	SegmentTree tree(numCol+1); // this store the minimum cost for each node & auxiliary node.


	auto& data=tree.data;
	for(int _=numOffer; _--;){
		int const left=read<int>()-1;
		int const right=read<int>()+1; // it's complex
		int const cost=read<int>();

		auto const leftNode=left+tree.offset(), rightNode=right+tree.offset();

		tree.forRangeIndex(leftNode, rightNode, [&](int node){
			data[node].innerCost=std::min(data[node].innerCost, cost);
		});

		auto [node, left1]=tree.rangeIterate(leftNode, rightNode);
		if(left1!=rightNode){
			data[node].other.push_back({.rightNode=rightNode, .cost=cost, .distance=INT64_MAX});
		}
	}
	for(int const node: range(1, int(tree.offset()))){
		data[node*2].innerCost=std::min(data[node*2].innerCost, data[node].innerCost);
		data[node*2+1].innerCost=std::min(data[node*2+1].innerCost, data[node].innerCost);
	}

	for(int const index: range(0, int(a.size()))){
		data[tree.offset()+index].inDistance=-a[index];
	}

	int64_t result=INT64_MAX;
	for(int const index: range(0, int(tree.offset()))){
		int const node=index+tree.offset();
		for(int shift=__builtin_ctz(node); shift!=0; shift--){
			auto const node1=node>>shift;
			data[node1*2].outDistance=std::min(data[node1*2].outDistance, data[node1].outDistance);
			data[node1*2+1].outDistance=std::min(data[node1*2+1].outDistance, data[node1].outDistance);
		}

		if(index==0) assert(data[node].outDistance==INT64_MAX);
		if(data[node].outDistance!=INT64_MAX)
			result=std::min(result, 
					data[node].outDistance-b[index]
					);
		data[node].inDistance=std::min(data[node].inDistance, data[node].outDistance);

		int tmp=node;
		while(true){
			// process auxiliary nodes in tmp
			auto& l=data[tmp].other;
			while(not l.empty()){
				auto& [rightNode, cost, distance]=l.front();
				auto tmpnode=l.pop_front();
				distance=std::min(distance, data[tmp].inDistance);
				auto [node1, left1]=tree.rangeIterate(node+1, rightNode);
				data[node1].outDistance=std::min(data[node1].outDistance, distance+cost);
				if(left1!=rightNode){
					data[node1].other.push_back(std::move(tmpnode));
				}
			}

			// walk to upper in-node
			data[tmp>>1].inDistance=std::min(data[tmp>>1].inDistance, data[tmp].inDistance);
			if((tmp&1)==0) {
				if(data[tmp>>1].innerCost!=INT_MAX){
					data[tmp+1].outDistance=std::min(data[tmp+1].outDistance, data[tmp].inDistance+data[tmp>>1].innerCost);
				}
				break;
			}

			tmp>>=1;
		}
	}

	std::cout<<-result<<'\n';

}