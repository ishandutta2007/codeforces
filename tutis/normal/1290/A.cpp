/*input
4
6 4 2
2 9 2 3 8 5
4 4 1
2 13 60 4
4 1 3
1 2 2 1
2 2 0
1 2

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, m, k;
		cin >> n >> m >> k;
		k = min(k, m - 1);
		ll a[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		ll lo = *min_element(a, a + n);
		ll hi = *max_element(a, a + n);
		while (lo < hi)
		{
			ll x = (lo + hi + 1) / 2;
			bool ok = false;
			ll A = m - 1 - k;
			for (ll d = 0; d <= k; d++)
			{
				bool gerai = true;
				for (ll al = 0; al <= A; al++)
				{
					if (a[d + al] < x && a[n - 1 - (m - 1 - (d + al))] < x)
						gerai = false;
				}
				if (gerai)
				{
					ok = true;
					break;
				}
			}
			if (ok)
				lo = x;
			else
				hi = x - 1;
		}
		cout << lo << "\n";
	}
}