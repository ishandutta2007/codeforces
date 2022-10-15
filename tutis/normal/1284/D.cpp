/*input
3
1 3 2 4
4 5 6 7
3 4 5 5

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int32_t main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll H[n];
	for (int i = 0; i < n; i++)
		H[i] = rng();
	ll sa[n], ea[n], sb[n], eb[n];
	for (int i = 0; i < n; i++)
		cin >> sa[i] >> ea[i] >> sb[i] >> eb[i];
	map<ll, ll, less<ll>>SA, SB;
	map<ll, ll, greater<ll>>EA, EB;
	SA[-2] = 0;
	SA[1e9 + 100] = 0;
	SB[-2] = 0;
	SB[1e9 + 100] = 0;

	EA[-2] = 0;
	EA[1e9 + 100] = 0;
	EB[-2] = 0;
	EB[1e9 + 100] = 0;
	for (int i = 0; i < n; i++)
	{
		SA[sa[i]] ^= H[i];
		SB[sb[i]] ^= H[i];
		EA[ea[i]] ^= H[i];
		EB[eb[i]] ^= H[i];
	}
	ll h = 0;
	for (auto it = (SA.rbegin()); it != SA.rend(); it++)
	{
		h ^= it->second;
		it->second = h;
	}
	h = 0;
	for (auto it = (SB.rbegin()); it != SB.rend(); it++)
	{
		h ^= it->second;
		it->second = h;
	}
	h = 0;
	for (auto it = (EA.rbegin()); it != EA.rend(); it++)
	{
		h ^= it->second;
		it->second = h;
	}
	h = 0;
	for (auto it = (EB.rbegin()); it != EB.rend(); it++)
	{
		h ^= it->second;
		it->second = h;
	}
	for (int i = 0; i < n; i++)
	{
		if (((SA.upper_bound(ea[i])->second) ^ (EA.upper_bound(sa[i])->second) ^
		        (SB.upper_bound(eb[i])->second) ^ (EB.upper_bound(sb[i])->second)) != 0)
		{
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}