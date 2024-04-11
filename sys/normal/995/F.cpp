#include <bits/stdc++.h>
using namespace std;

const int Maxn = 3005, p = 1e9 + 7;
int n, D, cnt, head[Maxn];
long long ans, f[Maxn][Maxn], s[Maxn][Maxn];
long long get_inv(long long x)
{
	if (x <= 1) return x;
	return (p - p / x) * get_inv(p % x) % p;
}
struct edg
{
	int nxt, to;
} edge[Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	for (int i = 1; i <= n + 1; i++)
		f[u][i] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		dfs(to);
		for (int i = 1; i <= n + 1; i++)
			(f[u][i] *= s[to][i]) %= p;
	}
	for (int i = 1; i <= n + 1; i++)
		(s[u][i] = s[u][i - 1] + f[u][i]) %= p;
}
void work(void)
{
	for (int i = 1; i <= n + 1; i++)
	{
		long long now1 = 1, now2 = 1;
		for (int j = 1; j <= n + 1; j++)
			if (i != j)
				(now1 *= D - j) %= p, (now2 *= i - j) %= p;
		(ans += s[1][i] * (p + now1) % p * get_inv((p + now2) % p)) %= p;
	}
}
int main()
{
	scanf("%d%d", &n, &D);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(x, i);
	}
	dfs(1);
	work();
	printf("%lld", ans);
	return 0;
}