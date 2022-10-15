#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int q, n, k;
char s[200001], s1[200001], s2[200001], s3[200001];
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
	for (int i = 0; i <= 200000; i++)
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
		for (int i = 1; i <= k; i++)
		{
			if (s[i] == s1[i])
			{
				temp++;
			}
		}
		checkmax(maxlen, temp);
		for (int i = k + 1; i <= n; i++)
		{
			if (s[i - k] == s1[i - k])
			{
				temp--;
			}
			if (s[i] == s1[i])
			{
				temp++;
			}
			checkmax(maxlen, temp);
		}
		temp = 0;
		for (int i = 1; i <= k; i++)
		{
			if (s[i] == s2[i])
			{
				temp++;
			}
		}
		checkmax(maxlen, temp);
		for (int i = k + 1; i <= n; i++)
		{
			if (s[i - k] == s2[i - k])
			{
				temp--;
			}
			if (s[i] == s2[i])
			{
				temp++;
			}
			checkmax(maxlen, temp);
		}
		temp = 0;
		for (int i = 1; i <= k; i++)
		{
			if (s[i] == s3[i])
			{
				temp++;
			}
		}
		checkmax(maxlen, temp);
		for (int i = k + 1; i <= n; i++)
		{
			if (s[i - k] == s3[i - k])
			{
				temp--;
			}
			if (s[i] == s3[i])
			{
				temp++;
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