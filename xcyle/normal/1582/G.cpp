/*

_/      _/      _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/     _/      _/     _/    _/     _/           _/
  _/  _/      _/              _/  _/      _/           _/
   _/_/       _/                _/        _/           _/_/_/_/
  _/  _/      _/                _/        _/           _/
 _/    _/     _/      _/        _/        _/           _/
_/      _/      _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
char s[maxn];
struct node
{
	int pos, d;
};
vector<node> p[maxn];
int sta[maxn], top;
int t[4000005];
void build(int x, int l, int r)
{
	t[x] = n;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(lc(x), l, mid);
	build(rc(x), mid + 1, r);
}
void work(int x, int l, int r, int a, int b, int d)
{
	if(a > r || b < l) return;
	if(a <= l && r <= b)
	{
		t[x] = min(t[x], d);
		return;
	}
	int mid = (l + r) >> 1;
	if(a <= mid) work(lc(x), l, mid, a, b, d);
	if(b > mid) work(rc(x), mid + 1, r, a, b, d);
} 
long long ans = 0;
void calc(int x, int l, int r, int d)
{
	d = min(d, t[x]);
	if(l == r)
	{
//		printf("%d %d\n", l, d);
		ans += max(0, (d - l + 1));
		return;
	}
	int mid = (l + r) >> 1; 
	calc(lc(x), l, mid, d);
	calc(rc(x), mid + 1, r, d);
}
int mn[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= 1000000; i++) mn[i] = i;
	for (int i = 2; i <= 1000000; i++)
	{
		for (int j = i; j <= 1000000; j += i)
		{
			mn[j] = min(mn[j], i);
		}
	}
	build(1, 1, n);
	for (int i = 2; i <= 1000000; i++) p[i].push_back({0, 0});
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		while(a[i] != 1)
		{
			int j = mn[a[i]];
			int cnt = 0;
			while(a[i] % j == 0)
			{
				cnt++;
				a[i] /= j;
			}
			if(s[i] == '/') cnt = -cnt;
			p[j].push_back({i, cnt});
		}
	}
	for (int i = 2; i <= 1000000; i++)
	{
		if(p[i].size() == 1) continue;
		for (int j = 1; j < p[i].size(); j++)
		{
			p[i][j].d += p[i][j - 1].d;
		}
		p[i].push_back({n + 1, -INF});
		sta[top = 0] = p[i].size() - 1;
		for (int j = p[i].size() - 2; j >= 0; j--)
		{
			while(top && p[i][sta[top]].d >= p[i][j].d) top--;
			work(1, 1, n, p[i][j].pos + 1, p[i][j + 1].pos, p[i][sta[top]].pos - 1);
//			printf("%d %d %d\n", p[i][j].pos + 1, p[i][j + 1].pos, p[i][sta[top]].pos - 1);
			sta[++top] = j;
		}
	}
	calc(1, 1, n, n);
	printf("%lld\n", ans);
	return 0;
}