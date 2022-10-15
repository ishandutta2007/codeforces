/*input
3
1 2 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll f(ll x)
{
	return (x) * (x + 1) / 2;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll p[n];
	ll kur[n + 1];
	for (ll i = 0; i < n; i++)
	{
		cin >> p[i];
		kur[p[i]] = i;
	}
	ll inv = 0;
	tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>S;
	set<ll>s1;
	set<ll>s2;
	ll S1 = 0;
	ll S2 = 0;
	for (ll i = 1; i <= n; i++)
	{
		if (s1.empty() || (!s2.empty() && (*s2.begin()) <= kur[i]))
		{
			s2.insert(kur[i]);
			S2 += kur[i];
		}
		else
		{
			s1.insert(kur[i]);
			S1 += kur[i];
		}
		while (s1.size() > s2.size())
		{
			ll k = *(--s1.end());
			s2.insert(k);
			s1.erase(k);
			S1 -= k;
			S2 += k;
		}
		while (s2.size() > s1.size())
		{
			ll k = *(s2.begin());
			s1.insert(k);
			s2.erase(k);
			S2 -= k;
			S1 += k;
		}
		ll k = 0;
		ll reikia = 0;
		if (s1.size() >= s2.size())
		{
			k = *(--s1.end());
			reikia -= f((ll)s1.size() - 1) + f((ll)s2.size());
		}
		else
		{
			k = *(s2.begin());
			reikia -= f(s1.size()) + f((ll)s2.size() - 1);
		}
		reikia += ll(s1.size()) * k - S1;
		reikia += S2 - ll(s2.size()) * k;
		inv += ll(S.size() - S.order_of_key(kur[i]));
		reikia += inv;
		S.insert(kur[i]);
		cout << reikia << "\n";
	}

}