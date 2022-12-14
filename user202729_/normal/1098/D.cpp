#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>



struct SegmentTree{
	struct Node{
		int64_t maxBreak; // this segment will break  iff  sum of previous nodes is <= this value
		int64_t sum;
		int minimum;
	};
	
	std::vector<Node> data;
	SegmentTree(int len): data(len*2, Node{INT64_MIN, 0, INT_MAX}){}

	int nodeAt(int index) const{
		index+=1<<(31 xor __builtin_clz((int)data.size()));
		if(index>=(int)data.size()) index-=int(data.size()/2);
		return index;
	}
	static Node combine(Node left, Node right){
		Node result{
			left.maxBreak,
			left.sum+right.sum,
			std::min(left.minimum, right.minimum)
		};
		if(left.minimum!=INT_MAX) assert(left.minimum<=right.minimum);

		if(right.maxBreak!=INT64_MIN)
			result.maxBreak=std::max(result.maxBreak,
					right.maxBreak-left.sum);
		if(right.minimum!=INT_MAX){
			result.maxBreak=std::max(result.maxBreak,
					((right.minimum-1)>>1)-left.sum);
			// floor division needed here
		}
		return result;
	}
	void combineAll(int node){
		for(node>>=1; node; node>>=1)
			data[node]=combine(data[node<<1], data[node<<1|1]);
	}
	void add(int index, int value){
		auto const node=nodeAt(index);
		assert(data[node].sum==0 and data[node].minimum==INT_MAX);
		assert(data[node].maxBreak==INT64_MIN);
		data[node].sum=data[node].minimum=value;
		combineAll(node);
	}
	void remove(int index){
		auto const node=nodeAt(index);
		assert(data[node].sum>0 and data[node].sum==data[node].minimum);
		assert(data[node].maxBreak==INT64_MIN);
		data[node].sum=0; data[node].minimum=INT_MAX;
		combineAll(node);
	}

	int numSegment(int node=1, int64_t sumBefore=0)const{ // time complexity: log n * return value
		if(data[node].minimum==INT_MAX) return 0;
		if(sumBefore>data[node].maxBreak) return 1;

		int result=0;
		auto const sumMid=sumBefore+data[node*2].sum;

		bool haveLeft=data[node*2].minimum!=INT_MAX, haveRight=data[node*2+1].minimum!=INT_MAX;
		if(haveLeft) result+=numSegment(node*2, sumBefore);
		if(haveRight) result+=numSegment(node*2+1, sumMid);
		if(haveLeft and haveRight and sumMid*2>=data[node*2+1].minimum) --result;
		return result;
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	struct eel{
		int weight;
		int addTime, removeTime;
	};

	struct eelCompare{
		using is_transparent=void;
		bool operator()(eel const& first, eel const& sec) const{return first.weight<sec.weight;};
		bool operator()(eel const& first, int sec) const{return first.weight<sec;};
		bool operator()(int first, eel const& sec) const{return first<sec.weight;};
	};

	int numQuery; std::cin>>numQuery;

	std::vector<eel> eels;
	{
		std::multiset<eel, eelCompare> current;
		for(int time=0;time<numQuery;++time) {
			char type; int weight; std::cin>>type>>weight;
			if(type=='+'){
				current.insert({weight, time, -1});
			}else{
				assert(type=='-');
				auto iterator=current.find(weight);
				auto tmp=*iterator; tmp.removeTime=time;
				eels.push_back(tmp);
				current.erase(iterator);
			}
		}
		eels.insert(eels.end(),begin(current),end(current));
	}
	std::sort(begin(eels),end(eels), eelCompare{});


	struct event{ int index; bool add; };
	std::vector<event> events(numQuery);
	for(int index=0;index<(int)eels.size();++index) {
		events[eels[index].addTime]={index, true};
		if(eels[index].removeTime>=0)
			events[eels[index].removeTime]={index, false};
	}

	SegmentTree tree((int)eels.size());
	int number=0;
	for(auto [index, add]: events){
		if(add) {
			tree.add(index, eels[index].weight);
			++number;
		} else {
			tree.remove(index);
			--number;
		}

		std::cout<<number-tree.numSegment()<<'\n';
	}
}