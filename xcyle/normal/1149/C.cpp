#include <iostream>
#include <cstdio>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
#define N 800005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, q, a[maxn], sum[maxn], p1, p2;
char s[maxn];
int t[N][5], tag[N]; 
void pushdown(int x)
{
	tag[lc(x)] += tag[x];
	t[lc(x)][0] += tag[x];
	t[lc(x)][1] += tag[x];
	t[lc(x)][2] -= tag[x];
	t[lc(x)][3] -= tag[x];
	tag[rc(x)] += tag[x];
	t[rc(x)][0] += tag[x];
	t[rc(x)][1] += tag[x];
	t[rc(x)][2] -= tag[x];
	t[rc(x)][3] -= tag[x];
	tag[x] = 0;
}
void pushup(int x)
{
	t[x][0] = max(t[lc(x)][0], t[rc(x)][0]);
	t[x][1] = min(t[lc(x)][1], t[rc(x)][1]);
	t[x][2] = max(max(t[lc(x)][2], t[rc(x)][2]), t[lc(x)][0] - 2 * t[rc(x)][1]);
	t[x][3] = max(max(t[lc(x)][3], t[rc(x)][3]), t[rc(x)][0] - 2 * t[lc(x)][1]);
	t[x][4] = max(max(t[lc(x)][4], t[rc(x)][4]), max(t[lc(x)][0] + t[rc(x)][3], t[lc(x)][2] + t[rc(x)][0]));
}
void build(int x, int l, int r)
{
	if(l == r)
	{
		t[x][0] = t[x][1] = sum[l];
		t[x][2] = t[x][3] = t[x][4] = -INF;
		return;
	}
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
	pushup(x);
}
void add(int x, int l, int r, int a, int b, int data)
{
	if(a <= l && r <= b)
	{
		tag[x] += data;
		t[x][0] += data;
		t[x][1] += data;
		t[x][2] -= data;
		t[x][3] -= data;
		return;
	}
	pushdown(x);
	int mid = (l + r) >> 1;
	if(a <= mid) add(lc(x), l, mid, a, b, data);
	if(b > mid) add(rc(x), mid + 1, r, a, b, data);
	pushup(x);
}
int main()
{
	scanf("%d%d%s", &n, &q, s + 1);
	n = 2 * (n - 1);
	for (int i = 1; i <= n; i++) 
	{
		a[i] = (s[i] == '(' ? 0 : 1); 
		sum[i] = sum[i - 1] - a[i] * 2 + 1;
	}
	build(1, 1, n);
	printf("%d\n", max(t[1][0], t[1][4]));
	for (int i = 1; i <= q; i++)
	{
		scanf("%d%d", &p1, &p2);
		if(p1 > p2) swap(p1, p2);
		if(a[p1] != a[p2]) add(1, 1, n, p1, p2 - 1, a[p1] * 4 - 2);
		swap(a[p1], a[p2]);
		printf("%d\n", max(t[1][0], t[1][4]));
	}
	return 0;
}