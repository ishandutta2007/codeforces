/*input
6 4
1 2 5 10 15 20
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, B;
	cin >> n >> B;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	ll sum = 0;
	vector<ll>X;
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			sum++;
		else
			sum--;
		if (i != n - 1 && sum == 0)
		{
			X.push_back(abs(a[i] - a[i + 1]));
		}
	}
	sort(X.begin(), X.end());
	ll ans = 0;
	for (ll i : X)
	{
		if (B - i >= 0)
		{
			B -= i;
			ans++;
		}
	}
	cout << ans << "\n";
}