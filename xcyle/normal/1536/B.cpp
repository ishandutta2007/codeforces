#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 1005
using namespace std;
int t, n;
char s[maxn];
int x[30], y[30][30], z[30][30][30];
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		memset(x, 0, sizeof(x));
		memset(y, 0, sizeof(y));
		memset(z, 0, sizeof(z));
		scanf("%d%s", &n, s + 1);
		for (int i = 1; i <= n; i++)
		{
			x[s[i] - 'a' + 1] = 1;
		}
		for (int i = 1; i < n; i++)
		{
			y[s[i] - 'a' + 1][s[i + 1] - 'a' + 1] = 1;
		}
		for (int i = 1; i < n - 1; i++)
		{
			z[s[i] - 'a' + 1][s[i + 1] - 'a' + 1][s[i + 2] - 'a' + 1] = 1;
		}
		int flag = 0;
		for (int i = 1; i <= 26; i++)
		{
			if(!x[i])
			{
				putchar((char)i + 'a' - 1);
				putchar('\n');
				flag = 1;
				break;
			}
		}
		if(flag) continue;
		for (int i = 1; i <= 26; i++)
		{
			for (int j = 1; j <= 26; j++)
			{
				if(!y[i][j])
				{
					putchar((char)i + 'a' - 1);
					putchar((char)j + 'a' - 1);
					putchar('\n');
					flag = 1;
					break;
				}
			}
				if(flag) break;
		}
		if(flag) continue;
		for (int i = 1; i <= 26; i++)
		{
			for (int j = 1; j <= 26; j++)
			{
				for (int k = 1; k <= 26; k++)
				{
				if(!z[i][j][k])
				{
					putchar((char)i + 'a' - 1);
					putchar((char)j + 'a' - 1);
					putchar((char)k + 'a' - 1);
					putchar('\n');
					flag = 1;
					break;
				}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) break;
		}
		if(flag) continue;
	}
	return 0;
}