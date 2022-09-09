#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
const int S=317;
#define ll long long
ll C[N],sol[N];
int Sum[N],mx;
void Add(int x)
{
	if(Sum[x]) C[Sum[x]]-=x;
	if(mx==Sum[x]) mx++;
	Sum[x]++;
	C[Sum[x]]+=x;
}
void Err(int x)
{
	C[Sum[x]]-=x;
	if(mx==Sum[x] && !C[Sum[x]]) mx--;
	Sum[x]--;
	if(Sum[x]) C[Sum[x]]+=x;
}
int c[N],b[N],e[N],time,Node[N];
vector<int> E[N];
void DFS(int c, int p)
{
	b[c]=++time;
	Node[time]=c;
	for(int i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p) DFS(v,c);
	}
	e[c]=time;
}
struct Query
{
	int l,r,i;
	Query(){}
	Query(int a, int b, int c){ l=a,r=b,i=c;}
	bool operator < (Query b) const
	{
		return (r/S<b.r/S)||(r/S==b.r/S && l<b.l);
	}
} Q[N];
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&c[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0);
	for(i=1;i<=n;i++) Q[i]=Query(b[i],e[i],i);
	sort(Q+1,Q+1+n);
	int l=1,r=0;
	for(i=1;i<=n;i++)
	{
		while(r<Q[i].r) Add(c[Node[++r]]);
		while(r>Q[i].r) Err(c[Node[r--]]);
		while(l<Q[i].l) Err(c[Node[l++]]);
		while(l>Q[i].l) Add(c[Node[--l]]);
		sol[Q[i].i]=C[mx];
	}
	for(i=1;i<=n;i++) printf("%lld ",sol[i]);
	return 0;
}