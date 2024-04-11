/*input
5 4
1
2
3
4
1
3
5
7
*/
#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
ll power(ll x, ll y)
{
	if (abs(x) >= mod)
		x %= mod;
	if (x < 0)
		x += mod;
	if (abs(y) >= mod - 1)
		y %= mod - 1;
	if (y < 0)
		y += mod - 1;
	ll r = 1;
	while (y != 0)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	ll l[m];
	for (int i = 0; i < m; i++)
	{
		string s(m, '0');
		s[i] = '1';
		cout << "? " << s << endl;
		cin >> l[i];
	}
	ll ret = 0;
	string s(m, '0');
	ll val = 0;
	int p[m];
	for (int i = 0; i < m; i++)
		p[i] = i;
	sort(p, p + m, [&](int x, int y) {return l[x] < l[y];});
	for (int i : p)
	{
		s[i] = '1';
		cout << "? " << s << endl;
		ll val1;
		cin >> val1;
		if (val1 == val + l[i])
		{
			ret += l[i];
			val = val1;
		}
		else
		{
			s[i] = '0';
		}
	}
	cout << "! " << ret << endl;
}