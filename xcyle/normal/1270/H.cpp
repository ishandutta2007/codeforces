#include <iostream>
#include <cstdio>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define mid ((l + r) >> 1)
#define maxn 500005
#define maxa 1000005
#define A 1000000
using namespace std;
inline int read()
{
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return x;
}
int n, q, a[maxn];
int t[maxa * 4], tag[maxa * 4], cnt[maxa * 4];
inline void pushdown(int x)
{
	t[lc(x)] += tag[x], t[rc(x)] += tag[x];
	tag[lc(x)] += tag[x], tag[rc(x)] += tag[x];
	tag[x] = 0;
}
inline void pushup(int x)
{
	t[x] = min(t[lc(x)], t[rc(x)]), cnt[x] = 0;
	if(t[lc(x)] == t[x]) cnt[x] += cnt[lc(x)];
	if(t[rc(x)] == t[x]) cnt[x] += cnt[rc(x)];
}
void modify(int x, int l, int r, int a, int b, int d)
{
	if(a > b) return;
	if(a <= l && r <= b){tag[x] += d, t[x] += d; return;}
	pushdown(x);
	if(a <= mid) modify(lc(x), l, mid, a, b, d);
	if(b > mid) modify(rc(x), mid + 1, r, a, b, d);
	pushup(x);
}
void change(int x, int l, int r, int pos, int d)
{
	if(l == r){cnt[x] += d; t[x] = (cnt[x] ? tag[x] : maxn); return;}
	pushdown(x);
	if(pos <= mid) change(lc(x), l, mid, pos, d);
	else change(rc(x), mid + 1, r, pos, d);
	pushup(x);
}
int main()
{
	//freopen("CF1270H.in", "r", stdin);
	//freopen("CF1270H.out", "w", stdout);
	n = read(), q = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	a[0] = 1e6, a[n + 1] = 0;
	for (int i = 1; i < maxn * 4; i++) t[i] = maxn;
	for (int i = 1; i <= n + 1; i++) modify(1, 1, A, a[i - 1] + 1, a[i], 1);
	for (int i = 1; i <= n; i++) change(1, 1, A, a[i], 1);
	while(q--)
	{
		int pos = read(), x = read();
		modify(1, 1, A, a[pos] + 1, a[pos + 1], -1);
		modify(1, 1, A, a[pos - 1] + 1, a[pos], -1);
		change(1, 1, A, a[pos], -1);
		a[pos] = x;
		modify(1, 1, A, a[pos] + 1, a[pos + 1], 1);
		modify(1, 1, A, a[pos - 1] + 1, a[pos], 1);
		change(1, 1, A, a[pos], 1);
		if(t[1] == 0) printf("%d\n", cnt[1]);
		else printf("0\n");
	} 
	return 0;
}