#include<cstdio>
#include<vector>

using namespace std;

vector<int> G[100100];
int dep[100100];

int c=0;
void dfs(int v,int p)
{
	c++;
	dep[v]=c;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==p) continue;
		dfs(G[v][i],v);
	}
	c--;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(0,-1);
	double ans=0;
	for(int i=0;i<N;i++)
	{
		ans+=(1.0/dep[i]);
	}
	printf("%.9f\n",ans);
	return 0;
}