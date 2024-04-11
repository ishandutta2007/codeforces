#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=100050;
const int M=20*N;
const int inf=1e9+69;
int min(int a, int b){ return a>b?b:a;}
int x[M],ls[M],rs[M],clock,root[N];
void Set(int p, int &c, int ss, int se, int qi, int val)
{
	c=++clock,ls[c]=ls[p],rs[c]=rs[p],x[c]=min(x[p],val);
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[p],ls[c],ss,mid,qi,val);
	else Set(rs[p],rs[c],mid+1,se,qi,val);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return inf;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return min(Get(ls[c],ss,mid,qs,qe),Get(rs[c],mid+1,se,qs,qe));
}
vector<int> E[N],D[N];
int b[N],e[N],d[N],val[N],time;
void DFS(int u, int p, int l)
{
	d[u]=l,b[u]=++time,D[l].pb(u);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(p!=v) DFS(v,u,l+1);
	}
	e[u]=time;
}
int main()
{
	x[0]=inf;
	int n,r,u,v,i,j,q,k,p;
	scanf("%i %i",&n,&r);
	for(i=1;i<=n;i++) scanf("%i",&val[i]);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(r,0,1);
	for(i=1;i<N;i++)
	{
		root[i]=root[i-1];
		for(j=0;j<D[i].size();j++) Set(root[i],root[i],1,N,b[D[i][j]],val[D[i][j]]);
	}
	scanf("%i",&q);
	int last=0;
	while(q--)
	{
		scanf("%i %i",&k,&p);
		u=((k+last)%n)+1;
		k=(p+last)%n;
		last=Get(root[min(N-1,d[u]+k)],1,N,b[u],e[u]);
		printf("%i\n",last);
	}
	return 0;
}