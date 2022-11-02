#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#include<iostream>
#include<string>
using namespace std;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define PLL pair<LL, LL>

int n, m, T[404][404], dist[404];
vector<int> V[2][404];
queue<int> Q;

int BFS(int ind)
{
	for(int i=2; i<=n; i++)
		dist[i]=1000000000;
	Q.push(1);
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		for(int i=0; i<(int)V[ind][v].size(); i++)
		{
			if(dist[V[ind][v][i]]==1000000000)
			{
				dist[V[ind][v][i]]=dist[v]+1;
				Q.push(V[ind][v][i]);
			}
		}
	}
	if(dist[n]==1000000000)
		return -1;
	return dist[n];
}

int main()
{
	//ios_base::sync_with_stdio(0);
	scanf("%d%d", &n, &m);
	for(int i=0; i<m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		T[min(a, b)][max(a, b)]=1;
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=i+1; j<=n; j++)
		{
			if(T[i][j])
			{
				V[0][j].PB(i);
				V[0][i].PB(j);
			}
			else
			{
				V[1][j].PB(i);
				V[1][i].PB(j);
			}
		}
	}
	if(T[1][n])
		printf("%d\n", BFS(1));
	else
		printf("%d\n", BFS(0));
	return 0;
}