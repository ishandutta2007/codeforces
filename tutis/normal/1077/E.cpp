/*input
3
1337 1337 1337
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	map<ll, ll>A;
	while (n--)
	{
		ll a;
		cin >> a;
		A[a]++;
	}
	vector<ll>B;
	for (pair<ll, ll>i : A)
		B.push_back(i.second);
	sort(B.begin(), B.end(), greater<ll>());
	ll ans = 0;
	for (ll kiek = 1; kiek <= 32 && kiek <= B.size(); kiek++)
	{
		ll mn = 1000000000000ll;
		for (ll i = 0; i < kiek; i++)
		{
			mn = min(mn, B[i] / (1ll << (kiek - 1 - i)));
		}
		ll suma = 0;
		for (ll i = 0; i < kiek; i++)
		{
			suma += (1ll << (kiek - 1 - i));
		}
		ans = max(ans, suma * mn);
	}
	cout << ans << "\n";
}