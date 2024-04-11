#include <stdio.h>
#include <queue>
using namespace std;
const int Max_N=120;
const int inf=1000000000;
const int s=0,t=1;
int TMP[Max_N][Max_N];
int ResidualGraph[Max_N][Max_N];
int down[Max_N],up[Max_N];
int max(int a, int b){ return a>b?a:b;}
int min(int a, int b){ return a>b?b:a;}
int N;
void BuildTMP(int n)
{
	N=n+1;
	int i,j;
	for(i=1;i<=n;i++)
	{
		TMP[s][i+1]=1;
		for(j=down[i];j<=up[i];j++) TMP[i+1][j+N]=inf;
	}
}
void BuildResidualGraph(int time)
{
	int i,j;
	for(i=0;i<N*2;i++)
		for(j=0;j<N*2;j++) 
			ResidualGraph[i][j]=TMP[i][j];
	for(i=N+1;i<N*2;i++) ResidualGraph[i][t]=time;
}
int par[Max_N];
bool vis[Max_N];
queue<int> q;
bool BFS()
{
	int i;
	for(i=0;i<N*2;i++) vis[i]=false;
	vis[s]=true;
	q.push(s);
	int best=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		if(x==t) continue;
		for(i=0;i<N*2;i++)
		{
			if(!vis[i] && ResidualGraph[x][i]>0)
			{
				par[i]=x;
				vis[i]=true;
				q.push(i);
			}
		}
		if(ResidualGraph[x][t]>0)
		{
			if(ResidualGraph[x][t]>best)
			{
				best=ResidualGraph[x][t];
				par[t]=x;
			}
		}
	}
	return vis[t];
}
int MaxFlow()
{
	int MinCut,Flow=0,i;
	while(BFS())
	{
		MinCut=inf;
		for(i=t;i!=s;i=par[i]) MinCut=min(MinCut,ResidualGraph[par[i]][i]);
		Flow+=MinCut;
		for(i=t;i!=s;i=par[i])
		{
			ResidualGraph[par[i]][i]-=MinCut;
			ResidualGraph[i][par[i]]+=MinCut;
		}
	}
	return Flow;
}
int main()
{
	int n,i,l,r,v,t,q,j,k;
	scanf("%i %i",&n,&q);
	for(i=1;i<=n;i++) down[i]=1,up[i]=n;
	while(q--)
	{
		scanf("%i %i %i %i",&t,&l,&r,&v);
		if(t==1) for(i=l;i<=r;i++) down[i]=max(down[i],v);
		else for(i=l;i<=r;i++) up[i]=min(up[i],v);
	}
	BuildTMP(n);
	int sol=inf,ans;
		BuildResidualGraph(n);
		int Flow=MaxFlow();
		if(Flow==n)
		{
			ans=0;
			for(j=N+1;j<N*2;j++) ans+=ResidualGraph[1][j]*ResidualGraph[1][j];
			sol=min(sol,ans);
		}
	printf("%i\n",sol==inf?-1:sol);
	return 0;
}