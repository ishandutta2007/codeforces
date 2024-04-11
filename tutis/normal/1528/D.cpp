/*input
4 5
0 1 1
1 3 2
2 2 10
3 0 1
0 0 2

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 1000000007;
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
ll C[600][600];
ll D[600][600];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < 600; i++)
	{
		for (int j = 0; j < 600; j++)
		{
			C[i][j] = 2e9;
			D[i][j] = 2e9;
		}
		D[i][i] = 0;
	}
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		C[a][b] = c;
	}
	for (int a = 0; a < n; a++)
	{
		for (int b = 0; b < n; b++)
			D[a][b] = C[a][b];
		for (int r : {0, 1})
			for (int b = 0; b < n; b++)
			{
				int b1 = b + 1;
				if (b1 == n)
					b1 = 0;
				D[a][b1] = min(D[a][b] + 1, D[a][b1]);
			}
		bool ok = true;
		while (ok)
		{
			ok = false;
			for (int b = 0; b < n; b++)
			{
				int t1 = D[a][b] % n;
				for (int c = 0; c < n; c++)
				{
					//D[a][b], b
					//D[a][b]+C[b][c], c+D[a][b]
					ll t = D[a][b] + C[b][c];
					int pos = c + t1;
					if (pos >= n)
						pos -= n;
					if (D[a][pos] > t)
					{
						D[a][pos] = t;
						ok = true;
					}
				}
				//D[a][b] = C[a][b];
			}
			for (int r : {0, 1})
				for (int b = 0; b < n; b++)
				{
					int b1 = b + 1;
					if (b1 == n)
						b1 = 0;
					D[a][b1] = min(D[a][b] + 1, D[a][b1]);
				}
		}
	}
	for (int i = 0; i < n; i++)
	{
		D[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			cout << D[i][j] << " ";
		}
		cout << "\n";
	}
}