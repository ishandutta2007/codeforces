#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define N 200005

int n,a[N];

std::vector<int> E[N];

int d[N];
std::queue<int> Q;
inline void bfs(){
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++) if(a[i])
		d[i]=0,Q.push(i);
	while(Q.size()){
		int u=Q.front();Q.pop();
		for(auto v:E[u]) if(d[v]>d[u]+1)
			d[v]=d[u]+1,Q.push(v);
	}
}

std::vector<int> V[N];

int ans[N];

std::priority_queue<std::tuple<int,int,int>> q;
int dis[N];
bool vis[N];
std::vector<int> U;
inline void dij(int i){
	for(auto u:V[i])
		dis[u]=0,q.emplace(-i,0,u);
	while(q.size()){
		int u=std::get<2>(q.top());q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		U.push_back(u);
		for(auto v:E[u]) if(d[v]>=d[u]){
			int w=std::max(0,dis[u]+(d[v]==d[u]?1:-1));
			if(dis[v]>w)
				dis[v]=w,q.emplace(-d[v],-dis[v],v);
		}
	}
	for(auto u:U){
		if(!dis[u])
			ans[u]=i;
		dis[u]=inf,vis[u]=0;
	}
	U.clear();
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
	bfs();
	for(int u=1;u<=n;u++) for(auto v:E[u]) if(d[u]==d[v]){
		V[d[u]].push_back(u);
		break;
	}
	for(int i=1;i<=n;i++)
		ans[i]=d[i];
	memset(dis,0x3f,sizeof(dis));
	for(int i=n;~i;i--) if(V[i].size())
		dij(i);
	for(int i=1;i<=n;i++)
		printf("%d ",2*d[i]-ans[i]);
	puts("");
}