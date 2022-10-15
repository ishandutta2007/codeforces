/*input
3 7
1 4 9

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
const ll mod = 1000000000 + 7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	if (n > m)
	{
		cout << "0\n";
		return 0;
	}
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll ret = 1;
	for (int i = 0; i < n; i++)
	{
		a[i] %= m;
		for (int j = 0; j < i; j++)
		{
			ret *= a[i] - a[j];
			ret %= m;
		}
	}
	if (ret < 0)
		ret += m;
	cout << ret << "\n";
}