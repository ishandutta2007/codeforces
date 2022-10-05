#include <bits/stdc++.h>
using namespace std;

const int Maxn = 800005;
int n, m, ct, top, maxi, tmp_c, scc_ct, dfn_cnt, x[Maxn], y[Maxn], c[Maxn], w[Maxn], sta[Maxn], bel[Maxn], dfn[Maxn], low[Maxn], tmp[Maxn];
vector <int> G[Maxn], V[Maxn], Ve[Maxn];
set <int> Se;
void add(int x, int y)
{
	G[x].push_back(y);
	G[y ^ 1].push_back(x ^ 1);
}
void tarjan(int u)
{
	dfn[u] = low[u] = ++dfn_cnt;
	sta[++top] = u;
	for (vector <int> :: iterator it = G[u].begin(); it != G[u].end(); it++)
	{
		int to = *it;
		if (!dfn[to])
		{
			tarjan(to);
			low[u] = min(low[u], low[to]);
		}
		else if (!bel[to]) low[u] = min(low[u], dfn[to]);
	}
	if (dfn[u] == low[u])
	{
		bel[u] = ++scc_ct;
		while (sta[top] != u)
			bel[sta[top--]] = scc_ct;
		top--;
	}
}
bool check(int val)
{
	for (int i = 0; i <= (ct << 1 | 1); i++)
		G[i].clear();
	ct = m - 1;
	for (int u = 1; u <= n; u++)
	{
		int tmp_ct = 0;
		for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
			if (w[*it] <= val) tmp_ct++;
		int pnt = ct + 1;
		for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
			if (w[*it] <= val)
			{
				add(*it << 1, pnt << 1);
				if (pnt != ct + 1) add((pnt - 1) << 1, pnt << 1), add((pnt - 1) << 1, *it << 1 | 1);
				pnt++;
			}
		ct += tmp_ct;
		Se.clear();
		for (vector <int> :: iterator it = Ve[u].begin(); it != Ve[u].end(); it++)
			V[c[*it]].push_back(*it), Se.insert(c[*it]);
		for (set <int> :: iterator se_it = Se.begin(); se_it != Se.end(); se_it++)
		{
			int pnt = ct + 1;
			for (vector <int> :: iterator it = V[*se_it].begin(); it != V[*se_it].end(); it++)
			{
				add(pnt << 1, *it << 1);
				if (pnt != ct + 1) add(pnt << 1, (pnt - 1) << 1), add(*it << 1 | 1, (pnt - 1) << 1);
				pnt++;
			}
			ct += V[*se_it].size();
			V[*se_it].clear();
		}
	}
	for (int i = 0; i < m; i++)
		if (w[i] > val) G[i << 1].push_back(i << 1 | 1);
	dfn_cnt = scc_ct = 0;
	memset(dfn, 0, sizeof(int[(ct + 1) << 1]));
	memset(bel, 0, sizeof(int[(ct + 1) << 1]));
	for (int i = 0; i <= (ct << 1 | 1); i++)
		if (!dfn[i]) tarjan(i);
	for (int i = 0; i < m; i++)
		if (bel[i << 1] == bel[i << 1 | 1]) return false;
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	ct = m - 1;
	for (int i = 0; i < m; i++)
		scanf("%d%d%d%d", &x[i], &y[i], &c[i], &w[i]), maxi = max(maxi, w[i]), Ve[x[i]].push_back(i), Ve[y[i]].push_back(i), tmp[++tmp_c] = c[i];
	sort(tmp + 1, tmp + 1 + tmp_c);
	tmp_c = unique(tmp + 1, tmp + 1 + tmp_c) - tmp - 1;
	for (int i = 0; i < m; i++)
		c[i] = lower_bound(tmp + 1, tmp + 1 + tmp_c, c[i]) - tmp;
	int lt = 0, rt = maxi + 1;
	while (lt + 1 <= rt)
	{
		int mid = (lt + rt) >> 1;
		if (check(mid)) rt = mid;
		else lt = mid + 1;
	}
	if (lt == maxi + 1)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	check(lt);
	int tmp_ct = 0;
	for (int i = 0; i < m; i++)
		if (w[i] <= lt && bel[i << 1] < bel[i << 1 | 1]) tmp_ct++;
	printf("%d %d\n", lt, tmp_ct);
	for (int i = 0; i < m; i++)
		if (w[i] <= lt && bel[i << 1] < bel[i << 1 | 1])
			printf("%d ", i + 1);
	return 0;
}