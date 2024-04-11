/*input
5
6 7 4
10 7 12
12 30 7
1 1 1
3247834 10298779 625324

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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll m, d, w;
		cin >> m >> d >> w;
		ll ans = 0;
		ll n = min(m, d);
		if (d == 1)
			ans = n * n;
		else
		{
			d--;
			ll g = __gcd(d, w);
			w /= g;
			ll k = n / w;//po w
			ll k1 = n % w;
			ans += k1 * (k * k + 2 * k + 1);
			ans += (w - k1) * (k * k);
		}
		cout << (ans - n) / 2 << endl;
	}


	return 0;
}