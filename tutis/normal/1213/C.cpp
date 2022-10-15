/*input
7
1 1
10 1
100 3
1024 14
998244353 1337
123 144
1234312817382646 13

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int q;
	cin >> q;
	while (q--)
	{
		ll n, m;
		cin >> n >> m;
		ll ans = 0;
		for (ll a = 0; a < 10; a++)
		{
			//(10x+a) * m <= n
			//(10x+a) <= c
			ll c = n / m;
			ll d = c - a;
			if (d < 0)
				continue;
			ans += ((a * m) % 10) * (d / 10 + 1);
		}
		cout << ans << "\n";
	}
}