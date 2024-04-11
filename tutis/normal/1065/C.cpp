/*input
4 5
2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	ll h[n];
	for (ll i = 0; i < n; i++)
		cin >> h[i];
	ll sum[200009];
	for (ll i = 0; i < 200009; i++)
		sum[i] = 0;
	for (ll i = 0; i < n; i++)
	{
		sum[0]++;
		sum[h[i] + 1]--;
	}
	for (ll i = 1; i < 200009; i++)
		sum[i] += sum[i - 1];
	ll mini = *min_element(h, h + n);
	ll maxi = *max_element(h, h + n);
	ll ans = 0;
	ll c = 0;
	for (ll a = maxi; a > mini; a--)
	{
		c += sum[a];
		if (c > k)
		{
			c = sum[a];
			ans++;
		}
	}
	if (c > 0)
		ans++;
	cout << ans << "\n";
}