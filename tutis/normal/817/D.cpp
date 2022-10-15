/*input
3
1 4 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll suma = 0;
	bool lazy = false;
	ll set = 0;
	ll l, r;
	ST *left;
	ST *right;
	ST(ll l, ll r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void fix()
	{
		if (lazy)
		{
			suma = (r - l + 1) * set;
			if (l < r)
			{
				left->set = set;
				right->set = set;
				left->lazy = true;
				right->lazy = true;
			}
			lazy = false;
		}
	}
	void Set(ll a, ll b, ll w)
	{
		if (a <= l && r <= b)
		{
			set = w;
			lazy = true;
			return fix();
		}
		fix();
		if (b < l || r < a)
			return;
		left->Set(a, b, w);
		right->Set(a, b, w);
		suma = left->suma + right->suma;
	}
	ll get(ll a, ll b)
	{
		if (a <= l && r <= b)
		{
			fix();
			return suma;
		}
		if (b < l || r < a)
			return 0;
		fix();
		return left->get(a, b) + right->get(a, b);
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	stack<ll>MX;
	stack<ll>MN;
	ST X(0, n - 1);
	ST Y(0, n - 1);
	ll ans = 0;
	for (ll r = 0; r < n; r++)
	{
		while (!MX.empty() && a[MX.top()] <= a[r])
			MX.pop();
		while (!MN.empty() && a[MN.top()] >= a[r])
			MN.pop();
		if (MX.empty())
		{
			X.Set(0, r, a[r]);
		}
		else
		{
			X.Set(MX.top() + 1, r, a[r]);
		}
		if (MN.empty())
		{
			Y.Set(0, r, a[r]);
		}
		else
		{
			Y.Set(MN.top() + 1, r, a[r]);
		}
		ans += X.get(0, n - 1) - Y.get(0, n - 1);
		MX.push(r);
		MN.push(r);
	}
	cout << ans << "\n";
}