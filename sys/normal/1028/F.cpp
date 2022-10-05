#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 200005;
int q, m1, m2, ct, t[Maxn], x[Maxn], y[Maxn], pos[Maxn], ang_pos[Maxn], ans[Maxn], at[Maxn];
long long d[Maxn];
pair <int, int> tmp[Maxn];
vector <int> Ve[Maxn];
void insert(int u, int id)
{
	for (int i = 0; i < (int) Ve[u].size(); i++)
	{
		pair <int, int> now = make_pair(x[Ve[u][i]] + x[id], y[Ve[u][i]] + y[id]);
		int g = __gcd(now.first, now.second);
		now.first /= g, now.second /= g;
		int pos = lower_bound(tmp + 1, tmp + 1 + m1, now) - tmp;
		if (tmp[pos] != now) continue;
		ans[pos]++;
	}
	Ve[u].push_back(id);
}
void erase(int u, int id)
{
	vector <int> V;
	for (auto now : Ve[u])
		if (now != id) V.push_back(now);
	Ve[u] = V;
	for (int i = 0; i < (int) Ve[u].size(); i++)
	{
		pair <int, int> now = make_pair(x[Ve[u][i]] + x[id], y[Ve[u][i]] + y[id]);
		int g = __gcd(now.first, now.second);
		now.first /= g, now.second /= g;
		int pos = lower_bound(tmp + 1, tmp + 1 + m1, now) - tmp;
		if (tmp[pos] != now) continue;
		ans[pos]--;
	}
}
map <pair <int, int>, int> id;
int main()
{
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d%d", &t[i], &x[i], &y[i]), d[i] = (long long) x[i] * x[i] + (long long) y[i] * y[i];
		tmp[i] = make_pair(x[i], y[i]);
		int g = __gcd(x[i], y[i]);
		tmp[i].first /= g, tmp[i].second /= g;
	}
	sort(tmp + 1, tmp + 1 + q);
	m1 = unique(tmp + 1, tmp + 1 + q) - tmp - 1;
	sort(d + 1, d + 1 + q);
	m2 = unique(d + 1, d + 1 + q) - d - 1;
	for (int i = 1; i <= q; i++)
	{
		pos[i] = lower_bound(d + 1, d + 1 + m2, (long long) x[i] * x[i] + (long long) y[i] * y[i]) - d;
		ang_pos[i] = lower_bound(tmp + 1, tmp + 1 + m1, make_pair(x[i] / __gcd(x[i], y[i]), y[i] / __gcd(x[i], y[i]))) - tmp;
	}
	for (int i = 1; i <= q; i++)
	{
		if (t[i] == 1)
			insert(pos[i], i), id[make_pair(x[i], y[i])] = i, ct++, at[ang_pos[i]]++;
		if (t[i] == 2)
			erase(pos[i], id[make_pair(x[i], y[i])]), ct--, at[ang_pos[i]]--;
		if (t[i] == 3)
			printf("%d\n", ct - at[ang_pos[i]] - 2 * ans[ang_pos[i]]);
	}
	return 0;
}