#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 305
using namespace std;
int n, m;
char s[100005], t[100005];
int cnt[2][maxn];
int a[400005][4], ans1;
int b[400005][4], ans2;
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%s", s + 1);
			int len = strlen(s + 1);
			if(i == 1)
			{
				for (int k = len; k >= 1; k--)
				{
					if(s[k] == '0')
					{
						a[++ans1][0] = i;
						a[ans1][1] = j;
						a[ans1][2] = 1;
						a[ans1][3] = j + 1 > m ? j - 1 : j + 1;
						cnt[0][a[ans1][3]]++;
					}
					else
					{
						a[++ans1][0] = i;
						a[ans1][1] = j;
						a[ans1][2] = 2;
						a[ans1][3] = j;
						cnt[1][j]++;
					}
				}
				continue; 
			}
			if(i == 2)
			{
				for (int k = len; k >= 1; k--)
				{
					if(s[k] == '0')
					{
						a[++ans1][0] = i;
						a[ans1][1] = j;
						a[ans1][2] = 1;
						a[ans1][3] = j;
						cnt[0][j]++;
					}
					else
					{
						a[++ans1][0] = i;
						a[ans1][1] = j;
						a[ans1][2] = 2;
						a[ans1][3] = j + 1 > m ? j - 1 : j + 1;
						cnt[1][a[ans1][3]]++;
					}
				}
				continue;
			}
			for (int k = len; k >= 1; k--)
			{
				if(s[k] == '0')
				{
					a[++ans1][0] = i;
					a[ans1][1] = j;
					a[ans1][2] = 1;
					a[ans1][3] = j;
					cnt[0][j]++;
				}
				else
				{
					a[++ans1][0] = i;
					a[ans1][1] = j;
					a[ans1][2] = 2;
					a[ans1][3] = j;
					cnt[1][j]++;
				}
			}
		}
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= cnt[0][i]; j++)
		{
		    a[++ans1][0] = 1;
			a[ans1][1] = i;
			a[ans1][2] = 1;
			a[ans1][3] = 1;
		}
		for (int j = 1; j <= cnt[1][i]; j++)
		{
		    a[++ans1][0] = 2;
			a[ans1][1] = i;
			a[ans1][2] = 2;
			a[ans1][3] = 1;
		}
	}
	memset(cnt, 0, sizeof(cnt));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%s", t + 1);
			int len = strlen(t + 1);
			for (int k = 1; k <= len; k++)
			{
				s[k] = t[len - k + 1];
			}
			if(i == 1)
			{
				for (int k = len; k >= 1; k--)
				{
					if(s[k] == '0')
					{
						b[++ans2][0] = i;
						b[ans2][1] = j;
						b[ans2][2] = 1;
						b[ans2][3] = j + 1 > m ? j - 1 : j + 1;
						cnt[0][b[ans2][3]]++;
					}
					else
					{
						b[++ans2][0] = i;
						b[ans2][1] = j;
						b[ans2][2] = 2;
						b[ans2][3] = j;
						cnt[1][j]++;
					}
				}
				continue; 
			}
			if(i == 2)
			{
				for (int k = len; k >= 1; k--)
				{
					if(s[k] == '0')
					{
						b[++ans2][0] = i;
						b[ans2][1] = j;
						b[ans2][2] = 1;
						b[ans2][3] = j;
						cnt[0][j]++;
					}
					else
					{
						b[++ans2][0] = i;
						b[ans2][1] = j;
						b[ans2][2] = 2;
						b[ans2][3] = j + 1 > m ? j - 1 : j + 1;
						cnt[1][b[ans2][3]]++;
					}
				}
				continue;
			}
			for (int k = len; k >= 1; k--)
			{
				if(s[k] == '0')
				{
					b[++ans2][0] = i;
					b[ans2][1] = j;
					b[ans2][2] = 1;
					b[ans2][3] = j;
					cnt[0][j]++;
				}
				else
				{
					b[++ans2][0] = i;
					b[ans2][1] = j;
					b[ans2][2] = 2;
					b[ans2][3] = j;
					cnt[1][j]++;
				}
			}
		}
	}
	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= cnt[0][i]; j++)
		{
		    b[++ans2][0] = 1;
			b[ans2][1] = i;
			b[ans2][2] = 1;
			b[ans2][3] = 1;
		}
		for (int j = 1; j <= cnt[1][i]; j++)
		{
		    b[++ans2][0] = 2;
			b[ans2][1] = i;
			b[ans2][2] = 2;
			b[ans2][3] = 1;
		}
	}
	printf("%d\n", ans1 + ans2);
	for (int i = 1; i <= ans1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	for (int i = ans2; i >= 1; i--)
	{
		swap(b[i][0], b[i][2]);
		swap(b[i][1], b[i][3]);
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	return 0;
}