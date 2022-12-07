#include<bits/stdc++.h>

using namespace std;

const int N=1005;
int adj[N][N],ans[N];
int id[N],c[N],n,m;

struct edge{
	int to,next,f;
};
namespace Net{
	edge e[N*10];
	int head[N],cur[N],tot=1,n;
	int dis[N],q[N];
	void init(int _n){
		tot=1; n=_n;
		memset(head,0,sizeof(int)*(n+2));
	}
	void add(int x,int y,int v){
		e[++tot]=(edge){y,head[x],v};
		head[x]=tot;
		e[++tot]=(edge){x,head[y],0};
		head[y]=tot;
	}
	bool bfs(int S,int T){
		for (int i=1;i<=n;i++)		
			dis[i]=-1;
		int h=0,t=1;
		q[1]=S; dis[S]=0; cur[S]=head[S];
		while (h!=t){
			int x=q[++h];
			for (int i=head[x];i;i=e[i].next)
				if (dis[e[i].to]==-1&&e[i].f){
					dis[e[i].to]=dis[x]+1;
					cur[e[i].to]=head[e[i].to];
					if (e[i].to==T) return 1;
					q[++t]=e[i].to;
				}
		}
		return 0;
	}
	int dfs(int x,int flow,int T){
		if (x==T) return flow;
		int k,rest=flow;
		for (int &i=cur[x];i&&rest;i=e[i].next)
			if (dis[e[i].to]==dis[x]+1&&e[i].f){
				k=dfs(e[i].to,min(rest,e[i].f),T);
				e[i^1].f+=k; e[i].f-=k;
				if (!(rest-=k)) break;
			}
		if (rest) dis[x]=-1;
		return flow-rest;
	}
	void Flow(int S,int T){
		for (;bfs(S,T);dfs(S,1<<30,T));
	}
}
void solve(int l,int r,vector<int> v){
	if (!v.size()) return;
	if (l==r){
		for (auto i:v)
			ans[i]=l;
		return;
	}
	int mid=(l+r)/2,idx=0;
	for (auto i:v) id[i]=++idx;
	int S=++idx,T=++idx;
	Net::init(idx);
	for (auto i:v)
		for (auto j:v)
			 if (adj[i][j])
			 	Net::add(id[i],id[j],1<<30);
	for (auto i:v)
		if (c[i]<=mid)
			Net::add(id[i],T,1);
		else
			Net::add(S,id[i],1);
	Net::Flow(S,T);
	vector<int> v1,v2;
	for (auto i:v)
		if (Net::dis[id[i]]==-1)
			v1.push_back(i);
		else
			v2.push_back(i);
	solve(l,mid,v1);
	solve(mid+1,r,v2);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		adj[x][y]=1;
	}
	vector<int> v;
	for (int i=1;i<=n;i++)
		v.push_back(i);
	solve(0,1e9+1,v);
	for (int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}