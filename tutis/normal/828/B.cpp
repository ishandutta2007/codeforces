/***
3 3
WWW
WWW
WWW
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define INF (100009)
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int A[n][m];
	int D[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char x;
			cin >> x;
			if (x == 'B')
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			D[i][j] = A[i][j];
			if (i - 1 >= 0)
				D[i][j] += D[i - 1][j];
			if (j - 1 >= 0)
				D[i][j] += D[i][j - 1];
			if (i - 1 >= 0 && j - 1 >= 0)
				D[i][j] -= D[i - 1][j - 1];
		}
	}
	ll ans = INF;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int a = 0; i + a < n && j + a < m; a++)
			{
				int isv = D[n - 1][m - 1];
				int vid = D[i + a][j + a];
				if (i - 1 >= 0)
					vid -= D[i - 1][j + a];
				if (j - 1 >= 0)
					vid -= D[i + a][j - 1];
				if (i - 1 >= 0 && j - 1 >= 0)
					vid += D[i - 1][j - 1];
				isv -= vid;
				if (isv == 0)
				{
					ans = min(ans, ll((a + 1) * (a + 1) - vid));
				}
			}
		}
	}
	if (ans != INF)
		cout << ans;
	else
		cout << -1;
}