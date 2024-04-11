#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<numeric>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

std::vector<std::vector<int>> ad;
std::vector<int> num,low,stsize;
int lastn=0;

int a,b;
int n_isolated_a,n_isolated_b;

void dd(int node,int par){
	num[node]=low[node]=++lastn;
	stsize[node]=1;

	for(int c:ad[node])if(c!=par){
		if(num[c]!=0){
			low[node]=std::min(low[node],num[c]);
		}else{
			dd(c,node);
			low[node]=std::min(low[node],low[c]);
			stsize[node]+=stsize[c];

			if(node==b){
				assert(par==a);
				if(low[c]>=num[node])
					n_isolated_b+=stsize[c];
			}
			if(par<0){
				assert(node==a);
				if(c!=b)
					n_isolated_a+=stsize[c];
			}

		}
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int ntest;std::cin>>ntest;
	while(ntest--){
		int nnode,nedge;std::cin>>nnode>>nedge>>a>>b;
		--a;--b;
		ad.clear();ad.resize(nnode);

		ad[a].push_back(b); ad[b].push_back(a); // does not change the answer
		for(int z=nedge;z--;){
			int u,v;std::cin>>u>>v;--u;--v;
			ad[u].push_back(v);ad[v].push_back(u);
		}

		num.clear(); low.clear(); stsize.clear();
		num.resize(nnode); low.resize(nnode); stsize.resize(nnode);
		assert(ad[a][0]==b);
		n_isolated_a=n_isolated_b=0;
		dd(a,-1);
		std::cout<<n_isolated_b*(int64_t)n_isolated_a<<'\n';
	}
}