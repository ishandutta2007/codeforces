/*input
2 3
-1 3
0 0
-1 -4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll asum(ll x)
{
	return x * (x + 1) / 2;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	ll ans = 0;
	ll mn = n * n * n;
	for (int i = 1; i <= n; i++)
	{
		mn = min(mn, asum(abs(i - 1)) + asum(abs(n - i)));
	}
	while (m--)
	{
		ll x, d;
		cin >> x >> d;
		ans += x * n;
		if (d >= 0)
		{
			ans += ((d) * (n - 1) * n) / 2;
		}
		else
		{
			ans += (mn * d);
		}
	}
	cout << fixed << setprecision(15) << (ld(ans) / ld(n)) << "\n";
}