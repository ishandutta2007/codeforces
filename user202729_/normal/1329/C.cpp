// (still) unproven, but (probably) passes sample test cases
#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

int startHeight, resultHeight;
std::vector<int> data;
std::vector<int> operations;

void work(int root){
	if(root>=(int)data.size() or data[root]==0) return;

	while(true){
		auto node=root;

		auto const getChild=[](int node, bool other=false){
			node=node*2+1; if(other xor (data[node+1]>data[node])) ++node;
			return node;
		};
		assert(data[root]!=0);
		while(node*2+2<(int)data.size() and (data[node*2+1]!=0 or data[node*2+2]!=0))
			node=getChild(node);

		assert(data[node]!=0);
		if(node<(1<<resultHeight)-1){
			work(root*2+1); work(root*2+2);
			return;
		}else{
			operations.push_back(root);
			auto node=root;
			while(node*2+2<(int)data.size() and (data[node*2+1]!=0 or data[node*2+2]!=0)){
				auto const next=getChild(node);
				data[node]=data[next];
				node=next;
			}
			assert(data[node]!=0);
			data[node]=0;
		}
	}
}

void up(){
	std::cin>>startHeight>>resultHeight;
	data.resize((1<<startHeight)-1);
	for(auto & it: data) std::cin>>it;

	operations.clear();
	operations.reserve((1<<startHeight)-(1<<resultHeight));
	work(0);
	assert((int)operations.size()==((1<<startHeight)-(1<<resultHeight)));

	auto const iterator=(1<<resultHeight)-1+begin(data);
	assert(std::none_of(begin(data), iterator, [&](auto it){return it==0;}));
	assert(std::all_of(iterator, end(data), [&](auto it){return it==0;}));
	std::cout<<std::accumulate(begin(data), iterator,(int64_t)0)<<'\n';
	for(auto it: operations) std::cout<<it+1<<' ';
	std::cout<<'\n';
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}