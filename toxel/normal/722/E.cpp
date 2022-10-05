#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
const long long moder = 1000000007;
typedef struct anomaly
{
	long long x, y, count;
};
anomaly a[N];
vector <long long> v[N];
long long ans[N][21], fac[2 * N], inv[2 * N], solve = 0;
long long power(long long num,long long index)
{
	long long i,j,bi[60];
	long long ans = 1;
	i = 0;
	while (index)
	{
		bi[i++] = index % 2;
		index /= 2;
	}
	for (j = 0;j < i;j++)
	{
		if (bi[j])
			ans = ans * num % moder;
		num = num * num % moder;
	}
	return ans;
}
bool compare(anomaly x, anomaly y)
{
	return x.count < y.count;
}
long long comb(long long n, long long m)
{
	return fac[n] * inv[m] % moder * inv[n - m] % moder;
}
int main()
{
	long long n, m, k, s, x, y;
	bool flag = false;
	scanf("%I64d%I64d%I64d%I64d", &n, &m, &k, &s);
	int j = 0;
	for (int i = 0; i < k; i++)
	{
		scanf("%I64d %I64d", &x, &y);
		if (x == 1 && y == 1)
			flag = true;
		else if (x == m && y == n)
			s = s / 2 + (s & 1);
		else
		{
			a[j].x = x;
			a[j++].y = y;
		}
	}
	a[j].x = 1;
	a[j++].y = 1;
	k = j;
	if (!flag)
		s *= 2;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < k; j++)
			if (i != j && a[i].x <= a[j].x && a[i].y <= a[j].y)
				a[i].count++;
	sort(a, a + k, compare);
	fac[0] = 1;
	for (int i = 1; i < 2 * N; i++)
		fac[i] = fac[i - 1] * i % moder;
	for (int i = 0; i < 2 * N; i++)
		inv[i] = power(fac[i], moder - 2);
	for (int i = 0; i < k; i++)
		for (int j = 0; j < i; j++)
			if (a[i].x <= a[j].x && a[i].y <= a[j].y)
				v[i].push_back(j);
	for (int kk = 0; kk < 21; kk++)
		for (int i = 0; i < k; i++)
		{
			long long total = comb(n - a[i].x + m - a[i].y, n - a[i].x);
			for (int j = 0; j < v[i].size(); j++)
				total = (total - comb(a[v[i][j]].x - a[i].x + a[v[i][j]].y - a[i].y, a[v[i][j]].x - a[i].x) * ans[v[i][j]][kk] % moder + moder) % moder;
			for (int j = 0; j < kk; j++)
				total = (total - ans[i][j] + moder) % moder;
			ans[i][kk] = total;
		}
	long long total = comb(n + m -2, n - 1);
	for (int i = 0; i < 21; i++)
	{
		s = s / 2 + (s & 1);
		solve = (solve + s * ans[k - 1][i]) % moder;
		total = (total - ans[k - 1][i] + moder) % moder;
	}
	solve = (solve + s * total) % moder;
	solve = solve * power(comb(n + m -2, n - 1), moder - 2) % moder;
	printf("%I64d", solve);
	return 0;
}