#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

int N,M;
vector<int> e[200010];
int d[200010];
LL sum1;
LL sum2;
vector<int> now;
bool vis[200010];

void dfs(int x)
{
	vis[x] = true;
	sum1++;
	sum2+=LL(d[x]);
	for (int i=0;i<e[x].size();i++)
	if (!vis[e[x][i]])
	{
		dfs(e[x][i]);
	}
}

int main()
{
	scanf("%d%d",&N,&M);
	for (int i=1;i<=M;i++)
	{
		int X,Y;
		scanf("%d%d",&X,&Y);
		e[X].push_back(Y);
		e[Y].push_back(X);
		d[X]++;
		d[Y]++;
	}
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=N;i++)
	if (!vis[i])
	{
		sum1 = 0;
		sum2 = 0;
		dfs(i);
		if (sum2!=sum1*(sum1-1))
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}