#include<bits/stdc++.h>
#define N 200005

int n,m;

int d[N];
std::vector<int> E[N];

int dis[N];
bool vis[N];
std::priority_queue<std::pair<int,int>> q;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		E[v].push_back(u),d[u]++;
	}
	memset(dis,0x3f,sizeof(dis));
	dis[n]=0,q.emplace(0,n);
	while(q.size()){
		int u=q.top().second;q.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(auto v:E[u]){
			if(dis[v]>dis[u]+d[v])
				dis[v]=dis[u]+d[v],q.emplace(-dis[v],v);
			d[v]--;
		}
	}
	printf("%d\n",dis[1]);
}