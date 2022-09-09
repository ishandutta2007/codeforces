#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pb push_back
#define ldb double
const int N=200050;
vector<pii> E[N],cyc;
int par[N],up[N],dep[N];
bool was[N];
void NO(){printf("NO\n");exit(0);}
ldb ans[N];
void DFS(int u){
	was[u]=1;
	for(pii e:E[u]){
		int v=e.first,w=e.second;
		if(!was[v]){
			dep[v]=dep[u]+1;
			up[v]=w;
			par[v]=u;
			DFS(v);
		}else{
			if(dep[u]%2==dep[v]%2&&cyc.empty()){
				for(int i=u;i!=v;i=par[i])cyc.pb({i,up[i]});
				cyc.pb({v,w});
			}
		}
	}
}
bool done[N];
int side[N];
vector<int> nodes[2];
void Expand(int u){
	done[u]=1;
	nodes[side[u]].pb(u);
	for(pii e:E[u]){
		int v=e.first,w=e.second;
		if(!done[v]){
			ans[v]=w-ans[u];
			side[v]=side[u]^1;
			Expand(v);
		}else if(ans[v]!=w-ans[u])NO();
	}
}
void Solve(int u){
	cyc.clear();
	DFS(u);
	if(cyc.size()){
		int sum=0;
		for(int i=0;i<cyc.size();i++)sum+=cyc[i].second*(i%2==0?1:-1);
		ans[cyc[0].first]=sum*0.5;
		Expand(cyc[0].first);
	}else{
		nodes[0].clear();nodes[1].clear();
		Expand(u);
		for(int z=0;z<2;z++)sort(nodes[z].begin(),nodes[z].end(),[&](int i,int j){return ans[i]<ans[j];});
		int x1=0,cnt1=0,cnt2=0,sz1=nodes[0].size(),sz2=nodes[1].size();
		while(1){
			while(cnt1<sz1&&ans[nodes[0][cnt1]]<-x1)cnt1++;
			while(cnt1>0&&ans[nodes[0][cnt1-1]]>=-x1)cnt1--;
			while(cnt2<sz2&&ans[nodes[1][sz2-cnt2-1]]>x1)cnt2++;
			while(cnt2>0&&ans[nodes[1][sz2-cnt2]]<=x1)cnt2--;
			if((cnt1+cnt2)*2>sz1+sz2){
				x1++;
			}else break;
		}
		while(1){
			while(cnt1<sz1&&ans[nodes[0][sz1-cnt1-1]]>-x1)cnt1++;
			while(cnt1>0&&ans[nodes[0][sz1-cnt1]]<=-x1)cnt1--;
			while(cnt2<sz2&&ans[nodes[1][cnt2]]<x1)cnt2++;
			while(cnt2>0&&ans[nodes[1][cnt2-1]]>=x1)cnt2--;
			if((cnt1+cnt2)*2>sz1+sz2){
				x1--;
			}else break;
		}
		for(int v:nodes[0])ans[v]+=x1;
		for(int v:nodes[1])ans[v]-=x1;
	}
}
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v,w;i<=m;i++)scanf("%i %i %i",&u,&v,&w),E[u].pb({v,w}),E[v].pb({u,w});
	for(int i=1;i<=n;i++)if(!was[i])Solve(i);
	printf("YES\n");
	for(int i=1;i<=n;i++)printf("%.1f ",ans[i]);
	return 0;
}