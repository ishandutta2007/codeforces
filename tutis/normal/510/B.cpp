/*input
3 4
AAAA
ABCA
AADA
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	char A[n + 2][m + 2];
	for (int i = 0; i < n + 2; i++)
	{
		for (int j = 0; j < m + 2; j++)
		{
			A[i][j] = 0;
		}
	}
	int comp = 0;
	int edge = 0;
	int dx[4] = {0, 0, 1, -1};
	int dy[4] = {1, -1, 0, 0};
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			edge += (A[i][j] == A[i + 1][j]);
			edge += (A[i][j] == A[i][j + 1]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (A[i][j] >= 'A' && A[i][j] <= 'Z')
			{
				comp++;
				queue<pair<int, int>>Q;
				Q.push({i, j});
				char C = A[i][j];
				while (!Q.empty())
				{
					int x = Q.front().first;
					int y = Q.front().second;
					A[x][y] = 0;
					Q.pop();
					for (int k = 0; k < 4; k++)
					{
						if (A[x + dx[k]][y + dy[k]] == C)
						{
							A[x + dx[k]][y + dy[k]] = 0;
							Q.push({x + dx[k], y + dy[k]});
						}
					}
				}
			}
		}
	}
	if (edge > n * m - comp)
	{
		cout << "Yes\n";
	}
	else
		cout << "No\n";



}