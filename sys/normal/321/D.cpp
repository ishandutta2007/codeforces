#include <bits/stdc++.h>
using namespace std;

const int Maxn = 37;
int n, m, maxi, a[Maxn][Maxn], tmp[Maxn][Maxn];
long long ans = -0x3f3f3f3f3f3f3f3fLL;
long long get_val(int x, int y)
{
	return tmp[x][y] * (long long) a[x][y];
}
long long work(int x, int y, int val)
{
	tmp[x][y] = val;
	tmp[x][y + m] = tmp[x][y] * tmp[x][m];
	tmp[x + m][y] = tmp[x][y] * tmp[m][y];
	tmp[x + m][y + m] = tmp[x + m][y] * tmp[x + m][m];
	return get_val(x, y) + get_val(x, y + m) + get_val(x + m, y) + get_val(x + m, y + m);
}
long long work(int pos, int val)
{
	tmp[m][pos] = val, tmp[m][pos + m] = tmp[m][pos] * tmp[m][m];
	long long result = get_val(m, pos) + get_val(m, pos + m);
	for (int i = 1; i < m; i++)
		result += max(work(i, pos, -1), work(i, pos, 1));
	return result;
}
long long work(void)
{
	long long result = 0;
	for (int i = 1; i < m; i++)
		tmp[i + m][m] = tmp[i][m] * tmp[m][m], result += get_val(i, m) + get_val(i + m, m);
	result += get_val(m, m);
	for (int i = 1; i < m; i++)
		result += max(work(i, -1), work(i, 1));
	return result;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	m = (n + 1) >> 1, maxi = (1 << m) - 1;
	for (int i = 0; i <= maxi; i++)
	{
		for (int j = 0; j < m; j++)
			if (i & (1 << j)) tmp[j + 1][m] = 1;
			else tmp[j + 1][m] = -1;
		ans = max(ans, work());
	}
	printf("%lld", ans);
	return 0;
}