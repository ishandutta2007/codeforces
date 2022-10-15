/*input
3 7
1 1 1 3
1 1 1 3
1 1 1 2
1 1 1 1
2 1 1
1 1 1 2
2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 998244353;
ll l[1000000], r[1000000];
ll suma[1000000];
ll pridek[1000000];
ll daugink[1000000];
void ST(int i, ll l_, ll r_)
{
	l[i] = l_;
	r[i] = r_;
	suma[i] = 0;
	pridek[i] = 0;
	daugink[i] = 1;
	if (l[i] < r[i])
	{
		ST(i * 2 + 1, l_, (l_ + r_) / 2);
		ST(i * 2 + 2, (l_ + r_) / 2 + 1, r_);
	}
}
void fix(int i)
{
	suma[i] *= daugink[i];
	suma[i] += (r[i] - l[i] + 1) * pridek[i];
	suma[i] %= modulo;
	if (l[i] < r[i])
	{
		daugink[2 * i + 1] *= daugink[i];
		pridek[2 * i + 1] *= daugink[i];
		pridek[2 * i + 1] += pridek[i];
		daugink[2 * i + 1] %= modulo;
		pridek[2 * i + 1] %= modulo;

		daugink[2 * i + 2] *= daugink[i];
		pridek[2 * i + 2] *= daugink[i];
		pridek[2 * i + 2] += pridek[i];
		daugink[2 * i + 2] %= modulo;
		pridek[2 * i + 2] %= modulo;
	}
	pridek[i] = 0;
	daugink[i] = 1;
}
void multiply(int i, ll a, ll b, ll w)
{
	fix(i);
	if (a <= l[i] && r[i] <= b)
	{
		daugink[i] *= w;
		pridek[i] *= w;
		fix(i);
		return;
	}
	if (r[i] < a || b < l[i])
		return;
	multiply(2 * i + 1, a, b, w);
	multiply(2 * i + 2, a, b, w);
	suma[i] = (suma[2 * i + 1] + suma[2 * i + 2]) % modulo;
}
void add(int i, ll a, ll b, ll w)
{
	fix(i);
	if (a <= l[i] && r[i] <= b)
	{
		pridek[i] += w;
		fix(i);
		return;
	}
	if (r[i] < a || b < l[i])
		return;
	add(2 * i + 1, a, b, w);
	add(2 * i + 2, a, b, w);
	suma[i] = (suma[2 * i + 1] + suma[2 * i + 2]) % modulo;
}
ll get(int i, ll a, ll b)
{
	fix(i);
	if (a <= l[i] && r[i] <= b)
		return suma[i];
	if (r[i] < a || b < l[i])
		return 0;
	return (get(i * 2 + 1, a, b) + get(i * 2 + 2, a, b)) % modulo;
}
bool turi(pair<ll, ll>a, pair<ll, ll>b)
{
	return max(a.first, b.first) <= min(a.second, b.second);
}
pair<ll, ll> bendras(pair<ll, ll>a, pair<ll, ll>b)
{
	return {max(a.first, b.first), min(a.second, b.second)};
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, q;
	cin >> n >> q;
	ST (0, 1, n);
	map<ll, ll>G[n + 1];
	while (q--)
	{
		ll t;
		cin >> t;
		if (t == 1)
		{
			ll l, r, x;
			cin >> l >> r >> x;
			vector<map<ll, ll>::iterator>bendri;
			auto it = G[x].lower_bound(l);
			auto it1 = it;
			if (it1 != G[x].begin())
			{
				it1--;
				if (it1 != G[x].end() && turi({l, r}, *it1))
					bendri.push_back(it1);
			}
			while (it != G[x].end() && turi({l, r}, *it))
			{
				bendri.push_back(it);
				it++;
			}
			if (bendri.empty())
			{
				G[x][l] = r;
				add(0, l, r, 1);
				continue;
			}
			if (bendri.size() == 1)
			{
				pair<ll, ll>a = *bendri[0];
				if (a.first <= l && r <= a.second)
				{
					multiply(0, l, r, 2);
					continue;
				}
			}
			add(0, l, bendri.front()->first - 1, 1);
			add(0, bendri.back()->second + 1, r, 1);
			for (ll i = 1; i < bendri.size(); i++)
				add(0, bendri[i - 1]->second + 1, bendri[i]->first - 1, 1);
			ll l_ = l;
			ll r_ = r;
			for (ll i = 0; i < bendri.size(); i++)
			{
				l_ = min(l_, bendri[i]->first);
				r_ = max(r_, bendri[i]->second);
				pair<ll, ll> a = bendras({l, r}, *bendri[i]);
				multiply(0, a.first, a.second, 2);
			}
			for (auto i : bendri)
				G[x].erase(i);
			G[x][l_] = r_;
		}
		if (t == 2)
		{
			ll l, r;
			cin >> l >> r;
			cout << get(0, l, r) << "\n";
		}
	}


}