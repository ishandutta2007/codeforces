/*input
5 1
-1 -2 -3 -4 5

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll n, k;
	cin >> n >> k;
	k++;
	k = min(k, n);
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll ret = -1e18;
	ll sum = 0;
	ll s1[n], s2[n];
	for (ll i = n - 1; i >= 0; i--)
	{
		s1[i] = a[i];
		s2[i] = a[i] * i;
		if (i + 1 < n)
		{
			s1[i] += s1[i + 1];
			s2[i] += s2[i + 1];
		}
	}
	for (ll i = 0; i < n; i++)
	{
		sum += a[i] * (i / k);
		ll gal = sum;
		if (i + 1 < n)
		{
			gal += s1[i + 1] * (i / k - i);
			gal += s2[i + 1];
		}
		ret = max(ret, gal);
	}
	cout << ret << "\n";
}