/*input
6
1 4
4 2
5 3
6 3
2 3
4
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("mmx,sse,sse2,sse3,ssse3,sse4.1,sse4.2,aes,avx,avx2")
#include <ext/pb_ds/assoc_container.hpp>
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template <typename A, typename B>
using Map = tree<A, B, less<A>, rb_tree_tag, tree_order_statistics_node_update>;
const ll mod = 1000000000 + 7;
int ask(int u, int v)
{
	cout << "? " << u << " " << v << endl;
	int w;
	cin >> w;
	return w;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	set<int>adj[n + 1];
	for (int i = 1; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		adj[x].insert(y);
		adj[y].insert(x);
	}
	set<int>S;
	for (int i = 1; i <= n; i++)
		S.insert(i);
	function<void(int, int, int)>rem = [&](int i, int p, int no)
	{
		if (i == no || S.count(i) == 0)
			return;
		S.erase(i);
		for (int j : adj[i])
		{
			if (j == p)
				continue;
			rem(j, i, no);
		}
	};
	while (S.size() >= 3)
	{
		for (ll x : S)
		{
			for (ll y : S)
			{
				if (adj[x].count(y) || x == y)
					continue;
				ll z = ask(x, y);
				if (z == y)
					swap(x, y);
				if (z == x)
				{
					rem(y, -1, z);
				}
				else
				{
					rem(y, -1, z);
					rem(x, -1, z);
				}
				goto XXX;
			}
		}
XXX:;
	}
	if (S.size() == 2)
		S = {ask(*S.begin(), *(++S.begin()))};
	cout << "! " << *S.begin() << endl;
}