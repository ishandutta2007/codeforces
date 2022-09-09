#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
#define upd x[c]=max((y[c]?1:0)*(se-ss+1),x[ls[c]]+x[rs[c]])
const int N=100050;
const int M=2*N;
int x[M],y[M],ls[M],rs[M],clock,root;
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
void Set(int &c, int ss, int se, int qs, int qe, int val)
{
	if(!c) c=++clock;
	if(ss>qe || qs>se) return;
	if(qs<=ss && qe>=se){ y[c]+=val;upd;return;}
	int mid=ss+se>>1;
	Set(ls[c],ss,mid,qs,qe,val);
	Set(rs[c],mid+1,se,qs,qe,val);
	upd;
}
int b[N],e[N],time,sol[N];
vector<int> E[N],Q[N];
void DFS(int u, int p)
{
	b[u]=++time;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	e[u]=time;
}
void Solve(int u, int p)
{
	int i;
	for(i=0;i<Q[u].size();i++) Set(root,1,N,b[Q[u][i]],e[Q[u][i]],1);
	sol[u]=x[root];if(sol[u]>0) sol[u]--;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) Solve(v,u);
	}
	for(i=0;i<Q[u].size();i++) Set(root,1,N,b[Q[u][i]],e[Q[u][i]],-1);
}
int main()
{
	int n,u,v,i,q;
	scanf("%i %i",&n,&q);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	while(q--) scanf("%i %i",&u,&v),Q[u].pb(v),Q[u].pb(u),Q[v].pb(v),Q[v].pb(u);
	DFS(1,0);
	Solve(1,0);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}