// time-limit: 2000
// problem-url: https://codeforces.com/contest/1615/problem/E

// proven
// (why prove anyway? It's contest)

// still there might be implementation bug


#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
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
		// NOTE bad things may happen if there's lazy (propagation) data inside node
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
struct Item{
	int value, index;
	
auto tie() const{return std::tie(value);}
#define D(op) bool operator op(Item const& other) const{return tie() op other.tie();}
D(==) D(!=)
	D(<) D(>) D(<=) D(>=)
#undef D

};

struct Node{
	int add=0; // as usual, lazy is above data
	// TODO refactor that SegmentTreeTemplate thing... this is not good
	Item maximum_;
	Item maximum() const{return {.value=maximum_.value+add,.index=maximum_.index};}
};
struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left , Node& right ){
		if(parent.add){
			left.add+=parent.add; right.add+=parent.add;
			parent.maximum_.value+=parent.add; parent.add=0;
		}
	}
	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		parent.maximum_=std::max(left.maximum(), right.maximum());
	}

	// other methods
	void add(int left, int right, int delta){
		if(left==right) return;
		assert(left<=right);
		left+=offset(); right+=offset();
		forRange(left, right, [&](Node& node){node.add+=delta;});
		combineAll(left); combineAll(right-1);
	}

	/*
	Item get(int left, int right){
		assert(left<right);
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		return combinedRange(left, right).maximum_;
	}
	*/

};

std::vector<std::vector<int>> add;

std::vector<int> left, right; //[node]=span of the leaves in this subtree in (leaves)
std::vector<int> leaves;
std::vector<int> parOf;

void work(int node, int par){
	parOf[node]=par;
	left[node]=(int)leaves.size();
	bool isLeaf=true;
	for(auto other: add[node]) if(other!=par){
		isLeaf=false;
		work(other, node);
	}
	if(isLeaf){
		leaves.push_back(node);
	}
	right[node]=(int)leaves.size();
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	int limit; std::cin>>limit;
	add.clear(); add.resize(number);
	for(int _=0, u, v; _<number-1; _++){
		std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v); add[v].push_back(u);
	}

	parOf.resize(number);
	left.resize(number);
	right.resize(number);
	work(0, -1);

	//std::vector<int> value(leaves.size());
	SegmentTree value;
	value.assign((int)leaves.size(), [&](int index){
		return Node{
			.add=0,
				.maximum_=Item{.value=0,.index=index}
		};
	});

	auto const addValue=[&](int left, int right, int delta){
		/*
		for(int tmp=left; tmp<right; ++tmp)
			value[tmp]+=delta;
			*/
		value.add(left, right, delta);
	};

	for(int node=0; node<number; ++node)
		addValue(left[node], right[node], 1);

	std::vector<char> marked(number); // removed (blue cannot color this one)
	
	auto result=INT64_MIN;
	int maxBlue=number;
	for(int red=1; red<=limit; ++red){
		// greedily remove one vertex (proven correct, mentioned above)

		//if(not queue.empty()){
			//auto node=queue.top(); queue.pop();
			//auto const leafIndex=int(std::max_element(begin(value), end(value))-value.begin());
			auto const leafIndex=value.data[1].maximum().index;
			auto const node=leaves[leafIndex];
			if(not marked[node]){
				assert(not marked[node]);

				int par=node;
				while(true){
					assert(not marked[par]);

					addValue(left[par], right[par], -1);
					marked[par]=true;
					maxBlue--;

					par=parOf[par];
					if(par<0 or marked[par]) break;
				}
			}else{
				// otherwise there's no leaf left
				assert(maxBlue==0);
			}

		 auto const blue=std::min(maxBlue, number>>1);
		 auto const white=number-red-blue;
		 result=std::max(result, white*int64_t(red-blue));
	}
	std::cout<<result<<'\n';
}