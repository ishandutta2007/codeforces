/*input
2

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll C(ll n, ll k)
{
	if (k > n || k < 0)
		return 0;
	ll s = 1;
	ll f = 1;
	for (int i = 0; i < k; i++)
		f *= i + 1;
	for (int i = 0; i < k; i++)
	{
		ll x = n - i;
		ll g = __gcd(x, f);
		f /= g;
		x /= g;
		s *= x;
	}
	s /= f;
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans1 = 0;
	ll ans2 = 0;
	vector<vector<int>>K = {{3}, {2, 1}, {1, 1, 1}, {5}, {4, 1}, {3, 2}, {3, 1, 1}, {2, 2, 1}, {2, 1, 1, 1}, {1, 1, 1, 1, 1}};
	for (vector<int>i : K)
	{
		ll sum = 0;
		for (int j : i)
			sum += j;
		sort(i.begin(), i.end());
		do
		{
			if (sum == 3)
				ans1 += C(n, i.size());
			else
				ans2 += C(n, i.size());
		} while (next_permutation(i.begin(), i.end()));
	}
	cout << ans1*ans2 << "\n";
}