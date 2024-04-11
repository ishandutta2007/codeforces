/*input
1
1 1
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int sgn(ll x)
{
	if (x > 0)
		return 1;
	if (x < 0)
		return -1;
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll v[n];
	ll msk[n];
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i] >> msk[i];
		sum += v[i];
	}
	if (sum < 0)
	{
		for (int i = 0; i < n; i++)
			v[i] *= -1;
		sum *= -1;
	}
	ll a[65];
	fill_n(a, 65, 0ll);
	for (int i = 0; i < n; i++)
		a[__builtin_ctzll(msk[i])] += v[i];
	ll s = 0;
	for (int c = 62; c >= 0; c--)
	{
		if (a[c] > 0)
		{
			s += (1ll << c);
			for (int i = 0; i < n; i++)
			{
				if ((msk[i] & (1ll << c)) > 0)
				{
					a[__builtin_ctzll(msk[i])] -= 2 * v[i];
					v[i] = -v[i];
				}
			}
		}
	}
	cout << s << "\n";
}