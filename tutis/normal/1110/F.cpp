/*input
11 8
1 7
2 1
1 20
1 2
5 6
6 2
6 3
5 1
9 10
9 11
5 1 11
1 1 4
9 4 8
6 1 4
9 7 11
9 10 11
8 1 11
11 4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct ST
{
	ll l, r;
	ll mn = 0;
	ll lazy = 0;
} A[500000 * 4];
void create(ll l, ll r, ll i = 0)
{
	A[i].l = l;
	A[i].r = r;
	if (l < r)
	{
		create(l, (l + r) / 2, 2 * i + 1);
		create((l + r) / 2 + 1, r, 2 * i + 2);
	}
}
void fix(int i)
{
	A[i].mn += A[i].lazy;
	if (A[i].l < A[i].r)
	{
		A[2 * i + 1].lazy += A[i].lazy;
		A[2 * i + 2].lazy += A[i].lazy;
	}
	A[i].lazy = 0;
}
ll get(ll x, ll y, int i = 0, ll sum = 0)
{
	sum += A[i].lazy;
	if (x <= A[i].l && A[i].r <= y)
		return A[i].mn + sum;
	if (A[i].r < x || y < A[i].l)
		return 1e17;
	return min(get(x, y, 2 * i + 1, sum), get(x, y, 2 * i + 2, sum));
}
void add(ll x, ll y, ll w, int i = 0)
{
	if (x <= A[i].l && A[i].r <= y)
	{
		A[i].lazy += w;
		return fix(i);
	}
	fix(i);
	if (A[i].r < x || y < A[i].l)
		return;
	add(x, y, w, 2 * i + 1);
	add(x, y, w, 2 * i + 2);
	A[i].mn = min(A[2 * i + 1].mn, A[2 * i + 2].mn);
}
vector<pair<ll, ll>>adj[500005];
ll d[500005];
ll iki[500005];
void dfs(ll i)
{
	iki[i] = i;
	for (pair<ll, ll>j : adj[i])
	{
		d[j.first] = d[i] + j.second;
		dfs(j.first);
		iki[i] = iki[j.first];
	}
}
vector<pair<pair<ll, ll>, ll>>quer[500005];
ll ans[500005];
ll delta = 0;
void dfs1(ll i)
{
	for (pair<pair<ll, ll>, ll>x : quer[i])
	{
		ans[x.second] = get(x.first.first, x.first.second) + delta;
	}
	for (pair<ll, ll>j : adj[i])
	{
		delta += j.second;
		add(j.first, iki[j.first], -2 * j.second);
		dfs1(j.first);
		delta -= j.second;
		add(j.first, iki[j.first], 2 * j.second);
	}
}
int main()
{
	create(0, 500005, 0);
	ios_base::sync_with_stdio(false);
	ll n, q;
	cin >> n >> q;
	for (ll i = 2; i <= n; i++)
	{
		ll p, w;
		cin >> p >> w;
		adj[p].push_back({i, w});
	}
	d[1] = 0;
	dfs(1);
	for (ll i = 0; i < q; i++)
	{
		ll v, l, r;
		cin >> v >> l >> r;
		quer[v].push_back({{l, r}, i});
	}
	for (ll i = 1; i <= n; i++)
	{
		if (adj[i].size() == 0)
			add(i, i, d[i]);
		else
			add(i, i, 1e17);
	}
	dfs1(1);
	for (ll i = 0; i < q; i++)
		cout << ans[i] << "\n";
}