#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int number; std::cin>>number;
	std::vector<int> target(number);
	for(int i=0; i<number; ++i){
		std::cin>>target[i];
		--target[i];
		assert(0<=target[i]); assert(target[i]<number);
		assert(std::find(begin(target), end(target), target[i])==target.begin()+i);
	}


	std::vector<std::vector<int>> add;
	add.clear(); add.resize(number);
	for(int _=0, u, v; _<number-1; _++){
		std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v);
	}
	
	for(auto& it: add)
		std::sort(begin(it), end(it), [&](auto const& first, auto const& sec){
			return target[first]<target[sec]; // this does work
		});

	std::vector<int> order(number);
	std::vector<int> pos(number); // should have been constructed later when label is constructed
	int curOrder=0;
	auto const dfs=[&](auto dfs, int node)->void{
		order[node]=curOrder++;
		pos[order[node]]=node;
		for(auto other: add[node])
			dfs(dfs, other);
	};
	dfs(dfs, 0);
	assert(curOrder==number);

	int64_t numStep{};
	auto label=order;
	
	// emulate it from the beginning on (label, pos) until label=>target
	std::vector<int> chain{0};
	std::deque<int> chainLabel{0};
	assert(label[0]==0); assert(pos[0]==0);
	label[0]=pos[0]=-1;

	std::vector<int> lockedPosition(number); // in the emulation, etc.
	// include those pushed into the chain

	auto const extendChain=[&]{ // all the way to the bottom, therefore idempotent
		int node=chain.back();
		while(assert(node==chain.back()),
				lockedPosition[node]!=(int)add[node].size()){
			chain.push_back(node=add[node][lockedPosition[node]++]);
			assert(label[node]>=0);
			chainLabel.push_back(label[node]);

			assert(chain.size()==chainLabel.size());

			assert(pos[label[node]]==node);
			pos[label[node]]=-1;
			label[node]=-1;
		}
	};

	auto const popChain=[&]{
		// do **not** revert lockedPosition
		pos[label[chain.back()]=chainLabel.back()]=chain.back();
		chain.pop_back(); chainLabel.pop_back();
	};

	auto const pushValue=[&]{
		assert(chain.size()>1);
		numStep+=(int)chain.size()-1;

		assert(chainLabel[0]==chainLabel.front());
		chainLabel.push_back(chainLabel[0]);
		chainLabel.pop_front();

		assert(chain.size()>1);
		popChain();
	};

	assert(chainLabel[0]==0); assert(chain[0]==0);
	for(int value=0; value<target[0]-1; ++value){
		assert(chainLabel[0]==value); assert(chain[0]==0);
		extendChain();
		pushValue();
		assert(chainLabel[0]==value+1); assert(chain[0]==0);
	}

	extendChain();
	if(target[0]!=chainLabel[0]){
		assert(target[0]==chainLabel[0]+1);
		while(chain.size()>1 and target[chain.back()]!=chainLabel[0]){
			assert(chain.size()>1);
			popChain();
		}
		if(chain.size()==1){
			assert(target[0]==chainLabel[0]+1); assert(chain.back()==0);
			// therefore
			assert(target[chain.back()]!=chainLabel[0]);

			std::cout<<"NO\n";
			return 0;
		}else{
			pushValue();
			assert(target[0]==chainLabel[0]);
			assert(target[chain.back()]==chainLabel.back());
		}
	}

	while(not chain.empty()) popChain();
	for(auto it: label) assert(it>=0);
	for(auto it: pos) assert(it>=0);
	if(target!=label){
		std::cout<<"NO\n";
		return 0;
	}else{
		std::cout<<"YES\n"<<numStep<<'\n';
		for(auto const& it: order){
			std::cout<<it+1<<' ';
		}
		std::cout<<'\n';
		
	}

}