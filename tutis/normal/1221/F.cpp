/*input
5
3 3 0
3 3 -3
0 2 -1
3 1 3
0 0 -2

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y, c;
	ll i;
};
struct ST
{
	ll l, r;
	pair<ll, ll> maxi = { -1e17, -1};
	ll lazy = 0;
	ST *left, *right;
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
		maxi.first += lazy;
		if (l < r)
		{
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}
	void add(ll x, ll y, ll w)
	{
		fix();
		if (x <= l && r <= y)
		{
			lazy += w;
			return fix();
		}
		if (r < x || y < l)
			return;
		left->add(x, y, w);
		right->add(x, y, w);
		maxi = max(left->maxi, right->maxi);
	}
	void set(ll i, pair<ll, ll>w)
	{
		fix();
		if (l < r)
		{
			if (i <= (l + r) / 2)
				left->set(i, w);
			else
				right->set(i, w);
			maxi = max(left->maxi, right->maxi);
		}
		else
		{
			maxi = w;
		}
	}
	pair<ll, ll>get(int x, int y)
	{
		fix();
		if (x <= l && r <= y)
		{
			return maxi;
		}
		if (r < x || y < l)
			return { -1e17, -1};
		return max(left->get(x, y), right->get(x, y));
	}
} medis(0, 1005050);
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	point a[n];
	map<ll, ll>M;
	map<ll, ll>K;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].c;
		if (a[i].y < a[i].x)
			swap(a[i].x, a[i].y);
		M[a[i].x] = 0;
		M[a[i].y] = 0;
		K[a[i].y]++;
	}
	ll timer = 1;
	for (auto&i : M)
	{
		i.second = timer++;
		medis.set(i.second, {i.first, i.first});
	}
	sort(a, a + n, [&](point x, point y) {
		if (x.y == y.y)
			return x.x < y.x;
		return x.y < y.y;
	});
	ll x = 156;
	while (M.count(x))
		x++;
	pair<ll, pair<ll, ll>>ans = {0, {x, x}};
	for (point i : a)
	{
		K[i.y]--;
		medis.add(-1, M[i.x], i.c);
		if (K[i.y] == 0)
		{
			pair<ll, ll>mx = medis.get(0, M[i.y]);
			ans = max(ans, {mx.first - i.y, {mx.second, i.y}});
		}
	}
	cout << ans.first << "\n";
	cout << ans.second.first << " " << ans.second.first << " " << ans.second.second << " " << ans.second.second << "\n";
}