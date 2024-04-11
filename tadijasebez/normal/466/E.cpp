#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
int in[N],lid[N],rid[N],tid;
vector<int> E[N];
void DFS(int u, int p)
{
	lid[u]=++tid;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u);
	}
	rid[u]=tid;
}
int p[N];
void Init(){ for(int i=0;i<N;i++) p[i]=i;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ p[Find(x)]=Find(y);}
int t[N],x[N],y[N],a[N],b[N];
int main()
{
	int n,m,i,cnt=0;
	scanf("%i %i",&n,&m);
	Init();
	for(i=1;i<=m;i++)
	{
		scanf("%i",&t[i]);
		if(t[i]==1)
		{
			scanf("%i %i",&x[i],&y[i]);
			E[y[i]].push_back(x[i]);
			in[x[i]]++;
		}
		else if(t[i]==2) scanf("%i",&x[i]),y[i]=++cnt;
		else scanf("%i %i",&x[i],&y[i]);
	}
	for(i=1;i<=n;i++) if(!in[i]) DFS(i,0);
	for(i=1;i<=m;i++)
	{
		if(t[i]==1) Union(x[i],y[i]);
		if(t[i]==2) a[y[i]]=x[i],b[y[i]]=Find(x[i]);
		if(t[i]==3)
		{
			int id=y[i];
			int u=x[i];
			if(lid[u]<=lid[a[id]] && rid[u]>=lid[a[id]] && lid[b[id]]<=lid[u] && rid[b[id]]>=lid[u]) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}