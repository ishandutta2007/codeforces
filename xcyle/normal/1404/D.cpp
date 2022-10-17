#include <iostream>
#include <cstdio>
#include <vector>
#define maxn 1000005
using namespace std;
int n, x, p[maxn], type[maxn];
vector<int> t[maxn], G[maxn];
inline int read()
{
	int x = 0; char ch = getchar();
	while(ch < '0' || ch > '9') ch = getchar();
	while(ch >= '0' && ch <= '9')
	{
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar(); 
	}
	return x;
}
int vis[maxn], sum;
void dfs(int x, int c)
{
	sum = (sum + x * c) % (2 * n);
	vis[x] = 1;
	type[x] = c;
	for (int i = 0; i < G[x].size(); i++)
	{
		if(vis[G[x][i]]) continue;
		dfs(G[x][i], (c ^ 1));
	}
}
int main()
{
	scanf("%d", &n);
	if(n % 2 == 0)
	{
		printf("First\n");
		fflush(stdout);
		for (int i = 1; i <= 2 * n; i++)
		{
			printf("%d ", (i - 1) % n + 1);
			fflush(stdout);
		}
	}
	else
	{
		printf("Second\n");
		fflush(stdout);
		for (int i = 1; i <= 2 * n; i++)
		{
			p[i] = read();
			t[p[i]].push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			G[t[i][0]].push_back(t[i][1]);
			G[t[i][1]].push_back(t[i][0]);
			G[i].push_back(n + i);
			G[n + i].push_back(i);
		}
		for (int i = 1; i <= 2 * n; i++)
		{
			if(!vis[i])
			{
				dfs(i, 1);
			}
		}
		if(sum == n)
		{
			for (int i = 1; i <= 2 * n; i++) type[i] ^= 1;
		}
		for (int i = 1; i <= 2 * n; i++)
		{
			if(!type[i]) continue;
			printf("%d ", i);
			fflush(stdout);
		}
	}
	return 0;
}