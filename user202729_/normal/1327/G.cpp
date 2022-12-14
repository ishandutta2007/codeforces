// wrong algorithm... now fixed. :(
// but taking about half an hour to find and fix the INT_MIN bug is still terribly slow.

// UPD: more constant optimization. Might still TLE.
// should look for algorithmic optimization instead...

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int const numChar=14;

struct AhoCorasick{
	using NodeIndex=int;
	struct Node{
		NodeIndex sfxLink;
		int64_t cost; // minimum len of a dict word reachable via sfxLink, or 0
		std::array<NodeIndex,numChar> child;
	};
	std::vector<Node> data;

	bool constructed=false;

	AhoCorasick(){
		newNode(); // root
	}

	NodeIndex newNode(){
		assert(!constructed);
		data.push_back({-1,0});
		for(auto & x: data.back().child) x=-1;
		assert(NodeIndex(data.size()-1)>=0);
		return NodeIndex(data.size()-1);
	}

	NodeIndex child(NodeIndex node,int letter){
		assert(0<=letter&&letter<numChar);
		assert(0<=node);
		if(data[node].child[letter]<0){
			assert(!constructed);
			NodeIndex z=newNode();
			assert(z>=0);
			data[node].child[letter]=z;
			assert(data[node].child[letter]>=0);
		}else{
			assert(data[node].child[letter]>=0);
		}
		assert(data[node].child[letter]>=0);
		return data[node].child[letter];
	}

	NodeIndex next(int node, int direction) const{
		return data[node].child[direction];
	}

	void build(){
		assert(!constructed);
		constructed=true;

		std::queue<NodeIndex> q;
		q.push(0);
		while(!q.empty()){
			NodeIndex node=q.front();q.pop();
			assert(node==0||data[node].sfxLink>=0);
			for(int letter=0;letter<numChar;++letter){
				NodeIndex& child_=data[node].child[letter];
				if(child_<0){
					child_=node==0 ? 0: data[data[node].sfxLink].child[letter];
					assert(child_>=0);
					continue;
				}

				// construct sfxLink for child_
				NodeIndex z=data[node].sfxLink;
				while(z>=0&&data[z].child[letter]<0)
					z=data[z].sfxLink;
				if(z<0)
					data[child_].sfxLink=0;
				else
					data[child_].sfxLink=data[z].child[letter];

				// construct cost for child_
				data[child_].cost+=data[data[child_].sfxLink].cost;
				q.push(child_);
			}
		}
	}

};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numString; std::cin>>numString;

	AhoCorasick tree;
	std::string string;
	for(int _=0;_<numString;++_) {
		int cost;
		std::cin>>string>>cost;
		assert(std::abs(cost)<=1000000);
		
		int node=0;
		for(auto ch: string) node=tree.child(node, ch-'a');
		tree.data[node].cost+=cost;
	}
	tree.build();
	assert(tree.data[0].cost==0);

	int const numMask=1<<numChar;
	std::vector<std::vector<int64_t>> value(numMask, std::vector<int64_t>(tree.data.size(), INT64_MIN));
	// [mask of used characters][node] = maximum
	value[0][0]=0;


	struct item{
		int node; int64_t addedValue;
	};
	std::vector<item> pending(tree.data.size());

	auto const resetPending=[&]{
		assert(pending.size()==tree.data.size());
		for(int node=0;node<(int)pending.size();++node) pending[node]={node, 0};
	};
	resetPending();

	auto const applyPending=[&]{
		std::vector<int64_t> newValue(tree.data.size());

		for(auto mask=numMask; mask--;){
			// note: is it more memory efficient to swap node and mask?

			std::fill(begin(newValue),end(newValue), INT64_MIN);
			for(int node=0;node<(int)tree.data.size();++node) {
				auto const cost=value[mask][node];
				if(cost==INT64_MIN) continue;

				auto const [newNode, addedCost]=pending[node];
				assert(newNode>=0);
				newValue[newNode]=std::max(newValue[newNode], cost+addedCost);
			}
			std::swap(value[mask], newValue);
		}

		resetPending();
	};

	auto const addPendingChar=[&](int direction){
		for(auto &[node, value]: pending){
			node=tree.next(node, direction);
			value+=tree.data[node].cost;
		}
	};


	std::cin>>string;
	for(auto ch: string){
		if(ch=='?'){
			applyPending();

			for(auto mask=numMask; mask--;){
				// now value at mask>mask is new, value at mask<=mask is old
				for(int node=0;node<(int)tree.data.size();++node) {
					auto const cost=value[mask][node]; if(cost==INT64_MIN) continue;
					for(auto tmp=(numMask-1) xor mask; tmp; tmp-=tmp&-tmp) {
						auto const ch=__builtin_ctz(tmp);
						auto const newNode=tree.next(node, ch);
						auto& it=value[mask|1<<ch][newNode];
						it=std::max(it, cost+tree.data[newNode].cost);
					}
				}
				std::fill(begin(value[mask]),end(value[mask]), INT64_MIN);
				// now value at mask>=mask is new, value at mask<mask is old
			}
		}else{
			addPendingChar(ch-'a');
		}
	}
	applyPending();

	std::cout<<std::accumulate(begin(value),end(value), INT64_MIN,[&](int64_t value, auto const& it){
		return std::max(value, *std::max_element(begin(it),end(it)));
	})
	<<'\n';
}