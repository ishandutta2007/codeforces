/*input
4
2 2 2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll N = n;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	sort(a, a + n);
	ll mx = a[n - 1];
	ll suma = 0;
	for (ll &i : a)
		suma += mx - i;
	if (suma >= mx)
	{
		cout << mx << "\n";
		return 0;
	}
	ll k = mx - suma;
	ll x = k / (N - 1);
	suma += x * N;
	k %= (N - 1);
	if (k != 0)
		suma += k + 1;
	cout << suma << "\n";
}