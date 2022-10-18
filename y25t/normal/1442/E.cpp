#include<cstdio>
#include<algorithm>
#define N 200005

int T;

int n,a[N];

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int dis[N],c[N];
inline void dfs(int u,int fa,int col){
	dis[u]=fa?dis[fa]+(a[u]!=0&&a[u]!=col):0;
	c[u]=a[u]?a[u]:col;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,u,c[u]);
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
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		int o=0;
		for(int i=1;i<=n;i++)
			if(a[i])
				o=i;
		if(!o){
			puts("1");
			continue;
		}
		dfs(o,0,a[o]);
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[o])
				o=i;
//		printf("^%d %d %d\n",o,dis[o],c[o]);
		dfs(o,0,c[o]);
		for(int i=1;i<=n;i++)
			if(dis[i]>dis[o])
				o=i;
//		printf("&%d\n",dis[o]);
		printf("%d\n",(dis[o]+1)/2+1);
	}
}