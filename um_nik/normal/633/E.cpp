#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 1000100;
const int L = 20;
int a[L][N], b[L][N];
int n, k;
int c[N];
int p[N];

int getA(int l, int r)
{
	if (r <= l) return 0;
	int k = p[r - l];
	return max(a[k][l], a[k][r - (1 << k)]);
}
int getB(int l, int r)
{
	if (r <= l) return 0;
	int k = p[r - l];
	return min(b[k][l], b[k][r - (1 << k)]);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[0][i]);
		a[0][i] *= 100;
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &b[0][i]);
	for (int k = 1; k < L; k++)
	{
		for (int i = 0; i + (1 << (k - 1)) <= n; i++)
		{
			a[k][i] = max(a[k - 1][i], a[k - 1][i + (1 << (k - 1))]);
			b[k][i] = min(b[k - 1][i], b[k - 1][i + (1 << (k - 1))]);
		}
	}
	p[1] = 0;
	for (int i = 2; i < N; i++)
		p[i] = p[i / 2] + 1;

	int r = 0;
	for (int l = 0; l < n; l++)
	{
		if (r < l) r++;
		while(r < n && getA(l, r + 1) < getB(l, r + 1)) r++;
//		printf("%d %d\n", l, r);
		if (r == n)
			c[l] = getA(l, r);
		else if (l == r)
			c[l] = getB(l, r + 1);
		else
			c[l] = max(getA(l, r), getB(l, r + 1));
	}
	sort(c, c + n);
//	for (int i = 0; i < n; i++)
//		printf("%d ", c[i]);
//	printf("\n");
	double ans = 0;
	double q = 1.;
	for (int i = 0; i + k <= n; i++)
	{
		double f = (double)(n - i - k) / (double)(n - i);
		ans += c[i] * q * (1. - f);
		q *= f;
	}
	printf("%.12lf\n", ans);

	return 0;
}