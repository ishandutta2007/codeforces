/*input
3
1 3
2 4
5 7
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll n;
	cin >> n;
	map<ll, ll>isime;
	map<ll, ll>idejo;
	set<ll>A;
	for (ll i = 0; i < n; i++)
	{
		ll l, r;
		cin >> l >> r;
		isime[r + 1]++;
		idejo[l]++;
		A.insert(l);
		A.insert(l - 1);
		A.insert(r);
		A.insert(r + 1);
	}
	ll xx = *A.begin();
	ll kiekis = 0;
	ll buvo = 0;
	ll ans[n + 1];
	fill_n(ans, n + 1, 0);
	for (ll x : A)
	{
		if (x != xx + 1)
			ans[buvo] += (x - xx - 1);
		kiekis += idejo[x];
		kiekis -= isime[x];
		ans[kiekis]++;


		buvo = kiekis;
		xx = x;
	}
	for (ll i = 1; i <= n; i++)
		cout << ans[i] << " ";
}