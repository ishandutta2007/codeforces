#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 500500;
int n, m, p;
char s[N];
int l[N], r[N];
int a[N];
int st[N];
int sz;
char b[N];
char ans[N];
int ansSz;

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d", &n, &m, &p);
	p--;
	scanf(" %s ", s);
	scanf(" %s ", b);
	for (int i = 0; i < n; i++)
	{
		l[i] = i - 1;
		r[i] = i + 1;
	}
	r[n - 1] = -1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '(')
			st[sz++] = i;
		else
		{
			int x = st[--sz];
			a[x] = i;
			a[i] = x;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (b[i] == 'L')
			p = l[p];
		else if (b[i] == 'R')
			p = r[p];
		else
		{
			int x = p, y = a[p];
			if (x > y) swap(x, y);
			x = l[x];
			y = r[y];
			if (x != -1)
				r[x] = y;
			if (y != -1)
				l[y] = x;
			if (y != -1)
				p = y;
			else
				p = x;
		}
	}
	while(l[p] != -1) p = l[p];
	while(p != -1)
	{
		ans[ansSz++] = s[p];
		p = r[p];
	}
	ans[ansSz] = (char)0;
	printf("%s\n", ans);

	return 0;
}