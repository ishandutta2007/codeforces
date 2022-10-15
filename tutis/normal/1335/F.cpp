/*input
3
1 2
01
RL
3 3
001
101
110
RLL
DLD
ULL
3 3
000
000
000
RRD
RLD
ULL
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		string c[n];
		for (int i = 0; i < n; i++)
			cin >> c[i];
		string s[n];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		int ans = 0;
		int ans1 = 0;
		int id[n][m];
		int timer = 0;
		int nxt[n * m];
		vector<int>atg[n * m];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				id[i][j] = timer++;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (s[i][j] == 'U')
					nxt[id[i][j]] = id[i - 1][j];
				if (s[i][j] == 'D')
					nxt[id[i][j]] = id[i + 1][j];
				if (s[i][j] == 'L')
					nxt[id[i][j]] = id[i][j - 1];
				if (s[i][j] == 'R')
					nxt[id[i][j]] = id[i][j + 1];
				atg[nxt[id[i][j]]].push_back(id[i][j]);
			}
		}
		int tim[n * m];
		for (int i = 0; i < timer; i++)
		{
			if (nxt[i] != -1)
			{
				int j = i;
				set<int>S = {};
				while (S.count(j) == 0)
				{
					S.insert(j);
					j = nxt[j];
				}
				set<int>T;
				queue<int>Q;
				Q.push(j);
				T.insert(j);
				tim[j] = 0;
				int sz = 0;
				vector<int>V;
				while (!Q.empty())
				{
					int a = Q.front();
					Q.pop();
					V.push_back(a);
					nxt[a] = -1;
					for (int b : atg[a])
					{
						if (T.count(b) == 0)
						{
							Q.push(b);
							T.insert(b);
							tim[b] = tim[a] + 1;
						}
						if (b == j)
						{
							sz = tim[a] + 1;
						}
					}
				}
				set<int>A;
				set<int>B;
				for (int i : V)
				{
					tim[i] %= sz;
					if (c[i / m][i % m] == '0')
						A.insert(tim[i]);
					B.insert(tim[i]);
				}
				ans += A.size();
				ans1 += B.size();
			}
		}
		cout << ans1 << " " << ans << "\n";
	}
	return 0;
}