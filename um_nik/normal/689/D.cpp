#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 200100;
const int L = 18;
int n;
int p[N];
int a[L][N];
int b[L][N];

void read()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[0][i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[0][i]);

	p[0] = p[1] = 0;
	for (int i = 2; i < N; i++)
		p[i] = 1 + p[i / 2];

	for (int k = 1; k < L; k++)
		for (int i = 0; i + (1 << k) <= n; i++)
		{
			a[k][i] = max(a[k - 1][i], a[k - 1][i + (1 << (k - 1))]);
			b[k][i] = min(b[k - 1][i], b[k - 1][i + (1 << (k - 1))]);
		}
	return;
}

int getA(int l, int r)
{
	int k = p[r - l];
	return max(a[k][l], a[k][r - (1 << k)]);
}
int getB(int l, int r)
{
	int k = p[r - l];
	return min(b[k][l], b[k][r - (1 << k)]);
}

int getRight(int it)
{
	int l = it, r = n + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if (getA(it, m) <= getB(it, m))
			l = m;
		else
			r = m;
	}
	return r;
}
int getLeft(int it)
{
	int l = it, r = n + 1;
	while(r - l > 1)
	{
		int m = (l + r) / 2;
		if (getA(it, m) < getB(it, m))
			l = m;
		else
			r = m;
	}
	return r;
}

int solve(int it)
{
	return getRight(it) - getLeft(it);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	long long ans = 0;
	for (int i = 0; i < n; i++)
		ans += solve(i);
	printf("%lld\n", ans);

	return 0;
}