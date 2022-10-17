#include <iostream>
#include <cstdio>
#define maxn 300005
using namespace std;
int T, n;
char s[3][maxn];
int ans[maxn], cnt[3][2];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for (int i = 0; i <= 3 * n; i++) ans[i] = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++) cnt[i][j] = 0;
		}
		int tmp[2] = {0, 0};
		for (int i = 0; i < 3; i++)
		{
			scanf("%s", s[i] + 1);
			for (int j = 1; j <= 2 * n; j++)
			{
				cnt[i][s[i][j] - '0']++;
			}
			if(cnt[i][0] >= n) tmp[0]++;
			if(cnt[i][1] >= n) tmp[1]++;
		}
		if(tmp[0] >= 2)
		{
			int now = 0, temp = 0;
			for (int i = 0; i < 3; i++)
			{
				if(cnt[i][0] >= n && now < 2)
				{
					int pos = 0, x = 0;
					for (int j = 1; j <= 2 * n; j++)
					{
						if(s[i][j] == '0') 
						{
							ans[pos] = max(ans[pos], x);
							pos++;
							x = 0;
						}
						else x++;
					}
					ans[pos] = max(ans[pos], x); 
					now++;
					temp = max(temp, pos);
				}
			}
			for (int i = 0; i < temp; i++)
			{
				for (int j = 1; j <= ans[i]; j++) printf("1");
				printf("0");
			}
			for (int j = 1; j <= ans[temp]; j++) printf("1");
			printf("\n");
		}
		else
		{
			int now = 0, temp = 0;
			for (int i = 0; i < 3; i++)
			{
				if(cnt[i][1] >= n && now < 2)
				{
					int pos = 0, x = 0;
					for (int j = 1; j <= 2 * n; j++)
					{
						if(s[i][j] == '1') 
						{
							ans[pos] = max(ans[pos], x);
							pos++;
							x = 0;
						}
						else x++;
					}
					ans[pos] = max(ans[pos], x); 
					now++;
					temp = max(temp, pos);
				}
			}
			for (int i = 0; i < temp; i++)
			{
				for (int j = 1; j <= ans[i]; j++) printf("0");
				printf("1");
			}
			for (int j = 1; j <= ans[temp]; j++) printf("0");
			printf("\n");
		}
	}
	return 0;
}