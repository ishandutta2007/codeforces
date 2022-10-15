/*input
10 10
.XXXXXX...
.XXXXXX...
.XXXXXX...
.XXXXXX...
.XXXXXXXX.
...XXXXXX.
...XXXXXX.
...XXXXXX.
...XXXXXX.
..........

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
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	int A[n + 2][m + 2];
	int B[n + 2][m + 2];
	int C[n + 2][m + 2];
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			A[i][j] = 0;
			if (i > 0 && j > 0)
			{
				A[i][j] += A[i - 1][j];
				A[i][j] += A[i][j - 1];
				A[i][j] -= A[i - 1][j - 1];
				if (s[i - 1][j - 1] == 'X')
					A[i][j]++;
			}
		}
	}
	int lo = 0;
	int hi = n + m;
	while (lo <= hi)
	{
		int t = (lo + hi + 1) / 2;
		int sz = 2 * t + 1;
		if (sz > n || sz > m)
		{
			hi = t - 1;
			continue;
		}
		for (int i = 0; i <= n + 1; i++)
		{
			for (int j = 0; j <= m + 1; j++)
			{
				B[i][j] = C[i][j] = 0;
			}
		}
		for (int i = 1; i + sz - 1 <= n; i++)
		{
			for (int j = 1; j + sz - 1 <= m; j++)
			{
				int i1 = i + sz - 1;
				int j1 = j + sz - 1;
				int kiek = A[i1][j1] - A[i - 1][j1] - A[i1][j - 1] + A[i - 1][j - 1];
				if (kiek == sz * sz)
				{
					B[i][j]++;
					B[i1 + 1][j]--;
					B[i][j1 + 1]--;
					B[i1 + 1][j1 + 1]++;
					C[i][j] = 1;
				}
			}
		}
		bool ok = true;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				B[i][j] += B[i - 1][j];
				B[i][j] += B[i][j - 1];
				B[i][j] -= B[i - 1][j - 1];
				int k1 = A[i][j] - A[i - 1][j] - A[i][j - 1] + A[i - 1][j - 1];
				int k2 = B[i][j];
				if ((k1 > 0) != (k2 > 0))
					ok = false;
			}
		}
		if (lo == hi)
		{
			cout << t << "\n";
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (i >= t && j >= t && C[i - t][j - t] > 0)
						cout << "X";
					else
						cout << ".";
				}
				cout << "\n";
			}
			return 0;
		}
		if (ok)
			lo = t;
		else
			hi = t - 1;
	}
}