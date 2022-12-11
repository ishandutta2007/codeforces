#include <bits/stdc++.h>
using namespace std;
constexpr int max_n=1000000;
constexpr int max_m=max_n+2;
vector<int> g[max_n+1];
int par[max_n+1],dep[max_n+1],cnt[max_n+1];
pair<int,int>edg[max_m+1];
void dfs(const int u,const int p){
	par[u]=p,dep[u]=dep[p]+1;
	for(const int&v:g[u])
		if(!par[v])
			dfs(v,u);
}
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		g[i].clear(),par[i]=0,cnt[i]=0;
	for(int i=1; i<=m; ++i){
		scanf("%d%d",&edg[i].first,&edg[i].second);
		g[edg[i].first].emplace_back(edg[i].second);
		g[edg[i].second].emplace_back(edg[i].first);
	}
	dep[1]=0;
	dfs(1,1);
	vector<pair<int,int> >e;
	if(m<=n+1){
		for(int i=1; i<=m; ++i)
			putchar((par[edg[i].first]!=edg[i].second&&par[edg[i].second]!=edg[i].first)|'0');
		putchar('\n');
		return;
	}
	for(int i=1; i<=m; ++i)
		if(par[edg[i].first]!=edg[i].second&&par[edg[i].second]!=edg[i].first)
			e.emplace_back(edg[i].first,edg[i].second),++cnt[edg[i].first],++cnt[edg[i].second];
	int now=0,p=0;
	for(int i=1; i<=n; ++i)
		if(cnt[i]==2){
			++p;
			if(!now||dep[i]>dep[now])
				now=i;
		}
	if(p==3){
		for(const pair<int,int>&p:e)
			if(p.first==now){
				par[p.first]=p.second;
				break;
			}
			else
				if(p.second==now){
					par[p.second]=p.first;
					break;
				}
	}
	for(int i=1; i<=m; ++i)
		putchar((par[edg[i].first]!=edg[i].second&&par[edg[i].second]!=edg[i].first)|'0');
	putchar('\n');
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}