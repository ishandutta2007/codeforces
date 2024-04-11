#include <iostream>
#include <cstdio>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
using namespace std;
int n, m, q, a[maxn], type, l, r;
long long d;
int t[2][maxn * 4][32], tag[maxn * 4];
void pushup(int x)
{
	for (int i = 0; i < (1 << m); i++)
	{
		t[0][x][i] = t[0][lc(x)][t[0][rc(x)][i]];
		t[1][x][i] = t[1][lc(x)][t[1][rc(x)][i]]; 
	}
}
void pushdown(int x)
{
	if(!tag[x]) return;
	for (int i = 0; i < (1 << m); i++) 
	{
		swap(t[0][lc(x)][i], t[1][lc(x)][i]);
		swap(t[0][rc(x)][i], t[1][rc(x)][i]);
	}
	tag[lc(x)] ^= 1, tag[rc(x)] ^= 1; 
	tag[x] = 0;
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		for (int i = 0; i < (1 << m); i++)
		{
			t[(a[l] & 1) ^ 1][x][i] = (i >> 1) + (1 << (m - 1));
			t[a[l] & 1][x][i] = (i >> 1) + ((i == (1 << m) - 1 ? 0 : 1) << (m - 1));
		}
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
	pushup(x);
}
void change(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b)
	{
		tag[x] ^= 1;
		for (int i = 0; i < (1 << m); i++) swap(t[0][x][i], t[1][x][i]);
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) change(lc(x), l, mid, a, b);
	if(b > mid) change(rc(x), mid + 1, r, a, b);
	pushup(x);
}
int query(int x, int l, int r, int a, int b, int st)
{
	if(a <= l && r <= b) return t[0][x][st];
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid && mid < b)
	{
		int tmp = query(rc(x), mid + 1, r, a, b, st);
		return query(lc(x), l, mid, a, b, tmp);
	}
	else if(a <= mid) return query(lc(x), l, mid, a, b, st);
	else return query(rc(x), mid + 1, r, a, b, st);
}
int main()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%lld", &d);
		d++;
		d &= 1ll;
		a[i] = d;
	}
	build(1, 1, n);
	while(q--)
	{
		scanf("%d%d%d", &type, &l, &r);
		if(type == 1)
		{
			scanf("%lld", &d);
			if(d % 2 == 1) change(1, 1, n, l, r);
		}
		else printf("%d\n", 2 - ((query(1, 1, n, l, r, (1 << m) - 1) >> (m - 1)) & 1));
	}
	return 0;
}