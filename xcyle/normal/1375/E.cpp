#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
inline ll readll()
{
	ll x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
struct node
{
	int pos, data;
}p[maxn];
inline int cmp(node aa, node bb)
{
	return aa.data == bb.data ? aa.pos < bb.pos : aa.data < bb.data;
}
int cnt, ans1[maxn * maxn], ans2[maxn * maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = n; i >= 1; i--)
	{
		int mx = a[i], pos = i;
		for (int j = 1; j < i; j++)
		{
			p[j].data = a[j];
			p[j].pos = j;
		}
		sort(p + 1, p + i, cmp);
		for (int j = 1; j < i; j++)
		{
			if(p[j].data <= a[i]) continue;
			ans1[++cnt] = p[j].pos;
			ans2[cnt] = i;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
	{
		printf("%d %d\n", ans1[i], ans2[i]);
	}
	return 0;
}