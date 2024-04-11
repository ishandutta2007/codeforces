/***
2 4
1 2
3 4
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	ll val = 0;
	ST *left, *right;
	ST(ll l, ll r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void set(ll i, ll v)
	{
		if (l <= i && i <= r)
		{
			if (l == r)
			{
				val = max(val, v);
			}
			else
			{
				left->set(i, v);
				right->set(i, v);
				val = max(left->val, right->val);
			}
		}
	}
	ll get(ll x, ll y)
	{
		if (x <= l && r <= y)
			return val;
		if (r < x || y < l)
			return 0;
		return max(left->get(x, y), right->get(x, y));
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, m;
	cin >> n >> m;
	ll A[m + 2];
	fill_n(A, m + 2, 0);
	for (ll i = 0; i < n; i++)
	{
		ll l, r;
		cin >> l >> r;
		A[l]++;
		A[r + 1]--;
	}
	for (ll i = 1; i <= m; i++)
		A[i] += A[i - 1];
	ll MN[m + 2];
	MN[m + 1] = 1000000;
	MN[m] = A[m];
	for (ll i = m - 1; i > 0; i--)
		MN[i] = min(MN[i + 1], A[i]);
	ll ans = 0;
	ST Y(0, n + 5);
	ST Z(0, n + 5);
	int D[m + 1];
	for (ll i = m; i >= 1; i--)
	{
		int c = Z.get(0, A[i]);
		Z.set(A[i], 1 + c);
		D[i] = 1 + c;
	}
	for (ll i = 1; i <= m; i++)
	{
		ll d = 1 + Y.get(0, A[i]);
		Y.set(A[i], d);
		ans = max(ans, d);
		if (MN[i + 1] <= A[i])
			ans = max(ans, d + D[i] - 1);
	}
	cout << ans << "\n";
}