#include<bits/stdc++.h>
#define N 200005

int T;

int n;

int hd[N],_hd;
struct edge{
	int v,nxt;
}e[N<<1];
inline void addedge(int u,int v){
	e[++_hd]=(edge){v,hd[u]};
	hd[u]=_hd;
}

int fa[N],deg[N],dep[N];
inline void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	deg[u]=0;
	for(int i=hd[u];i;i=e[i].nxt){
		int v=e[i].v;
		if(v==fa[u])
			continue;
		fa[v]=u;
		dfs(v);
		deg[u]++;
	}
}

bool vis[N];
std::priority_queue<std::pair<int,int>> q;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			hd[i]=0;
		_hd=0;
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			addedge(u,v);
			addedge(v,u);
		}
		dfs(1);
		for(int i=1;i<=n;i++)
			if(!deg[i])
				q.push({dep[i],i});
		for(int i=1;i<=n;i++)
			vis[i]=0;
		int ans=0;
		bool f=0,g=0;
		while(q.size()){
			int u=q.top().second;
			q.pop();
			if(u==1||fa[u]==1||vis[fa[u]]){
				if(fa[u]==1)
					ans++,f=1;
				continue;
			}
			int v=fa[u];
			vis[v]=1;
			if(fa[v]!=1&&!--deg[fa[v]])
				q.push({dep[fa[v]],fa[v]});
			ans+=deg[v]-g;
			g=1;
		}
		ans-=f&&g;
		printf("%d\n",ans);
	}
}