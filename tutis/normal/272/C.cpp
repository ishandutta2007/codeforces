/*input
5
1 2 3 6 6
4
1 1
3 1
1 1
4 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	ll mx = 0;
	ll lazy;
	bool leizi = false;
	ST *left;
	ST *right;
	ST(ll l, ll r, ll a[]): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2, a);
			right = new ST((l + r) / 2 + 1, r, a);
			mx = max(left->mx, right->mx);
		}
		else
		{
			mx = a[l];
		}
	}
	void fix()
	{
		if (leizi)
		{
			mx = lazy;
			if (l < r)
			{
				right->lazy = lazy;
				left->lazy = lazy;
				left->leizi = true;
				right->leizi = true;
			}
			leizi = false;
		}
	}
	ll maxi(ll a, ll b)
	{
		fix();
		if (a <= l && r <= b)
			return mx;
		if (r < a || b < l)
			return 0;
		return max(left->maxi(a, b), right->maxi(a, b));
	}
	void set(ll a, ll b, ll w)
	{
		if (a <= l && r <= b)
		{
			leizi = true;
			lazy = w;
			return fix();
		}
		fix();
		if (r < a || b < l)
			return;
		left->set(a, b, w);
		right->set(a, b, w);
		mx = max(left->mx, right->mx);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ST X(1, n, a);
	ll q;
	cin >> q;
	while (q--)
	{
		ll w, h;
		cin >> w >> h;
		ll c = X.maxi(1, w);
		X.set(1, w, h + c);
		cout << c << "\n";
	}
}