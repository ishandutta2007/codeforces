/*input
2 2
2 7 8
1 -8

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, w;
	cin >> n >> w;
	vector<ll>A(w + 3, 0);
	for (ll i = 0; i < n; i++)
	{
		ll l;
		cin >> l;
		vector<pair<ll, ll>> a(l + 2);
		for (ll j = 0; j <= l + 1; j++)
			a[j] = {0, j};
		for (ll j = 1; j <= l; j++)
			cin >> a[j].first;
		ll x = w - l;
		sort(a.begin(), a.end(), greater<pair<ll, ll>>());
		set<ll>P;
		for (auto i : a)
		{
			ll l = i.second;
			ll r = i.second + x;
			auto it = P.upper_bound(l);
			if (it != P.end() && (*it) <= r)
				r = min(r, *it - 1);
			if (it != P.begin())
			{
				it--;
				l = max(l, *it + x + 1);
			}
			P.insert(i.second);
			if (l <= r)
			{
				A[l] += i.first;
				A[r + 1] -= i.first;
			}
		}
	}
	for (ll i = 1; i <= w; i++)
	{
		A[i] += A[i - 1];
		cout << A[i] << " ";
	}
}