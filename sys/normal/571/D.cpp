#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1000005;
int n, m, ct, cnt, dfn_cnt, head[Maxn], dfn[Maxn], siz1[Maxn], siz2[Maxn], fa[Maxn], opt[Maxn], x[Maxn], y[Maxn], las[Maxn];
long long ans[Maxn];
vector <int> Ve[Maxn];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add_edge(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u, int fa)
{
	dfn[u] = ++dfn_cnt;
	siz1[u] = (u <= n);
	siz2[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		if (to != fa)
			dfs(to, u), siz1[u] += siz1[to], siz2[u] += siz2[to];
	}
}
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
void merge(int x, int y)
{
	int a = get_fa(x), b = get_fa(y);
	fa[min(a, b)] = max(a, b);
}
int lowbit(int x)
{
	return x & -x;
}
long long sum[Maxn];
void add(int x, int y)
{
	for (int i = x; i <= 2 * n; i += lowbit(i))
		sum[i] += y;
}
long long ask(int x)
{
	long long tmp = 0;
	for (int i = x; i; i -= lowbit(i))
		tmp += sum[i];
	return tmp;
}
struct sta
{
	int lt, rt, times;
	bool operator < (const sta &tmp) const
	{
		return lt < tmp.lt;
	}
};
set <sta> Se;
set <sta> :: iterator spilt(int x)
{
	if (x > 2 * n) return Se.end();
	set <sta> :: iterator it = --Se.upper_bound((sta){x, 0, 0});
	if (it -> lt == x) return it;
	sta tmp = *it;
	Se.erase(it);
	Se.insert((sta){tmp.lt, x - 1, tmp.times});
	return Se.insert((sta){x, tmp.rt, tmp.times}).first;
}
void assign(int lt, int rt, int times)
{
	set <sta> :: iterator it_r = spilt(rt + 1), it_l = spilt(lt);
	Se.erase(it_l, it_r);
	Se.insert((sta){lt, rt, times});
}
int main()
{
	scanf("%d%d", &n, &m);
	ct = n;
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		opt[i] = getchar();
		while (!(opt[i] >= 'A' && opt[i] <= 'Z')) opt[i] = getchar();
		if (opt[i] == 'U')
			scanf("%d%d", &x[i], &y[i]);
		else if (opt[i] == 'M')
		{
			scanf("%d%d", &x[i], &y[i]);
			add_edge(++ct, get_fa(x[i])), add_edge(ct, get_fa(y[i]));
			merge(ct, x[i]), merge(ct, y[i]);
		}
		else scanf("%d", &x[i]);
	}
	for (int i = ct; i >= 1; i--)
		if (!dfn[i]) dfs(i, 0);
	Se.insert((sta){1, 2 * n, 0});
	for (int i = 1; i <= ct; i++)
		fa[i] = i;
	ct = n;
	for (int i = 1; i <= m; i++)
	{
		if (opt[i] == 'M') merge(++ct, x[i]), merge(ct, y[i]);
		if (opt[i] == 'Z')
			assign(dfn[get_fa(x[i])], dfn[get_fa(x[i])] + siz2[get_fa(x[i])] - 1, i);
		if (opt[i] == 'Q')
		{
			set <sta> :: iterator it = Se.upper_bound((sta){dfn[x[i]], 0, 0});
			if (it == Se.begin()) continue;
			it--;
			if (it -> lt > dfn[x[i]] || it -> rt < dfn[x[i]]) continue;
			las[i] = it -> times;
			Ve[las[i]].push_back(i);
		}
	}
	memset(head, 0, sizeof(int[ct + 1])), dfn_cnt = cnt = 0, ct = n;
	for (int i = 1; i <= 2 * n; i++) fa[i] = i;
	for (int i = 1; i <= m; i++)
		if (opt[i] == 'U') add_edge(++ct, get_fa(y[i])), add_edge(ct, get_fa(x[i])), merge(x[i], ct), merge(y[i], ct);
	memset(dfn, 0, sizeof(int[ct + 1]));
	for (int i = ct; i >= 1; i--)
		if (!dfn[i]) dfs(i, 0);
	for (int i = 1; i <= ct; i++)
		fa[i] = i;
	ct = n;
	for (int i = 1; i <= m; i++)
	{
		if (opt[i] == 'A')
		{
			int a = get_fa(x[i]);
			add(dfn[a], siz1[a]), add(dfn[a] + siz2[a], -siz1[a]);
		}
		if (opt[i] == 'U')
			merge(x[i], ++ct), merge(y[i], ct);
		if (opt[i] == 'Q')
			printf("%lld\n", ans[i] + ask(dfn[x[i]]));
		for (vector <int> :: iterator it = Ve[i].begin(); it != Ve[i].end(); it++)
			ans[*it] -= ask(dfn[x[*it]]);
	}
	return 0;
}