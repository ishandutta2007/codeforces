/***
3 4 5
1 1 2
2 3 0
3 3 1
0 1 1 100 100
1 2 2 4 4
2 2 1 4 7
1 50 50 51 51
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int A[102][102][12];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, q, c;
	cin >> n >> q >> c;
	ll x[n], y[n], s[n];
	for (int i = 0; i < 102; i++)
		for (int j = 0; j < 102; j++)
			for (int k = 0; k < 12; k++)
				A[i][j][k] = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i] >> y[i] >> s[i];
		for (int t = 0; t <= c; t++)
		{
			A[x[i]][y[i]][t] += ((s[i] + t) % (c + 1));
		}
	}
	for (int i = 1; i < 102; i++)
	{
		for (int j = 1; j < 102; j++)
		{
			for (int k = 0; k < 12; k++)
			{
				A[i][j][k] += A[i - 1][j][k];
				A[i][j][k] += A[i][j - 1][k];
				A[i][j][k] -= A[i - 1][j - 1][k];
			}
		}
	}
	while (q--)
	{
		int t, x1, y1, x2, y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		x1--;
		y1--;
		t %= c + 1;
		cout << A[x2][y2][t] - A[x1][y2][t] - A[x2][y1][t] + A[x1][y1][t] << "\n";
	}
}