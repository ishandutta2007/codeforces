#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int q, n, k, dp[3001][3001];
char s[3001], s1[3001], s2[3001], s3[3001];
void checkmax(int &x, int y)
{
	if (x < y)
	{
		x = y;
	}
}
int main()
{
	scanf("%d", &q);
	for (int i = 0; i <= 3000; i++)
	{
		if (i % 3 == 0)
		{
			s1[i] = 'R';
			s2[i] = 'G';
			s3[i] = 'B';
		}
		if (i % 3 == 1)
		{
			s1[i] = 'G';
			s2[i] = 'B';
			s3[i] = 'R';
		}
		if (i % 3 == 2)
		{
			s1[i] = 'B';
			s2[i] = 'R';
			s3[i] = 'G';
		}
	}
	while (q--)
	{
		scanf("%d%d%s", &n, &k, s + 1);
		int maxlen = 0, temp = 0;
		for (int i = 1; i + k - 1<= n; i++)
		{
			temp = 0;
			for (int j = i; j <= i + k - 1; j++)
			{
				if (s[j] == s1[j])
				{
					temp++;
				}
			}
			checkmax(maxlen, temp);
		}
		for (int i = 1; i + k - 1 <= n; i++)
		{
			temp = 0;
			for (int j = i; j <= i + k - 1; j++)
			{
				if (s[j] == s2[j])
				{
					temp++;
				}
			}
			checkmax(maxlen, temp);
		}
		for (int i = 1; i + k - 1<= n; i++)
		{
			temp = 0;
			for (int j = i; j <= i + k - 1; j++)
			{
				if (s[j] == s3[j])
				{
					temp++;
				}
			}
			checkmax(maxlen, temp);
		}
		if (maxlen > k)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", k - maxlen);
		}
	}
	return 0;
}