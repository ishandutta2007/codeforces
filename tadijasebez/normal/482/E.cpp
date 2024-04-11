#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ldb double
#define pb push_back
const int N=50050;
int fa[N],go[N][2],sub[N],ssz[N],val[N];
ll zsv[N],stc[N],lzy[N];
void upd(int x,ll f){if(x)stc[x]-=sub[x]*f,lzy[x]+=f;}
void push(int x){if(lzy[x])upd(go[x][0],lzy[x]),upd(go[x][1],lzy[x]),lzy[x]=0;}
void pull(int x){
	ssz[x]=ssz[go[x][0]]+sub[x]+ssz[go[x][1]];
	zsv[x]=zsv[go[x][0]]+(ll)val[x]*sub[x]+zsv[go[x][1]];
}
int pd(int x){return go[fa[x]][0]==x?0:go[fa[x]][1]==x?1:-1;}
void rot(int x){
	int y=fa[x],z=fa[y],p=pd(x),q=pd(y),w=go[x][p^1];
	if(~q)go[z][q]=x;go[x][p^1]=y;go[y][p]=w;
	if(w)fa[w]=y;fa[y]=x;fa[x]=z;
	pull(y);pull(x);
}
void cl(int x){if(~pd(x))cl(fa[x]);push(x);}
void splay(int x){for(cl(x);~pd(x);rot(x))if(~pd(fa[x]))rot(pd(x)==pd(fa[x])?fa[x]:x);}
void access(int x){
	splay(x);sub[x]+=ssz[go[x][1]];go[x][1]=0;pull(x);
	for(;fa[x];rot(x)){
		splay(fa[x]);
		sub[fa[x]]+=ssz[go[fa[x]][1]];
		sub[fa[x]]-=ssz[x];
		go[fa[x]][1]=x;
		pull(fa[x]);
	}
}
int p[N],sz[N];
ll now[N],ans;
vector<int> E[N];
void DFS(int u){sz[u]=1;for(int v:E[u])DFS(v),sz[u]+=sz[v],now[u]-=(ll)sz[v]*sz[v];now[u]+=(ll)sz[u]*sz[u];}
int main(){
	int n;
	scanf("%i",&n);
	for(int i=2;i<=n;i++)scanf("%i",&p[i]),E[p[i]].pb(i);
	DFS(1);
	for(int i=1;i<=n;i++){
		scanf("%i",&val[i]);
		fa[i]=p[i];
		sub[i]=sz[i];
		stc[i]=now[i];
		pull(i);
		ans+=now[i]*val[i];
	}
	printf("%.15f\n",(ldb)ans/n/n);
	int q;
	scanf("%i",&q);
	while(q--){
		int x,y;char t;
		scanf("\n%c %i %i",&t,&x,&y);
		if(t=='P'){
			access(y);splay(x);
			if(!fa[x]) swap(x,y);
			int z=p[x];
			access(z);
			sub[z]-=ssz[x];
			fa[x]=0;
			pull(z);
			upd(z,ssz[x]*2);
			ans-=zsv[z]*ssz[x]*2;
			access(y);
			upd(y,-ssz[x]*2);
			ans+=zsv[y]*ssz[x]*2;
			sub[y]+=ssz[x];
			pull(y);
			fa[x]=y;
			p[x]=y;
		}
		else{
			splay(x);
			ans-=stc[x]*val[x];
			val[x]=y;
			ans+=stc[x]*val[x];
			pull(x);
		}
		printf("%.15f\n",(ldb)ans/n/n);
	}
	return 0;
}