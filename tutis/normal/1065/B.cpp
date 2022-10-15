/*input
4 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	if (m == 0)
	{
		cout << n << " " << n << "\n";
		return 0;
	}
	ll mini = n + 1;
	ll maxi = 0;
	for (ll a = 0; a < n; a++)
	{
		ll b = n - a;
		if (b - 1 <= m && m <= (b) * (b - 1) / 2)
		{
			mini = min(mini, a);
			maxi = max(maxi, a);
		}
	}
	mini = min(mini, n - 2 * m);
	mini = max(mini, 0ll);
	cout << mini << " " << maxi << "\n";
}