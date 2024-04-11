#include <stdio.h>
#include <vector>
using namespace std;
const int N=400050;
const int M=2*N;
int max(int a, int b){ return a>b?a:b;}
int x[M],ls[M],rs[M],tsz,root;
void Set(int &c, int ss, int se, int qi, int val)
{
	if(!c) c=++tsz;
	if(ss==se){ x[c]=val;return;}
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi,val);
	else Set(rs[c],mid+1,se,qi,val);
	x[c]=max(x[ls[c]],x[rs[c]]);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(qs>qe) return 0;
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return max(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
int sz[N],lid[N],rid[N],tid;
vector<int> E[N];
void DFS(int u, int p)
{
	sz[u]=1;lid[u]=++tid;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
	rid[u]=tid;
}
void Set(int n){ for(int i=1;i<=n;i++) if(sz[i]<=n/2) Set(root,1,tid,lid[i],sz[i]);}
bool cen[N];
void Solve(int u, int p, int n)
{
	cen[u]=1;
	int HC=0,i;
	if(n-sz[u]>n/2) cen[u]=0;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && sz[v]>n/2) cen[u]=0,HC=v;
	}
	if(!cen[u])
	{
		if(HC)
		{
			int Max=Get(root,1,tid,lid[HC],rid[HC]);
			if(sz[HC]-Max<=n/2) cen[u]=1;
		}
		else
		{
			int Max=max(Get(root,1,tid,1,lid[u]-1),Get(root,1,tid,rid[u]+1,tid));
			if(n-sz[u]-Max<=n/2) cen[u]=1;
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p)
		{
			if(n-sz[v]<=n/2) Set(root,1,tid,lid[u],n-sz[v]);
			else Set(root,1,tid,lid[u],0);
			Solve(v,u,n);
			if(sz[u]<=n/2) Set(root,1,tid,lid[u],sz[u]);
			else Set(root,1,tid,lid[u],0);
		}
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0);
	Set(n);
	Solve(1,0,n);
	for(i=1;i<=n;i++) printf("%i ",cen[i]);
	printf("\n");
	return 0;
}