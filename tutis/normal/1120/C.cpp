/*input
4 10 1
aaaa

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll W = 57;
const ll modulo = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, a, b;
	cin >> n >> a >> b;
	string s;
	cin >> s;
	s = "{" + s;
	ll DP[n + 1];
	DP[0] = 0;
	ll H[n + 1];
	ll w[n + 1];
	H[0] = 0;
	w[0] = 1;
	for (ll i = 1; i <= n; i++)
		w[i] = (w[i - 1] * W) % modulo;
	map<ll, ll>pirmas;
	for (ll i = 1; i <= n; i++)
	{
		H[i] = H[i - 1];
		H[i] += w[i] * ll(s[i] - 'a' + 1);
		H[i] %= modulo;
	}
	set<char>buvo;
	for (ll i = 1; i <= n; i++)
	{
		DP[i] = DP[i - 1] + a;
		if (buvo.count(s[i]))
		{
			ll lo = 1;
			ll hi = i;
			while (lo < hi)
			{
				ll sz = (lo + hi + 1) / 2;
				bool ok = false;
				for (ll j = i - sz; j >= sz; j--)
				{
					ll H1 = (H[i] - H[i - sz] + modulo) % modulo;
					ll H2 = (H[j] - H[j - sz] + modulo) % modulo;
					H2 *= w[i - j];
					H2 %= modulo;
					if (H1 == H2)
						ok = true;
				}
				if (ok)
					lo = sz;
				else
					hi = sz - 1;
			}
			ll sz = (lo + hi) / 2;
			DP[i] = min(DP[i], DP[i - sz] + b);
		}
		buvo.insert(s[i]);
	}
	cout << DP[n] << endl;
}