/*input
8 3
1 1 2 2 1 3 1 1
2 7
1 6
2 7

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int cnt[1000001];
ll sum = 0;
void add(int x, int del)
{
	if (del == 1)
		sum += ((ll)cnt[x] * 2 + 1) * x;
	else
		sum -= ((ll)cnt[x] * 2 - 1) * x;
	cnt[x] += del;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, t;
	cin >> n >> t;
	int a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	a[0] = 0;
	vector<pair<int, pair<int, int>>>v(t);
	for (int i = 0; i < t; i++)
	{
		cin >> v[i].second.first >> v[i].second.second;
		v[i].first = i;
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
	ll ans[t];
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
		ans[id] = sum;
	}
	for (int i = 0; i < t; i++)
		cout << ans[i] << "\n";
}