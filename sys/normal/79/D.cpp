#include <bits/stdc++.h>
using namespace std;

int n, k, l, m, G[21][21], x[105], f[1 << 20 | 5], dis[21][10005];
bool a[10005];
queue <int> Qu;
vector <int> Ve;
void bfs(int id, int s)
{
	memset(dis[id], 0x3f, sizeof(dis[id]));
	dis[id][s] = 0;
	Qu.push(s);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		for (int i = 1; i <= l; i++)
		{
			if (u + x[i] <= n && u + x[i] != s && dis[id][u + x[i]] == 0x3f3f3f3f)
				dis[id][u + x[i]] = dis[id][u] + 1, Qu.push(u + x[i]);
			if (u - x[i] >= 1 && u - x[i] != s && dis[id][u - x[i]] == 0x3f3f3f3f)
				dis[id][u - x[i]] = dis[id][u] + 1, Qu.push(u - x[i]);
		}
	}
}
int lowbit(int x)
{
	return x & -x;
}
int main()
{
	scanf("%d%d%d", &n, &k, &l);
	n++;
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		a[x] = true;
	}
	for (int i = n; i >= 1; i--)
	{
		a[i] ^= a[i - 1];
		if (a[i]) Ve.push_back(i);
	}
	for (int i = 1; i <= l; i++)
		scanf("%d", &x[i]);
	m = Ve.size();
	for (int i = 0; i < m; i++)
		bfs(i, Ve[i]);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			G[i][j] = dis[i][Ve[j]];
	int maxi = (1 << m) - 1;
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for (int i = 0; i < maxi; i++)
	{
		int A = log2(lowbit(maxi ^ i));
		for (int B = 0; B < m; B++)
			if (A != B && !(i & (1 << B))) f[i ^ (1 << A) ^ (1 << B)] = min(f[i ^ (1 << A) ^ (1 << B)], f[i] + G[A][B]);
	}
	printf("%d", f[maxi] == 0x3f3f3f3f ? -1 : f[maxi]);
	return 0;
}