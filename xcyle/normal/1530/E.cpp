#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define maxn 200005
using namespace std;
int T, n;
int cnt[30];
char s[maxn];
int ans[maxn];
void solve()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(n <= 1)
	{
		for (int i = 1; i <= n; i++) printf("%c", s[i]);
		printf("\n");
		return;
	}
	for (int i = 0; i < 26; i++) cnt[i] = 0;
	for (int i = 1; i <= n; i++) cnt[s[i] - 'a']++;
	for (int i = 0; i < 26; i++)
	{
		if(cnt[i] == 1)
		{
			printf("%c", (char)'a' + i);
			for (int j = 0; j < 26; j++)
			{
				if(i == j) continue;
				for (int k = 1; k <= cnt[j]; k++) printf("%c", (char)'a' + j);
			}
			printf("\n");
			return;
		}
	}
	for (int i = 1; i <= n; i++) ans[i] = -1;
	int FLAG = 0;
	int tot = 0;
	for (int i = 0; i < 26; i++)
	{
		if(cnt[i]) tot++;
	}
	for (int i = 0; i < 26; i++)
	{
		if(FLAG && cnt[i])
		{
			printf("%c", (char)'a' + i);
			cnt[i]--;
			for (int j = 0; j < 26; j++)
			{
				for (int k = 1; k <= cnt[j]; k++) printf("%c", (char)'a' + j);
			}
			printf("\n");
			return;
		}
		if((cnt[i] - 2) * 2 <= n - 2 && cnt[i] != 0)
		{
			ans[1] = ans[2] = i;
			cnt[i] -= 2;
			int pos = 4, flag = 0;
			for (int j = 1; j <= cnt[i]; j++)
			{
				ans[pos] = i;
				pos += 2;
			}
			pos = 3;
			for (int j = 0; j < 26; j++)
			{
				if(i == j) continue;
				for (int k = 1; k <= cnt[j]; k++)
				{
					if(ans[pos] != -1) pos++;
					ans[pos] = j;
					pos++;
				}
			}
			for (int j = 1; j <= n; j++) printf("%c", (char)ans[j] + 'a');
			printf("\n");
			return;
		}
		if(cnt[i])
		{
			if(tot == 2)
			{
				printf("%c", (char)'a' + i);
				cnt[i]--;
				for (int j = 0; j < 26; j++)
				{
					if(i == j) continue;
					for (int k = 1; k <= cnt[j]; k++) printf("%c", (char)'a' + j);
				}
				for (int j = 0; j < 26; j++)
				{
					if(i != j) continue;
					for (int k = 1; k <= cnt[j]; k++) printf("%c", (char)'a' + j);
				}
				printf("\n");
			return;
			}
			if(tot > 2)
			{
				printf("%c", (char)'a' + i);
				cnt[i]--;
				int tmp;
				for (int j = 0; j < 26; j++)
				{
					if(i == j ||!cnt[j]) continue;
					printf("%c", (char)'a' + j);
					cnt[j]--;
					tmp = j;
					break;
				}
					for (int k = 1; k <= cnt[i]; k++) printf("%c", (char)'a' + i);
				for (int j = 0; j < 26; j++)
				{
					if(i == j || tmp == j ||!cnt[j]) continue;
					printf("%c", (char)'a' + j);
					cnt[j]--;
					break;
				}
				for (int j = 0; j < 26; j++)
				{
					if(i == j) continue;
					for (int k = 1; k <= cnt[j]; k++) printf("%c", (char)'a' + j);
				}
				printf("\n");
			return;
			}
		}
		if(cnt[i]) FLAG = 1;
	}
	for (int i = 1; i <= n; i++) printf("%c", s[i]);
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}