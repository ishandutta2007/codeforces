/*input
3
3
.X.
XXX
.X.
6
XX.XXX
XXXXXX
XXX.XX
XXXXXX
XX.X.X
XXXXXX
5
XXX.X
.X..X
XXX.X
..X..
..X..

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, less<T>, null_type, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		string a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			for (char c : a[i])
				if (c == 'X')
					k++;
		}
		int comp[n][n];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				comp[i][j] = -1;
			}
		int timer = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 'X' && comp[i][j] == -1)
				{
					queue<pair<int, int>>Q;
					Q.push({i, j});
					comp[i][j] = timer;
					while (!Q.empty())
					{
						pair<int, int>cc = Q.front();
						Q.pop();
						int x = cc.first;
						int y = cc.second;
						for (int dx : { -1, 0, 1})
						{
							for (int dy : { -1, 0, 1})
							{
								if (dx * dx + dy * dy == 1)
								{
									int x_ = x + dx;
									int y_ = y + dy;
									if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n)
									{
										if (a[x_][y_] == a[x][y] && comp[x_][y_] == -1)
										{
											comp[x_][y_] = timer;
											Q.push({x_, y_});
										}
									}
								}
							}
						}
					}
				}
				timer++;
			}
		int cnt[timer + 1][3];
		for (int i = 0; i <= timer; i++)
			cnt[i][0] = cnt[i][1] = cnt[i][2] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (comp[i][j] != -1)
				{
					cnt[comp[i][j]][(i + j) % 3]++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (comp[i][j] != -1)
				{
					int c = comp[i][j];
					int m = 0;
					for (int t = 1; t < 3; t++)
						if (cnt[c][t] < cnt[c][m])
							m = t;
					if ((i + j) % 3 == m)
						a[i][j] = 'O';
				}
			}
		}
		for (int i = 0; i < n; i++)
			cout << a[i] << "\n";
	}
}