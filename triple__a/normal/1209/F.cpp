#include<bits/stdc++.h>
using namespace std;

const int maxn=4000007;
const int mod=1e9+7;
vector<int> e[maxn][10];
bool vis[maxn];
long long ans[maxn];
int n,m,cnt;

void ad(int u,int v,int w){
//	printf("%d %d %d\n",u,v,w);
	e[u][w].push_back(v);
}

void addedge(int u,int v,int w){
	vector<pair<int,int> > tmp;
	tmp.clear();
	tmp.push_back({v,w%10});
	w/=10;
	while (w){
		tmp.push_back({++cnt,w%10});
		w/=10;
	}
	tmp.push_back({u,0});
	for (int i=0;i<tmp.size()-1;++i){
		ad(tmp[i+1].first,tmp[i].first,tmp[i].second);
	}
}

void bfs(int u){
	vis[u]=1,ans[u]=0;
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(u);
	while (!q.empty()){
		vector<int> tmp;
		tmp.clear();
		int x=q.front();
		q.pop();
		tmp.push_back(x);
		while (!q.empty()&&ans[q.front()]==ans[x]) tmp.push_back(q.front()),q.pop();
		for (int t=0;t<10;++t){
			for (auto c:tmp){
				for (auto v:e[c][t]){
					if (!vis[v]){
						vis[v]=1;
						ans[v]=(ans[c]*10+t)%mod;
						q.push(v); 
					}
				}
			}
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	cnt=n;
	for (int i=1;i<=m;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		addedge(u,v,i);
		addedge(v,u,i);
	}
	memset(vis,0,sizeof(vis));
	bfs(1);
	for (int i=2;i<=n;++i){
		printf("%d\n",ans[i]);
	}
	return 0;
}