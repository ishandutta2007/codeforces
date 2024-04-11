#include <iostream>
#include <cstdio>
#define maxn 2005
using namespace std;
int t, n, k, cnt, l[maxn], r[maxn];
char s[maxn];
char tmp[maxn];
void work(int x, int y)
{
	l[++cnt] = x, r[cnt] = y;
	for (int i = x; i <= y; i++)
	{
		tmp[i] = s[i];
	}
	for (int i = x; i <= y; i++)
	{
		s[i] = tmp[y - (i - x)];
	}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		cnt = 0;
		scanf("%d%d%s", &n, &k, s + 1);
		for (int i = 1; i <= k - 1; i++)
		{
			if(s[2 * i - 1] == '(')
			{
				for (int j = 2 * i; j <= n; j++)
				{
					if(s[j] == ')')
					{
						work(2 * i, j);
						break;
					}
				}
			}
			else
			{
				for (int j = 2 * i; j <= n; j++)
				{
					if(s[j] == '(')
					{
						work(2 * i - 1, j);
						break;
					}
				}
			}
		}
		int pos = 2 * k - 1;// 
		for (int i = 2 * k - 1; i <= n; i++)
		{
			if(s[i] == '(')
			{
				work(pos, i);
				pos++;
			}
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i++)
		{
			printf("%d %d\n", l[i], r[i]);
		}
	}
	return 0;
}