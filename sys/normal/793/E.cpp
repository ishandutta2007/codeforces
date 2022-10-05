#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005, lim = 30;
int n, a, b, c, d, cnt, tot, ct[Maxn], type[Maxn], siz[Maxn], head[Maxn];
bitset <500005> Bi, tmp;
map <int, int> Ma[6];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void work(pair <int, int> now)
{
	if (now.second <= lim)
		for (int i = 1; i <= now.second; i++) Bi |= Bi << now.first;
	else
	{
		tmp.reset();
		for (int i = 0; i <= 500000; i++)
		{
			tmp[i] = Bi[i] | (bool) ct[i % now.first];
			if (i >= now.second * now.first) ct[i % now.first] -= Bi[i - now.second * now.first];
			ct[i % now.first] += Bi[i];
		}
		Bi = tmp;
		for (int i = 0; i < now.first; i++) ct[i] = 0;
	}
}
void dfs(int u, int fa)
{
	if (u == a) type[u] = 1;
	if (u == b) type[u] = 2;
	if (u == c) type[u] = 3;
	if (u == d) type[u] = 4;
	siz[u] = !edge[head[u]].nxt;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
		{
			dfs(to, u);
			if (u != 1 && type[u] && type[to]) puts("No"), exit(0);
			type[u] |= type[to];
			siz[u] += siz[to];
		}
	}
	if (type[u])
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (to != fa && !type[to])
				Ma[u == 1 ? 0 : type[u]][siz[to]]++;
		}
}
int main()
{
	scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d", &x), y = i + 1;
		add(x, y), add(y, x);
	}
	if (a == c || a == d || b == c || b == d) return puts("No"), 0;
	dfs(1, 0);
	if (siz[1] & 1) return puts("No"), 0;
	Bi[0] = 1;
	for (auto now : Ma[3]) tot += now.first * now.second;
	for (auto now : Ma[1]) work(now);
	for (auto now : Ma[2]) work(now);
	for (auto now : Ma[0]) work(now);
	if (siz[1] / 2 - tot - 2 < 0 || !Bi[siz[1] / 2 - tot - 2]) return puts("No"), 0;
	Bi.reset();
	Bi[0] = 1;
	tot = 0;
	for (auto now : Ma[1]) tot += now.first * now.second;
	for (auto now : Ma[3]) work(now);
	for (auto now : Ma[4]) work(now);
	for (auto now : Ma[0]) work(now);
	if (siz[1] / 2 - tot - 2 < 0 || !Bi[siz[1] / 2 - tot - 2]) return puts("No"), 0;
	puts("Yes");
	return 0;
}