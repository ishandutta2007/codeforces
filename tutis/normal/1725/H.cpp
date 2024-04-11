/*input
4
4 10 9 14
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using oset = tree<T,  null_type,  less<T>,  rb_tree_tag,  tree_order_statistics_node_update>;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
mt19937_64 rng(0);
const ll mod = 1e9 + 7;
ll p(ll x, ll y)
{
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		y /= 2;
		x = (x * x) % mod;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int A[N];
	vector<int>X[3];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		X[A[i] % 3].push_back(i);
	}
	for (int Z : {0, 1, 2})
	{
		for (int m1 = 1; m1 < (1 << 3); m1++)
		{
			for (int m2 = 1; m2 < (1 << 3); m2++)
			{
				vector<int>G[2];
				bool GG[2][3];
				for (int g = 0; g < 3; g++)
				{
					if ((m1 & (1 << g)) != 0)
						G[0].push_back(g);
					if ((m2 & (1 << g)) != 0)
						G[1].push_back(g);
					GG[0][g] = (m1 & (1 << g)) != 0;
					GG[1][g] = (m2 & (1 << g)) != 0;
				}
				bool ok = true;
				for (int g0 : G[0])
				{
					for (int g1 : G[1])
					{
						if ((((g0 + g1) * (g0 + g1) + g1 * g0) % 3) == Z)
							ok = false;
					}
				}
				for (int g = 0; g < 3; g++)
					if ((!(GG[0][g] || GG[1][g])) && (X[g].size() > 0))
						ok = false;
				if (ok)
				{
					int c0 = N;
					for (int i = 0; i < 3; i++)
						if (GG[0][i] == false)
							c0 -= (int)X[i].size();
					int s = 0;
					for (int i = 0; i < 3; i++)
						if (GG[0][i] && GG[1][i])
							s += (int)X[i].size();
					if (c0 - s <= N / 2 && N / 2 <= c0)
					{
						vector<bool> k(N, false);
						for (int i = 0; i < 3; i++)
							if (GG[0][i] == false)
								for (int v : X[i])
									k[v] = true;
						for (int i = 0; i < 3; i++)
							if (GG[0][i] && GG[1][i])
							{
								for (int v : X[i])
									if (c0 > N / 2)
									{
										k[v] = true;
										c0--;
									}
							}
						assert(c0 == N / 2);
						cout << Z << "\n";
						for (int i = 0; i < N; i++)
							cout << k[i];
						cout << "\n";
						return 0;
					}
				}
			}
		}
	}
	cout << "-1\n";
	return 0;
}