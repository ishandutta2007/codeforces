/*input
4 1
1 2 3 4
1 2
2 3
3 4
1 1

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[100001];
ll sum = 0;
const int sq = 317;
int c[100001 / sq + 2];
int cnt1[100001];
const int C = 100000;
void add1(int i, int del)
{
	c[i / sq] += del;
	cnt1[i] += del;
}
void add(int x, int del)
{
	add1(cnt[x], -1);
	cnt[x] += del;
	add1(cnt[x], 1);
}
int get(int k)
{
	int ret = 0;
	while ((k + 1) % sq != 0)
	{
		ret += cnt1[k];
		k--;
	}
	while (k >= 0)
	{
		ret += c[k / sq];
		k -= sq;
	}
	return ret;
}
int main()
{
	add1(0, C);
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int c[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> c[i];
	vector<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int fr[n + 1], to[n + 1];
	int timer = -1;
	int a[n];
	function<void(int, int)>dfs = [&](int i, int p)->void
	{
		timer++;
		a[timer] = c[i];
		fr[i] = timer;
		for (int j : adj[i])
		{
			if (j != p)
			{
				dfs(j, i);
			}
		}
		to[i] = timer;
	};
	dfs(1, 1);
	vector<pair<pair<int, int>, pair<int, int>>>v(m);
	for (int i = 0; i < m; i++)
	{
		int w, k;
		cin >> w >> k;
		v[i] = {{i, k}, {fr[w], to[w]}};
	}
	const int k = 512;
	sort(v.begin(), v.end(), [&](pair<pair<int, int>, pair<int, int>>a, pair<pair<int, int>, pair<int, int>>b) {
		int x = a.second.first / k;
		int y = b.second.first / k;
		if (x != y)
			return x < y;
		return a.second.second < b.second.second;
	});
	int l = 0;
	int r = -1;
	ll ans[v.size()];
	for (auto i : v)
	{
		int id = i.first.first;
		int k = i.first.second;
		int x = i.second.first;
		int y = i.second.second;
		while (r < y) {
			r++;
			add(a[r], 1);
		}
		while (l > x)
		{
			l--;
			add(a[l], 1);
		}
		while (r > y)
		{
			add(a[r], -1);
			r--;
		}
		while (l < x)
		{
			add(a[l], -1);
			l++;
		}
		ans[id] = C - get(k - 1);
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << "\n";
}