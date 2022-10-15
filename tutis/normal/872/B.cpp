/*input
5 2
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000 * 1000 * 1000 + 7;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	ll a[n];
	for (ll &i : a)
		cin >> i;
	if (k == 1)
		cout << *min_element(a, a + n) << '\n';
	if (k >= 3)
		cout << *max_element(a, a + n) << '\n';
	if (k == 2)
	{
		ll ans = *min_element(a, a + n);
		vector<ll>b[2];
		for (int t = 0; t < 2; t++)
		{
			reverse(a, a + n);
			b[t].push_back(a[0]);
			for (int i = 1; i < n; i++)
			{
				b[t].push_back(min(b[t].back(), a[i]));
			}
		}
		for (int i = 1; i < n; i++)
		{
			ans = max(ans, max(b[0][i - 1], b[1][n - i - 1]));
		}
		cout << ans << "\n";
	}
}