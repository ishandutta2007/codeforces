#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, p = 1e9 + 7;
int n, cnt, a[Maxn], head[Maxn];
long long d, sum, ans, ct[Maxn], tot[Maxn], siz[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	siz[u] = a[u];
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		dfs(to, u);
		siz[u] += siz[to];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), sum += a[i];
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(x, i);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		long long c = sum / __gcd(sum, siz[i]);
		if (c > n) continue;
		for (int j = c; j <= n; j += c)
			ct[j]++;
	}
	for (int i = 2; i <= n; i++)
		if (sum % i == 0 && ct[i] == i)
		{
			tot[i]++;
			for (int j = 2 * i; j <= n; j += i)
				(tot[j] += tot[i]) %= p;
			(ans += tot[i]) %= p;
		}
	printf("%lld", (ans + 1) % p);
	return 0;
}