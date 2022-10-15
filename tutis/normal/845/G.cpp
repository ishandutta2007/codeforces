/*input
2 2
1 1 3
1 2 3

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
mt19937_64 rng(123);
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>>adj[n];
	while (m--)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--;
		y--;
		adj[x].push_back({y, w});
		adj[y].push_back({x, w});
	}
	bool ok[n];
	for (int i = 0; i < n; i++)
		ok[i] = false;
	bool eilej[n];
	for (int i = 0; i < n; i++)
		eilej[i] = false;
	int off[n];
	vector<int>A[n];
	queue<int>Q;
	Q.push(0);
	ok[0] = true;
	off[0] = 0;
	eilej[0] = true;
	A[0] = {0};
	while (!Q.empty())
	{
		int a = Q.front();
		Q.pop();
		eilej[a] = false;
		for (pair<int, int>b : adj[a])
		{
			if (ok[b.first] == false)
			{
				off[b.first] = off[a] ^ b.second;
				ok[b.first] = true;
				if (!eilej[b.first])
					Q.push(b.first);
				eilej[b.first] = true;
				A[b.first] = A[a];
			}
			else
			{
				if (a == b.first)
				{
					int v = b.second;
					bool cikl = true;
					while (cikl)
					{
						cikl = false;
						for (int a : A[a])
						{
							if ((v ^ a) < v)
							{
								v ^= a;
								cikl = true;
							}
						}
					}
					if (v)
					{
						A[a].push_back(v);
						if (!eilej[a])
							Q.push(a);
						eilej[a] = true;
					}
				}
				else
					for (int v : A[a])
					{
						v ^= off[a] ^ off[b.first] ^ b.second;
						bool cikl = true;
						while (cikl)
						{
							cikl = false;
							for (int a : A[b.first])
							{
								if ((v ^ a) < v)
								{
									v ^= a;
									cikl = true;
								}
							}
						}
						if (v)
						{
							A[b.first].push_back(v);
							if (!eilej[b.first])
								Q.push(b.first);
							eilej[b.first] = true;
						}
					}
			}
		}
	}
	int ans = off[n - 1];
	bool cikl = true;
	while (cikl)
	{
		cikl = false;
		for (int a : A[n - 1])
		{
			if ((ans ^ a) < ans)
			{
				ans ^= a;
				cikl = true;
			}
		}
	}
	cout << ans << "\n";
}