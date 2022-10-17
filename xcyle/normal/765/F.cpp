#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 400005
using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, a[maxn];
struct node
{
	int id, l;
};
vector<node> qs[maxn];
int ans[maxn * 3];
int t[maxn * 4];
vector<int> seg[400005];
void build(int x, int l, int r)
{
	for (int i = l; i <= r; i++) seg[x].push_back(a[i]);
	std::sort(seg[x].begin(), seg[x].end());
	t[x] = INF;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lc(x), l, mid), build(rc(x), mid + 1, r);
}
int data;
void change(int x, int l, int r, int aim)
{
	if(r < aim)
	{
        std::vector <int>::iterator it = std::upper_bound(seg[x].begin(), seg[x].end(), a[aim]);
        if(it != seg[x].end()) t[x] = min(t[x], *it - a[aim]);
        if(it != seg[x].begin()) t[x] = min(t[x], a[aim] - *(it - 1));
//        printf("?????%d %d\n", x, t[x]);
        if(data <= t[x]) return;
        if(l == r)
        {
//        	printf("%d ", l);
        	data = min(data, t[x]);
        	return;
		}
	}
	int mid = (l + r) >> 1;
	if(aim > mid + 1) change(rc(x), mid + 1, r, aim);
	change(lc(x), l, mid, aim);
	t[x] = min(t[x], min(t[lc(x)], t[rc(x)]));
	data = min(data, t[x]);
}
int que(int x, int l, int r, int a, int b)
{
	if(a <= l && r <= b) return t[x];
	int mid = (l + r) >> 1, res = INF;
	if(a <= mid) res = min(res, que(lc(x), l, mid, a, b));
	if(b > mid) res = min(res, que(rc(x), mid + 1, r, a, b));
	return res; 
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int tl, tr;
		scanf("%d%d", &tl, &tr);
		qs[tr].push_back((node){i, tl});
	}
	build(1, 1, n);
	for (int i = 2; i <= n; i++)
	{
		data = INF;
//		printf("!!!%d ", i);
		change(1, 1, n, i);
//		printf("\n");
		for (int j = 0; j < qs[i].size(); j++)
		{
			ans[qs[i][j].id] = que(1, 1, n, qs[i][j].l, i);
		}
	}
	for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
	return 0;
}