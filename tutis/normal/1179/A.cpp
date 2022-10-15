/*input
2 0
0 0

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll sz = 4e5;
ll aa[sz];
ll bb[sz];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	deque<ll>a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	for (ll t = 0; t < sz; t++)
	{
		ll A = a[0];
		ll B = a[1];
		aa[t] = A;
		bb[t] = B;
		a.pop_front();
		a.pop_front();
		if (A > B)
		{
			a.push_front(A);
			a.push_back(B);
		}
		else
		{
			a.push_front(B);
			a.push_back(A);
		}
	}
	while (q--)
	{
		ll k;
		cin >> k;
		k--;
		if (k >= sz)
		{
			ll a = (k - sz) / (n - 1);
			k -= a * (n - 1);
		}
		while (k >= sz)
		{
			k -= n - 1;
		}
		cout << aa[k] << " " << bb[k] << "\n";
	}

}