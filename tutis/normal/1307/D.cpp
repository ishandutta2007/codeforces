/*input
5 4 2
2 4
1 2
2 3
3 4
4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m, k;
	cin >> n >> m >> k;
	ll a[k];
	for (int i = 0; i < k; i++)
		cin >> a[i];
	vector<int>adj[n + 1];
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll x[n + 1], y[n + 1];
	fill_n(x, n + 1, n + 2);
	fill_n(y, n + 1, n + 2);
	x[1] = 0;
	y[n] = 0;
	queue<int>Q;
	Q.push(1);
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for (int b : adj[a])
		{
			if (x[b] > x[a] + 1)
			{
				x[b] = x[a] + 1;
				Q.push(b);
			}
		}
	}
	Q.push(n);
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		for (int b : adj[a])
		{
			if (y[b] > y[a] + 1)
			{
				y[b] = y[a] + 1;
				Q.push(b);
			}
		}
	}
	ll ans = 0;
	sort(a, a + k, [&](int i, int j) {
		return x[i] - y[i] < x[j] - y[j];
	});
	ll mxx = -n - 100;
	ll mxy = -n - 100;
	for (int i = 0; i < k; i++)
	{
		if (i >= 1)
		{
			ll d = x[n];
			d = min(d, 1 + mxx + y[a[i]]);
			ans = max(ans, d);
		}
		mxx = max(mxx, x[a[i]]);
		mxy = max(mxy, y[a[i]]);
	}
	cout << ans << "\n";
}