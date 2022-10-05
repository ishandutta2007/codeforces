#include <bits/stdc++.h>
using namespace std;
const int INF=3.14e8;
int n,m,a[100005],d[100005],A[100005],B[100005],c[100005],b[100005],vis[100005],flag[100005];
vector<int> k[100005],g[100005],rg[100005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
int dfs(int u){
	if(vis[u])	return B[u]=-2;
	if(B[u])	return B[u];
	vis[u]=1;
	for(int i=0;i<k[u].size();i++) 
		if(!flag[k[u][i]]){
			int w=d[k[u][i]];
			for(int j=0;j<g[k[u][i]].size();j++){
				int x=dfs(g[k[u][i]][j]);
				if(x==-2){
					vis[u]=0;
					return B[u]=x;
				}
				w=min(w+x,INF);
			}
			B[u]=max(B[u],w);
		}
	vis[u]=0;
	return B[u];
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		int x;
		scanf("%d%d",&a[i],&x);
		k[a[i]].push_back(i);
		for(int j=0;j<x;j++){
			int y;scanf("%d",&y);
			if(y==-1)	d[i]++;
			else		g[i].push_back(y),rg[y].push_back(i);
		}
		c[i]=g[i].size();
		b[i]=d[i];
	}
	memset(A,-1,sizeof(A));
	for(int i=1;i<=m;i++)
		if(g[i].size()==0)
			q.push({d[i],a[i]});
	while(!q.empty()){
		pair<int,int> p=q.top();q.pop();
		int x=p.first,y=p.second;
		if(A[y]>-1)	continue;
		A[y]=x;
		for(int i=0;i<rg[y].size();i++){
			c[rg[y][i]]--;
			b[rg[y][i]]=min(b[rg[y][i]]+A[y],INF);
			if(!c[rg[y][i]])	q.push({b[rg[y][i]],a[rg[y][i]]});
		}
	}
	for(int i=1;i<=m;i++)
		for(int j=0;j<g[i].size();j++)
			if(A[g[i][j]]==-1)
				flag[i]=1;
	for(int i=1;i<=n;i++){
		if(A[i]!=-1)	dfs(i);
		else			B[i]=-1;
	}
	for(int i=1;i<=n;i++)	printf("%d %d\n",A[i],B[i]);
	return 0;
}