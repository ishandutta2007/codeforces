/*input
5 5 6
78237
84658
09523
48007
70591
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	k++;
	int A[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			A[i][j] = x - '0';
		}
	}
	pair<int, int> D[n][m][k];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int c = 0; c < k; c++)
			{
				D[i][j][c] = { -1000000, -1};
			}
		}
	}
	{
		int i = 0;
		for (int j = 0; j < m; j++)
		{
			D[i][j][A[i][j] % k] = {A[i][j], -1};
		}
	}
	for (int i = 0; i + 1 < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int c = 0; c < k; c++)
			{
				if (j + 1 < m)
					D[i + 1][j + 1][(c + A[i + 1][j + 1]) % k] = max(D[i + 1][j + 1][(c + A[i + 1][j + 1]) % k], {A[i + 1][j + 1] + D[i][j][c].first, j});
				if (j - 1 >= 0)
					D[i + 1][j - 1][(c + A[i + 1][j - 1]) % k] = max(D[i + 1][j - 1][(c + A[i + 1][j - 1]) % k], {A[i + 1][j - 1] + D[i][j][c].first, j});
			}
		}
	}
	pair<int, int>ans = { -1, -1};
	{
		for (int j = 0; j < m; j++)
		{
			int c = 0;
			ans = max(ans, {D[n - 1][j][0].first, j});
		}
	}
	if (ans.second == -1)
	{
		cout << "-1\n";
		return 0;
	}
	int c = 0;
	int j = ans.second;
	int i = n - 1;
	if (ans.first < 0)
	{
		cout << "-1\n";
		return 0;
	}
	cout << ans.first << "\n" << j + 1 << "\n";
	while (i != 0)
	{
		int dx = D[i][j][c].second - j;
		if (dx < 0)
			cout << "L";
		else
			cout << "R";
		ll x = A[i][j];
		j = D[i][j][c].second;
		i--;
		c -= x;
		c += k * 100;
		c %= k;
	}
	cout << "\n";
}