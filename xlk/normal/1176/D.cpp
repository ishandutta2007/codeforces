#include <bits/stdc++.h>
using namespace std;
const int N = 2750131;
int v[N + 1];
int p[N + 1], pc;
int n, x;
int c[N + 1];
int main()
{
	for (int i = 2; i <= N; i++)
	{
		if (!v[i])
		{
			p[++pc] = i;
		}
		for (int j = 1; j <= pc && i * p[j] <= N; j++)
		{
			v[i * p[j]] = p[j];
			if (v[i] == p[j])
			{
				break;
			}
		}
	}
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> x;
		c[x]++;
	}
	for (int i = N; i > 0; i--)
	{
		if (v[i])
		{
			for (;c[i] > 0; c[i]--)
			{
				printf("%d ", i);
				c[i / v[i]]--;
			}
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (;c[i] > 0; c[i]--)
		{
			printf("%d ", i);
			c[p[i]]--;
		}
	}
	printf("\n");
	return 0;
}