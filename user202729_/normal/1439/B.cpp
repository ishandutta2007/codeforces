// ???
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int numNode; std::cin>>numNode;
	int numEdge; std::cin>>numEdge;
	int k; std::cin>>k;
	std::vector<std::vector<int>> add;
	add.clear(); add.resize(numNode);
	for(int _=0, u, v; _<numEdge; _++){
		std::cin>>u>>v;
		--u;--v;
		add[u].push_back(v); add[v].push_back(u);
	}
	
	for(auto& it: add) std::sort(begin(it), end(it));

	//std::vector<char> deleted(numNode);

	std::vector<int> degree(numNode); // -1: removed

	struct S{
		int degree, node;
		bool operator<(S other) const{return degree>other.degree;}; // priority queue->minimum
	};
	std::priority_queue<S> nodes;
	for(int node=0; node<numNode; ++node){
		degree[node]=(int)add[node].size();
		nodes.push({degree[node], node});
	}

	while(not nodes.empty()){
		auto const removeNode=[&](int node){
			for(auto other: add[node]){
				assert(degree[other]!=0);
				if(degree[other]>=0){
					--degree[other];
					nodes.push({degree[other], other});
				} else assert(degree[other]==-1);
			}
			assert(degree[node]>=0);
			degree[node]=-1;
		};

		auto const [curDegree, node]=nodes.top(); nodes.pop();

		if(curDegree!=degree[node]) continue;
		if(degree[node]<k-1){
			removeNode(node);
			continue;
		}else if(degree[node]==k-1){
			add[node].erase(std::remove_if(begin(add[node]), end(add[node]), [&](auto const& it){
				return degree[it]<0;
			}), end(add[node]));
			assert((int)add[node].size()==k-1);

			if(std::all_of(begin(add[node]), end(add[node]), [&](auto const& first){
				if(add[first].size()>add[node].size()*5)
					return std::all_of(begin(add[node]), end(add[node]), [&](auto const& second){
						return first==second or std::binary_search(begin(add[first]), end(add[first]), second);
					});

				// optimization, try to remove log factor
				// (still no better algorithm...)
				add[first].erase(std::remove_if(begin(add[first]), end(add[first]), [&](auto const& it){
					return degree[it]<0;
				}), end(add[first]));
				auto iterator=add[first].begin();
				for(auto other: add[node]) if(other!=first){
					while(iterator!=add[first].end() and *iterator<other) ++iterator;
					if(iterator==add[first].end() or *iterator>other) return false;
				}
				return true;

			})){
				std::cout<<"2\n"<<node+1<<' ';
				for(auto const& it: add[node]){
					std::cout<<it+1<<' ';
				}
				std::cout<<'\n';
				return;
			}else{
				removeNode(node);
				continue;
			}
		}else{
			std::cout<<"1 "<<
			std::count_if(begin(degree), end(degree), [&](auto const& it){
				return it>=0;
			})<<'\n';
			for(int node=0; node<numNode; ++node)
				if(degree[node]>=0) std::cout<<node+1<<' ';
			std::cout<<'\n';
			return;
		}
	}

	std::cout<<"-1\n";


}