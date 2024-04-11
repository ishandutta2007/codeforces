/*input
5
1 2
1 3
1 4
4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<ll>adj[505050];
ll h[505050];
ll a[505050];
ll d[505050];
void dfs1(ll i, ll p)
{
	h[i] = 1;
	for (ll j : adj[i])
	{
		if (j != p)
		{
			d[j] = d[i] + 1;
			dfs1(j, i);
			h[i] = max(h[i], h[j] + 1);
		}
	}
}
multiset<ll, greater<ll>>B;
vector<ll>A_[505050];
ll P[505050];
set<ll>S[505050];
void dfs2(ll i, ll p)
{
	vector<ll>A;
	ll h1 = 0;
	ll h2 = 0;
	for (ll j : adj[i])
	{
		if (j != p)
		{
			if (h[j] >= h1)
			{
				h2 = h1;
				h1 = h[j];
			}
			else if (h[j] >= h2)
			{
				h2 = h[j];
			}
		}
	}
	for (ll j : adj[i])
	{
		if (j != p)
		{
			ll hh = 0;
			if (h[j] == h1)
				hh = h2;
			else
				hh = h1;
			B.insert(hh - d[i]);
			dfs2(j, i);
			B.erase(B.find(hh - d[i]));
			A.push_back(h[j]);
		}
	}
	if (!B.empty())
	{
		P[i] = d[i] + (*B.begin());
		A.push_back(d[i] + (*B.begin()));
	}
	sort(A.begin(), A.end(), greater<ll>());
	S[i] = set<ll>(A.begin(), A.end());
	A_[i] = A;
	for (ll j = 1; j < A.size(); j++)
	{
		a[A[j] * 2] = max(a[A[j] * 2], j + 1);
		a[A[j] * 2 - 1] = max(a[A[j] * 2 - 1], j + 1);
		if (A[j] != A[j - 1])
		{
			a[A[j] * 2 + 1] = max(a[A[j] * 2 + 1], j + 1);
		}
	}
}
ll kiek(const vector<ll>&a, ll x)
{
	ll lo = 0;
	ll hi = a.size() - 1;
	while (lo < hi)
	{
		ll i = (lo + hi + 1) / 2;
		if (a[i] >= x)
			lo = i;
		else
			hi = i - 1;
	}
	return lo + 1;
}
void dfs3(ll i, ll p)
{
	for (ll j : adj[i])
	{
		if (j != p)
		{
			dfs3(j, i);
		}
	}
	if (p == i)
		return;
	vector<ll> &A = A_[i];
	vector<ll>a1 = {h[i]};
	vector<ll>a2 = {P[i]};
	for (ll j = 0; j < A.size(); j++)
	{
		vector<ll>V = {A[j], A[j] - 1, A[j] + 1, P[i], h[i]};
		auto it = S[p].lower_bound(A[j]);
		if (it != S[p].begin()) {
			it--;
			V.push_back(*it);
		}
		if (it != S[p].begin()) {
			it--;
			V.push_back(*it);
		}
		it = S[p].lower_bound(A[j]);
		if (it != S[p].end()) {
			V.push_back(*it);
			it++;
		}
		if (it != S[p].end()) {
			V.push_back(*it);
			it++;
		}
		for (ll x : V)
		{
			if (x >= 1)
			{
				if (h[i] >= x)
				{
					ll k1 = kiek(A, x) - kiek(a2, x);
					ll k2 = kiek(A_[p], x) - kiek(a1, x);
					if (k2 > 0)
						a[2 * x] = max(a[2 * x], k1 + k2);
				}
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	for (ll i = 1; i < n; i++)
	{
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	fill_n(a, n + 1, 1);
	for (ll i = 1; i <= n; i++)
		a[1] = max(a[1], (ll)adj[i].size() + 1);
	dfs1(1, 1);
	dfs2(1, 1);
	dfs3(1, 1);
	for (ll i = n - 2; i >= 2; i--)
		a[i] = max(a[i], a[i + 2]);
	for (ll i = 1; i <= n; i++)
		cout << a[i] << " ";
}