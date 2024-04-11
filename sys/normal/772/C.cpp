#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
int n, m, maxi, ct, cnt, pos, val[Maxn], head[Maxn], from[Maxn], fac[Maxn], deg[Maxn], f[Maxn];
bool vis[Maxn];
vector <int> Ve[Maxn];
struct edg
{
	int nxt, to;
} edge[20 * Maxn];
void add(int x, int y)
{
	deg[y]++;
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
queue <int> Qu;
pair <long long, long long> exgcd(long long x, long long y)
{
	if (!x)
		return make_pair(0, 1);
	else
	{
		pair <long long, long long> tmp = exgcd(y % x, x);
		return make_pair(tmp.second - tmp.first * (y / x), tmp.first);
	}
}
void work(void)
{
	for (int i = 1; i <= m; i++)
		if (!deg[i]) Qu.push(i);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		f[u] += Ve[u].size();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (f[to] < f[u])
			{
				f[to] = f[u];
				from[to] = u;
			}
			deg[to]--;
			if (!deg[to]) Qu.push(to);
		}
	}
}
void work(int x, int y)
{
	int l = __gcd(x, m);
	x /= l, y /= l;
	pair <long long, long long> result = exgcd(x, m / l);
	val[++maxi] = y * (result.first % m + m) % m;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x), vis[x] = true;
	}
	for (int i = 0; i < m; i++)
		if (!vis[i]) Ve[__gcd(i, m)].push_back(i);
	for (int i = 1; i <= m; i++)
		if (m % i == 0) fac[++ct] = i;
	for (int i = 1; i <= ct; i++)
		for (int j = i + 1; j <= ct; j++)
			if (fac[j] % fac[i] == 0) add(fac[i], fac[j]);
	work();
	for (int i = 1; i <= m; i++)
		if (maxi < f[i]) maxi = f[i], pos = i;
	int las = -1;
	printf("%d\n", maxi);
	maxi = 0;
	while (pos)
	{
		if (Ve[pos].size())
		{
			if (las == -1) las = *Ve[pos].rbegin(), Ve[pos].pop_back();
			for (vector <int> :: iterator it = Ve[pos].begin(); it != Ve[pos].end(); it++)
				work(*it, las), las = *it;
		}
		pos = from[pos];
	}
	printf("%d ", las);
	for (int i = maxi; i >= 1; i--)
		printf("%d ", val[i]);
	return 0;
}