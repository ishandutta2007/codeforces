/*input
4 5
3 2
1 2
.....
.***.
...**
*....
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int r, c;
	cin >> r >> c;
	int x, y;
	cin >> x >> y;
	char A[n + 2][m + 2];
	pair<int, int> D[n + 2][m + 2];
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			A[i][j] = '*';
			D[i][j] = {x + y + 2, x + y + 2};
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> A[i][j];
	queue<pair<int, int>>Q;
	Q.push({r, c});
	D[r][c] = {0, 0};
	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		for (int dx : { -1, 1})
			if (A[x + dx][y] == '.' && D[x + dx][y] > D[x][y])
			{
				D[x + dx][y] = D[x][y];
				Q.push({x + dx, y});
			}
		for (int dy : { -1, 1})
		{
			pair<int, int>C = D[x][y];
			if (dy == -1)
				C.first++;
			else
				C.second++;
			if (A[x][y + dy] == '.' && D[x][y + dy] > C)
			{
				D[x][y + dy] = C;
				Q.push({x, y + dy});
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= m + 1; j++)
		{
			if (D[i][j].first <= x && D[i][j].second <= y)
				ans++;
		}
	cout << ans << "\n";
}