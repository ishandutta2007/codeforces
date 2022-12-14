#ifndef LOCAL
#define NDEBUG
#endif
#include<climits>
#include<cassert>
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
#include<map>

std::vector<int> /* jump index */ proc(std::vector<int64_t> v /* prefix sums, inclusive */ ){
	std::map<int64_t,int> m; // value -> last index >= current
	std::vector<int> ans(v.size()+1,INT_MAX); // INT_MAX: no jump
	for(auto i=(int)v.size();i;--i){
		auto [iter,succ]=m.insert({v[i-1],i});
		if(!succ){
			ans[i]=iter->second;
			iter->second=i;
		}
	}

	int i=0;
	auto [iter,succ]=m.insert({0LL,0});
	if(!succ){
		ans[i]=iter->second;
	}

	// minsuffix ans
	for(auto i=(int)ans.size()-1;i--;)
		ans[i]=std::min(ans[i],ans[i+1]);
	return ans;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;

	std::vector<int64_t> v1(n),v2(n);
	for(auto vv:{&v1,&v2}){
		int64_t s=0;
		for(auto& x:*vv){
			std::cin>>x;
			s+=x;
			x=s;
		}
	}

	std::vector<int64_t> vs(n);
	std::transform(begin(v1),end(v1),begin(v2),begin(vs),std::plus<int64_t>{});

	auto const p1=proc(v1);
	auto const p2=proc(v2);
	auto const ps=proc(vs);

	std::vector<int> g(n+1,0);
	struct zz{
		int nextind;
		int val;
	};
	auto const nextind_cmp=[](zz a,zz b){return a.nextind<b.nextind;};
	std::vector<std::vector<zz>> g1(n+1),g2(n+1);

	g[0]=0;

	for(int i=0;i<n;++i){
		auto proc2=[&](int x,int y,int cnt){
			if(x==INT_MAX or y==INT_MAX)
				return;
			if(x==y){
				g[x]=std::max(g[x],cnt);
			}else if(x<y){
				g2[x].push_back({y,cnt});
			}else{
				g1[y].push_back({x,cnt});
			}
		};

		proc2(i+1,i+1,g[i]);
		proc2(p1[i],i,g[i]+1);
		proc2(i,p2[i],g[i]+1);
		proc2(ps[i],ps[i],g[i]+1);

		g1[i].erase(std::remove_if(begin(g1[i]),end(g1[i]),[gi=g[i]](zz z){return z.val<=gi;}),end(g1[i]));
		g2[i].erase(std::remove_if(begin(g2[i]),end(g2[i]),[gi=g[i]](zz z){return z.val<=gi;}),end(g2[i]));

		if(not g1[i].empty()){
			auto [nxt,cnt]=*std::min_element(begin(g1[i]),end(g1[i]),nextind_cmp);
			proc2(nxt,i+1,cnt);
			proc2(nxt,p2[i],cnt+1);
		}
		if(not g2[i].empty()){
			auto [nxt,cnt]=*std::min_element(begin(g2[i]),end(g2[i]),nextind_cmp);
			proc2(i+1,nxt,cnt);
			proc2(p1[i],nxt,cnt+1);
		}
	}

	std::cout<<g[n]<<'\n';
}