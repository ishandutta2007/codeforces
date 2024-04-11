#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int n;
char s[111];
int cnt[111][30];
int res[3][111][30];
char ans[111];
void query(int k, int (*res)[30])
{
	int m = k * (k + 1) / 2;
	memset(cnt, 0, sizeof(cnt));
	for(int i = 1; i <= m; i++)
	{
		scanf("%s", s);
		int l = strlen(s);
		for(int j = 0; j < l; j++)
			cnt[l][s[j] - 'a']++;
	}
	for(int i = (k + 1) / 2; i >= 2; i--)
		for(int j = 0; j < 26; j++)
			cnt[i][j] -= cnt[i - 1][j];
	for(int i = 1; i < (k + 1) / 2; i++)
		for(int j = 0; j < 26; j++)
			res[i][j] = cnt[i][j] - cnt[i + 1][j];
	for(int i = (k + 1) / 2; i <= (k + 1) / 2; i++)
		for(int j = 0; j < 26; j++)
			res[i][j] = cnt[i][j];
	res[0][0] = k;
}
char get(int *from)
{
	for(int j = 0; j < 26; j++)
		if(from[j])
			return j + 'a';
}
char get(int *from, char pre)
{
	for(int j = 0; j < 26; j++)
		if((j + 'a' != pre && from[j]) || from[j] == 2)
			return j + 'a';
}
int rem;
void update(int &now, int nxt, int *from)
{
	rem--;
	ans[nxt] = get(from, ans[now]);
//	printf("update %d->%d: %c\n", now, nxt, ans[nxt]);
	now = nxt;
}
int main()
{
	scanf("%d", &n);
	ans[n + 1] = 0;
	if(n <= 3)
	{
		for(int i = 1; i <= n; i++)
		{
			printf("? %d %d\n", i, i);
			fflush(stdout);
			scanf("%s", s);
			ans[i] = s[0];
		}
		printf("! %s\n", ans + 1);
		return 0;
	}
	printf("? %d %d\n", 1, n);
	fflush(stdout);
	query(n, res[0]);
	int now;
	rem = n - 1;
	if(n % 2 == 0)
	{
		if(n / 2 % 2 == 0)
		{
			printf("? %d %d\n", 1, n / 2 - 1);
			fflush(stdout);
			query(n / 2 - 1, res[1]);
			printf("? %d %d\n", n / 2 + 1, n);
			fflush(stdout);
			query(n / 2, res[2]);
			now = n / 4;
		}
		else
		{
			printf("? %d %d\n", 1, n / 2);
			fflush(stdout);
			query(n / 2, res[1]);
			printf("? %d %d\n", n / 2 + 2, n);
			fflush(stdout);
			query(n / 2 - 1, res[2]);
			now = n / 4 + 1;
		}
	}
	else
	{
		rem--;
		if(n / 2 % 2 == 0)
		{
			printf("? %d %d\n", 1, n / 2 + 1);
			fflush(stdout);
			query(n / 2 + 1, res[1]);
			printf("? %d %d\n", n / 2 + 2, n);
			fflush(stdout);
			query(n / 2, res[2]);
			now = n / 4 + 1;
		}
		else
		{
			printf("? %d %d\n", 1, n / 2);
			fflush(stdout);
			query(n / 2, res[1]);
			printf("? %d %d\n", n / 2 + 1, n);
			fflush(stdout);
			query(n / 2 + 1, res[2]);
			now = n / 4 + 1;
		}
		ans[(n + 1) / 2] = get(res[0][(n + 1) / 2]);
	}
	ans[now] = get(res[1][now]);
	while(rem > 0)
	{
		update(now, n + 1 - now, res[0][now]);
		if(!rem) break;
		update(now, 2 * n - res[2][0][0] - now + 1, res[2][min(n + 1 - now, n + 1 - (2 * n - res[2][0][0] - now + 1))]);
		if(!rem) break;
		update(now, n + 1 - now, res[0][n + 1 - now]);
		if(!rem) break;
		update(now, res[1][0][0] + 1 - now, res[1][min(res[1][0][0] + 1 - now, now)]);
	}
	printf("! %s\n", ans + 1);
	return 0;
}
/*
7
a
b
c
d
e
ab
bc
cd
de
abc
bcd
cde
abcd
bcde
abcde
f
ef
def
cdef
bcdef
abcdef
g
fg
efg
defg
cdefg
bcdefg
abcdefg
a
b
c
ab
cb
abc
e
f
ef
d
g
de
fg
def
efg
defg
*/