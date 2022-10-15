/*input
4 1
3 -1 6 0

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll k, n;
	cin >> n >> k;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = n - 2; i >= 0; i--)
		a[i] += a[i + 1];
	if (n > 1)
		sort(a + 1, a + n, greater<ll>());
	ll ans = 0;
	for (int i = 0; i < k; i++)
		ans += a[i];
	cout << ans << "\n";
	return 0;
}