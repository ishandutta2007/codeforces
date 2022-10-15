/*input
11
0 0 0 5 0 0 0 4 0 0 11
9 2 6 0 8 1 7 0 3 0 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll t[n + 1];
	set<ll>a;
	for (ll i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		a.insert(x);
		t[x] = 0;
	}
	ll ans = 0;
	deque<ll>b(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> b[i];
		t[b[i]] = i + 1;
	}
	ll gal = 0;
	while (a.count(b.back() + 1))
	{
		ll x = b.back();
		a.insert(b[0]);
		b.pop_front();
		b.push_back(x + 1);
		a.erase(x + 1);
		gal++;
	}
	bool ok = true;
	for (ll i = 0; i < n; i++)
	{
		ok &= (b[i] == i + 1);
	}
	for (ll i = 1; i <= n; i++)
	{
		ans = max(ans, t[i] + n - i + 1);
	}
	if (ok == false)
		gal = ans + 1;
	cout << min(ans, gal) << "\n";
	return 0;
}