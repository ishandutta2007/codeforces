/*input
6 2 987 789
-8 42 -4 -65 -8 -8
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n, k, B, c;
	cin >> n >> k >> B >> c;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll x = *min_element(a, a + n);
	for (int i = 0; i < n; i++)
		a[i] = a[i] - x;
	B = min(B, 5 * c);
	ll ans = 1e18;
	for (int t = 0; t < 5; t++)
	{
		pair<ll, ll>b[n];
		for (int i = 0; i < n; i++)
		{
			b[i] = {a[i], 0};
			while (b[i].first % 5 != t)
			{
				b[i].first++;
				b[i].second += c;
			}
			b[i].first /= 5;
		}
		sort(b, b + n);
		priority_queue<ll>G;
		ll suma = 0;
		for (int i = 0; i < n; i++)
		{
			if (G.size() >= k - 1)
			{
				ans = min(ans, b[i].second + b[i].first * B * (k - 1) + suma);
			}
			G.push(b[i].second - b[i].first * B);
			suma += b[i].second - b[i].first * B;
			while (G.size() >= k)
			{
				suma -= G.top();
				G.pop();
			}
		}

	}
	cout << ans << "\n";
}