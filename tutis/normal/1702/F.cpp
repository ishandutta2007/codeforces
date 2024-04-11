/*input
5
4
2 4 5 24
1 4 6 11
3
1 4 17
4 5 31
5
4 7 10 13 14
2 14 14 26 42
5
2 2 4 4 4
28 46 62 71 98
6
1 2 10 16 64 80
20 43 60 74 85 99
*/

#pragma GCC optimize ("O3")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		multiset<ll>A;
		for (ll i = 0; i < n; i++)
		{
			ll a;
			cin >> a;
			while (a % 2 == 0)
				a /= 2;
			A.insert(a);
		}
		multiset<ll>B;
		for (ll i = 0; i < n; i++)
		{
			ll a;
			cin >> a;
			while (a * 2 <= 1000000000)
				a *= 2;
			B.insert(a);
		}
		bool ok = true;
		while (!B.empty())
		{
			ll x = *(--B.end());
			B.erase(B.find(x));
			if (A.count(x) != 0)
			{
				A.erase(A.find(x));
			}
			else
			{
				x /= 2;
				if (x != 0)
				{
					B.insert(x);
				}
				else
				{
					ok = false;
					break;
				}
			}
		}
		if (ok)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}