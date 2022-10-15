/*input
3
1 9 3
8 6 7
4 2 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int N;
	cin >> N;
	int A[N][N];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> A[i][j];
	pair<int, int> D[N][N][3][N][N][3];
	queue<pair<pair<pair<int, int>, int>, pair<pair<int, int>, int>>>Q;
	for (int x1 = 0; x1 < N; x1++)
	{
		for (int y1 = 0; y1 < N; y1++)
		{
			for (int x2 = 0; x2 < N; x2++)
			{
				for (int y2 = 0; y2 < N; y2++)
				{
					for (int a : {0, 1, 2})
					{
						for (int b : {0, 1, 2})
						{
							D[x1][y1][a][x2][y2][b] = {1000, 1000};
						}
					}
				}
			}
			for (int a : {0, 1, 2})
			{
				D[x1][y1][a][x1][y1][a] = {0, 0};
				Q.push({{{x1, y1}, a}, {{x1, y1}, a}});
			}
		}
	}
	int dx[8] = {1, 1, -1, -1, 2, 2, -2, -2};
	int dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
	while (!Q.empty())
	{
		int x1 = Q.front().first.first.first;
		int y1 = Q.front().first.first.second;
		int a1 = Q.front().first.second;
		int x2 = Q.front().second.first.first;
		int y2 = Q.front().second.first.second;
		int a2 = Q.front().second.second;
		Q.pop();
		for (int t : {0, 1, 2})
		{
			pair<int, int>c = D[x1][y1][a1][x2][y2][a2];
			c.second++;
			c.first++;
			if (D[x1][y1][a1][x2][y2][t] > c)
			{
				D[x1][y1][a1][x2][y2][t] = c;
				Q.push({{{x1, y1}, a1}, {{x2, y2}, t}});
			}
		}
		pair<int, int>c = D[x1][y1][a1][x2][y2][a2];
		c.first++;
		if (a2 == 0)
		{
			for (int t = 0; t < 8; t++)
			{
				if (x2 + dx[t] >= 0 && x2 + dx[t] < N)
				{
					if (y2 + dy[t] >= 0 && y2 + dy[t] < N)
					{
						if (D[x1][y1][a1][x2 + dx[t]][y2 + dy[t]][a2] > c)
						{
							D[x1][y1][a1][x2 + dx[t]][y2 + dy[t]][a2] = c;
							Q.push({{{x1, y1}, a1}, {{x2 + dx[t], y2 + dy[t]}, a2}});
						}
					}
				}
			}
		}
		if (a2 == 1)
		{
			for (int t = -N; t <= N; t++)
			{
				if (x2 + t >= 0 && x2 + t < N)
				{
					if (y2 + t >= 0 && y2 + t < N)
					{
						if (D[x1][y1][a1][x2 + t][y2 + t][a2] > c)
						{
							D[x1][y1][a1][x2 + t][y2 + t][a2] = c;
							Q.push({{{x1, y1}, a1}, {{x2 + t, y2 + t}, a2}});
						}
					}
				}
			}
			for (int t = -N; t <= N; t++)
			{
				if (x2 + t >= 0 && x2 + t < N)
				{
					if (y2 - t >= 0 && y2 - t < N)
					{
						if (D[x1][y1][a1][x2 + t][y2 - t][a2] > c)
						{
							D[x1][y1][a1][x2 + t][y2 - t][a2] = c;
							Q.push({{{x1, y1}, a1}, {{x2 + t, y2 - t}, a2}});
						}
					}
				}
			}
		}
		if (a2 == 2)
		{
			for (int t = -N; t <= N; t++)
			{
				if (x2 + t >= 0 && x2 + t < N)
				{
					if (y2 >= 0 && y2 < N)
					{
						if (D[x1][y1][a1][x2 + t][y2][a2] > c)
						{
							D[x1][y1][a1][x2 + t][y2][a2] = c;
							Q.push({{{x1, y1}, a1}, {{x2 + t, y2}, a2}});
						}
					}
				}
			}
			for (int t = -N; t <= N; t++)
			{
				if (x2 >= 0 && x2 < N)
				{
					if (y2 + t >= 0 && y2 + t < N)
					{
						if (D[x1][y1][a1][x2][y2 + t][a2] > c)
						{
							D[x1][y1][a1][x2][y2 + t][a2] = c;
							Q.push({{{x1, y1}, a1}, {{x2, y2 + t}, a2}});
						}
					}
				}
			}
		}
	}
	pair<int, int>X[N * N + 1];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			X[A[i][j]] = {i, j};
	pair<int, int>DP[N * N + 1][3];
	DP[1][0] = DP[1][1] = DP[2][2] = {0, 0};
	for (int i = 2; i <= N * N; i++)
	{
		for (int b : {0, 1, 2})
		{
			DP[i][b] = {2000000, 2000000};
			for (int a : {0, 1, 2})
			{
				pair<int, int>c = DP[i - 1][a];
				pair<int, int>d = D[X[i - 1].first][X[i - 1].second][a][X[i].first][X[i].second][b];
				d.first += c.first;
				d.second += c.second;
				DP[i][b] = min(DP[i][b], d);
			}
		}
	}
	pair<int, int>ans = min({DP[N * N][0], DP[N * N][1], DP[N * N][2]});
	cout << ans.first << " " << ans.second << "\n";
}