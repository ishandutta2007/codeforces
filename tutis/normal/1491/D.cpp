/*input
5
1 4
3 6
1 6
6 2
5 5

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
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int q;
	cin >> q;
	while (q--)
	{
		ll a, b;
		cin >> a >> b;
		while (a < b)
		{
			ll c = 0;
			for (ll t = (1ll << 32); t > 0; t /= 2)
			{
				if ((a & t) != 0)
				{
					if (a + c + t <= b)
					{
						c += t;
						break;
					}
				}
			}
			if (c == 0)
				break;
			a += c;
		}
		if (a == b)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}