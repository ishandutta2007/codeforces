#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long
#define N 200005

int T;

int n,l[N],r[N];

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

ll f[N][2];
inline void dfs(int u,int fa){
	f[u][0]=f[u][1]=0;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,u);
		f[u][0]+=std::max(f[v][0]+std::abs(l[u]-l[v]),f[v][1]+std::abs(l[u]-r[v]));
		f[u][1]+=std::max(f[v][0]+std::abs(r[u]-l[v]),f[v][1]+std::abs(r[u]-r[v]));
	}
}

int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&r[i]);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1,0);
		printf("%lld\n",std::max(f[1][0],f[1][1]));
	}
}