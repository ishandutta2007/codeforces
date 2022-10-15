/*input
21
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
	ll w = 9;
	ll nuo = 1;
	for (ll len = 1;; len++, w *= 10, nuo *= 10)
	{
		if (n <= len * w)
		{
			ll k = (n - 1) / (len);
			string s = to_string(nuo + k);
			cout << s[(n - 1) % len] << "\n";
			return 0;
		}
		else
			n -= len * w;
	}
}