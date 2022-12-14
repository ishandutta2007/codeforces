#include<iostream>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> ad;
std::vector<int64_t> beauty;

int const mod=1000000007;

int64_t gcd(int64_t x,int64_t y){
	return y==0?x:gcd(y,x%y);
}

struct ResultRange{
	int cnt;int64_t gcd;
};
std::vector<std::vector<ResultRange>> res;

void dfs(int a){
	auto const& resa=res[a];
	for(int b:ad[a]){
		ad[b].erase(std::find(begin(ad[b]),end(ad[b]),a));
		std::vector<ResultRange> resb;
		resb.reserve(resa.size()+1);
		int64_t g=beauty[b];
		resb.push_back({1,g});
		for(ResultRange r:resa){
			g=gcd(g,r.gcd);
			if(g==resb.back().gcd)
				resb.back().cnt+=r.cnt;
			else
				resb.push_back({r.cnt,g});
		}
		res[b]=std::move(resb);
		dfs(b);
	}
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	beauty.resize(n);for(auto& y:beauty)std::cin>>y;
	ad.resize(n);
	for(int u,v,_=n-1;_--;){
		std::cin>>u>>v;--u;--v;
		ad[u].push_back(v);
		ad[v].push_back(u);
	}

	res.resize(n);
	res[0].push_back({1,beauty[0]});
	dfs(0);
	
	int ans=0;
	for(int i=0;i<n;++i)
		for(auto r:res[i])
			ans=int((ans+r.gcd%mod*r.cnt)%mod);
	std::cout<<ans<<'\n';
}