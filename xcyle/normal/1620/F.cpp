/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1000005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, p[maxn], ans[maxn];
int st[maxn][25], LOG[(1 << 22)];
inline int pushup(int x, int y)
{
	return p[x] > p[y] ? x : y; 
}
inline int que(int l, int r)
{
	return pushup(st[l][LOG[r - l + 1]], st[r - (1 << LOG[r - l + 1]) + 1][LOG[r - l + 1]]);
}
inline int check(int l, int r, int x, int tp)
{
	if(l > r) return 1; 
	int res = 1;
	if(tp == 0)
	{
		int ok = x < -p[l];
		for (int i = l; i < r; i++) ok &= (-p[i] < -p[i + 1]);
		if(ok)
		{
			for (int i = l; i <= r; i++) ans[i] = -p[i];
			return 1;
		}
		ans[r] = p[r];
		for (int i = r - 1; i >= l; i--)
		{
			if(p[i] < ans[i + 1])
			{
				ans[i] = p[i];
			}
			else ans[i] = -p[i];
			res &= (ans[i] < ans[i + 1]);
		}
		res &= (x < ans[l]);
	}
	else
	{
		int ok = p[r] < x;
		for (int i = l; i < r; i++) ok &= (p[i] < p[i + 1]);
		if(ok)
		{
			for (int i = l; i <= r; i++) ans[i] = p[i];
			return 1;
		}
		ans[l] = -p[l];
		for (int i = l + 1; i <= r; i++)
		{
			if(-p[i] > ans[i - 1])
			{
				ans[i] = -p[i];
			}
			else ans[i] = p[i];
			res &= (ans[i] > ans[i - 1]);
		}
		res &= (x > ans[r]);
	}
	return res;
}
int fl = 1;
void work(int l, int r, int a, int b)
{
//	printf("%d %d %d %d %d\n", l, r, a, b, fl);
	if(l > r) return;
	if(l == r)
	{
		if(a < p[l] || p[l] < b)
		{
			ans[l] = p[l];
			return;
		}
		else
		{
			ans[l] = -p[l];
			fl &= (a < ans[l] || ans[l] < b);
		}
		return;
	}
	int pos = que(l, r);
	if(pos == l)
	{
		if(a < -p[pos] || -p[pos] < b)
		{
			ans[pos] = -p[pos];
		}
		else
		{
			ans[pos] = p[pos];
			fl &= ((a < p[pos]) || (p[pos] < b));
		}
		work(l + 1, r, max(a, ans[pos]), b);
		return;
	}
	if(pos == r)
	{
		if(a < p[pos] || p[pos] < b)
		{
			ans[pos] = p[pos];
		}
		else
		{
			ans[pos] = -p[pos];
			fl &= ((a < -p[pos]) || (-p[pos] < b));
		}
		work(l, r - 1, a, min(b, ans[pos]));
		return;
	}
//	printf("%d %d %d\n", l, pos, r);
//	fflush(stdout);
	int mid = (l + r) >> 1;
	if(pos <= mid)
	{
		if(check(l, pos - 1, a, 0) && -p[pos] < b)
		{
			ans[pos] = -p[pos];
			work(pos + 1, r, max(a, ans[pos - 1]), b);
		}
		else
		{
			ans[pos] = p[pos];
			fl &= check(pos + 1, r, b, 1);
			fl &= (p[pos] > a);
			work(l, pos - 1, a, min(b, ans[pos + 1]));
		}
	}
	else
	{
		if(check(pos + 1, r, b, 1) && p[pos] > a)
		{
			ans[pos] = p[pos];
			work(l, pos - 1, a, min(b, ans[pos + 1]));
		}
		else
		{
			ans[pos] = -p[pos];
			fl &= check(l, pos - 1, a, 0);
			fl &= (-p[pos] < b);
			work(pos + 1, r, max(a, ans[pos - 1]), b);
		}
	}
}
void solve()
{
	fl = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) p[i] = read();
	for (int i = n; i >= 1; i--)
	{
		st[i][0] = i;
		for (int j = 1; j <= 20; j++) 
		{
			if(i + (1 << j) - 1 > n) continue;
			st[i][j] = pushup(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		}
	}
	work(1, n, - n - 1, n + 1);
//	if(T > 117024 - 1502 + 1) return;
//	if(T == 117024 - 1502 + 1)
//	{
//		printf("%d\n", n);
//		for (int i = 1; i <= n; i++) printf("%d ", p[i]);
//		printf("\n");
//	}
	if(!fl) printf("NO\n");
	else
	{
		printf("YES\n");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
		printf("\n");
	}
}
int main()
{
	for (int i = 0; i <= 20; i++)
	{
		for (int j = (1 << i); j < (1 << (i + 1)); j++) LOG[j] = i;
	}
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}