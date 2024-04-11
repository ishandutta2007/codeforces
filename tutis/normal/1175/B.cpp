/*input
9
add
for 43
end
for 10
for 15
add
end
add
end
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r[101010];
ll spresk(ll i, ll j, ll a[])
{
	if (i > j)
		return 0;
	ll ret = 0;
	if (a[i] == 0)
	{
		ret = 1 + spresk(i + 1, j, a);
	}
	else if (a[i] > 0)
	{
		ret = a[i] * spresk(i + 1, r[i] - 1, a) + spresk(r[i] + 1, j, a);
	}
	else
	{
		cout << "?" << endl;
	}
	ret = min(ret, 1ll << 32);
	return ret;
}
int main()
{
	ll l;
	cin >> l;
	ll a[l];
	for (ll i = 0; i < l; i++)
	{
		string s;
		cin >> s;
		if (s == "add")
			a[i] = 0;
		else if (s == "end")
			a[i] = -1;
		else
		{
			cin >> a[i];
		}
	}
	ll d[l];
	ll dep = 0;
	for (ll i = 0; i < l; i++)
	{
		if (a[i] > 0)
			dep++;
		else if (a[i] < 0)
			dep--;
		d[i] = dep;
	}
	map<ll, ll>xx;
	for (ll i = l - 1; i >= 0; i--)
	{
		r[i] = xx[d[i] - 1];
		xx[d[i]] = i;
	}
	ll x = spresk(0, l - 1, a);
	if (x < (1ll << 32))
		cout << x << endl;
	else
	{
		cout << "OVERFLOW!!!\n";
	}
	return 0;
}