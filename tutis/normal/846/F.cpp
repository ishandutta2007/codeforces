#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n];
	ll ans = -n;
	ll last[1000001];
	fill_n(last, 1000001, -1);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll i = 0; i < n; i++)
	{
		ans += 2 * (i - last[a[i]]) * (n - i);
		last[a[i]] = i;
	}
	cout << (ld(ans) / ld(n * n));
}