#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> G[100100];
vector<int> depths[100100];

int par[24][100100];
int depth[100100];
int pre[100100],pos[100100];

int num=0;

void dfs(int v,int d)
{
	pre[v]=num;
	depth[v]=d;
	num++;
	for(int i=0;i<G[v].size();i++)
	{
		dfs(G[v][i],d+1);
	}
	pos[v]=num;
}

int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
	{
		int in;
		scanf("%d",&in);
		par[0][i]=in;
		G[in].push_back(i);
	}
	dfs(0,0);
	par[0][0]=-1;
	for(int i=1;i<24;i++)
	{
		for(int j=0;j<=N;j++)
		{
			if(par[i-1][j]<0) par[i][j]=-1;
			else par[i][j]=par[i-1][par[i-1][j]];
		}
	}
	for(int i=1;i<=N;i++)
	{
		depths[depth[i]].push_back(pre[i]);
	}
	for(int i=0;i<=N+2;i++) sort(depths[i].begin(),depths[i].end());
	int Q;
	scanf("%d",&Q);
	/*
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<=N;j++)
		{
			printf("%d ",par[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<=N;i++) printf("%d ",pre[i]);
	printf("\n");
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<depths[i].size();j++)
		{
			printf("%d ",depths[i][j]);
		}
		printf("\n");
	}*/
	for(int q=0;q<Q;q++)
	{
		int v,p;
		scanf("%d%d",&v,&p);
		if(depth[v]<=p)
		{
			printf("0%c",q==Q-1?'\n':' ');
			continue;
		}
		int pp=v;
		for(int dig=23;dig>=0;dig--)
		{
			if((p&(1<<dig))!=0)
			{
				pp=par[dig][pp];
			}
		}
		if(pp<=0)
		{
			printf("0%c",q==Q-1?'\n':' ');
			continue;
		}
		int de=depth[v];
		int ans=distance(lower_bound(depths[de].begin(),depths[de].end(),pre[pp]),upper_bound(depths[de].begin(),depths[de].end(),pos[pp]));
		ans--;
		printf("%d%c",ans,q==Q-1?'\n':' ');
	}
	return 0;
}