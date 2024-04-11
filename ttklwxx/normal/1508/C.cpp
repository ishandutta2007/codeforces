#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e5+9;
int n,m;
ll mi,ans;
int f[M],g[M],d[M];
bool v[M];
struct P{
	int u,v,w;
}e[M];
map<int,bool>mp[M];
int find(int x){
	return f[x]==x?x:f[x]=find(f[x]);
}
int get(int x){
	return g[x]==x?x:g[x]=get(g[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	ll re=1ll*n*(n-1)/2-m;
	for(int i=1;i<=n;++i)f[i]=g[i]=i;
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		d[e[i].u]++;mp[e[i].u][e[i].v]=1;
		d[e[i].v]++;mp[e[i].v][e[i].u]=1;
		mi^=e[i].w;
	}
	sort(e+1,e+m+1,[&](const P&l,const P&r){return l.w<r.w;});
	int p=1;
	for(int i=2;i<=n;++i)if(n-d[i]>n-d[p])p=i;
	for(int i=1;i<=n;++i)if(!mp[p].count(i))f[i]=p,v[i]=1;
	for(int i=1;i<=n;++i){
		if(!v[i]){
			for(int j=1;j<=n;++j){
				if(!mp[i].count(j))f[find(i)]=find(j);
			}
		}
	}
	for(int i=1;i<=n;++i)re-=f[i]!=i;
	if(re)mi=0;
	for(int i=1;i<=m;++i){
		int u=e[i].u,v=e[i].v,w=e[i].w;
		if(find(u)!=find(v))ans+=w,f[find(u)]=find(v),g[get(u)]=get(v);
		else if(get(u)!=get(v))mi=min(mi,1ll*w);
	}
	printf("%lld\n",mi+ans);
	return 0;
}