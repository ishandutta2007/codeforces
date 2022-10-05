#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 500005;
int n, k, m, q, top, las, ans, lt, rt, siz[Maxn], fa[Maxn], fa2[Maxn], bel[Maxn], sta[Maxn], out[Maxn];
vector <int> Ve[Maxn];
struct quest
{
	int first, second, id;
} Q[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : get_fa(fa[x]);
}
void merge(int x, int y, bool type)
{
	int a = get_fa(x), b = get_fa(y);
	if (a != b)
	{
		if (siz[a] > siz[b]) swap(a, b);
		if (type) sta[++top] = a;
		fa[a] = b;
		siz[b] += siz[a];
		ans++;
	}
}
int get_fa2(int x)
{
	return x == fa2[x] ? x : fa2[x] = get_fa2(fa2[x]);
}
void merge2(int x, int y)
{
	int a = get_fa2(x), b = get_fa2(y);
	if (a != b)
	{
		fa2[a] = b;
		ans++;
	}
}
int main()
{
	scanf("%d%d%d", &n, &k, &m);
	int bloc = sqrt(n), per = n / bloc + 1;
	for (int i = 1; i <= n; i++)
		bel[i] = (i - 1) / per + 1, fa2[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		Ve[x].push_back(y), Ve[y].push_back(x);
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
		scanf("%d%d", &Q[i].first, &Q[i].second), Q[i].id = i;
	sort(Q + 1, Q + 1 + q, [](quest x, quest y){if (bel[x.first] != bel[y.first]) return x.first < y.first; return x.second < y.second;});
	for (int i = 1; i <= q; i++)
	{
		if (bel[Q[i].first] == bel[Q[i].second])
		{
			ans = 0;
			for (int j = Q[i].first; j <= Q[i].second; j++)
				for (auto u : Ve[j])
					if (u <= Q[i].second && u >= Q[i].first)
						merge2(u, j);
			out[Q[i].id] = Q[i].second - Q[i].first + 1 - ans;
			for (int j = Q[i].first; j <= Q[i].second; j++)
				for (auto u : Ve[j])
					if (u <= Q[i].second && u >= Q[i].first)
						fa2[u] = u, fa2[j] = j;
		}
		else
		{
			if (bel[Q[i].first] != las)
			{
				top = ans = 0;
				for (int j = 1; j <= n; j++) fa[j] = j;
				rt = bel[Q[i].first] * per;
				las = bel[Q[i].first];
			}
			lt = bel[Q[i].first] * per + 1;
			while (rt < Q[i].second)
			{
				rt++;
				for (auto u : Ve[rt])
					if (u >= lt && u <= rt) merge(u, rt, false);
			}
			while (lt > Q[i].first)
			{
				lt--;
				for (auto u : Ve[lt])
					if (u >= lt && u <= rt) merge(u, lt, true);
			}
			out[Q[i].id] = Q[i].second - Q[i].first + 1 - ans;
			while (top)
				siz[fa[sta[top]]] -= siz[sta[top]], fa[sta[top]] = sta[top], top--, ans--;
		}
	}
	for (int i = 1; i <= q; i++)
		printf("%d\n", out[i]);
	return 0;
}