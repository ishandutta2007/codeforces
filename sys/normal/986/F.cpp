#include <bits/stdc++.h>
using namespace std;

const int Maxn = 500005;
int T, ct, cnt, mini, ord[Maxn], head[Maxn], prim[10 * Maxn];
bool vis[Maxn], not_prime[100 * Maxn];
long long dis[Maxn], n[Maxn], k[Maxn], fac[Maxn];
pair <int, int> result;
string ans[Maxn];
struct edg
{
	int nxt, to, w;
} edge[20 * Maxn];
void add(int x, int y, int w)
{
	edge[++cnt] = (edg){head[x], y, w};
	head[x] = cnt;
}
struct sta
{
	int u;
	long long w;
	bool operator < (const sta &tmp) const
	{
		return w > tmp.w;
	}
};
priority_queue <sta> Pr;
void dijkstra(void)
{
	memset(dis, 0x3f, sizeof(long long[mini]));
	memset(vis, 0, sizeof(bool[mini]));
	dis[0] = 0;
	Pr.push((sta){0, 0});
	while (!Pr.empty())
	{
		int u = Pr.top().u;
		Pr.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].w)
			{
				dis[to] = dis[u] + edge[i].w;
				Pr.push((sta){to, dis[to]});
			}
		}
	}
}
void init(void)
{
	int lim = 40000000;
	for (int i = 2; i <= lim; i++)
	{
		if (!not_prime[i]) prim[++cnt] = i;
		for (int j = 1; j <= cnt && i * prim[j] <= lim; j++)
		{
			not_prime[i * prim[j]] = true;
			if (i % prim[j] == 0) break;
		}
	}
}
pair <int, int> exgcd(pair <int, int> now)
{
	if (!now.second) return make_pair(1, 0);
	pair <int, int> result = exgcd(make_pair(now.second, now.first % now.second));
	return make_pair(result.second, result.first - result.second * (now.first / now.second));
}
void work(long long x)
{
	mini = ct = 0;
	for (int i = 1; prim[i] * (long long) prim[i] <= x; i++)
		if (x % prim[i] == 0)
		{
			if (!mini) mini = prim[i];
			fac[++ct] = prim[i];
			while (x % prim[i] == 0) x /= prim[i];
		}
	if (x != 1)
	{
		if (!mini) mini = x;
		fac[++ct] = x;
	}
	if (ct > 2)
	{
		memset(head, 0, sizeof(int[mini]));
		cnt = 0;
		for (int i = 1; i <= ct; i++)
			for (int j = 0; j < mini; j++)
				add(j, (j + fac[i]) % mini, fac[i]);
		dijkstra();
	}
	if (ct == 2)
	{
		int g = __gcd(fac[1], fac[2]);
		result = exgcd(make_pair(fac[1] / g, fac[2] / g));
	}
}
int main()
{
	scanf("%d", &T);
	init();
	for (int i = 1; i <= T; i++)
		scanf("%lld%lld", &n[i], &k[i]), ord[i] = i;
	sort(ord + 1, ord + 1 + T, [](int x, int y){return k[x] < k[y];});
	for (int i = 1; i <= T; i++)
	{
		if (k[ord[i]] != k[ord[i - 1]]) work(k[ord[i]]);
		if (k[ord[i]] == 1)
		{
			puts("NO");
			continue;
		}
		if (ct == 1)
			ans[ord[i]] = n[ord[i]] % fac[1] == 0 ? "YES" : "NO";
		else if (ct == 2)
		{
			if (n[ord[i]] % __gcd(fac[1], fac[2]))
			{
				puts("NO");
				continue;
			}
			long long tmpx = ((result.first * (long long) (n[ord[i]] % fac[2])) % fac[2] + fac[2]) % fac[2];
			ans[ord[i]] = n[ord[i]] - tmpx * fac[1] >= 0 ? "YES" : "NO";
		}
		else ans[ord[i]] = dis[n[ord[i]] % mini] > n[ord[i]] ? "NO" : "YES";
	}
	for (int i = 1; i <= T; i++)
		cout << ans[i] << endl;
	return 0;
}