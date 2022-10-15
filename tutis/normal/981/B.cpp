/*input
1
1000000000 239
3
14 15
92 65
35 89
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	map<ll, ll>A;
	map<ll, ll>B;
	ll n;
	cin >> n;
	while (n--)
	{
		ll a, x;
		cin >> a >> x;
		A[a] = x;
	}
	ll m;
	cin >> m;
	while (m--)
	{
		ll b, x;
		cin >> b >> x;
		B[b] = x;
	}
	ll ans = 0;
	for (pair<ll, ll>a : A)
	{
		if (B.count(a.first))
		{
			if (a.second > B[a.first])
				ans += a.second;
		}
		else
		{
			ans += a.second;
		}
	}
	for (pair<ll, ll>a : B)
	{
		if (A.count(a.first))
		{
			if (a.second >= A[a.first])
				ans += a.second;
		}
		else
		{
			ans += a.second;
		}
	}

	cout << ans << "\n";
}