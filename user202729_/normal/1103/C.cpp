// {}
//
// Why is it so hard to solve just 1 problem a day...

#ifndef LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

std::vector<std::vector<int>> ad;
std::vector<char> visited,isleaf;
std::vector<int> depth;

std::vector<int> par;

struct diameter_t{
	using Self=diameter_t;
	int len;
	int a,b;
	bool operator<(Self x)const{ return len<x.len; }
} diameter;

struct maxchild_t{
	using Self=maxchild_t;
	int len;
	int a;
	bool operator<(Self x)const{ return len<x.len; }
};

maxchild_t dd(int node,int depthnode){
	// return {maximum depth of some node int this subtree, that node}

	visited[node]=true;
	depth[node]=depthnode;

	maxchild_t max1{depthnode,node},max2{-1,-1};

	for(int child:ad[node])
		if(not visited[child]){
			isleaf[node]=false;
			par[child]=node;
			max2=std::max(max2,
					dd(child,depthnode+1)
					);
			if(max1<max2) std::swap(max1,max2);
		}

	if(max2.len>=0){
		assert(max1.len>=depthnode and max2.len>=depthnode);
		diameter=std::max(diameter,{max1.len+max2.len-2*depthnode,max1.a,max2.a});
	}

	return max1;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int nnode,nedge,k;std::cin>>nnode>>nedge>>k;

	assert(nnode>=4);
	assert(nedge>=1);
	assert(k>=1 and k<=nnode);

	ad.resize(nnode);
	for(int i=nedge;i--;){
		int u,v;std::cin>>u>>v;
		--u;--v;
		ad[u].push_back(v);ad[v].push_back(u);
	}

	//std::mt19937 engine(123456);

	depth.resize(nnode);
	par.resize(nnode);
	//while(true){
	//	auto const root=std::uniform_int_distribution<int>(0,nnode-1)(engine);
	//	for(auto& adx:ad) std::shuffle(begin(adx),end(adx),engine);
		int const root=0;

		par[root]=-1;

		visited.assign(nnode,false);
		isleaf.assign(nnode,true);
		diameter={-1,-1,-1};
		dd(root,0);
		assert(std::all_of(begin(visited),end(visited),[](auto x){ return x; }));
		assert(diameter.len>=0);

		if(diameter.len+1>=(nnode+k-1)/k){
			std::cout<<"PATH\n"<<diameter.len+1<<'\n';

			std::vector<int> para{diameter.a};
			while(para.back()!=root) para.push_back(par[para.back()]);
			std::vector<int> parb{diameter.b};
			while(parb.back()!=root) parb.push_back(par[parb.back()]);

			int lca;
			do{
				lca=para.back();
				para.pop_back();
				parb.pop_back();
			}while(not para.empty() and not parb.empty() and para.back()==parb.back());

			assert(diameter.len==depth[diameter.a]+depth[diameter.b]-2*depth[lca]);

			for(auto x:para) std::cout<<x+1<<' ';
			std::cout<<lca+1;
			std::for_each(parb.rbegin(),parb.rend(),[](int x){ std::cout<<' '<<x+1; });
			std::cout<<'\n';

			return 0;
		}

		assert(std::accumulate(begin(isleaf),end(isleaf),0)>=k); // if I computed correctly

		struct found_cycle_t{ int repr,a,b; };
		std::vector<found_cycle_t> found_cycles;

		for(int node=0;node<nnode;++node)if(isleaf[node]){
			assert(ad[node].size()>=3);
			for(auto i2=begin(ad[node]);i2!=begin(ad[node])+3;++i2){
				for(auto i1=begin(ad[node]);i1!=i2;++i1)
					if((std::abs(depth[*i1]-depth[*i2])+2)%3!=0){
						found_cycles.push_back({node,*i1,*i2});
						goto nextnode;
					}
			}
			assert(false);

nextnode:;
		}

		assert((int)found_cycles.size()>=k);
		std::cout<<"CYCLES\n";
		found_cycles.resize(k);
		for(auto [repr,a,b]:found_cycles){
			if(depth[a]<depth[b]) std::swap(a,b);
			std::cout<<depth[a]-depth[b]+2<<'\n'
				<<repr+1;
			while(true){
				std::cout<<' '<<a+1;
				if(a==b) break;
				a=par[a];
			}
			std::cout<<'\n';
		}
		return 0;


	//}
}