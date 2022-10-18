#include<bits/stdc++.h>
#define ll long long
#define N 300005
#define W 19

bool _;

char buf[1<<23],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<23,stdin),p1==p2)?EOF:*p1++)
inline void rd(int &x){
	x=0;
	char c=getchar();
	while(c<'0'||c>'9')
		c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char obuf[1<<23],*O=obuf;
#define putchar(c) (*O++=c)
inline void wr(ll x){
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		wr(x/10);
	putchar(x%10+'0');
}

int n,q,a[N];

std::vector<std::tuple<int,int,int>> E[N];

int dep[N];
ll d[N],D[N];
int fa[N][W];
ll f[N],F[N],g[N][W];
inline void dfs1(int u){
	dep[u]=dep[fa[u][0]]+1;
	f[u]=a[u];
	for(auto e:E[u]){
		int v,x,y;
		std::tie(v,x,y)=e;
		if(v==fa[u][0])
			continue;
		d[v]=d[u]+x,D[v]=D[u]+y,fa[v][0]=u;
		dfs1(v);
		f[u]+=std::max(0ll,f[v]-x-y);
	}
}
inline void dfs2(int u){
	for(int i=1;i<W;i++){
		fa[u][i]=fa[fa[u][i-1]][i-1];
		g[u][i]=g[u][i-1]+g[fa[u][i-1]][i-1];
	}
	for(auto e:E[u]){
		int v,x,y;
		std::tie(v,x,y)=e;
		if(v==fa[u][0])
			continue;
		g[v][0]=f[u]-std::max(0ll,f[v]-x-y);
		F[v]=std::max(0ll,F[u]+g[v][0]-x-y);
		dfs2(v);
	}
}

inline ll cal(int u,int v){
	if(u==v)
		return f[u]+F[u];
	int x=u,y=v;
	if(dep[u]<dep[v])
		std::swap(u,v);
	ll res=0;
	for(int i=W-1;~i;i--) if(dep[fa[u][i]]>dep[v])
		res+=g[u][i],u=fa[u][i];
	if(dep[u]>dep[v])
		res+=g[u][0],u=fa[u][0];
	for(int i=W-1;~i;i--) if(fa[u][i]!=fa[v][i])
		res+=g[u][i]+g[v][i],u=fa[u][i],v=fa[v][i];
	if(u!=v){
		int w=fa[u][0];
		res+=f[w]-std::max(0ll,f[u]-(d[u]-d[w])-(D[u]-D[w]))-std::max(0ll,f[v]-(d[v]-d[w])-(D[v]-D[w]));
		res+=f[x]+f[y]+F[w];
		u=w;
	}
	else
		res+=f[x==u?y:x]+F[x==u?x:y];
	res-=D[x]-D[u]+d[y]-d[u];
	return res;
}

bool __;

int main(){
	std::cerr<<(&_-&__)/pow(2,20)<<'\n';
	rd(n),rd(q);
	for(int i=1;i<=n;i++)
		rd(a[i]);
	for(int i=1;i<n;i++){
		int u,v,x,y;
		rd(u),rd(v),rd(x),y=x;
		E[u].emplace_back(v,x,y),E[v].emplace_back(u,y,x);
	}
	dfs1(1),dfs2(1);
	while(q--){
		int u,v;
		rd(u),rd(v);
		wr(cal(u,v)),putchar('\n');
	}
	fwrite(obuf,O-obuf,1,stdout);
}