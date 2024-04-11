/*input
4
2 6 7 8
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll g[1010101];
ll h[1010101];
bool blogai(int a, int b, int c)
{
	//g[a]-ax, g[b]-bx, g[c]-cx
	//g[a]-ax=g[b]-bx
	//g[a]-g[b]=ax-bx
	//g[a]-g[b]=(a-b)x
	ld xab = ld(g[a] - g[b]) / ld(a - b);
	ld xac = ld(g[a] - g[c]) / ld(a - c);
	if (xac <= xab)
		return true;
	else
		return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> h[i];
	ll lo = 0;
	ll hi = 1e12;
	while (lo < hi)
	{
		ll m = (lo + hi) / 2;
		ll hh = h[0] + m;
		bool ok = true;
		ll suma = 0;
		for (ll i = 0; i < n; i++)
		{
			suma -= h[i];
			suma += hh;
			if (suma < 0)
				ok = false;
			hh++;
		}
		if (ok)
			hi = m;
		else
			lo = m + 1;
	}
	ll m = (lo + hi) / 2;
	ll hh = h[0] + m;
	ll suma = 0;
	for (ll i = 0; i < n; i++)
	{
		suma -= h[i];
		suma += hh;
		g[i] = suma;
		hh++;
	}
	// for (ll i = n - 2; i >= 0; i--)
	// 	g[i] = max(g[i], g[i + 1]);
	h[0] = h[0] + m;
	ll c = 0;
	ll a = 0;
	struct ST
	{
		int l, r;
		ST *left, *right;
		vector<int>A;
		int id = 0;
		ST(int l, int r): l(l), r(r)
		{
			if (l < r)
			{
				left = new ST(l, (l + r) / 2);
				right = new ST((l + r) / 2 + 1, r);
				A = left->A;
				for (int i : right->A)
				{
					while (A.size() >= 2 && blogai(A[A.size() - 2], A.back(), i))
						A.pop_back();
					A.push_back(i);
				}
			}
			else
			{
				A = {l};
			}
		}
		ll get(int a, int b, ll x)
		{
			if (a <= l && r <= b)
			{
				ll ret = g[A[id]] - A[id] * x;
				while (id + 1 < A.size())
				{
					ll ret1 = g[A[id + 1]] - A[id + 1] * x;
					if (ret1 < ret)
					{
						ret = ret1;
						id++;
					}
					else
						break;
				}
				return ret;
			}
			else if (b < l || r < a)return 1e18;
			else
				return min(left->get(a, b, x), right->get(a, b, x));
		}
	} S(0, n - 1);
	for (ll i = 1; i < n; i++)
	{
		bool ok = true;
			if (S.get(i, n - 1, a + 1) < 1 - i - c)
				ok = false;
		if (ok)
		{
			a++;
			c += i - 1;
			h[i] = h[i - 1];
		}
		else
			h[i] = h[i - 1] + 1;
	}
	for (ll i = 0; i < n; i++)
		cout << h[i] << " ";
	cout << "\n";
	return 0;
}