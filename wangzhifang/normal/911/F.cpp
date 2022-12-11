#include <cstdio>
#include <vector>
#include <cstring>
#define cs const
using namespace std;
typedef long long ll;
constexpr int max_n=200000;
vector<int>g[max_n+1];
int par[max_n+1],dep[max_n+1];
bool vis[max_n+1];
pair<int,int>ans[max_n];
int rt,len,s,cnt;
void dfs1(cs int u,cs int p=0,cs int d=0){
	if(d>len)
		rt=u,len=d;
	for(int v:g[u])
		if(v!=p)
			dfs1(v,u,d+1);
}
void dfs2(cs int u,cs int p=0,cs int d=0){
	if(d>len)
		s=u,len=d;
	par[u]=p,dep[u]=d;
	for(int v:g[u])
		if(v!=p)
			dfs2(v,u,d+1);
}
ll answ;
void dfs3(cs int u,cs int p,cs int t){
	for(int v:g[u])
		if(v!=p&&!vis[v]){
			dfs3(v,u,t);
			pair<int,int>&tmp=ans[++cnt];
			tmp.first=v,tmp.second=t,answ+=dep[v];
		}
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=n,u,v; --i; g[u].push_back(v),g[v].push_back(u))
		scanf("%d%d",&u,&v);
	rt=1,len=0;
	dfs1(1);
	s=rt,len=0;
	dfs2(rt);
	cnt=0,memset(vis+1,0,n),answ=0;
	for(int u=s,i=len; u; u=par[u],--i){
		vis[u]=1;
		if(i*2<=len){
			int x=cnt;
			dfs3(u,par[u],s);
			answ+=(len-i*2)*ll(cnt-x);
		}
		else
			dfs3(u,par[u],rt);
	}
	for(int u=s,i=len; i; u=par[u],--i){
		pair<int,int>&tmp=ans[++cnt];
		tmp.first=u,tmp.second=rt,answ+=i;
	}
	printf("%lld\n",answ);
	for(int i=1; i<=cnt; ++i)
		printf("%d %d %d\n",ans[i].first,ans[i].second,ans[i].first);
	return 0;
}