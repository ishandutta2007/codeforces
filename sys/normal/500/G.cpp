#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, t, cnt, dep[Maxn], head[Maxn], anc[Maxn][21];
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
	anc[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs(to, u);
	}
}
void init(void)
{
	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i <= n; i++)
			anc[i][j] = anc[anc[i][j - 1]][j - 1];
}
int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; i--)
		if ((dep[x] - dep[y]) & (1 << i)) x = anc[x][i];
	if (x == y) return x;
	for (int i = 19; i >= 0; i--)
		if (anc[x][i] != anc[y][i]) x = anc[x][i], y = anc[y][i];
	return anc[x][0];
}
int get_dis(int x, int y)
{
	return dep[x] + dep[y] - 2 * dep[lca(x, y)];
}
long long f(long long l, long long r, long long a, long long b)
{
	if (l > r || !a) return 0x3f3f3f3f3f3f3f3fLL;
	if ((l - 1) / a != r / a) return (l + a - 1) / a;
	long long result = f((a - r % a) % a, (a - l % a) % a, b % a, a);
	if (result == 0x3f3f3f3f3f3f3f3fLL) return 0x3f3f3f3f3f3f3f3fLL;
	return (result * b + l + a - 1) / a;
}
pair <long long, long long> exgcd(long long a, long long b)
{
	if (!a) return make_pair(0, b < 0 ? -1 : 1);
	pair <long long, long long> tmp = exgcd(b % a, a);
	return make_pair(tmp.second - tmp.first * (b / a), tmp.first);
}
long long work1(long long D1, long long D2, long long T1, long long T2)
{
	long long C = T2 - T1, g = __gcd(D1, D2);
	if (C % g) return 0x3f3f3f3f3f3f3f3fLL;
	pair <long long, long long> result = exgcd(D1, -D2);
	result.first *= C / g, result.second *= C / g;
	D1 /= g, D2 /= g;
	if (result.first < 0 || result.second < 0)
	{
		long long s = max((-result.first - 1) / D2 + 1, (-result.second - 1) / D1 + 1);
		result.first += s * D2, result.second += s * D1;
	}
	long long s = min(result.first / D2, result.second / D1);
	return (result.first - s * D2) * D1 * g + T1;
}
long long work2(long long D1, long long D2, long long T1, long long T2, long long D)
{
	if ((D + T1 + T2) & 1) return 0x3f3f3f3f3f3f3f3fLL;
	long long l = ((T2 - T1 - D) % D2 + D2) % D2, r = ((T2 - T1 + D) % D2 + D2) % D2;
	long long x, y;
	if (!l || 2 * D == D2 || l > r) x = 0;
	else x = f(l, r, D1 % D2, D2);
	if (x == 0x3f3f3f3f3f3f3f3fLL) return 0x3f3f3f3f3f3f3f3fLL;
	y = (x * D1 + T1 - T2 + D) / D2;
	return (x * D1 + y * D2 + T1 + T2 + D) / 2;
}
long long work(int u, int v, int x, int y)
{
	int l[] = {0, lca(u, x), lca(u, y), lca(v, x), lca(v, y)};
	sort(l + 1, l + 5, [](int a, int b){return dep[a] < dep[b];});
	if (l[3] == l[4] && !(dep[l[3]] >= max(dep[lca(x, y)], dep[lca(u, v)]))) return -1;
	int D1 = get_dis(u, v) * 2, D2 = get_dis(x, y) * 2, D = get_dis(l[3], l[4]);
	int U1 = get_dis(u, l[3]), U2 = get_dis(u, l[4]);
	if (U1 < U2) U2 = D1 - U2;
	else U1 = D1 - U1;
	int X1 = get_dis(x, l[3]), X2 = get_dis(x, l[4]);
	if (X1 < X2) X2 = D2 - X2;
	else X1 = D2 - X1;
	long long ans = min(min(work1(D1, D2, U1, X1), work1(D1, D2, U2, X2)), min(work2(D1, D2, U1, X2, D), work2(D1, D2, U2, X1, D)));
	if (ans == 0x3f3f3f3f3f3f3f3fLL) return -1;
	return ans;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	init();
	scanf("%d", &t);
	while (t--)
	{
		int u, v, x, y;
		scanf("%d%d%d%d", &u, &v, &x, &y);
		printf("%lld\n", work(u, v, x, y));
	}
	return 0;
}