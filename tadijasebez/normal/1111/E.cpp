#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int mod=1e9+7;
int mul(int x,int y){return (ll)x*y%mod;}
int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
void ckadd(int &x,int y){x=add(x,y);}
const int N=100050;
const int M=305;
int dp[M],m;
void upd_dp(int x){
	for(int i=m;i>=0;i--){
		dp[i]=mul(dp[i],max(0,i-x));
		if(i)ckadd(dp[i],dp[i-1]);
	}
}
int go[N][2],fa[N],val[N],sum[N],tag[N],sz[N];
void pull(int x){sum[x]=sum[go[x][0]]+val[x]+sum[go[x][1]];sz[x]=sz[go[x][0]]+1+sz[go[x][1]];}
void upd(int x){if(x)swap(go[x][0],go[x][1]),tag[x]^=1;}
void push(int x){if(tag[x])upd(go[x][0]),upd(go[x][1]),tag[x]=0;}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void cl(int x){if(~pd(x))cl(fa[x]);push(x);}
void splay(int x){for(cl(x);~pd(x);rot(x))if(~pd(fa[x]))rot(pd(x)==pd(fa[x])?fa[x]:x);}
void access(int x){for(splay(x),go[x][1]=0,pull(x);fa[x];rot(x))splay(fa[x]),go[fa[x]][1]=x,pull(fa[x]);}
void make_rt(int x){access(x);upd(x);}
int dist(int x,int y){make_rt(x);access(y);return sz[y];}
int get(int x,int y){make_rt(x);access(y);return sum[y];}
vector<int> E[N];
void DFS(int u,int p){
	fa[u]=p;
	sz[u]=1;
	for(int v:E[u])if(v!=p)DFS(v,u);
}
int main(){
	int n,q;
	scanf("%i %i",&n,&q);
	for(int i=1,u,v;i<n;i++)scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	while(q--){
		int k,r;
		scanf("%i %i %i",&k,&m,&r);
		vector<pair<int,int>> a(k);
		for(auto &i:a)scanf("%i",&i.second),i.first=dist(r,i.second);
		sort(a.begin(),a.end());
		for(int i=0;i<=m;i++)dp[i]=0;
		dp[0]=1;
		for(auto p:a){
			int x=get(r,p.second);
			upd_dp(x);
			make_rt(p.second);
			access(p.second);
			sum[p.second]=val[p.second]=1;
		}
		for(auto p:a){
			make_rt(p.second);
			access(p.second);
			sum[p.second]=val[p.second]=0;
		}
		int ans=0;
		for(int i=0;i<=m;i++)ckadd(ans,dp[i]);
		printf("%i\n",ans);
	}
	return 0;
}