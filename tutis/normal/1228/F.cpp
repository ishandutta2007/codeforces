/*input
4
1 2
1 3
2 4
2 5
3 6
3 13
3 14
4 7
4 8
5 9
5 10
6 11
6 12
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
	int n;
	cin >> n;
	int cnt = (1 << n) - 2;
	vector<int>adj[cnt + 1];
	for (int i = 1; i < cnt; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int h[cnt + 1];
	int sz[cnt + 1];
	for (int i = 0; i <= cnt; i++)
		h[i] = cnt + 1;
	{
		queue<int>Q;
		for (int i = 1; i <= cnt; i++)
			if (adj[i].size() == 1)
			{
				h[i] = 0;
				Q.push(i);
			}
		while (!Q.empty())
		{
			int a = Q.front();
			Q.pop();
			for (int b : adj[a])
			{
				if (h[b] > h[a] + 1)
				{
					h[b] = h[a] + 1;
					Q.push(b);
				}
			}
		}
	}
	vector<int>R = {1};
	for (int i = 2; i <= cnt; i++)
	{
		if (h[i] == h[R.back()])
			R.push_back(i);
		else if (h[i] > h[R.back()])
			R = {i};
	}
	vector<int>ans;
	if (R.size() < 5)
	{
		for (int r : R)
		{
			bool full[cnt + 1];
			vector<int>t[cnt + 1];
			function<void(int, int)>dfs = [&](int i, int p)
			{
				sz[i] = 1;
				vector<int>c;
				for (int j : adj[i])
				{
					if (j != p)
					{
						c.push_back(j);
						dfs(j, i);
						sz[i] += sz[j];
					}
				}
				if (sz[i] == 1)
				{
					full[i] = true;
				}
				else
				{
					if (c.size() == 2 && sz[c[0]] == sz[c[1]] && full[c[0]] && full[c[1]])
						full[i] = true;
					else
						full[i] = false;
				}
				if (sz[i] == 2)
				{
					t[i] = {i};
				}
				else
				{
					if (c.size() == 2)
					{
						for (int r : {0, 1})
						{
							if (sz[c[0]] == sz[c[1]] - 1 && full[c[1]])
								for (int v : t[c[0]])
									t[i].push_back(v);
							swap(c[0], c[1]);
						}
					}
					if (c.size() == 3)
					{
						for (int r : {0, 1, 2})
						{
							if (sz[c[0]] == sz[c[1]] && sz[c[2]] == sz[c[1]] * 2 + 1)
							{
								if (full[c[0]] && full[c[1]] && full[c[2]])
									t[i].push_back(i);
							}
							swap(c[0], c[1]);
							swap(c[1], c[2]);
						}
					}
				}
			};
			dfs(r, r);
			for (int v : t[r])
				ans.push_back(v);
		}
	}
	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	cout << ans.size() << "\n";
	for (int i : ans)
		cout << i << " ";
}