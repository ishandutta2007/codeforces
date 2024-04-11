#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 200005;
int n, q, cnt, per, dfn_cnt, pos[Maxn], bel[Maxn], head[Maxn], siz[Maxn], dfn[Maxn], pnt[Maxn], top[Maxn];
long long a[Maxn], b[Maxn], A[Maxn], B[Maxn], shift[Maxn];
pair <int, int> ord[2005][505];
pair <long long, long long> sta[2005][505];
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
void dfs(int u)
{
	dfn[u] = ++dfn_cnt;
	pos[dfn_cnt] = u;
	siz[u] = 1;
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int to = edge[i].to;
		b[to] += b[u], a[to] += a[u], dfs(to), siz[u] += siz[to];
	}
}
double slope(pair <long long, long long> x, pair <long long, long long> y)
{
	return (x.second - y.second) / (double) (y.first - x.first);
}
vector <pair <long long, long long> > tmp;
void rebuild(int x)
{
	int lt = (x - 1) * per + 1, rt = min(n, x * per);
	for (int i = lt; i <= rt; i++)
		A[i] += shift[x];
	shift[x] = 0;
	tmp.clear();
	for (int i = 1; i <= 2 * (rt - lt + 1); i++)
	{
		if (ord[x][i].second) tmp.push_back(make_pair(-B[ord[x][i].first], -A[ord[x][i].first] * B[ord[x][i].first]));
		else tmp.push_back(make_pair(B[ord[x][i].first], A[ord[x][i].first] * B[ord[x][i].first]));
	}
	pnt[x] = 1, top[x] = 0;
	for (auto now : tmp)
	{
		while (top[x] && sta[x][top[x]].first == now.first && sta[x][top[x]].second <= now.second) top[x]--;
		while (top[x] > 1 && slope(sta[x][top[x] - 1], sta[x][top[x]]) >= slope(sta[x][top[x]], now)) top[x]--;
		sta[x][++top[x]] = now;
	}
}
void modify(int lt, int rt, int val)
{
	if (bel[lt] == bel[rt])
	{
		for (int i = lt; i <= rt; i++)
			A[i] += val;
		rebuild(bel[lt]);
	}
	else
	{
		for (int i = lt; i <= bel[lt] * per; i++)
			A[i] += val;
		rebuild(bel[lt]);
		for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
			A[i] += val;
		rebuild(bel[rt]);
		for (int i = bel[lt] + 1; i <= bel[rt] - 1; i++)
			shift[i] += val;
	}
}
long long ask(int lt, int rt)
{
	long long ans = 0;
	if (bel[lt] == bel[rt])
	{
		for (int i = lt; i <= rt; i++)
			ans = max(ans, abs(A[i] + shift[bel[lt]]) * B[i]);
		return ans;
	}
	for (int i = lt; i <= bel[lt] * per; i++)
		ans = max(ans, abs(A[i] + shift[bel[lt]]) * B[i]);
	for (int i = (bel[rt] - 1) * per + 1; i <= rt; i++)
		ans = max(ans, abs(A[i] + shift[bel[rt]]) * B[i]);
	for (int i = bel[lt] + 1; i <= bel[rt] - 1; i++)
	{
		while (pnt[i] < top[i] && sta[i][pnt[i]].first * shift[i] + sta[i][pnt[i]].second <= sta[i][pnt[i] + 1].first * shift[i] + sta[i][pnt[i] + 1].second)
			pnt[i]++;
		ans = max(ans, sta[i][pnt[i]].first * shift[i] + sta[i][pnt[i]].second);
	}
	return ans;
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 2; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(x, i);
	}
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]);
	dfs(1);
	for (int i = 1; i <= n; i++) A[dfn[i]] = a[i], B[dfn[i]] = abs(b[i]);
	int bloc = max(1.0, sqrt(n * 12));
	per = n / bloc + 1;
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / per + 1;
	for (int i = 1; i <= bloc; i++)
	{
		int tmp_ct = 0;
		for (int j = (i - 1) * per + 1; j <= min(n, i * per); j++)
			ord[i][++tmp_ct] = make_pair(j, 0), ord[i][++tmp_ct] = make_pair(j, 1);
		sort(ord[i] + 1, ord[i] + 1 + tmp_ct, [](pair <int, int> x, pair <int, int> y){return (x.second ? -B[x.first] : B[x.first]) < (y.second ? -B[y.first] : B[y.first]);});
	}
	for (int i = 1; i <= bloc; i++)
		rebuild(i);
	for (int i = 1; i <= q; i++)
	{
		int opt;
		scanf("%d", &opt);
		if (opt == 1)
		{
			int v, x;
			scanf("%d%d", &v, &x);
			modify(dfn[v], dfn[v] + siz[v] - 1, x);
		}
		else
		{
			int v;
			scanf("%d", &v);
			printf("%lld\n", ask(dfn[v], dfn[v] + siz[v] - 1));
		}
	}
	return 0;
}