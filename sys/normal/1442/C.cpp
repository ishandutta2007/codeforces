#include <bits/stdc++.h>
using namespace std;

const int Maxn = 400005, p = 998244353;
int n, m, cnt, head1[Maxn], head2[Maxn];
long long ans = 0x3f3f3f3f3f3f3f3fLL, dis[Maxn][45][2];
pair <int, int> d[Maxn][2];
bool vis[Maxn][2];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head1[x], y};
	head1[x] = cnt;
	edge[++cnt] = (edg){head2[y], x};
	head2[y] = cnt;
}
struct sta1
{
	int first, second;
	bool third;
};
queue <sta1> Qu;
void bfs(void)
{
	memset(dis, -1, sizeof(dis));
	dis[1][0][0] = 0;
	Qu.push((sta1){1, 0, 0});
	while (!Qu.empty())
	{
		sta1 now = Qu.front();
		Qu.pop();
		for (int i = head1[now.first]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to][now.second + now.third][0] == -1 && now.second + now.third <= 40)
			{
				dis[to][now.second + now.third][0] = dis[now.first][now.second][now.third] + 1 + now.third * (1LL << now.second);
				Qu.push((sta1){to, now.second + now.third, 0});
			}
		}
		for (int i = head2[now.first]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to][now.second + !now.third][1] == -1 && now.second + !now.third <= 40)
			{
				dis[to][now.second + !now.third][1] = dis[now.first][now.second][now.third] + 1 + !now.third * (1LL << now.second);
				Qu.push((sta1){to, now.second + !now.third, 1});
			}
		}
	}
}
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
struct sta
{
	int u, first, second;
	bool third;
	bool operator < (const sta &tmp) const
	{
		return make_pair(first, second) > make_pair(tmp.first, tmp.second);
	}
};
priority_queue <sta> Pr;
void dijkstra(void)
{
	for (int i = 1; i <= n; i++)
		d[i][0] = d[i][1] = make_pair(0x3f3f3f3f, 0);
	d[1][0] = make_pair(0, 0);
	Pr.push((sta){1, 0, 0, 0});
	while (!Pr.empty())
	{
		int u = Pr.top().u;
		bool third = Pr.top().third;
		Pr.pop();
		if (vis[u][third]) continue;
		vis[u][third] = true;
		for (int i = head1[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (make_pair(d[u][third].first + third, d[u][third].second + 1) < d[to][0])
			{
				d[to][0] = make_pair(d[u][third].first + third, d[u][third].second + 1);
				Pr.push((sta){to, d[u][third].first + third, d[u][third].second + 1, 0});
			}
		}
		for (int i = head2[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (make_pair(d[u][third].first + !third, d[u][third].second + 1) < d[to][1])
			{
				d[to][1] = make_pair(d[u][third].first + !third, d[u][third].second + 1);
				Pr.push((sta){to, d[u][third].first + !third, d[u][third].second + 1, 1});
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	bfs();
	for (int i = 0; i <= 40; i++)
	{
		if (dis[n][i][0] != -1)
			ans = min(ans, dis[n][i][0]);
		if (dis[n][i][1] != -1)
			ans = min(ans, dis[n][i][1]);
	}
	if (ans != 0x3f3f3f3f3f3f3f3fLL)
	{
		printf("%lld\n", ans);
		return 0;
	}
	dijkstra();
	if (d[n][0] < d[n][1])
		printf("%lld", (d[n][0].second + fast_pow(2, d[n][0].first) + p - 1) % p);
	else
		printf("%lld", (d[n][1].second + fast_pow(2, d[n][1].first) + p - 1) % p);
	return 0;
}