#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005, p = 998244353;
string A, B;
long long ans, f[Maxn][Maxn][2][4];
int main()
{
	cin >> A >> B;
	int n = A.size(), m = B.size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			f[i][j + 1][1][1]++, f[i + 1][j][0][2]++;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
		{
			if (i && i != n && A[i] != A[i - 1])
				for (int s = 0; s <= 1; s++)
				(f[i + 1][j][0][s | 2] += f[i][j][0][s] + f[i][j][0][s | 2]) %= p;
			if (j && i != n && A[i] != B[j - 1])
				for (int s = 0; s <= 1; s++)
					(f[i + 1][j][0][s | 2] += f[i][j][1][s] + f[i][j][1][s | 2]) %= p;
			if (i && j != m && B[j] != A[i - 1])
				for (int s = 0; s <= 2; s += 2)
					(f[i][j + 1][1][s | 1] += f[i][j][0][s] + f[i][j][0][s | 1]) %= p;
			if (j && j != m && B[j] != B[j - 1])
				for (int s = 0; s <= 2; s += 2)
					(f[i][j + 1][1][s | 1] += f[i][j][1][s] + f[i][j][1][s | 1]) %= p;
		}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			(ans += f[i][j][0][3] + f[i][j][1][3]) %= p;
	printf("%lld", ans);
	return 0;
}