/*input
4 5
1 2
2 4
1 3
3 4
2 3
2
2
3

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
vector<int>out[101010];
vector<int>in[101010];
ll O[101010], I[101010];
int val[101010];
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		out[a].push_back(b);
		O[a]++;
		I[b]++;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += I[i] * O[i];
	}
	cout << ans << "\n";
	int q;
	cin >> q;
	for (int i = 0; i <= n; i++)
		val[i] = i;
	int timer = n + 10;
	while (q--)
	{
		int x;
		cin >> x;
		ans -= I[x] * O[x];
		int vx = val[x];
		val[x] = timer++;
		for (int y : out[x])
		{
			if (val[y] > vx)
			{
				ans -= I[y] * O[y];
				I[y]--;
				O[y]++;
				out[y].push_back(x);
				ans += I[y] * O[y];
				if (out[y].size() > O[y] * 3)
				{
					vector<int>c;
					for (int z : out[y])
					{
						if (val[z] > val[y])
							c.push_back(z);
					}
					out[y] = c;
				}
			}
		}
		out[x].clear();
		I[x] += O[x];
		O[x] = 0;
		cout << ans << "\n";
	}
}