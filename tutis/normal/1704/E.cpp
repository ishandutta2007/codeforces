/*input
5
3 2
1 1 1
1 2
2 3
5 5
1 0 0 0 0
1 2
2 3
3 4
4 5
1 5
10 11
998244353 0 0 0 998244353 0 0 0 0 0
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
1 3
7 9
5 6
1293 1145 9961 9961 1919
1 2
2 3
3 4
5 4
1 4
2 4
6 9
10 10 10 10 10 10
1 2
1 3
2 3
4 3
6 3
3 5
6 5
6 1
6 2

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
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
	while (true)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		if (y != 0) {
			x = (x * x) % mod;
			y /= 2;
		}
		else
			break;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<pair<ll, pair<ll, ld>>>V[n + 1];
		for (int i = 1; i <= n; i++)
		{
			ll a;
			cin >> a;
			if (a != 0)
				V[i].push_back({0ll, {a % mod, (ld)a}});
		}
		vector<int>S;
		vector<int>adj[n + 1];
		{
			vector<int> cnt(n + 1, 0);
			while (m--)
			{
				int x, y;
				cin >> x >> y;
				adj[x].push_back(y);
				cnt[y]++;
			}
			vector<int>emp;
			for (int i = 1; i <= n; i++)
				if (cnt[i] == 0)
					emp.push_back(i);
			while (!emp.empty())
			{
				int i = emp.back();
				emp.pop_back();
				S.push_back(i);
				for (int j : adj[i])
				{
					cnt[j]--;
					if (cnt[j] == 0)
						emp.push_back(j);
				}
			}
		}
		for (int i : S)
		{
			sort(V[i].begin(), V[i].end());
			{
				vector<pair<ll, pair<ll, ld>>>W;
				for (pair<ll, pair<ll, ld>>v : V[i])
				{
					if (W.empty())
						W.push_back(v);
					else
					{
						pair<ll, pair<ll, ld>>&w = W.back();
						if (v.first <= w.first + w.second.second + 0.5)
						{
							w.second.first += v.second.first;
							w.second.second += v.second.second;
							if (w.second.first >= mod)
								w.second.first -= mod;
							w.second.second = min(w.second.second, ld(1e60));
						}
						else
							W.push_back(v);
					}
				}
				V[i] = W;
			}
			if (adj[i].size() != 0)
				for (int j : adj[i])
				{
					for (pair<ll, pair<ll, ld>>v : V[i])
					{
						v.first++;
						V[j].push_back(v);
					}
				}
			else
			{
				if (V[i].empty())
					cout << "0\n";
				else
				{
					ll x = V[i].back().first + V[i].back().second.first;
					x %= mod;
					cout << x << "\n";
				}
			}
		}
	}
}