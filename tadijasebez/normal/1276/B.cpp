#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}
const int N=200050;
vector<int> E[N];
int cmp[N],sz[N];
bool A[N],B[N],was[N];
void DFS(int u, int c)
{
	cmp[u]=c;
	was[u]=1;
	sz[c]++;
	for(int v:E[u]) if(!was[v])
	{
		DFS(v,c);
	}
}
int main()
{
	int n,m,a,b,t;
	scanf("%i",&t);
	while(t--)
	{
		scanf("%i %i %i %i",&n,&m,&a,&b);
		for(int i=1;i<=n;i++) E[i].clear();
		for(int i=1,u,v;i<=m;i++)
		{
			scanf("%i %i",&u,&v);
			E[u].pb(v);
			E[v].pb(u);
		}
		for(int i=1;i<=n;i++) was[i]=0,cmp[i]=0,sz[i]=0,A[i]=B[i]=0;
		was[a]=was[b]=1;
		for(int i=1;i<=n;i++) if(!was[i]) DFS(i,i);
		for(int u:E[a])
		{
			A[cmp[u]]=1;
		}
		for(int u:E[b])
		{
			B[cmp[u]]=1;
		}
		int asz=0,bsz=0;
		for(int i=1;i<=n;i++)
		{
			if(A[i] && !B[i]) asz+=sz[i];
			if(!A[i] && B[i]) bsz+=sz[i];
		}
		printf("%lld\n",(ll)asz*bsz);
	}
	return 0;
}