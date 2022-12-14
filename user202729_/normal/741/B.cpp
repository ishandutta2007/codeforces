#ifndef LOCAL
#define NDEBUG
#endif
#include<algorithm>
#include<vector>
#include<climits>
#include<cassert>
#include<iostream>

struct DSU{
	std::vector<int> p;
	DSU():p(){}
	DSU(int n):p(){reset(n);}
	void reset(int n){
		p.resize(n);
		while(n--)p[n]=n;
	}
	int root(int x){
		return p[x]!=x?p[x]=root(p[x]):x;
	}
	void join(int a,int b){ // let root(a) be the root
		p[root(b)]=root(a);
	}
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n,m,maxw;std::cin>>n>>m>>maxw;
	std::vector<int> weight(n);for(int& x:weight)std::cin>>x;
	std::vector<int> beauty(n);for(int& x:beauty)std::cin>>x;
	DSU d(n);
	for(int z=m;z--;){
		int u,v;std::cin>>u>>v;--u;--v;
		d.join(u,v);
	}

	std::vector<std::vector<std::pair<int,int>>> comps(n);
	for(int i=0;i<n;++i)
		comps[d.root(i)].push_back({weight[i],beauty[i]});

	std::vector<int> dp(maxw+1,INT_MIN);dp[0]=0;
	// INT_MIN < - sum weights

	for(auto const& cp:comps)if(!cp.empty()){
		for(auto w=dp.size();w--;){
			int twt=0,tbt=0;
			for(auto x:cp){
				auto [weight,beauty]=x;
				if(w+weight<dp.size())
					dp[w+weight]=std::max(dp[w+weight],dp[w]+beauty);
				twt+=weight;
				tbt+=beauty;
			}
			if(w+twt<dp.size())
				dp[w+twt]=std::max(dp[w+twt],dp[w]+tbt);
		}
	}
	std::cout<<*std::max_element(begin(dp),end(dp))<<'\n';
}