#include <bits/stdc++.h>
using namespace std;

const int Maxn = 55, p = 998244353;
int n, x, ans, ct, used_ct, d[Maxn];
long long mini, maxi, L[Maxn], R[Maxn], arr[6 * Maxn], sum[Maxn];
struct Matrix
{
	long long val[Maxn][Maxn];
	Matrix ()
	{
		memset(val, 0, sizeof(val));
	}
	void clear(void)
	{
		memset(val, 0, sizeof(val));
	}
	Matrix operator * (const Matrix &A) const
	{
		Matrix ans;
		for (int i = 1; i <= used_ct; i++)
			for (int j = 1; j <= used_ct; j++)
				for (int k = 1; k <= used_ct; k++)
					(ans.val[i][j] += val[i][k] * A.val[k][j]) %= p;
		return ans;
	}
} now, trans;
Matrix fast_pow(Matrix x, long long y)
{
	Matrix ans, now = x;
	for (int i = 1; i <= used_ct; i++)
		ans.val[i][i] = 1;
	while (y)
	{
		if (y & 1) ans = ans * now;
		now = now * now;
		y >>= 1;
	}
	return ans;
}
int work(int lt, int rt)
{
	used_ct = 1;
	L[used_ct] = R[used_ct] = 0;
	for (int i = lt; i <= rt; i++)
	{
		L[++used_ct] = sum[i - 1] - sum[lt - 1] + (d[i] < 0 ? -1 : 1), R[used_ct] = sum[i] - sum[lt - 1];
		for (int j = -1; j <= 1; j++)
		{
			if (L[used_ct] + j >= 0 && L[used_ct] + j <= maxi)
				arr[++ct] = L[used_ct] + j;
			if (R[used_ct] + j >= 0 && R[used_ct] + j <= maxi)
				arr[++ct] = R[used_ct] + j;
		}
	}
	sort(arr + 1, arr + 1 + ct);
	ct = unique(arr + 1, arr + 1 + ct) - arr - 1;
	now.clear();
	for (int i = 1; i <= used_ct; i++)
		if (!min(L[i], R[i])) now.val[1][i] = 1;
	for (int i = 2; i <= ct; i++)
	{
		trans.clear();
		for (int j = 1; j <= used_ct; j++)
			for (int k = j; k <= used_ct; k++)
				if (min(L[j], R[j]) <= arr[i - 1] && arr[i - 1] <= max(L[j], R[j]) && min(L[k], R[k]) <= arr[i] && arr[i] <= max(L[k], R[k]) && (j != k || L[j] <= R[j]))
					trans.val[j][k] = 1;
		now = now * fast_pow(trans, arr[i] - arr[i - 1]);
	}
	int result = 0;
	for (int i = 1; i <= used_ct; i++)
		(result += now.val[1][i]) %= p;
	return result;
}
int main()
{
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &d[i]);
		if (!d[i]) i--, n--;
		else
		{
			sum[i] = sum[i - 1] + d[i];
			mini = min(mini, sum[i]);
			maxi = max(maxi, sum[i] - mini);
		}
	}
	if (!maxi) ans = (-sum[n] + 1) % p;
	else
		for (int i = 1; i <= n; i++)
			for (int j = n; j >= i; j--)
				if (sum[j] - sum[i - 1] == maxi)
				{
					(ans += work(i, j)) %= p;
					i = j;
					break;
				}
	printf("%lld %d", maxi + 1, ans);
	return 0;
}