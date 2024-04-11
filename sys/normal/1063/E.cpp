#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, ct, p[Maxn], inv_p[Maxn];
bool flag = true, vis[Maxn], spec[Maxn];
char ch[Maxn][Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &inv_p[i]), p[inv_p[i]] = i;
		if (i != p[i]) flag = false;
	}
	if (flag)
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				putchar('.');
			puts("");
		}
		return 0;
	}
	memset(ch, '.', sizeof(ch));
	printf("%d\n", n - 1);
	int tmp = n;
	while (!spec[tmp]) spec[tmp] = true, tmp = p[tmp];
	p[n] = 0x3f3f3f3f;
	spec[0] = true;
	while (true)
	{
		int s = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i] && make_pair(~spec[i], p[i]) > make_pair(~spec[s], p[s])) s = i;
		if (!s) break;
		vis[s] = true;
		if (p[s] == s) continue;
		if (s != n) ct++, ch[ct][s] = ch[ct][n] = '\\';
		int u = s;
		while (!vis[inv_p[u]])
			ct++, ch[ct][inv_p[u]] = ch[ct][u] = inv_p[u] < u ? '\\' : '/', vis[inv_p[u]] = true, u = inv_p[u];
		if (s != n) ch[ct][p[s]] = ch[ct][n] = '/';
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			putchar(ch[i][j]);
		puts("");
	}
	return 0;
}