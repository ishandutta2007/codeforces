// 9
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>


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

	void pushAt(int node){
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
	int lazyAdd;
	int minimum_;
	int minimum() const{return lazyAdd+minimum_;}
};
struct Tree: SegmentTreeTemplate<Node, Tree>{
	using SegmentTreeTemplate::SegmentTreeTemplate;

	Tree(std::vector<int>&& value){
		assign((int)value.size(),[&](int index)->Node{return {0, value[index]};});
	}
	
	static void push(Node& parent, Node& left, Node& right){
		if(auto l=parent.lazyAdd){
			parent.minimum_+=l;
			left.lazyAdd+=l;
			right.lazyAdd+=l;
			parent.lazyAdd=0;
		}
	}
	template<bool first>
	static void combine(Node& parent, Node const& left, Node const& right){
		parent.minimum_=std::min(left.minimum(), right.minimum());
	}

	void set(int index, int value){
		index+=offset();
		pushAll(index);
		data[index].minimum_=value;
		data[index].lazyAdd=0;
		combineAll(index);
	}
	int operator[](int index){
		index+=offset();
		pushAll(index);
		return data[index].minimum();
	}

	void addRange(int left, int right, int value){
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		forRange(left, right, [&](Node& node){ node.lazyAdd+=value; });
		combineAll(left); combineAll(right-1);
	}

	/*
	int get(int left, int right){
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);
		return reduceRange(left, right, 0, [](int result, Node node){ ... });
	}
	*/

