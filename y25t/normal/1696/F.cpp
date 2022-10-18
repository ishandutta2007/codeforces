#include<bits/stdc++.h>
#define N 105

int T;

int n,a[N][N][N];
char str[N];

bool vis[N];
int d[N];
std::vector<int> V[N];
int fa[N];
std::vector<std::pair<int,int>> ans;
std::vector<int> E[N];
int dis[N];
inline void dfs(int u,int Fa){
	dis[u]=dis[Fa]+1;
	for(auto v:E[u]) if(v!=Fa)
		dfs(v,u);
}
inline void sol(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
		a[j][i][i]=1;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++){
		scanf("%s",str+1);
		for(int k=1;k<=n;k++)
			a[k][i][j]=a[k][j][i]=str[k]-'0';
	}
	for(int i=1;i<=n;i++)
		V[i].clear();
	int mn=n,mx=0;
	for(int i=1;i<=n;i++){
		d[i]=0;
		for(int j=1;j<=n;j++)
			vis[j]=0;
		for(int j=1;j<=n;j++) if(!vis[j]){
			d[i]++;
			for(int k=1;k<=n;k++) if(!vis[k]&&a[i][j][k])
				vis[k]=1;
		}
		d[i]--;
		mn=std::min(mn,d[i]),mx=std::max(mx,d[i]);
		V[d[i]].emplace_back(i);
	}
	ans.clear();
	#define No return puts("No"),void()
	for(int i=1;i<=n;i++)
		fa[i]=0;
	if(mn!=(mx+1)/2)
		No;
	for(int i=mn;i<=mx;i++) if(!V[i].size())
		No;
	if(V[mn].size()==1){
		if(mn*2!=mx)
			No;
		for(auto i:V[mn+1])
			fa[i]=V[mn][0],ans.emplace_back(fa[i],i);
	}
	else if(V[mn].size()==2){
		if(mn*2!=mx+1)
			No;
		ans.emplace_back(V[mn][0],V[mn][1]);
		if(mn<mx)
			for(auto i:V[mn+1])
				fa[i]=a[V[mn][0]][V[mn][1]][i]?V[mn][0]:V[mn][1],ans.emplace_back(fa[i],i);
	}
	else
		No;
	for(int i=mn+2;i<=mx;i++){
		for(auto u:V[i]){
			int x=0;
			for(auto v:V[i-2]) for(auto w:V[i-1]) if(fa[w]==v&&a[w][u][v]){
				if(x&&x!=w)
					No;
				x=w;
			}
			if(!x)
				No;
			fa[u]=x,ans.emplace_back(u,x);
		}
	}
	for(int i=1;i<=n;i++)
		E[i].clear();
	for(auto [i,j]:ans)
		E[i].push_back(j),E[j].push_back(i);
	for(int i=1;i<=n;i++){
		dfs(i,0);
		for(int j=1;j<=n;j++) for(int k=1;k<=n;k++)
			if(a[i][j][k]!=(dis[j]==dis[k]))
				No;
	}
	puts("Yes");
	for(auto [i,j]:ans)
		printf("%d %d\n",i,j);
}

int main(){
	scanf("%d",&T);
	while(T--)
		sol();
}