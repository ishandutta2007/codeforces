/*input
4
4
2 5 6 8
3
1 1 1
5
4 1 7 0 8
4
5 9 17 5
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
using namespace std;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
ll mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int>a(n);
		for (int &i : a)
			cin >> i;
		sort(a.begin(), a.end());
		bool same = true;
		for (int i : a)
			if (i != a[0])
				same = false;
		if (same == false && binary_search(a.begin(), a.end(), 1))
		{
			if (binary_search(a.begin(), a.end(), 0) || binary_search(a.begin(), a.end(), 2))
			{
				cout << "NO\n";
			}
			else
			{
				bool ok = true;
				for (int i = 1; i < (int)a.size(); i++)
					if (a[i] - a[i - 1] == 1)
						ok = false;
				if (ok)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
		else
			cout << "YES\n";
	}
}