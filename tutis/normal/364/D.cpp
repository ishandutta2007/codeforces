/*input
6
6 2 3 4 5 6

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
mt19937_64 rng(123123);
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	shuffle(a, a + n, rng);
	ll ret = 1;
	for (int te = 0; te < 10; te++)
	{
		int i = rng() % n;
		ll G = a[i];
		vector<pair<ll, int>>d1, d2;
		for (ll x = 1; x * x <= G; x++)
		{
			if (G % x == 0)
			{
				d1.push_back({x, 0});
				if (x != G / x)
					d2.push_back({ -G / x, 0});
			}
		}
		for (int j = 0; j < n; j++)
		{
			ll x = __gcd(G, a[j]);
			auto it = lower_bound(d1.begin(), d1.end(), make_pair(x, -1));
			if (it != d1.end() && it->first == x)
				it->second++;
			else
			{
				it = lower_bound(d2.begin(), d2.end(), make_pair(-x, -1));
				it->second++;
			}
		}
		for (pair<ll, int>a : d1)
		{
			if (a.first <= ret)
				continue;
			int k = 0;
			for (pair<ll, int>b : d1)
			{
				if (b.first % a.first == 0)
					k += b.second;
			}
			for (pair<ll, int>b : d2)
			{
				if (b.first % a.first == 0)
					k += b.second;
			}
			if (2 * k >= n)
				ret = a.first;
		}
		for (pair<ll, int>a : d2)
		{
			if (-a.first <= ret)
				continue;
			int k = 0;
			for (pair<ll, int>b : d1)
			{
				if (b.first % a.first == 0)
					k += b.second;
			}
			for (pair<ll, int>b : d2)
			{
				if (b.first % a.first == 0)
					k += b.second;
			}
			if (2 * k >= n)
				ret = -a.first;
		}
	}
	cout << ret << "\n";
}