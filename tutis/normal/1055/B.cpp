/*input
4 7 3
1 2 3 4
0
1 2 3
0
1 1 3
0
1 3 1
0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, l;
	cin >> n >> m >> l;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	map<ll, ll>M;
	ll L = 0;
	for (ll r = 1; r <= n; r++)
	{
		if (a[r] > l)
		{

		}
		else
		{
			if (r - 1 >= 1 && a[r - 1] > l)
			{
				M[L] = (r - 1);
			}
			L = r + 1;
		}
	}
	if (a[n] > l)
	{
		M[L] = n;
	}
	while (m--)
	{
		ll t;
		cin >> t;
		if (t == 0)
		{
			cout << M.size() << "\n";
		}
		else
		{
			ll i, p;
			cin >> i >> p;
			if (a[i] <= l)
			{
				a[i] += p;
				a[i] = min(a[i], l + 1);
				if (a[i] > l)
				{
					ll R = i;
					ll L = i;
					if (i + 1 <= n && a[i + 1] > l)
					{
						R = M[i + 1];
						M.erase(i + 1);
					}
					if (i - 1 >= 1 && a[i - 1] > l)
					{
						auto it = M.lower_bound(i);
						it--;
						L = it->first;
					}
					M[L] = R;
				}
			}
		}
	}


}