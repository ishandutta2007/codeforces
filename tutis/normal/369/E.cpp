/*input
3 3
1 3
4 5
6 7
3 1 4 7
2 4 5
1 8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct Fenwick
{
	vector<ll>A;
	int n;
	Fenwick(int n = 1): n(n)
	{
		A = vector<ll>(n + 1, 0);
	}
	inline int lsb(int x)
	{
		return ((x) & (-x));
	}
	void add(int i, ll w)
	{
		for (; i <= n; i += lsb(i))
		{
			A[i] += w;
		}
	}
	ll get(int i)
	{
		i = min(i, n);
		ll ret = 0;
		for (; i > 0; i -= lsb(i))
		{
			ret += A[i];
		}
		return ret;
	}
	ll get(int a, int b)
	{
		return get(b) - get(a - 1);
	}
};
vector<pair<int, int>> k[1000009];
vector<int>isimt[1000009];
Fenwick XXX(1000009);
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	pair<int, int> seg[n];
	for (int i = 0; i < n; i++)
		cin >> seg[i].first >> seg[i].second;
	int ans[m];
	for (int i = 0; i < m; i++)
	{
		ans[i] = 0;
		int cnt;
		cin >> cnt;
		int p[cnt];
		for (int j = 0; j < cnt; j++)
			cin >> p[j];
		k[1000000].push_back({p[cnt - 1], i});
		for (int j = 0; j < cnt - 1; j++)
			k[p[j + 1] - 1].push_back({p[j], i});
	}
	sort(seg, seg + n, [](pair<int, int>a, pair<int, int>b)
	{
		return a.second < b.second;
	});
	int i = 0;
	for (int r = 0; r <= 1000000; r++)
	{
		while (i < n && seg[i].second <= r)
		{
			XXX.add(seg[i].first, 1);
			XXX.add(seg[i].second + 1, -1);
			i++;
		}
		for (int i : isimt[r])
		{
			XXX.add(seg[i].first, -1);
			XXX.add(seg[i].second + 1, +1);
		}
		for (pair<int, int>a : k[r])
		{
			ans[a.second] += XXX.get(a.first);
		}
	}
	for (int i = 0; i < m; i++)
		cout << ans[i] << "\n";
}