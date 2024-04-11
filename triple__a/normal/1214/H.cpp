#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;
int n,k,dist[maxn],p[maxn],col[maxn];
vector<int> e[maxn];
bool vis[maxn];

int bfs(int u){
	int ans=-1;
	dist[u]=0;
	vis[u]=1;
	p[u]=-1;
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(u);
	while (!q.empty()){
		int x=q.front();
		ans=x;
		q.pop();
		for (int i=0;i<e[x].size();++i){
			int v=e[x][i];
			if (!vis[v]){
				p[v]=x;
				dist[v]=dist[x]+1;
				vis[v]=1;
				q.push(v);
			}
		}
	}
	return ans;
}

bool coloring(int u,int d){
	vis[u]=1;
	dist[u]=0;
	queue<int> q;
	while(!q.empty()){
		q.pop();
	}
	q.push(u);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for (int i=0;i<e[x].size();++i){
			int v=e[x][i];
			if (!vis[v]){
				dist[v]=dist[x]+1;
				if (dist[v]+min(col[u],d+1-col[u])>=k) return 1;
				vis[v]=1;
				q.push(v);
				if (col[u]<d+1-col[u]){
					col[v]=col[u]-dist[v];
				}
				else{
					col[v]=col[u]+dist[v];
				}
			}
		}
	}
	return 0;
}

int main(){
	scanf("%d%d",&n,&k); 
	for (int i=1;i<n;++i){
		int u,v;
		scanf("%d %d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	} 
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	if (k==2){
		cout<<"Yes"<<endl;
		bfs(1);
		for (int i=1;i<=n;++i){
			cout<<dist[i]%2+1<<" ";
		}
		return 0;
	}
	int l=bfs(1);
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	int r=bfs(l);
	int t=r,cnt=0;
	memset(vis,0,sizeof(vis));
	memset(dist,0,sizeof(dist));
	while (t!=-1){
//		cout<<t<<endl;
		col[t]=++cnt;
		vis[t]=1;
		t=p[t];
	} 
	while (r!=-1){
		if (coloring(r,cnt)){
			cout<<"No"<<endl;
			return 0;
		}
		r=p[r];
	}
	cout<<"Yes"<<endl;
	for (int i=1;i<=n;++i){
		cout<<(col[i]-1)%k+1<<" ";
	}
	cout<<endl;
	return 0;
}