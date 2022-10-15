/*input
1 4
19

*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	k -= n;
	int c[n];
	for (int i = 0; i < n; i++)
		c[i] = 1;
	auto f = [&](int i, int k)
	{
		if (k >= a[i])
			return a[i];
		else
		{
			ll x = a[i] / k;
			ll y = a[i] % k;
			return y * (x + 1) * (x + 1) + (k - y) * x * x;
		}
	};
	set<pair<ll, int>>X;
	for (int i = 0; i < n; i++)
		X.insert({f(i, c[i] + 1) - f(i, c[i]), i});
	for (int t = 0; t < k; t++)
	{
		auto it = X.begin();
		int i = it->second;
		X.erase(it);
		c[i]++;
		X.insert({f(i, c[i] + 1) - f(i, c[i]), i});
	}
	ll ret = 0;
	for (int i = 0; i < n; i++)
		ret += f(i, c[i]);
	cout << ret << "\n";
}