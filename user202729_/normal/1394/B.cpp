// there's an ongoing contest...
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<int> data;
int result;

auto const maxVariable=9*10/2;
std::array<std::bitset<maxVariable>, maxVariable> conflict{}; // note: not symmetric [a][b] b<a

int encode(int outDegree, int order){
	assert(0<=order); assert(order<outDegree);
	return ((outDegree*(outDegree-1))>>1)+order;
}

void work(int index){
	if(index==(int)data.size()){
		for(int i=0; i<index; ++i){
			auto const a=encode(i+1, data[i]);
			if(conflict[a][a])
				return;

			for(int j=0; j<i; ++j){
				assert(j<i);
				auto const b=encode(j+1, data[j]);
				assert(b<a);

				if(conflict[a][b])
					return;
				else assert(not conflict[b][a]);
			}
		}

		++result;
		for(auto it: data) assert(std::cerr<<it<<' ');
		assert(std::cerr<<'\n');
		return;
	}
	for(data[index]=0; data[index]<=index; data[index]++){
		work(index+1);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numNode, numEdge, maxDegree; std::cin>>numNode>>numEdge>>maxDegree;

	struct Edge{int node, weight;};
	std::vector<std::vector<Edge>> add(numNode);
	for(int _=0; _<numEdge; ++_){
		int u, v, w; std::cin>>u>>v>>w;
		--u;--v;
		add[u].push_back({v, w});
		// add[v].push_back({u, w}); // ...????
	}


	std::vector<std::array<int, maxVariable>> condition(numNode); // for each node, only one condition available can be true

	for(int node=0; node<numNode; ++node){
		auto& it=add[node];
		std::sort(begin(it), end(it), [&](auto const& first, auto const& sec){
			return first.weight<sec.weight;
		});
		for(int order=0; order<(int)it.size(); ++order){
			auto const [node, _weight]=it[order];
			condition[node][encode((int)it.size(), order)]++;
		}
	}

	for(auto& it: condition)
		for(int a=0; a<maxVariable; ++a) if(it[a]){
			if(it[a]==1){
				for(int b=0; b<a; ++b) if(it[b])
					conflict[a][b]=true;
			}else{
				assert(it[a]>1);
				conflict[a][a]=true;
			}
		}

	result=0;
	data.resize(maxDegree);
	work(0);
	std::cout<<result<<'\n';
	return 0;
}