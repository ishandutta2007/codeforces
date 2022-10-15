/*input
4
4 3 2 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ld LL = -1e18, RR = 1e18;
struct CHT
{
	ll k = 0, b = -1e18;
	CHT *left = NULL, *right = NULL;
	bool reset = false;
	CHT(ll k, ll b): k(k), b(b)
	{
	}
	void add(ll k_, ll b_, ld l = LL, ld r = RR)
	{
		if (reset)
		{
			k = k_;
			b = b_;
			if (left)
				left->reset = true;
			if (right)
				right->reset = true;
			reset = false;
			return;
		}
		if (abs(r - l) < 0.001)
			return;
		ld m = (l + r) / 2;
		ld fm = k * m + b;
		ld gm = k_ * m + b_;
		if (gm >= fm)
		{
			swap(k, k_);
			swap(b, b_);
		}
		if (k_ * l + b_ > k * l + b)
		{
			if (left == NULL)
			{
				left = new CHT(k_, b_);
			}
			else
			{
				left->add(k_, b_, l, m);
			}
		}
		else if (k_ * r + b_ > k * r + b)
		{
			if (right == NULL)
			{
				right = new CHT(k_, b_);
			}
			else
			{
				right->add(k_, b_, m, r);
			}
		}
	}
	ld get(ld x, ld l = LL, ld r = RR)
	{
		if (reset)
		{
			k = 0;
			b = -1e18;
			if (left)
				left->reset = true;
			if (right)
				right->reset = true;
			reset = false;
			return -1e18;
		}
		ld m = (l + r) / 2;
		if (x < m)
		{
			if (left)
				return max(k * x + b, left->get(x, l, m));
		}
		else if (right != NULL)
			return max(k * x + b, right->get(x, m, r));
		return k * x + b;
	}
} X(0, -1e18);
ll f(ll n, ll a[])
{
	X.reset = true;
	ll ret = 0;
	for (int i = 1; i <= n; i++)
		ret += a[i] * i;
	ll s[n + 1];
	s[0] = 0;
	for (int i = 1; i <= n; i++)
		s[i] = a[i] + s[i - 1];
	ll delt = 0;
	for (ll i = n - 1; i >= 1; i--)
	{
		ll nuoi = a[i] * (-i) + s[i];
		X.add(i + 1, -s[i + 1]);
		delt = max(delt, nuoi + ll(roundl(X.get(a[i]))));
	}
	return ret + delt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	ll ans = f(n, a);
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i];
	reverse(a + 1, a + (n + 1));
	for (int i = 1; i <= n; i++)
		a[i] = -a[i];
	ll ans1 = sum * (n + 1) + f(n, a);
	cout << max(ans, ans1) << "\n";
}