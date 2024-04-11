#include<bits/stdc++.h>
#define P 998244353
#define N 500005

const int i2=(P+1)>>1;

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int f[N];
inline void dfs(int u,int fa){
	int tmp=1;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa)
			continue;
		dfs(v,u);
		tmp=1ll*tmp*fmo(1+f[v]-P)%P*i2%P;
	}
	f[u]=fmo(1-tmp);
}

int ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
		addedge(v,u);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		ans=fmo(ans+f[i]-P);
	for(int i=1;i<=n;i++)
		ans=fmo(ans+ans-P);
	printf("%d\n",ans);
}