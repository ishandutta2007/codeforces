#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
vector<int> E[N];
int sz[N];
bool vis[N];
void DFS(int c, int p, int &n)
{
	n++;sz[c]=1;
	for(int i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p && !vis[v]) DFS(v,c,n),sz[c]+=sz[v];
	}
}
int Find(int c, int p, int n)
{
	for(int i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p && !vis[v] && sz[v]>n/2) return Find(v,c,n);
	}
	return c;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
ll sol;
int Track[21],Back[21],TrackCnt,BackCnt,a[N];
void Solve(int c, int p, int d, int u)
{
	int i;
	int goal=d^a[u];
	sol+=goal;
	for(i=0;i<21;i++)
	{
		if((goal>>i)&1) sol+=(ll)(1<<i)*(TrackCnt-Track[i]);
		else sol+=(ll)(1<<i)*Track[i];
	}
	for(i=0;i<21;i++) if((d>>i)&1) Back[i]++;
	BackCnt++;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p && !vis[v]) Solve(v,c,d^a[v],u);
	}
}
void Decompose(int u)
{
	u=Find(u);vis[u]=true;
	int i,j;
	for(i=0;i<21;i++) Track[i]=0;
	TrackCnt=0;
	sol+=a[u];
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v])
		{
			for(j=0;j<21;j++) Back[j]=0;
			BackCnt=0;
			Solve(v,u,a[v],u);
			for(j=0;j<21;j++) Track[j]+=Back[j];
			TrackCnt+=BackCnt;
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) Decompose(v);
	}
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	while(--n) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	Decompose(1);
	printf("%lld\n",sol);
	return 0;
}