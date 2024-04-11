/*input
3 2 1
3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, s1, s2;
	cin >> n >> s1 >> s2;
	ll lo = abs(s1 - s2);
	ll hi = 1000000000;
	ll x[n + 1];
	x[0] = s1;
	for (ll i = 1; i <= n; i++)
	{
		cin >> x[i];
	}
	while (lo < hi)
	{
		ll d = (lo + hi) / 2;
		set<ll>a;
		a.insert(s2);
		for (ll i = 1; i <= n; i++)
		{
			bool ok = false;
			while (!a.empty() && *a.begin() < x[i] - d)
				a.erase(a.begin());
			while (!a.empty() && *(--a.end()) > x[i] + d)
				a.erase((--a.end()));
			if (abs(x[i] - x[i - 1]) <= d)
				a.insert(x[i - 1]);
			if (a.empty())
				break;
		}
		if (a.empty())
			lo = d + 1;
		else
			hi = d;
	}
	cout << lo << "\n";
}