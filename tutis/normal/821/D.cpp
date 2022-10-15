/**
4 4 5
1 1
2 1
2 3
3 3
4 3
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF 300000
struct compare
{
	bool operator()(pair<int, pair<int, int>> &a, pair<int, pair<int, int>> &b)const
	{
		return a > b;
	}
};
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, compare>BFS;
	BFS.push(make_pair(0, make_pair(1, 1)));
	map<int, set<int>>X;
	map<int, set<int>>Y;
	map<pair<int, int>, int>WAS;
	map<int, int>row;
	map<int, int>col;
	WAS[make_pair(1, 1)] = 0;
	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		X[r].insert(c);
		Y[c].insert(r);
	}
	int ans = INF;
	while (!BFS.empty())
	{
		pair<int, int>a = BFS.top().second;
		int c = BFS.top().first;
		BFS.pop();
		//cout << a.first << " " << a.second << " " << c << endl;
		if (a.first == n && a.second == m)
			ans = min(ans, c);
		if (a.first == n)
			ans = min(ans, c + 1);
		if (a.first == n - 1)
			ans = min(ans, c + 1);
		if (a.second == m)
			ans = min(ans, c + 1);
		if (a.second == m - 1)
			ans = min(ans, c + 1);
		if
		(
		    X[a.first + 1].count(a.second) == 1 &&
		    ( WAS.count(make_pair(a.first + 1, a.second)) == 0 ||
		      WAS[make_pair(a.first + 1, a.second)] > c)
		)
		{
			BFS.push(make_pair(c, make_pair(a.first + 1, a.second)));
			WAS[make_pair(a.first + 1, a.second)] = c;
		}
		if (X[a.first - 1].count(a.second) == 1 &&
		        ( WAS.count(make_pair(a.first - 1, a.second)) == 0 ||
		          WAS[make_pair(a.first - 1, a.second)] > c))
		{
			BFS.push(make_pair(c, make_pair(a.first - 1, a.second)));
			WAS[make_pair(a.first - 1, a.second)] = c;
		}
		if (Y[a.second + 1].count(a.first) == 1 &&
		        ( WAS.count(make_pair(a.first, a.second + 1)) == 0 ||
		          WAS[make_pair(a.first, a.second + 1)] > c))
		{
			BFS.push(make_pair(c, make_pair(a.first, a.second + 1)));
			WAS[make_pair(a.first, a.second + 1)] = c;
		}
		if (Y[a.second + 1].count(a.first) == 1 &&
		        ( WAS.count(make_pair(a.first, a.second - 1)) == 0 ||
		          WAS[make_pair(a.first, a.second - 1)] > c))
		{
			BFS.push(make_pair(c, make_pair(a.first, a.second - 1)));
			WAS[make_pair(a.first, a.second - 1)] = c;
		}
		if (col.count(a.first) == 0 || col[a.first] > c + 1)
		{
			col[a.first] = c + 1;
			for (int y : X[a.first])
			{
				if (WAS.count(make_pair(a.first, y)) == 0 || WAS[make_pair(a.first, y)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(a.first, y)));
					WAS[make_pair(a.first, y)] = c + 1;
				}
			}
		}
		if (col.count(a.first + 1) == 0 || col[a.first + 1] > c + 1)
		{
			col[a.first + 1] = c + 1;
			for (int y : X[a.first + 1])
			{
				if (WAS.count(make_pair(a.first + 1, y)) == 0 || WAS[make_pair(a.first + 1, y)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(a.first + 1, y)));
					WAS[make_pair(a.first + 1, y)] = c + 1;
				}
			}
		}
		if (col.count(a.first + 2) == 0 || col[a.first + 2] > c + 1)
		{
			col[a.first + 2] = c + 1;
			for (int y : X[a.first + 2])
			{
				if (WAS.count(make_pair(a.first + 2, y)) == 0 || WAS[make_pair(a.first + 2, y)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(a.first + 2, y)));
					WAS[make_pair(a.first + 2, y)] = c + 1;
				}
			}
		}
		if (col.count(a.first - 1) == 0 || col[a.first - 1] > c + 1)
		{
			col[a.first - 1] = c + 1;
			for (int y : X[a.first - 1])
			{
				if (WAS.count(make_pair(a.first - 1, y)) == 0 || WAS[make_pair(a.first - 1, y)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(a.first - 1, y)));
					WAS[make_pair(a.first - 1, y)] = c + 1;
				}
			}
		}
		if (col.count(a.first - 2) == 0 || col[a.first - 2] > c + 1)
		{
			col[a.first - 2] = c + 1;
			for (int y : X[a.first - 2])
			{
				if (WAS.count(make_pair(a.first - 2, y)) == 0 || WAS[make_pair(a.first - 2, y)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(a.first - 2, y)));
					WAS[make_pair(a.first - 2, y)] = c + 1;
				}
			}
		}
		if (row.count(a.second) == 0 || row[a.second] > c + 1)
		{
			row[a.second] = c + 1;
			for (int x : Y[a.second])
			{
				if (WAS.count(make_pair(x, a.second)) == 0 || WAS[make_pair(x, a.second)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(x, a.second)));
					WAS[make_pair(x, a.second)] = c + 1;
				}
			}
		}
		if (row.count(a.second + 1) == 0 || row[a.second + 1] > c + 1)
		{
			row[a.second + 1] = c + 1;
			for (int x : Y[a.second + 1])
			{
				if (WAS.count(make_pair(x, a.second + 1)) == 0 || WAS[make_pair(x, a.second + 1)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(x, a.second + 1)));
					WAS[make_pair(x, a.second + 1)] = c + 1;
				}
			}
		}
		if (row.count(a.second + 2) == 0 || row[a.second + 2] > c + 1)
		{
			row[a.second + 2] = c + 1;
			for (int x : Y[a.second + 2])
			{
				if (WAS.count(make_pair(x, a.second + 2)) == 0 || WAS[make_pair(x, a.second + 2)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(x, a.second + 2)));
					WAS[make_pair(x, a.second + 2)] = c + 1;
				}
			}
		}
		if (row.count(a.second - 1) == 0 || row[a.second - 1] > c + 1)
		{
			row[a.second - 1] = c + 1;
			for (int x : Y[a.second - 1])
			{
				if (WAS.count(make_pair(x, a.second - 1)) == 0 || WAS[make_pair(x, a.second - 1)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(x, a.second - 1)));
					WAS[make_pair(x, a.second - 1)] = c + 1;
				}
			}
		}
		if (row.count(a.second - 2) == 0 || row[a.second - 2] > c + 1)
		{
			row[a.second - 2] = c + 1;
			for (int x : Y[a.second - 2])
			{
				if (WAS.count(make_pair(x, a.second - 2)) == 0 || WAS[make_pair(x, a.second - 2)] > c + 1)
				{
					BFS.push(make_pair(c + 1, make_pair(x, a.second - 2)));
					WAS[make_pair(x, a.second - 2)] = c + 1;
				}
			}
		}
	}
	cout << (ans == INF ? -1 : ans);
}