/*input
12
3
4 4
12 1
3 4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll D;
	cin >> D;
	map<ll, ll>M;
	vector<ll>A;
	for (ll x = 1; x * x <= D; x++)
	{
		if (D % x == 0)
		{
			A.push_back(x);
			A.push_back(D / x);
		}
	}
	ll G = D;
	vector<ll>P;
	for (ll x = 2; x * x <= G; x++)
	{
		if (G % x == 0)
		{
			P.push_back(x);
			while (G % x == 0)
				G /= x;
		}
	}
	if (G != 1)
		P.push_back(G);
	sort(A.begin(), A.end());
	for (ll i : A)
	{
		ll &x = M[i];
		x = 0;
		if (i == 1)
		{
			x = 1;
		}
		else
			for (ll p : P)
			{
				if (i % p == 0)
				{
					x += M[i / p];
					if (x >= mod)
						x -= mod;
				}
			}
	}
	ll q;
	cin >> q;
	while (q--)
	{
		ll x, y;
		cin >> x >> y;
		ll z = __gcd(x, y);
		cout << (M[x / z] * M[y / z]) % mod << "\n";
	}
	return 0;
}