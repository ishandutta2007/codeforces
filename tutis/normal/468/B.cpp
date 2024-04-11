/*input
4 5 9
2 3 4 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, a, b;
	cin >> n >> a >> b;
	set<int>AB;
	ll s[n];
	for (int i = 0; i < n; i++)
	{
		ll p;
		cin >> p;
		AB.insert(p);
		s[i] = p;
	}
	set<ll>A;
	set<ll>B;
	auto AB_ = AB;
	for (ll x : AB_)
	{
		if (AB.count(x) == 0)
			continue;
		queue<ll>Q;
		Q.push(x);
		set<ll>v;
		while (!Q.empty())
		{
			ll i = Q.front();
			Q.pop();
			v.insert(i);
			if (AB.count(a - i))
			{
				AB.erase(a - i);
				Q.push(a - i);
			}
			if (AB.count(b - i))
			{
				AB.erase(b - i);
				Q.push(b - i);
			}
		}
		bool oka = true;
		bool okb = true;
		for (ll i : v)
		{
			if (v.count(a - i) == 0)
				oka = false;
			if (v.count(b - i) == 0)
				okb = false;
		}
		if (oka)
		{
			for (ll i : v)
				A.insert(i);
		}
		else if (okb)
		{
			for (ll i : v)
				B.insert(i);
		}
		else
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for (ll i : s)
	{
		if (A.count(i))
			cout << "0 ";
		else
			cout << "1 ";
	}
}