#include <bits/stdc++.h>
using namespace std;
int n;
int a[100020];
int b[100020];
bool ok(int M)
{
	for (int i = 0; i <= M; i++)
	{
		b[i * 2] = a[n - 1 - i];
	}
	for (int i = 0; i < M; i++)
	{
		b[i * 2 + 1] = a[M - 1 - i];
	}
	for (int i = 2 * M + 1, j = M; i < n; i++)
	{
		b[i] = a[j++];
	}
	for (int i = 0; i < M; i++)
	{
		if (b[i * 2 + 1] == b[i * 2])
		{
			return false;
		}
		if (b[i * 2 + 1] == b[i * 2 + 2])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	int L = 0;
	int R = (n - 1) / 2 + 1;
	while (L < R - 1)
	{
		int M = (L + R) / 2;
		if (ok(M))
		{
			L = M;
		}
		else
		{
			R = M;
		}
	}
	ok(L);
	printf("%d\n", L);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}