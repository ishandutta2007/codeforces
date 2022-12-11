#include <bits/stdc++.h>
using namespace std;

long long cnt[100][100];

int main()
{
	int n, m, x, y;
	long long k;
	scanf("%d%d%lld%d%d", &n, &m, &k, &x, &y);
	x--; y--;

	if (n == 1)
	{
		for (int i = 0; i < m; i++) cnt[0][i] = k / m;
		for (int i = 0; i < k % m; i++) cnt[0][i]++;
		printf("%lld %lld %lld", *max_element(cnt[0], cnt[0] + m), *min_element(cnt[0], cnt[0] + m), cnt[0][y]);
		return 0;
	}

	int oneround = 2 * (n - 1) * m;
	long long numround = k / oneround;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cnt[i][j] = (i == 0 || i == n - 1) ? numround : numround * 2;
	k %= oneround;

	int p1 = 0, p2 = 0, dir = 1;
	while (k--)
	{
		cnt[p1][p2]++;
		if (++p2 == m)
		{
			p1 += dir;
			p2 = 0;
			if (p1 == n - 1) dir = -1;
		}
	}

	long long m1 = 1e18, m2 = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		m1 = min(m1, cnt[i][j]), m2 = max(m2, cnt[i][j]);
	printf("%lld %lld %lld", m2, m1, cnt[x][y]);
}