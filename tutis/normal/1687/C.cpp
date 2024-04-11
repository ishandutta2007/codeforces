/*input
2
5 2
1 5 4 2 3
3 2 5 4 1
1 3
2 5
5 2
1 5 4 2 3
3 2 4 5 1
1 2
2 4
*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
void solve()
{
	int n, m;
	cin >> n >> m;
	ll a[n + 1];
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		a[i] -= b;
	}
	pair<int, int>c[m];
	for (pair<int, int>&i : c)
	{
		cin >> i.first >> i.second;
		i.first--;
	}
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	if (a[n] != 0)
	{
		cout << "NO\n";
		return;
	}
	int R[n + 1];
	int pa[n + 1];
	function<int(int)>root = [&](int x)
	{
		if (pa[x] >= 0)
			return pa[x] = root(pa[x]);
		else
			return x;
	};
	auto merge = [&](int x, int y)->void
	{
		x = root(x);
		y = root(y);
		if (x != y)
		{
			if (pa[x] > pa[y])
				swap(x, y);
			pa[x] += pa[y];
			pa[y] = x;
			R[x] = max(R[x], R[y]);
		}
	};
	for (int i = 0; i <= n; i++)
	{
		R[i] = i;
		pa[i] = -1;
	}
	for (int i = 0; i < n; i++)
		if (a[i] == 0 && a[i + 1] == 0)
			merge(i, i + 1);
	vector<int>C[n + 1];
	queue<int>G;
	for (int i = 0; i < m; i++)
	{
		C[c[i].first].push_back(i);
		C[c[i].second].push_back(i);
		if (a[c[i].first] == 0 && a[c[i].second] == 0)
			G.push(i);
	}
	while (!G.empty())
	{
		int i = G.front();
		G.pop();
		int l = root(c[i].first);
		while (R[l] < c[i].second)
		{
			int i = R[l] + 1;
			a[i] = 0;
			for (int j : C[i])
			{
				if (a[c[j].first] == 0 && a[c[j].second] == 0)
					G.push(j);
			}
			merge(i, l);
			l = root(l);
		}
	}
	if (-pa[root(0)] != n + 1)
		cout << "NO\n";
	else
		cout << "YES\n";
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
		solve();
}