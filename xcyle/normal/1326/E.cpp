#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define uint unsigned int
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 3000005
using namespace std;
const int mod1 = 123984337;
const int bas1 = 1e9 + 7;
const uint bas2 = 1e9 + 9;
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
int n;
int p[maxn], q[maxn];
int t[maxn * 4], pos[maxn], tag[maxn * 4];
inline void pushdown(int x)
{
	tag[lc(x)] += tag[x];
	t[lc(x)] += tag[x];
	tag[rc(x)] += tag[x];
	t[rc(x)] += tag[x];
	tag[x] = 0;
}
void add(int x, int l, int r, int a, int b, int data)
{
	if(a <= l && r <= b)
	{
		tag[x] += data;
		t[x] += data;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, data);
	if(b > mid) add(rc(x), mid + 1, r, a, b, data);
	t[x] = max(t[lc(x)], t[rc(x)]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &q[i]);
	for (int i = n; i >= 1; i--) pos[p[i]] = i;
	add(1, 1, n, 1, pos[n], 1);
	int now = n;
	printf("%d ", now);
	for (int i = 1; i < n; i++)
	{
		add(1, 1, n, 1, q[i], -1);
		while(now && t[1] <= 0)
		{
			int loc = pos[now + 1];
			now--;
			add(1, 1, n, 1, pos[now], 1);
		}
		printf("%d ", now);
	}
	return 0;
}