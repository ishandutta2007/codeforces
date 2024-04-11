/*input
3
1 0 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[n];
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		sum += a[i];
	}
	vector<ll>b;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < a[i]; j++)
			b.push_back(i);
	ll ans = 1e18;
	for (ll k = 1; k * k <= sum; k++)
	{
		if (sum % k == 0)
		{
			for (ll g : {k, sum / k})
			{
				if (g == 1)
					continue;
				ll gal = 0;
				for (int i = 0; i < b.size(); i += g)
				{
					ll id = b[i + (g - 1) / 2];
					for (int j = i; j < i + g; j++)
						gal += abs(b[j] - id);
				}
				ans = min(ans, gal);
			}
		}
	}
	if (ans > 1e15)
		ans = -1;
	cout << ans << "\n";
}