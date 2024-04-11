/*input
4
5
231
7
2323
6
333
24
133321333
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll modulo = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	ll t;
	cin >> t;
	while (t--)
	{
		ll x;
		string s;
		cin >> x >> s;
		ll n = s.size();
		for (ll l = 1; l <= x; l++)
		{
			ll r = (n - l + modulo) % modulo;
			if (s.size() <= x)
			{
				ll k = (s[l - 1] - '0') - 1;
				string c = s.substr(l, s.size() - l);
				while (k--)
					s += c;
			}
			n = l + r * ll(s[l - 1] - '0');
			n %= modulo;
		}
		cout << n << "\n";
	}
}