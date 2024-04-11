#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;
int n, s, t, ct, cnt, ans, in[Maxn], out[Maxn], id[Maxn], head[Maxn], dis[Maxn], las[Maxn], from[Maxn], ord1[Maxn], ord2[Maxn], sum[Maxn];
queue <int> Qu;
long long k[Maxn], b[Maxn], pos[Maxn];
bool vis[Maxn];
struct edg
{
	int nxt, to, w, c;
} edge[2 * Maxn];
void add(int x, int y, int w, int c)
{
	edge[++cnt] = (edg){head[x], y, w, c};
	head[x] = cnt;
	edge[++cnt] = (edg){head[y], x, 0, -c};
	head[y] = cnt;
}
bool SPFA(void)
{
	memset(dis, 0x3f, sizeof(int[ct + 1]));
	dis[s] = 0;
	Qu.push(s);
	while (!Qu.empty())
	{
		int u = Qu.front();
		Qu.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (dis[to] > dis[u] + edge[i].c && edge[i].w)
			{
				dis[to] = dis[u] + edge[i].c;
				from[to] = u, las[to] = i;
				if (!vis[to]) Qu.push(to), vis[to] = true;
			}
		}
	}
	return dis[t] != 0x3f3f3f3f;
}
void MCMF(void)
{
	while (SPFA())
	{
		ans += dis[t];
		int u = t;
		while (u != s)
		{
			edge[las[u]].w--;
			edge[((las[u] - 1) ^ 1) + 1].w++;
			u = from[u];
		}
	}
}
bool check(int T)
{
	long long maxi = 0;
	for (int i = 1; i <= 2 * n; i++)
		ord1[i] = i, ord2[i] = i;
	sort(ord1 + 1, ord1 + 2 * n + 1, [](int x, int y){if (b[x] == b[y]) return k[x] > k[y]; return b[x] < b[y];});
	sort(ord2 + n + 1, ord2 + 2 * n + 1, [&](int x, int y){return k[x] * T + b[x] < k[y] * T + b[y];});
	for (int i = 1; i <= 2 * n; i++)
	{
		maxi = max(maxi, k[ord1[i]] * T + b[ord1[i]]);
		if (ord1[i] <= n) pos[ord1[i]] = maxi;
	}
	sort(pos + 1, pos + 1 + n);
	for (int i = n; i >= 1; i--)
		if (pos[i] < k[ord2[i + n]] * T + b[ord2[i + n]]) return false;
	return true;
}
void work(int T)
{
	s = ++ct, t = ++ct;
	for (int i = 1; i <= 2 * n; i++)
	{
		in[i] = ++ct, out[i] = ++ct;
		if (i <= n) add(s, in[i], 1, 0);
		else add(out[i], t, 1, 0);
		add(in[i], out[i], 0x3f3f3f3f, 0);
	}
	for (int i = 1; i <= 2 * n; i++) ord1[i] = i;
	sort(ord1 + 1, ord1 + 1 + 2 * n, [](int x, int y){return b[x] < b[y];});
	sum[1] = in[ord1[1]];
	for (int i = 2; i <= 2 * n; i++)
	{
		sum[i] = ++ct;
		add(sum[i], sum[i - 1], 0x3f3f3f3f, 0);
		add(sum[i], in[ord1[i]], 0x3f3f3f3f, 0);
	}
	for (int i = 2; i <= 2 * n; i++)
		add(in[ord1[i]], sum[i - 1], 0x3f3f3f3f, 1);
	for (int i = 1; i <= 2 * n; i++) ord2[i] = i;
	sort(ord2 + 1, ord2 + 1 + 2 * n, [&](int x, int y){if (k[x] * T + b[x] == k[y] * T + b[y]) return x > y; return k[x] * T + b[x] < k[y] * T + b[y];});
	sum[1] = out[ord2[1]];
	for (int i = 2; i <= 2 * n; i++)
	{
		sum[i] = ++ct;
		add(sum[i], sum[i - 1], 0x3f3f3f3f, 0);
		add(sum[i], out[ord2[i]], 0x3f3f3f3f, 0);
	}
	for (int i = 2; i <= 2 * n; i++)
		add(out[ord2[i]], sum[i - 1], 0x3f3f3f3f, 1);
	MCMF();
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++)
		scanf("%lld%lld", &k[i], &b[i]);
	int l = 0, r = 1e9 + 1;
	while (l + 1 <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	if (l == 1e9 + 1)
	{
		puts("-1");
		return 0;
	}
	printf("%d ", l);
	work(l);
	printf("%d", ans);
	return 0;
}