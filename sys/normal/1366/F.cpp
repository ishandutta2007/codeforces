#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005, p = 1e9 + 7;
int n, m, q, top, cnt, x[Maxn], y[Maxn], w[Maxn], head[Maxn];
long long ans, maxi[Maxn * Maxn], dis[Maxn][Maxn];
pair <long long, long long> sta[Maxn * Maxn];
bool vis[Maxn][Maxn];
queue <pair <int, int> > Qu;
struct edg
{
	int nxt, to, w;
} edge[2 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
void SPFA(void)
{
	Qu.push(make_pair(1, 0));
	memset(dis, -0x3f, sizeof(dis));
	dis[1][0] = 0;
	while (!Qu.empty())
	{
		pair <int, int> now = Qu.front();
		Qu.pop();
		vis[now.first][now.second] = false;
		for (int i = head[now.first]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to][now.second + 1] < dis[now.first][now.second] + edge[i].w)
			{
				dis[to][now.second + 1] = dis[now.first][now.second] + edge[i].w;
				if (now.second + 1 != n && !vis[to][now.second]) Qu.push(make_pair(to, now.second + 1)), vis[to][now.second] = true;
			}
		}
	}
}
double cross(pair <long long, long long> x, pair <long long, long long> y)
{
	if (!y.first) return 1e9 + 1;
	return (double) (y.second - x.second) / (x.first - y.first);
}
void line_add(pair <long long, long long> now)
{
	while (top > 1 && cross(sta[top - 1], sta[top]) >= cross(sta[top], now)) top--;
	sta[++top] = now;
}
long long f(pair <long long, long long> now, int x)
{
	return (x * now.first + now.second) % p;
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x[i], &y[i], &w[i]);
		add(x[i], y[i], w[i]), add(y[i], x[i], w[i]);
	}
	SPFA();
	memset(maxi, -0x3f, sizeof(maxi));
	for (int j = 0; j <= n; j++)
	{
		long long tmp_maxi = 0;
		for (int i = 1; i <= n; i++)
			tmp_maxi = max(tmp_maxi, dis[i][j]);
		if (j <= q) (ans += tmp_maxi) %= p;
		for (int i = 1; i <= m; i++)
			maxi[w[i]] = max(maxi[w[i]], max(dis[x[i]][j], dis[y[i]][j]) - (long long) w[i] * j);
	}
	for (int i = 1; i <= 1000000; i++)
		if (maxi[i] >= -1e12)
			line_add(make_pair(i, maxi[i]));
	int las = n + 1;
	sta[top + 1] = make_pair(0, 0);
	for (int i = 1; i <= top; i++)
	{
		int now = min(q, (int) cross(sta[i], sta[i + 1]));
		if (now < las) continue;
		(ans += (now - las + 1) * (f(sta[i], las) + f(sta[i], now)) % p * (p + 1) / 2 % p) %= p;
		las = now + 1;
	}
	printf("%lld", ans);
	return 0;
}