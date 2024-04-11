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
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int l[2][maxn], r[2][maxn], cnt[2][maxn], num[2];
void work(int L, int id)
{
	num[id] = 1;
	for (int i = 1, j; i <= L; i = j + 1, num[id]++)
	{
		cnt[id][num[id]] = L / i;
		j = L / (L / i);
		l[id][num[id]] = i, r[id][num[id]] = j;
		if(cnt[id][num[id]] == cnt[id][num[id] - 1])
		{
			num[id]--;
			r[id][num[id]] = j;
		}
		if(L % (L / i) == 0)
		{
			num[id]++;
			cnt[id][num[id]] = L / i - 1;
			l[id][num[id]] = r[id][num[id]] = L / (L / i);
//			printf("%d\n", L / i);
		}
	}
}
int main()
{
	int a = read(), b = read();
	work(a, 0), work(b, 1);
	int ans = 0, now = 0;
	for (int p0 = 1, p1 = 1; p0 < num[0] && p1 < num[1]; )
	{
		if(cnt[0][p0] == cnt[1][p1])
		{
//			printf("%d %d %d %d\n", l[0][p0], r[0][p0], l[1][p1], r[1][p1]);
			int L = l[0][p0] + l[1][p1], R = r[0][p0] + r[1][p1];
			L = max(L, now + 1);
//			printf("%d %d\n", L, R);
			ans += R - L + 1;
			now = R;
			p0++, p1++;
		}
		else if(cnt[0][p0] > cnt[1][p1]) p0++;
		else if(cnt[1][p1] > cnt[0][p0]) p1++;
	}
	printf("%d\n", ans);
	return 0;
}