/*input
7
1 1 1 1
2 2 2 2
1 2 3 4
4 3 2 1
228 21 11 3
239 21 11 3
1000000 1 1000000 1

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a - b * c > 0)
			cout << "-1\n";
		else
		{
			ll lo = 0;
			ll hi = c / d;
			auto f = [&](ll t)
			{
				ll x = t + 1;
				return a * x - b * d * x * (x - 1) / 2;
			};
			ll ret = a;
			while (hi - lo + 1 >= 4)
			{
				ll m = (lo + hi) / 2;
				ll f1 = f(m - 1);
				ll f2 = f(m);
				ll f3 = f(m + 1);
				ret = max({ret, f1, f2, f3});
				if (f3 >= f2)
					lo = m + 1;
				else
					hi = m - 1;
			}
			for (ll i = lo; i <= hi; i++)
				ret = max(ret, f(i));
			cout << ret << "\n";
		}
	}
}