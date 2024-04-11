#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

const int N = 111;
int n, m;
char s[N][N];
char ans[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf(" %s ", s[i]);
	int x;
	scanf("%d", &x);
	x--;
	int len = strlen(s[x]);
	for (int i = 0; i < len; i++)
		ans[i] = s[x][i];
	for (int j = 1; j < m; j++)
	{
		scanf("%d", &x);
		x--;
		if (len != strlen(s[x]))
		{
			printf("No\n");
			return 0;
		}
		for (int i = 0; i < len; i++)
			if (ans[i] != s[x][i])
				ans[i] = '?';
	}
	int cnt = 0;
	for (int j = 0; j < n; j++)
	{
		bool ok = (len == strlen(s[j]));
		for (int i = 0; i < len && ok; i++)
			ok &= (ans[i] == '?' || ans[i] == s[j][i]);
		cnt += (int)ok;
	}
	if (cnt != m)
		printf("No\n");
	else
	{
		printf("Yes\n");
		ans[len] = '\0';
		printf("%s\n", ans);
	}

	return 0;
}