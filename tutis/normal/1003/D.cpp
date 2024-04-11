/*input
5 4
2 4 8 2 4
8
5
14
10
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll kiek[60];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	while (n--)
	{
		ll a;
		cin >> a;
		for (int d = 0;; d++)
		{
			if (a == (1ll << d))
			{
				kiek[d]++;
				break;
			}
		}
	}
	while (q--)
	{
		ll B;
		cin >> B;
		ll ans = 0;
		for (int t = 59; t >= 0; t--)
		{
			ll k = min(kiek[t], B / (1ll << t));
			B -= k * (1ll << t);
			ans += k;
		}
		if (B > 0)
		{
			cout << "-1\n";
		}
		else
		{
			cout << ans << "\n";
		}
	}

}