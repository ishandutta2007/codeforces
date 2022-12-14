// time-limit: 3000
// problem-url: https://codeforces.com/contest/1601/problem/C
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

// ... hopefully fast enough
// { ==== Begin library SegmentTree.h ====
/*
Usage:

#include"SegmentTree.h"
struct Node{ ... };
struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left [, Node& right] ){ ... }
	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){ ... }

	// other methods
	void set(int left, int right){
		if(left==right) return;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		forRange(left, right, [&](Node& node){ ... });
		combineAll(left); combineAll(right-1);
	}

	void set(int left){
		left+=offset();
		pushAll(left);
		...
		combineAll(left); combineAll(right-1);
	}

	int get(int left, int right){
		if(left==right) return 0;
		assert(left<=right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		return reduceRange(left, right, 0, [](int result, Node node){ ... });
	}

	int get(int node){
		left+=offset();
		pushAll(left);
		return data[left];
	}
};

It's necessary to implement push for both children at once if the operation modifies parent.

Some callback functions can choose to take layer as last argument.
Layer 0: leaf (tree size=1), layer 1: parent of leaf, etc.
*/

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
			if constexpr(std::is_invocable_v<decltype(generator), int>){
				data.push_back(generator(i));
			}else{
				data.push_back(generator());
			}
		}
		for(int i=number; --i;) Detail::template combine<true>(data[i], data[i<<1], data[i<<1|1]);
	}
	template<class First, class Last>
	void assign(First first, Last last){
		assign(int(last-first), [&](int index){ return first[index]; });
	}

	private:
	static bool evaluatesToTrue(auto const& fn){ // fn is always evaluated
		if constexpr(std::is_same_v<decltype(fn()),void>){
			fn(); return false;
		}else{
			return fn();
		}
	}
#define IS_TRUE(expr...) evaluatesToTrue([&]{ return (expr); })

	template<class F, class T>
	static decltype(auto) invokeWithOptionalLayer(F const& f, T&& t, int layer) {
		if constexpr(std::is_invocable_v<F, T&&>) return f(std::forward<T>(t));
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
	static void forStrictAncestorIndexDown(int node,auto const& fn){ // fn returns true to break loop
		for(int shift=31^__builtin_clz(node);shift;--shift)
			if(IS_TRUE(fn(node>>shift))) break;
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

#undef IS_TRUE

	// return array index, -1 if not found
	int leftmostSatisfy(int leftNode, int rightNode, auto const& func /* : nodeIndex -> bool */){
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
	static void forRangeIndex(int leftNode, int rightNode, auto const& fn){
		forRangeIndex(leftNode,rightNode,fn,fn);
	}
	int size()const{ return int(data.size()/2u); }
	int offset()const{ return size(); }

	void pushAt(int node){
		assert(1<=node); assert(node<offset());
		if constexpr(std::is_invocable_v<decltype(Detail::push), Node&, Node&, Node&>)
			Detail::push(data[node], data[node<<1], data[node<<1|1]);
		else{
			Detail::push(data[node], data[node<<1]);
			Detail::push(data[node], data[node<<1|1]);
		}
	}

	void pushAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexDown(node, [&](int node){
			pushAt(node);
		});
	}
	void combineAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexUp(node, [&](int it){
			Detail::template combine<false>(data[it], data[it<<1], data[it<<1|1]);
		});
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

	static Node combined(Node const& left, Node const& right){
		Node result;
		Detail::template combine<true>(result, left, right);
		return result;
	}

	Node combinedRange(int left, int right, Node identity){
		assert(0<=left); assert(left<=right); assert(right<=offset());

		if(left==right) return identity;

		auto leftNode=left+offset(), rightNode=right+offset();

		pushAll(leftNode);
		pushAll(rightNode-1);
		Node leftAnswer=identity, rightAnswer=identity;
		forRange(leftNode, rightNode,
				[&](Node node){ leftAnswer=combined(leftAnswer, node); },
				[&](Node node){ rightAnswer=combined(node, rightAnswer); }
				);
		return combined(leftAnswer, rightAnswer);
	}

	template<class T> T reduceRange(int leftNode, int rightNode, T initial, auto const& function /* (T value, Node const& node)  T */) {
		// Reduce function with nodes on the range in arbitrary order.
		// See combinedRange if combiner is not commutative.
		forRange(leftNode, rightNode, [&](Node const& node){ initial=function(std::move(initial), node); });
		return initial;
	}
};

// } ==== End library SegmentTree.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

struct Node{ 
	int sum;
	int special; // minimum sum of any nonempty prefixes, include whole prefix (==sum)
	// therefore special<=sum, or node is empty

	

auto tie() const{return std::tie(
		sum, special
		);}
#define D(op) bool operator op(Node const& other) const{return tie() op other.tie();}
D(==) D(!=)
#undef D

};
Node const empty{0, INT_MAX};

struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left  ){ }

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){ 

#if LOCAL
		static bool inside=false;
		if(not inside){
			inside=true;
			assert(combined(left, empty)==left); assert(combined(empty, left)==left);
			assert(combined(right, empty)==right); assert(combined(empty, right)==right);
			inside=false;
		}
#endif

		parent.sum=left.sum+right.sum;
		assert(left==empty or left.special<=left.sum); assert(right==empty or right.special<=right.sum);
		parent.special=std::min(left.special, (right.special==empty.special ? 0: left.sum)+right.special);
	}

	// equivalent to increase/decrease inclusive suffix of [prefix-sum array]
	void set(int left, int delta){
		left+=offset();
		assert(data[left].sum==data[left].special);
		data[left].special=data[left].sum+=delta;
		combineAll(left);
	}

	int get(){
		return combinedRange(0, offset(), empty).special;
	}

	int getVirtualItem(int right){ // prefix sum to right, inclusive
		return combinedRange(0, right+1, empty).sum;
	}
};


void up(){
	int lenA; std::cin>>lenA;
	int lenB; std::cin>>lenB;
	
	std::map<int, std::vector<int>> aIndices; // value  list of indices in a
	for(int index=0; index<lenA; ++index){
		int a; std::cin>>a;
		aIndices[a].push_back(index);
	}

	std::vector<int> b(lenB);
	for(auto& it: b) {
		std::cin>>it;
	}

	std::sort(begin(b), end(b), std::greater {});

	SegmentTree tree; tree.assign(lenA+1, [&](int i){
		if(i==0) return Node{0, 0};
		return Node{1, 1};
	});

	int64_t addInversion {};

	auto const processBLess=[&](int value){
		int count {};
		while(not b.empty() and b.back()<value){count++; b.pop_back();}
		if(count==0) return;

		addInversion+=count*(int64_t)tree.get();
	};

	auto const processBEqual=[&](int value){
		int count {};
		while(not b.empty() and b.back()==value){count++; b.pop_back();}
		if(count==0) return;

		addInversion+=count*(int64_t)tree.get();
	};

	int64_t selfInversionTwice=0;

	for(auto const& [value, indices]: aIndices){
		processBLess(value);

		for(auto index: indices) tree.set(index+1, -1);
		processBEqual(value);

		for(auto index: indices) selfInversionTwice+=tree.getVirtualItem(index);

		for(auto index: indices) tree.set(index+1, -1);
		tree.set(0, (int)indices.size());

	}

	processBLess(INT_MAX);
	assert(b.empty());

	assert(selfInversionTwice%2==0);
	std::cout<<(selfInversionTwice>>1)+addInversion<<'\n';
}