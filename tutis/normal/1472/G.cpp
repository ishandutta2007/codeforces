/*input
3
6 7
1 2
1 3
2 5
2 4
5 1
3 6
6 2
2 2
1 2
2 1
6 8
1 2
1 5
2 6
6 1
2 3
3 4
4 2
5 4

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
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
		vector<int> d(n + 1);
		vector<int>adj[n + 1];
		vector<int>atg[n + 1];
		for (int i = 1; i <= n; i++)
			d[i] = n + 1;
		d[1] = 0;
		while (m--)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			atg[b].push_back(a);
		}
		queue<int>Q;
		Q.push(1);
		vector<int>E;
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			E.push_back(a);
			for (int b : adj[a])
			{
				if (d[b] > d[a] + 1)
				{
					Q.push(b);
					d[b] = d[a] + 1;
				}
			}
		}
		auto D = d;
		reverse(E.begin(), E.end());
		for (int i : E)
		{
			for (int j : adj[i])
			{
				if (d[j] > d[i])
					D[i] = min(D[i], D[j]);
				else
					D[i] = min(D[i], d[j]);
			}
		}
		for (int i = 1; i <= n; i++)
			cout << D[i] << " ";
		cout << "\n";
	}

}