#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
#define pb push_back
const int N=500050;
const int M=2*N;
int head[N],sz[N],dep[N],par[N],csz[N];
vector<int> E[N],all[N];
void DFS(int u)
{
	sz[u]=1;
	dep[u]=dep[par[u]]+1;
	all[dep[u]].pb(u);
	for(int i=0;i<E[u].size();i++) DFS(E[u][i]),sz[u]+=sz[E[u][i]];
}
void HLD(int u)
{
	if(!head[u]) head[u]=u;
	csz[head[u]]++;
	int i,HC=0;
	for(i=0;i<E[u].size();i++) if(sz[E[u][i]]>sz[HC]) HC=E[u][i];
	if(HC) head[HC]=head[u];
	for(i=0;i<E[u].size();i++) HLD(E[u][i]);
}
int root[N],ls[M],rs[M],tsz;
ll sum[M],lzy[M];
void Set(int &c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se) return;
	if(!c) c=++tsz;
	if(qs<=ss && qe>=se){ lzy[c]++;sum[c]+=se-ss+1;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe);
	Set(rs[c],mid+1,se,qs,qe);
	sum[c]=sum[ls[c]]+sum[rs[c]]+lzy[c]*(se-ss+1);
}
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int sec(int a, int b, int c, int d){ return max(0,min(b,d)-max(a,c)+1);}
ll Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe || ss>qe || qs>se || !c) return 0;
	if(qs<=ss && qe>=se) return sum[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe)+lzy[c]*sec(ss,se,qs,qe);
}
void Add(int u)
{
	while(u)
	{
		int id=dep[u]-dep[head[u]]+1;
		Set(root[head[u]],1,csz[head[u]],1,id);
		u=par[head[u]];
	}
}
ll Get(int u)
{
	ll ret=0;
	while(u)
	{
		int id=dep[u]-dep[head[u]]+1;
		ret+=Get(root[head[u]],1,csz[head[u]],1,id);
		u=par[head[u]];
	}
	return ret;
}
ll sol[N];
int main()
{
	int n,r,x,i,j;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&par[i]),E[par[i]].pb(i);
	r=E[0][0];
	DFS(r);HLD(r);
	for(i=1;i<=n;i++)
	{
		for(j=0;j<all[i].size();j++) Add(all[i][j]);
		for(j=0;j<all[i].size();j++)
		{
			sol[all[i][j]]=Get(all[i][j])-dep[all[i][j]];
		}
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}