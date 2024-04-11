#include<bits/stdc++.h>
#define ll long long
#define N 200005

int n,a[N];

std::vector<int> E[N];

ll f[N],ff[N];
struct node{
	int x,y,z;
	node(){
		x=y=z=0;
	}
	inline void ins(int u){
		if(u>x)
			z=y,y=x,x=u;
		else if(u>y)
			z=y,y=u;
		else if(u>z)
			z=u;
	}
	inline int mx(int u=-1,int v=-1){
		if(u<v)
			std::swap(u,v);
		return u==x?v==y?z:y:x;
	}
}g[N];
inline void dfs1(int u,int fa){
	for(auto v:E[u]) if(v!=fa){
		dfs1(v,u);
		f[u]+=f[v];
		g[u].ins(g[v].mx());
	}
	f[u]+=(ff[u]=std::max(0,a[u]-g[u].mx()));
	g[u].ins(a[u]);
//	printf("*%d %lld %d\n",u,f[u],g[u].mx());
}
ll F[N];
int G[N];
inline void dfs2(int u,int fa){
//	printf("^%d %lld %d %lld\n",u,F[u],G[u],f[u]+F[u]-ff[u]);
	for(auto v:E[u]) if(v!=fa){
		G[v]=std::max(G[u],g[u].mx(g[v].mx(),a[u]));
//		printf("&%d %d %d\n",u,v,G[v]);
		F[v]=F[u]+f[u]-ff[u]-f[v]+std::max(0,a[u]-G[v]);
		G[v]=std::max(G[v],a[u]);
		dfs2(v,u);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[u].push_back(v),E[v].push_back(u);
	}
	dfs1(1,0),dfs2(1,0);
	ll ans=0x3f3f3f3f3f3f3f3f;
	int mx=*std::max_element(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		ans=std::min(ans,F[i]+f[i]-ff[i]+mx+std::max(0,mx-std::max(g[i].mx(a[i]),G[i])));
	printf("%lld\n",ans);
}