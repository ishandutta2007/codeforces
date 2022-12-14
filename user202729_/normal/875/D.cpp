#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

template <class Node, class Detail>
struct SegmentTreeTemplate{
	std::vector<Node> data;

	SegmentTreeTemplate(){}
	SegmentTreeTemplate(int number){ assign(number); }
	SegmentTreeTemplate(auto&& container){ assign(container.begin(), container.end()); }
	template<class First, class Last, class=decltype(std::declval<First>()[0])>
	SegmentTreeTemplate(First first, Last last){ assign(first, last); }
	SegmentTreeTemplate(int number, Node const& node){ assign(number, node); }
	//SegmentTreeTemplate(int number, auto const& generator){ assign(number, generator); }

	// size=number, empty
	void assign(int number){
		assign(number, Node{});
	}
	template<class First, class Last, class=decltype(std::declval<First>()[0])>
	void assign(First first, Last last){
		assign([&](int index){ return first[index]; }, int(last-first));
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
		for(int i=number; --i;) Detail::combine(data[i], data[i<<1], data[i<<1|1]);
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
		else return f(std::forward<T>(t), layer);
	}

	public:
	static void forStrictAncestorIndexDown(int node,auto const& fn){ // fn returns true to break loop
		for(int shift=31^__builtin_clz(node);shift;--shift)
			if(IS_TRUE(fn(node>>shift))) break;
	}
	static void forStrictAncestorIndexUp(int node,auto const& fn){
		for(int y=node>>1;y;y>>=1)
			if(IS_TRUE(fn(y))) break;
	}
	static void forRangeIndex(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
		// leftfn is called from left to right on left nodes
		// rightfn is called from right to left on right nodes
		int layer=0;
		while(leftNode<rightNode){
			if(leftNode&1) if(IS_TRUE(invokeWithOptionalLayer(leftfn, leftNode++, layer))) break;
			if(rightNode&1) if(IS_TRUE(invokeWithOptionalLayer(rightfn, --rightNode, layer))) break;
			leftNode>>=1;rightNode>>=1; ++layer;
		}
	}
#undef IS_TRUE

	static void forRangeIndex(int leftNode, int rightNode, auto const& fn){
		forRangeIndex(leftNode,rightNode,fn,fn);
	}
	int offset()const{ return int(data.size()/2u); }

	void pushAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexDown(node, [&](int it){
			//if constexpr(std::is_invocable_v<decltype(Detail::push), Node, Node, Node>)
				Detail::push(data[it], data[it<<1], data[it<<1|1]);
			//else{
			//	Detail::push(data[it], data[it<<1]);
			//	Detail::push(data[it], data[it<<1|1]);
			//}
		});
	}
	void combineAll(int node){
		assert(node>=offset());
		forStrictAncestorIndexUp(node, [&](int it){
			Detail::combine(data[it], data[it<<1], data[it<<1|1]);
		});
	}
	void forRange(int leftNode, int rightNode, auto const& leftfn, auto const& rightfn){
		assert(leftNode>=offset());
		assert(rightNode>=offset());
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
	int lazy; // add, above minimum_
	int minimum_, count=1;
	int minimum() const{return minimum_+lazy;}
};
struct SegmentTree: SegmentTreeTemplate<Node, SegmentTree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;
	
	static void push(Node& parent, Node& left , Node& right ){
		if(auto const l=parent.lazy){
			parent.minimum_+=l;
			left.lazy+=l;
			right.lazy+=l;
			parent.lazy=0;
		}
	}
	static void combine(Node& parent, Node const& left, Node const& right){
		parent.minimum_=std::min(left.minimum(), right.minimum());
		parent.count=
			(parent.minimum_==left.minimum() ? left.count: 0)+
			(parent.minimum_==right.minimum() ? right.count: 0);
	}

	void set(int left, int right, int delta){
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		forRange(left, right, [&](Node& node){ 
			node.lazy+=delta;
		});
		combineAll(left); combineAll(right-1);
	}

	int get(int left, int right){
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		Node result=reduceRange(left, right, Node{0, INT_MAX, 0}, [](Node result, Node node){
			auto const tmp=result;
			combine(result, tmp, node);
			return result;
		});
		assert(result.minimum()!=INT_MAX);
		assert(result.minimum()>=0);
		return result.minimum()==0 ? result.count: 0;
	}
};


int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> data(number);
	for(auto & it: data) std::cin>>it;

	auto const compute=[&]{ // index -> length (minimum=0)
		struct Item{int orRange, left;};
		std::vector<Item> items{{0, 0}}; // left: minimum left with a particular orRange,
		std::vector<int> result((int)data.size());
		for(int index=0; index<(int)data.size(); ++index){
			auto const cur=data[index];
			for(auto &[orRange, left]: items) orRange|=cur;
			items.push_back({cur, index});

			auto out=++items.begin();
			std::for_each(out, items.end(),[&](auto item){
				if(item.orRange!=out[-1].orRange)
					*out++=item;
			});
			items.erase(out, items.end());

			result[index]=index-items.back().left;
		}
		return result;
	};

	auto left=compute();
	std::reverse(begin(data), end(data));
	auto right=compute();
	std::reverse(begin(right), end(right));

	struct Line{
		int y, left, right, delta; // delta 1: lower y
		bool operator<(Line other) const{return y<other.y;}
	};
	std::vector<Line> lines; lines.reserve(data.size()*2);
	for(int index=0; index<(int)data.size(); ++index){
		lines.push_back({index, index-left[index], index+1, 1});
		lines.push_back({index+1+right[index], index-left[index], index+1, -1});
	}
	std::sort(begin(lines), end(lines));
	SegmentTree tree(number);
	int lasty=0;
	int64_t result{};
	for(auto [y, left, right, delta]: lines){
		assert(y>=lasty);
		if(y!=lasty){
			result+=int64_t(y-lasty)*tree.get(0, number);
			lasty=y;
		}

		tree.set(left, right, delta);
	}

	result-=int64_t(number-1)*number/2;
	std::cout<<result<<'\n';

}