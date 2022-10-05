#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 5005, Maxk = 100005, p = 1e9 + 7;
int n, m, k, a, b, ct, id[25][25], tmp_pre[Maxn], tmp_suf[Maxn], sum_r[Maxn], sum1[Maxn], sum2[Maxn], pre[Maxn], suf[Maxn];
long long ans, r[Maxn], fac[Maxk], inv[Maxk];
long long fast_pow(long long x, long long y)
{
	long long ans = 1, now = x;
	while (y)
	{
		if (y & 1) ans = ans * now % p;
		now = now * now % p;
		y >>= 1;
	}
	return ans;
}
void init(void)
{
	fac[0] = 1;
	for (int i = 1; i <= k; i++)
		fac[i] = fac[i - 1] * i % p;
	inv[k] = fast_pow(fac[k], p - 2);
	for (int i = k - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1) % p;
}
long long C(int x, int y)
{
	return fac[x] * inv[y] % p * inv[x - y] % p;
}
struct Matrix
{
	long long val[405][405];
	Matrix()
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 1; i <= ct; i++)
			for (int j = 1; j <= ct; j++)
				for (int q = 1; q <= ct; q++)
					(ans.val[i][j] += val[i][q] * A.val[q][j]) %= p;
		return ans;
	}
} now, Tmp;
Matrix fast_pow(Matrix x, int y)
{
	Matrix ans, now;
	now = x;
	for (int i = 1; i <= ct; i++) ans.val[i][i] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &a, &b, &k);
	a = a * fast_pow(b, p - 2) % p;
	init();
	for (int i = 0; i <= min(k, m); i++)
		r[i] = fast_pow(a, i) * fast_pow(p + 1 - a, k - i) % p * C(k, i) % p;
	for (int i = 0; i <= m; i++) sum_r[i] = ((i ? sum_r[i - 1] : 0) + r[i]) % p;
	if (m <= 20)
	{
		for (int i = 1; i <= m; i++)
			for (int j = i; j <= m; j++)
				id[i][j] = ++ct;
		for (int l1 = 1; l1 <= m; l1++)
			for (int r1 = l1; r1 <= m; r1++)
				for (int l2 = 1; l2 <= m; l2++)
					for (int r2 = l2; r2 <= m; r2++)
						if (l2 <= r1 && r2 >= l1) now.val[id[l1][r1]][id[l2][r2]] = r[l2 - 1] * r[m - r2] % p;
		Tmp.val[1][id[1][m]] = 1;
		Matrix Ans = Tmp * fast_pow(now, n);
		int ans = 0;
		for (int i = 1; i <= ct; i++)
			(ans += Ans.val[1][i]) %= p;
		printf("%d\n", ans);
		return 0;
	}
	pre[m] = suf[1] = 1;
	for (int i = 1; i <= n; i++)
	{
		memcpy(tmp_pre, pre, sizeof(int[m + 1]));
		memcpy(tmp_suf, suf, sizeof(int[m + 1]));
		memset(pre, 0, sizeof(int[m + 1]));
		memset(suf, 0, sizeof(int[m + 1]));
		for (int j = m; j >= 1; j--)
			sum1[j] = (sum1[j + 1] + tmp_suf[j + 1] * r[m - j]) % p;
		for (int j = 1; j <= m; j++)
			sum2[j] = (sum2[j - 1] + tmp_pre[j - 1] * r[j - 1]) % p;
		for (int j = 1; j <= m; j++)
		{
			suf[j] = (suf[j] + (tmp_pre[m] - tmp_pre[j - 1] + p) * r[j - 1] % p * sum_r[m - j]) % p;
			suf[j] = (suf[j] + r[j - 1] * (p - sum1[j])) % p;
			pre[j] = (pre[j] + (tmp_pre[m] - tmp_suf[j + 1] + p) * r[m - j] % p * sum_r[j - 1]) % p;
			pre[j] = (pre[j] + r[m - j] * (p - sum2[j])) % p;
		}
		for (int j = 1; j <= m; j++) (pre[j] += pre[j - 1]) %= p;
		for (int j = m - 1; j >= 0; j--) (suf[j] += suf[j + 1]) %= p;
	}
	printf("%d", pre[m]);
	return 0;
}