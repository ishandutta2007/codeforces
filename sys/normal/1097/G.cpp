#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005, Maxk = 205, p = 1e9 + 7;
int n, k, cnt, siz[Maxn], head[Maxn];
long long result, tmp[Maxk], ans[Maxk], S[Maxk][Maxk], f[Maxn][Maxk];
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
	siz[u] = 1;
	f[u][0] = 2;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			memset(tmp, 0, sizeof(long long [k + 1]));
			for (int a = 0; a <= k && a <= siz[u]; a++)
				for (int b = 0; a + b <= k && b <= siz[to]; b++)
					(tmp[a + b] += f[u][a] * f[to][b]) %= p;
			for (int a = 0; a <= k; a++)
				f[u][a] = tmp[a], (ans[a] += p - f[to][a]) %= p;
			siz[u] += siz[to];
		}
	}
	for (int i = 0; i <= k; i++)
		(ans[i] += f[u][i]) %= p;
	for (int i = k; i >= 1; i--)
		(f[u][i] += f[u][i - 1]) %= p;
	f[u][1]--;
}
int main()
{
	scanf("%d%d", &n, &k);
	S[0][0] = 1;
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= k; j++)
			S[i][j] = (j * S[i - 1][j] + S[i - 1][j - 1]) % p;
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	long long now = 1;
	for (int i = 0; i <= k; i++)
		(result += S[k][i] * now % p * ans[i]) %= p, (now *= i + 1) %= p;
	printf("%lld", result);
	return 0;
}