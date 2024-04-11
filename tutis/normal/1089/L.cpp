/*input
3 3
3 1 2
5 3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	map<ll, ll>K;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		K[a[i]]++;
	}
	vector<pair<ll, ll>>b;
	for (ll i = 0; i < n; i++)
	{
		ll c;
		cin >> c;
		b.push_back({c, i});
	}
	sort(b.begin(), b.end());
	ll ans = 0;
	ll c = 0;
	for (pair<ll, ll>i : b)
	{
		if (c + K.size() >= k)
			break;
		if (K[a[i.second]] >= 2)
		{
			ans += i.first;
			K[a[i.second]]--;
			c++;
			if (c + K.size() >= k)
				break;
		}
	}
	cout << ans << "\n";
}