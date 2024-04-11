/*input
5 3 1
1 1 1 1 1
1 5
2 4
1 3

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//const int sq = 317;
ll cnt[2000001];
int k;
ll suma = 0;
void add(int x, int del)
{
	if (k == 0)
		suma -= (cnt[x] * (cnt[x] - 1)) / 2;
	else
		suma -= cnt[x] * cnt[x ^ k];
	cnt[x] += del;
	if (k == 0)
		suma += (cnt[x] * (cnt[x] - 1)) / 2;
	else
		suma += cnt[x] * cnt[x ^ k];
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m >> k;
	int a[n + 1];
	{
		a[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			a[i] ^= a[i - 1];
		}
	}
	vector<pair<int, pair<int, int>>>v(m);
	for (int i = 0; i < m; i++)
	{
		int l, r;
		cin >> l >> r;
		v[i] = {i, {l - 1, r}};
	}
	const int k = 512;
	sort(v.begin(), v.end(), [&](pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
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
		int id = i.first;
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
		ans[id] = suma;
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << "\n";
}