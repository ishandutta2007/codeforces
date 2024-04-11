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
#define maxn 100005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, cnt[4];
struct pt
{
	int x, y;
}pos[4][maxn];
inline bool cmpx(pt fir, pt sec)
{
	return fir.x < sec.x;
}
inline bool cmpy(pt fir, pt sec)
{
	return fir.y < sec.y;
}
int check2(int a, int b, int c)
{
	sort(pos[a] + 1, pos[a] + n + 1, cmpx), sort(pos[c] + 1, pos[c] + n + 1, cmpx);
	int l = 1, r = n, mid;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		int cnt = 0;
		for (int i = 1; i <= n; i++) cnt += (pos[b][i].x > pos[a][mid].x && pos[b][i].x < pos[c][n - mid + 1].x);
		if(cnt >= mid) l = mid;
		else r = mid - 1;
	}
	int res = l;
	sort(pos[b] + 1, pos[b] + n + 1, cmpy), sort(pos[c] + 1, pos[c] + n + 1, cmpy);
	l = 1, r = n;
	while(l < r)
	{
		mid = (l + r + 1) >> 1;
		int tot = 0, pre = 1e9 + 1, suf = -1e9 - 1;
		for (int i = 1; i <= n; i++)
		{
			if(pos[b][i].x <= pos[a][mid].x) continue;
			tot++;
			if(tot == mid) 
			{
				pre = pos[b][i].y;
				break;
			}
		}
		tot = 0;
		for (int i = n; i >= 1; i--)
		{
			if(pos[c][i].x <= pos[a][mid].x) continue;
			tot++;
			if(tot == mid)
			{
				suf = pos[c][i].y;
				break;
			}
		}
		if(pre < suf) l = mid;
		else r = mid - 1;
	}
	return max(res, l);
} 
int work()
{
	int res = 0;
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				if(i == j || j == k || i == k) continue;
				res = max(res, check2(i, j, k));
			}
		}
	}
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) swap(pos[i][j].x, pos[i][j].y);
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			for (int k = 1; k <= 3; k++)
			{
				if(i == j || j == k || i == k) continue;
				res = max(res, check2(i, j, k));
			}
		}
	}
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) swap(pos[i][j].x, pos[i][j].y);
	return res;
}
int main()
{
	scanf("%d", &n);
	int cntt[4] = {0, 0, 0, 0};
	for (int i = 1; i <= n; i++)
	{
		int xx = read(), yy = read(), zz = read();
		pos[zz][++cnt[zz]] = {xx, yy};
		cntt[zz] += (yy == 0);
	}
	n /= 3;
	int ans = work();
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) pos[i][j].x = -pos[i][j].x;
	ans = max(ans, work());
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) pos[i][j].y = -pos[i][j].y;
	ans = max(ans, work());
	for (int i = 1; i <= 3; i++) for (int j = 1; j <= n; j++) pos[i][j].x = -pos[i][j].x;
	ans = max(ans, work());
	cntt[1] = min(cntt[1], min(cntt[2], cntt[3]));
	printf("%d\n", ans * 3);
//	if(cntt[1] > 100) printf("%d\n", cntt[1]);
	return 0;
}