	int lastZero(int left, int right){
		if(left==right) return left-1;
		left+=offset(); right+=offset();
		pushAll(left); pushAll(right-1);

		auto const lastZero=[&](int node){
			while(node<offset()){
				pushAt(node);
				node*=2;
				if(data[node+1].minimum()==0) ++node;
			}
			assert(data[node].minimum()==0);
			assert((pushAll(node), data[node].minimum()==0));
			return node-offset();
		};

		std::vector<int> lefts;
		int result=-1;
		forRangeIndex(left, right,[&](int left){
			lefts.push_back(left);
		},[&](int right){
			assert(data[right].minimum()>=0);
			if(data[right].minimum()==0){
				result=lastZero(right);
				return true;
			}
			return false;
		});
		if(result>=0) return result;

		for(auto index=lefts.size(); index--;){
			auto node=lefts[index];
			if(data[node].minimum()==0)
				return lastZero(node);
		}
		return left-1-offset();
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numPocket, numQuery;
	while(std::cin>>numPocket>>numQuery){
		std::vector<int> pockets(numPocket);
		for(auto& it: pockets) std::cin>>it;

		std::vector<int> splits=pockets;
		for(int index=0; index<(int)splits.size(); ++index)
			splits[index]-=index;
		auto const jump=[&](int pos){
			return pos+int(std::upper_bound(begin(splits), end(splits), pos)-begin(splits));
		};
		auto const jumpMultipleNaive=[&](int pos, int times){
			for(int _=0; _<times; ++_)
				pos=jump(pos);
			return pos;
		};
		struct Bounce{int next, length, step, posLeft, nextLeft;};
		// left: at least 0. ==0 iff step(next+1)!=step(next).
		auto const bounce=[&](int pos)->Bounce{
			// move as many steps as possible without changing the next step size
			// (could be 0)
			auto const iterator=std::upper_bound(begin(splits), end(splits), pos);
			if(iterator==splits.end()) return {-1};
			auto const step=int(iterator-begin(splits));
			auto const posLeft=*iterator-pos-1, length=posLeft/step, nextLeft=posLeft%step;
			assert(length>=0); assert(posLeft>=nextLeft); assert(nextLeft>=0);
			return {pos+length*step, length, step, posLeft, nextLeft};
		};
		auto const jumpMultiple=[&](int const start, int const times)->int64_t{
			if(start<splits[0]) return start;
			int pos=start;
			for(int timesLeft=times; timesLeft;){
				auto [next, length, step,_,__]=bounce(pos);
				assert(timesLeft>=0);
				if(next<0)
					return pos+timesLeft*(int64_t)splits.size();
				if(timesLeft<=length+1){pos+=timesLeft*step; timesLeft=0; break;}
				timesLeft-=length+1; pos+=step*(length+1);
			}
			assert(pos==jumpMultipleNaive(start, times));
			return pos;
		};

		struct Query{
			int start, times, index;
		};
		std::vector<Query> queries; queries.reserve(numQuery);
		std::vector<int64_t> result(numQuery, -1);
		std::vector<int64_t> resultNaive; assert((resultNaive.resize(numQuery), true));

		for(int index=0, start, times; index<numQuery; ++index){
			std::cin>>start>>times;
			assert((resultNaive[index]=jumpMultiple(start, times), true));
			if(start<splits[0])
				result[index]=start;
			else if(start>=splits.back())
				result[index]=start+times*(int64_t)splits.size();
			else{
				auto tmp=bounce(start); assert(tmp.next>=0);
				if(tmp.length+1>=times)
					result[index]=start+times*(int64_t)tmp.step;
				else{
					assert(times-tmp.length>=2);
					queries.push_back({tmp.next, times-tmp.length, index});
					assert(jumpMultiple(tmp.next, times-tmp.length)==resultNaive[index]);
				}
			}
		}

		if(queries.empty()){
			for(auto it: result) std::cout<<it<<'\n';
			assert(result==resultNaive);
			continue;
		}
		std::sort(begin(queries), end(queries),[&](Query first, Query sec){return first.start>sec.start;});

		auto const tmp=bounce(splits[0]);
		std::vector<int> pos_{tmp.next};
		std::vector<int> lengthNext_;
		std::vector<int> left_{tmp.nextLeft};
		while(true){
			auto [next, length_, _,__, nextLeft]=bounce(jump(pos_.back()));
			if(next<0) break;
			pos_.push_back(next);
			left_.push_back(nextLeft);
			lengthNext_.push_back(length_+1);
		}
		auto const lengthNext=std::move(lengthNext_);
		std::vector<int> sumLength(lengthNext.size()+1);
		for(int index=0, last=0; index<(int)lengthNext.size(); ++index)
			sumLength[index+1]=last+=lengthNext[index];

		auto const oldPos1=pos_.back(), oldPos2=jump(oldPos1);
		assert(oldPos2<oldPos1+numPocket);
		assert(jump(oldPos2)==oldPos2+numPocket);

		assert(pos_.size()==lengthNext.size()+1);
		assert(pos_.size()==left_.size());

		auto const numPos=(int)pos_.size();
		Tree pos(std::move(pos_)), left(std::move(left_));
		pos_.clear(); left_.clear();
		std::vector<int> starts{0};

		std::vector<std::vector<Query>> queriesFor(numPos);
		for(int index=0;; ++index){
			auto const right=jump(pos[index]);
			while(not queries.empty()){
				auto cur=queries.back();
				assert(cur.times>=2);
				if(cur.start<pos[index]){
					cur.start=jump(cur.start);--cur.times;
					assert(cur.start>=pos[index]);
					queriesFor[index].push_back(cur);
					queries.pop_back();
				}else if(cur.start<=right){
					queriesFor[index].push_back(cur);
					queries.pop_back();
				}else
					break;
			}
			if(queries.empty()) break;
		}
		assert(queries.empty());

		auto const debug=[&]{
			return;
			/*
			for(auto it: pos){ std::cerr<<it<<' ';} std::cerr<<'\n';
			for(auto it: left){ std::cerr<<it<<' ';} std::cerr<<'\n';
			for(auto it: starts){ std::cerr<<it<<' ';} std::cerr<<'\n';
			std::cerr<<"======\n";
			*/
		};
		debug();

		Tree leftQuery(numPos);
		for(int index=0; index<(int)numPos; ++index){
			std::sort(begin(queriesFor[index]), end(queriesFor[index]),[&](Query first, Query sec){return first.start>sec.start;});
			leftQuery.set(index, queriesFor[index].empty() ? INT_MAX: queriesFor[index].back().start-pos[index]);
			assert(leftQuery[index]>=0);
		}

		auto const posJump=[&](int start, int times, int index)->int64_t{
			assert(start==pos[index]);

			/*
			while(index<(int)lengthNext.size() and lengthNext[index]<=times)
				times-=lengthNext[index++];
				*/
			auto const index1=int(std::upper_bound(begin(sumLength), end(sumLength), sumLength[index]+times)-sumLength.begin())-1;
			times-=sumLength[index1]-sumLength[index]; index=index1;

			start=pos[index];
			if(times==0) return start;
			assert(times>0);
			start=jump(start);--times;
			if(times==0) return start;

			auto tmp=bounce(start);
			if(tmp.next<0){
				return start+times*(int64_t)splits.size();
			}
			assert(tmp.length+1>=times);
			return start+(int64_t)times*tmp.step;
		};

		auto const lastQuery=[&](int left_){
			return leftQuery.lastZero(left_, numPos);
		};

		auto const processQueries=[&]{
			while(true){
				auto index=lastQuery(starts.back());
				if(index<starts.back()) break;

				assert(leftQuery[index]==0);
				auto const [start, times, queryIndex]=queriesFor[index].back(); queriesFor[index].pop_back();
				assert(pos[index]==start);
				leftQuery.set(index, queriesFor[index].empty() ? INT_MAX: queriesFor[index].back().start-pos[index]);
				assert(leftQuery[index]>=0);

				result[queryIndex]=posJump(start, times, index);
				assert(result[queryIndex]==jumpMultiple(start, times));
			}
		};
		processQueries();

		auto const findLeftLastZero=[&](int left_, int right)->int{
			return left.lastZero(left_, right);
		};
		auto const stepRange=[&](int left_, int right)->void{
			left.addRange(left_, right, -1);
			leftQuery.addRange(left_, right, -1);
			pos.addRange(left_, right, 1);
		};

		auto startPos0=pos[0];
		while(pos[numPos-1]!=oldPos2){ // could be O(1)
			auto const increment=[&](auto increment, int const index)->void{
				assert(index>=starts.back());
				int i=findLeftLastZero(starts.back(), index);
				if(i<starts.back()){
					stepRange(starts.back(), index+1);
					assert(i==starts.back()-1);
					if(i>=0){
						if(jumpMultiple(pos[i]+1, lengthNext[i])==pos[i+1]){
							starts.pop_back();
							assert(bounce(pos[i]).posLeft==0);
							increment(increment, i); assert(left[i]<0);
							left.set(i, bounce(pos[i]).posLeft); assert(left[i]>=0);
						}else{
							assert(jumpMultiple(pos[i], lengthNext[i])<pos[i+1]);
							assert(jumpMultiple(pos[i]+1, lengthNext[i])>pos[i+1]);
						}
					}
				}else{
					starts.push_back(i+1);
					stepRange(i+1, index+1);
				}
			};
			auto const tmp=pos[numPos-1];
			increment(increment, (int)numPos-1);
			debug();
			assert(pos[numPos-1]==tmp+1);
			processQueries();

			for(int i=starts.back()+1; i<(int)numPos; ++i){
				assert(jumpMultiple(pos[i-1], lengthNext[i-1])==pos[i]);
				assert(left[i-1]==bounce(pos[i-1]).posLeft);
			}
			//assert(std::binary_search(begin(pockets), end(pockets), pos[starts.back()]));
		}
		assert(pos[0]==jump(startPos0));
		assert(starts.size()==1); assert(starts[0]==0);

		for(auto const& it: queriesFor) assert(it.empty());

		assert(result==resultNaive);
		for(auto it: result) std::cout<<it<<'\n';
		//std::cout<<std::flush;
	}
}