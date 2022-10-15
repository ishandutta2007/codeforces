#include<bits/stdc++.h>
using namespace std;
 
const int maxn=100007;
vector<pair<int,int> > edge[maxn];
int pos,ans=maxn,sz[maxn],n;
bool vis[maxn];
 
void init(int u,int v){
	edge[u].push_back(make_pair(v,0));
	edge[v].push_back(make_pair(u,0));
}
 
void dfs(int u){
	vis[u]=1;
	int mx_sub=0;
	for (int i=0;i<edge[u].size();++i){
		int v=edge[u][i].first;
		if (!vis[v]){
			dfs(v);
			sz[u]+=sz[v];
			mx_sub=max(mx_sub,sz[v]);
		}
	}	
	mx_sub=max(mx_sub,n-sz[u]);
	if (mx_sub<ans){
		ans=mx_sub;
		pos=u;
	}
}
 
void dfs2(int u,int st){
	vis[u]=1;
	int ret=1;
	for (int i=0;i<edge[u].size();++i){
		int v=edge[u][i].first;
		if (!vis[v]){
			dfs2(v,st);
			edge[u][i].second=ret*st;
			ret+=sz[v];
		}
	}
}
 
int ck(int u){
	for (int i=0;i<edge[u].size();++i){
		int v=edge[u][i].first;
		if (sz[v]>n/3) return v;
	}
	return -1;
}
 
int main(){
    ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<n;++i){
		int u,v;
		cin>>u>>v;
		init(u,v);
	}
	for (int i=1;i<=n;++i){
		sz[i]=1,vis[i]=0;
	}
	dfs(1);
	for (int i=1;i<=n;++i){
		sz[i]=1,vis[i]=0;
	}
	int u=pos;
	dfs(u);
	int q=ck(u);
//	cout<<u<<" "<<q<<endl;
	memset(vis,0,sizeof(vis));
	vis[u]=1;
	if (q==-1){
		int sum=1,i=0;
		for (;i<edge[u].size();++i){
			if (sum>=n/3) break;
			edge[u][i].second=sum;
			dfs2(edge[u][i].first,1);
			sum+=sz[edge[u][i].first];
		}
		int tmp=1;
		for (;i<edge[u].size();++i){
			edge[u][i].second=tmp*sum;
			dfs2(edge[u][i].first,sum);
			tmp+=sz[edge[u][i].first];
		}
	}
	else{
		int sum=1,i=0,j=-1;
		for (i=0;i<edge[u].size();++i){
			if (edge[u][i].first==q){
				j=i;
				continue;
			}
			edge[u][i].second=sum;
			dfs2(edge[u][i].first,1);
			sum+=sz[edge[u][i].first];
		}
		edge[u][j].second=sum;
		dfs2(q,sum);
	}
	for (int i=1;i<=n;++i){
		for (int j=0;j<edge[i].size();++j){
			if (edge[i][j].second){
				cout<<i<<" "<<edge[i][j].first<<" "<<edge[i][j].second<<endl;
			}
		}
	}
	return 0;
}