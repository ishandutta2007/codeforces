#include<bits/stdc++.h>
#define ll long long
#define N 200005

int n,m;
ll a[N];

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int f[N];
ll b[N];
bool vis[N];
inline void dfs(int u){
	if(vis[u])
		return;
	vis[u]=1;
	std::set<int> tmp;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		dfs(v);
		tmp.insert(f[v]);
	}
	while(tmp.count(f[u]))
		f[u]++;
	b[f[u]]^=a[u];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v);
	}
	for(int i=1;i<=n;i++)
		dfs(i);
	for(int x=n;~x;x--)
		if(b[x]){
			for(int u=1;u<=n;u++)
				if(f[u]==x&&(a[u]^b[x])<a[u]){
					a[u]^=b[x];
					for(int i=hd[u];i;i=e[i].nxt){
						int v=e[i].v;
						if(b[f[v]]){
							a[v]^=b[f[v]];
							b[f[v]]=0;
						}
					}
					break;
				}
			puts("WIN");
			for(int i=1;i<=n;i++)
				printf("%lld ",a[i]);
			puts("");
			return 0;
		}
	puts("LOSE");
}