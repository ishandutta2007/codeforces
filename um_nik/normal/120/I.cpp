#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 200100;

int w[12][12] = {
	{6, 2, 4, 4, 3, 4, 5, 3, 6, 5},
	{2, 2, 1, 2, 2, 1, 1, 2, 2, 2},
	{4, 1, 5, 4, 2, 3, 4, 2, 5, 4},
	{4, 2, 4, 5, 3, 4, 4, 3, 5, 5},
	{3, 2, 2, 3, 4, 3, 3, 2, 4, 4},
	{4, 1, 3, 4, 3, 5, 5, 2, 5, 5},
	{5, 1, 4, 4, 3, 5, 6, 2, 6, 5},
	{3, 2, 2, 3, 2, 2, 2, 3, 3, 3},
	{6, 2, 5, 5, 4, 5, 6, 3, 7, 6},
	{5, 2, 4, 5, 4, 5, 5, 3, 6, 6}
};

int a[N];
int b[N];
char s[N];
int dp[N];
int n;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf(" %s ", s);
	n = strlen(s) / 2;
	for (int i = 0; i < 2 * n; i++)
		a[i] = (int)(s[i] - '0');
	dp[2 * n] = 0;
	int idx = -1;
	int bal;
	for (int pos = 2 * n - 1; pos >= 0; pos--)
	{
		for (int x = a[pos] + 1; x < 10; x++)
		{
			int c = dp[pos + 1];
			if (pos < n)
				c += w[x][8] - w[a[pos]][8];
			else
				c += w[x][a[pos - n]] - w[a[pos]][a[pos - n]];
			if (c > 0)
			{
				bal = c - dp[pos + 1];
				idx = pos + 1;
				for (int i = 0; i < pos; i++)
					b[i] = a[i];
				b[pos] = x;
				break;
			}
		}
		if (idx != -1) break;
		int c = dp[pos + 1];
		if (pos < n)
			c += w[8][8] - w[a[pos]][8];
		else
			c += w[a[pos - n]][8] - w[a[pos]][a[pos - n]];
		dp[pos] = c;
	}
	if (idx == -1)
	{
		printf("-1\n");
		return 0;
	}
	for(int pos = idx; pos < 2 * n; pos++)
	{
		for (int x = 0; x < 10; x++)
		{
			int c;
			if (pos < n)
				c = w[x][8] - w[a[pos]][8];
			else
				c = w[x][b[pos - n]] - w[a[pos]][a[pos - n]] - w[b[pos - n]][8] + w[a[pos - n]][8];
			if (bal + c + dp[pos + 1] > 0)
			{
				bal += c;
				b[pos] = x;
				break;
			}
		}
	}
	for (int i = 0; i < 2 * n; i++)
		printf("%d", b[i]);
	printf("\n");

	return 0;
}