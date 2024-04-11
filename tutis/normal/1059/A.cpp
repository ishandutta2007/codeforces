/*input
1 3 2
1 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, L, a;
	cin >> n >> L >> a;
	if (n == 0)
	{
		cout << (L) / a << "\n";
		return 0;
	}
	ll t[n];
	ll l[n];
	for (int i = 0; i < n; i++)
		cin >> t[i] >> l[i];
	ll ans = (t[0] / a);
	for (int i = 1; i < n; i++)
		ans += (t[i] - t[i - 1] - l[i - 1]) / a;
	ans += (L - t[n - 1] - l[n - 1]) / a;
	cout << ans << "\n";
}