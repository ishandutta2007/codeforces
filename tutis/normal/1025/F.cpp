/*input
7
0 -1000000000
-5 -5
5 -5
-5 0
5 0
-2 2
2 2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld PI = acosl(-1);
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct poll
{
	ll x, y;
	poll() {}
	poll(ll x, ll y): x(x), y(y)
	{

	}
	ll ketv()
	{
		if (x >= 0 && y >= 0)
			return 1;
		if (x <= 0 && y >= 0)
			return 2;
		if (x <= 0 && y <= 0)
			return 3;
		return 4;
	}
	ld kampas()
	{
		ld ret = atan2(y, x);
		if (ret < 0)
			ret += 2 * PI;
		return ret;
	}
};
poll operator+(poll a, poll b)
{
	return poll(a.x + b.x, a.y + b.y);
}
poll operator-(poll a, poll b)
{
	return poll(a.x - b.x, a.y - b.y);
}
poll operator*(poll a, ll k)
{
	return poll(a.x * k, a.y * k);
}
poll operator*(poll a, poll b)
{
	return poll(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
ll cross(poll a, poll b)
{
	return a.x * b.y - a.y * b.x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	poll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i].x >> a[i].y;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		vector<poll>b;
		for (ll j = 0; j < n; j++)
		{
			if (j != i)
				b.push_back(a[j] - a[i]);
		}
		sort(b.begin(), b.end(), [&](poll a, poll b) {
			if (a.ketv() != b.ketv())
				return a.ketv() < b.ketv();
			return cross(a, b) > 0;
		});
		ll k1 = 0;
		for (ll j = 0; j < (ll)b.size(); j++)
		{
			k1++;
			k1 = min(k1, n - 2);
			while (cross(b[j], b[(j + k1 + 1) % b.size()]) > 0)
				k1++;
			while (cross(b[j], b[(j + k1) % b.size()]) < 0)
				k1--;
			ll k2 = n - 2 - k1;
			ans += (k1 * (k1 - 1) * (k2) * (k2 - 1)) / 4;
		}
	}
	cout << ans / 2 << "\n";
}