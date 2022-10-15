/*input
7
4 2
0110
4 2
1001
9 3
010001110
9 3
101110001
10 3
0101110001
10 10
1111111111
11 10
11111111110
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
ll power(ll x, ll p)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (p)
	{
		if (p % 2 == 1)
			r = (r * x) % mod;
		p /= 2;
		x = (x * x) % mod;
	}
	return r;
}
bool prime(int x)
{
	if (x <= 1)
		return false;
	for (int a = 2; a * a <= x; a++)
	{
		if (x % a == 0)
			return false;
	}
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int>P;
	while (P.size() < 4)
	{
		int x = rng() % 1000000000;
		if (prime(x) && x >= 10000000)
		{
			P.push_back(x);
		}
	}
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		vector<int>S;
		for (char&c : s)
		{
			int a = c - '0';
			S.push_back(1 - a);
		}
		set<array<ll, 4>>SS;
		array<ll, 4>V = {0, 0, 0, 0};
		array<ll, 4>P2 = {1, 1, 1, 1};
		for (int i = 0; i < k; i++)
		{
			for (int t = 0; t < 4; t++)
			{
				P2[t] *= 2;
				if (P2[t] >= P[t])
					P2[t] -= P[t];
				V[t] *= 2;
				V[t] += S[i];
				while (V[t] >= P[t])
					V[t] -= P[t];
			}
		}
		SS.insert(V);
		for (int i = k; i < n; i++)
		{
			for (int t = 0; t < 4; t++)
			{
				V[t] *= 2;
				V[t] += S[i];
				V[t] -= S[i - k] * P2[t];
				while (V[t] >= P[t])
					V[t] -= P[t];
				while (V[t] < 0)
					V[t] += P[t];
			}
			SS.insert(V);
		}
		int ans = -1;
		for (ll x = 0; x <= n + 1 && x < (1ll << min(k, 35)); x++)
		{
			if (SS.count({x, x, x, x}) == 0)
			{
				ans = x;
				break;
			}
		}
		if (ans == -1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			string s(k, '0');
			int i = 0;
			while (ans != 0)
			{
				if (ans % 2 == 1)
					s[i] = '1';
				i++;
				ans /= 2;
			}
			reverse(s.begin(), s.end());
			cout << s << "\n";
		}
	}

}