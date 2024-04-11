/***
204
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll D(ll n)
{
	ll ans = 0;
	while (n > 0)
	{
		ans += n % 10;
		n /= 10;
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	vector<ll>ans;
	for (ll x = n; x > 0 && x >= n - 100; x--)
	{
		if (x + D(x) == n)
			ans.push_back(x);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << "\n";
}