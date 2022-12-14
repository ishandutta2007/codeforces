// time-limit: 3000
// problem-url: https://codeforces.com/contest/1609/problem/E
//
// hurry up or else I won't have time to solve harder problems
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



// way too slow...???

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
	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
		forRangeIndex(leftNode, rightNode,
				[&](auto it, auto layer){ return invokeWithOptionalLayer(leftfn,  data[it], layer); },
				[&](auto it, auto layer){ return invokeWithOptionalLayer(rightfn, data[it], layer); });
	}
	void forRange(int leftNode, int rightNode, auto const& fn){
		forRange(leftNode,rightNode,fn,fn);
	}

	template<class T> T reduceRange(int leftNode, int rightNode, T initial, auto const& function) {
		forRange(leftNode, rightNode, [&](Node const& node){ initial=function(std::move(initial), node); });
		return initial;
	}
};

struct Node{
	int a, b, c, first, last, all; // confusing name, see draft paper for details (don't keep anyway)
	auto const tie() const{return std::tie(a, b, c, first, last, all);}
	
#define D(op) bool operator op(auto const& other) const{return tie() op other.tie();}
D(==) D(!=)
D(<) D(>) D(<=) D(>=)
#undef D

	char toChar() const;

};
Node NodeA{1, 0, 0, 0, 0, 0};
Node NodeB{0, 1, 0, 0, 0, 0};
Node NodeC{0, 0, 1, 0, 0, 0};

char Node::toChar() const{
	if(a){assert(*this==NodeA); return'a';}
	if(b){assert(*this==NodeB); return'b';}
	if(c){assert(*this==NodeC); return'c';}
	assert(false);
}

struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& _){ }

	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		parent.a=left.a+right.a;
		parent.b=left.b+right.b;
		parent.c=left.c+right.c;
		parent.first=std::min(left.first+right.b, left.a+right.first);
		parent.last=std::min(left.last+right.c, left.b+right.last);
		parent.all=std::min({
			left.all+right.c,
				left.first+right.last,
				left.a+right.all
		});
	}

	static Node combine_(Node const& left, Node const& right){
		Node result;
		combine<false>(result, left, right);
		return result;
	}

	// other methods
	void set(int index, Node value){
		index+=offset();
		data[index]=value;
		combineAll(index);
	}

	Node get(int left, int right){
		assert(left<right);
		left+=offset(); right+=offset();
		if(left+1==right) return data[left];
		Node leftAnswer =data[left++], rightAnswer =data[--right];
		forRange(left, right,
				[&](Node x){leftAnswer=combine_(leftAnswer, x);},
				[&](Node x){rightAnswer=combine_(x, rightAnswer);}
				);
		return combine_(leftAnswer, rightAnswer);
	}
};
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	
	int n; std::cin>>n;
	int numQuery; std::cin>>numQuery;
	std::string s; std::cin>>s;

	auto const nodeOf=[&](char ch){
		switch(ch){
			case'a': return NodeA;
			case'b': return NodeB;
			case'c': return NodeC;
			default: assert(false); __builtin_unreachable();
		}
	};

	SegmentTree tree;
	tree.assign(n, [&](int i)->Node{
		return nodeOf(s[i]);
	});
	s.clear();

	for(int _=0; _<numQuery; ++_){
		int pos; std::cin>>pos; --pos;
		char ch; std::cin>>ch;

		assert([&]{
			return true;
			for(int i=0; i<n; ++i)
				std::cout<<tree.get(i, i+1).toChar()<<' ';
			std::cout<<'\n';
			return true;
		}());

		tree.set(pos, nodeOf(ch));
		std::cout<<tree.get(0, n).all<<'\n';
	}
	
}