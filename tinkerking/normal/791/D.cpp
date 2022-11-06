#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,K;
vector<int>e[200010];
LL S1[200010][5],S2[200010][5],ans;
LL TMPS1[5],TMPS2[5];
LL NS1[200010],NS2[200010];
bool vis[200010];

void dfs(int X)
{
	vis[X] = true;
	S1[X][0] = 0;
	S2[X][0] = 0;
	for (int jj=0;jj<e[X].size();jj++)
	{ 
		int Y = e[X][jj];
		if (!vis[Y])
		{
			dfs(Y);
			
			memset(TMPS1,0,sizeof(TMPS1));
			memset(TMPS2,0,sizeof(TMPS2));
			
			for (int i=0;i<K;i++)
			{
				TMPS1[(i+1)%K] += S1[Y][i];
				TMPS2[(i+1)%K] += S2[Y][i];
			}
			TMPS2[1] += S1[Y][0];
			
			/*
			printf("Calc %d %d:\n",X,Y);
			for (int i=0;i<K;i++)
			{
				printf("S1,S2[X][%d] %d %d\n",i,S1[X][i],S2[X][i]);
				printf("S1,S2[Y][%d] %d %d\n",i,TMPS1[i],TMPS2[i]);
			}
			*/
			
			for (int i=0;i<K;i++)
				for (int j=0;j<K;j++)
				{
					ans += S2[X][i]*TMPS1[j] + TMPS2[j]*S1[X][i]; 
					if (i>0 && j>0 && i+j<=K)
						ans -= S1[X][i]*TMPS1[j];
				}
			
			//printf("%I64d\n",ans);
			
			for (int i=0;i<K;i++)
			{
				S1[X][(i+1)%K] += S1[Y][i];
				S2[X][(i+1)%K] += S2[Y][i];
			}
			S2[X][1] += S1[Y][0];
		}
	}
	for (int i=0;i<K;i++)ans+=S2[X][i];
	S1[X][0]++;
	//printf("%d %I64d\n",X,ans);
}

void dfs1(int X)
{
	vis[X] = true;
	NS1[X] = NS2[X] = 0;
	for (int j=0;j<e[X].size();j++)
	{ 
		int Y = e[X][j];
		if (!vis[Y])
		{
			dfs1(Y);
			ans += NS1[Y]*NS2[X] + NS2[Y]*NS1[X];
			ans += NS1[Y]*NS1[X];
			NS1[X] += NS1[Y];
			NS2[X] += NS2[Y] + NS1[Y];
		}
	}
	ans+=NS2[X];
	NS1[X]++;
	//printf("%d %d %d\n",X,NS1[X],NS2[X]);
}

int main()
{
	scanf("%d%d",&N,&K);
	for (int i=1;i<N;i++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		e[X].push_back(Y);
		e[Y].push_back(X);
	}
	ans = 0;
	memset(vis,false,sizeof(vis));
	if (K==1)
		dfs1(1);
	else
		dfs(1);
	/*
	for (int i=1;i<=N;i++)
		for (int j=0;j<K;j++)
		{
			printf("%d %d:%d %d\n",i,j,S1[i][j],S2[i][j]);
		}
	*/
	printf("%I64d\n",ans);
}