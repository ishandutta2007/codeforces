/*input
3 4
aaaa
bbbb
cccc
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
const int INF = 500 * 500 + 1000;
int main()
{
	//ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	pair<int, pair<char, char>> DP[n][26][26];
	for (int G = 0; G < n; G++)
	{
		string a;
		cin >> a;
		int kiek[26][26];
		for (char x = 'a'; x <= 'z'; x++)
		{
			for (char y = 'a'; y <= 'z'; y++)
			{
				if (x == y)
				{
					kiek[x - 'a'][y - 'a'] = INF;
					continue;
				}
				kiek[x - 'a'][y - 'a'] = 0;
				for (int i = 0; i < a.size(); i++)
				{
					if (i % 2 == 0)
						kiek[x - 'a'][y - 'a'] += (a[i] != x);
					else
						kiek[x - 'a'][y - 'a'] += (a[i] != y);
				}
			}
		}
		if (G == 0)
		{
			for (char x = 'a'; x <= 'z'; x++)
			{
				for (char y = 'a'; y <= 'z'; y++)
				{
					DP[G][x - 'a'][y - 'a'] = {kiek[x - 'a'][y - 'a'], {0, 0}};
				}
			}
			continue;
		}
		for (char x = 'a'; x <= 'z'; x++)
		{
			for (char y = 'a'; y <= 'z'; y++)
			{
				DP[G][x - 'a'][y - 'a'] = {INF, {0, 0}};
				for (char z = 'a'; z <= 'z'; z++)
				{
					for (char t = 'a'; t <= 'z'; t++)
					{
						if (z != x && y != t)
						{
							DP[G][x - 'a'][y - 'a'] = min(DP[G][x - 'a'][y - 'a'], {DP[G - 1][z - 'a'][t - 'a'].first, {z, t}});
						}
					}
				}
				DP[G][x - 'a'][y - 'a'].first += kiek[x - 'a'][y - 'a'];
			}
		}
	}
	char A[n][m];
	pair<int, pair<char, char>>M = {INF, {0, 0}};
	for (char x = 'a'; x <= 'z'; x++)
	{
		for (char y = 'a'; y <= 'z'; y++)
		{
			M = min(M, {DP[n - 1][x - 'a'][y - 'a'].first, {x, y}});
		}
	}
	cout << M.first << "\n";
	char x = M.second.first;
	char y = M.second.second;
	for (int t = n - 1; t >= 0; t--)
	{
		for (int i = 0; i < m; i++)
			if (i % 2 == 0)
				A[t][i] = x;
			else
				A[t][i] = y;
		if (t != 0)
		{
			auto X = DP[t][x - 'a'][y - 'a'];
			x = X.second.first;
			y = X.second.second;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cout << A[i][j];
		cout << "\n";
	}
}/**/