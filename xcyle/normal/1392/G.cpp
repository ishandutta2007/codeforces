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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, m, k, x[maxn], y[maxn];
char s[maxn], t[maxn];
int tmp1[25], tmp2[25];
int cnt[(1 << 20)], ans1[(1 << 20)], pos[(1 << 20)], ans2[(1 << 20)];
int rev[maxn];
int ans, l, r;
void work2(int dat, int x, int id)
{
	if(ans2[x] >= dat) return;
	ans2[x] = dat;
	pos[x] = id;
	for (int i = 0; i < k; i++)
	{
		if(!((x >> i) & 1)) work2(dat, (x ^ (1 << i)), id);
	}
}
void work1(int x, int id)
{
	if(ans1[x]) return;
	ans1[x] = 1;
	work2(cnt[x], x, id);
	for (int i = 0; i < k; i++)
	{
		if((x >> i) & 1) work1((x ^ (1 << i)), id);
	}
}
int main()
{
	scanf("%d%d%d%s%s", &n, &m, &k, s, t);
	int sum = 0;
	for (int i = 0; i < k; i++) sum += s[i] - '0';
	for (int i = 0; i < k; i++) sum += t[i] - '0';
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d%d", &x[i], &y[i]);
		x[i]--, y[i]--;
	}
	ans = 0, l = 1, r = n;
	for (int i = 0; i < (1 << k); i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for (int i = 0; i < k; i++) tmp2[i] = i;
	for (int i = 0; i < k; i++) tmp1[i] = i;
	for (int i = n; i >= n - m + 2; i--) swap(tmp1[x[i]], tmp1[y[i]]);
	for (int i = n - m + 1; i >= 1; i--)
	{ 
		int a = 0;
		for (int j = 0; j < k; j++) if(t[j] == '1') a ^= (1 << tmp2[j]);
//		printf("add: %d\n", a);
		work1(a, i + m - 1);
		swap(tmp2[x[i + m - 1]], tmp2[y[i + m - 1]]);
		swap(tmp1[x[i]], tmp1[y[i]]);
		a = 0;
		for (int j = 0; j < k; j++) if(s[j] == '1') a ^= (1 << tmp1[j]);
//		printf("que: %d  res: %d %d\n", a, ans2[a], pos[a]);
		if(ans2[a] > ans)
		{
			ans = ans2[a];
			l = i, r = pos[a];
		}
	}
	printf("%d\n%d %d", k - sum + 2 * ans, l, r);
	return 0;
}