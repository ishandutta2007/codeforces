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
#define maxn 200005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int f[maxn], tot;
int sta[maxn], top, sum[maxn];
int work(int d, int pos)
{
	if(pos & 1) return d;
	else return (mo - d) % mo;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	f[0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		int tmp = 0;
		while(top && a[sta[top]] >= a[i])
		{
			tmp = (tmp + sum[top]) % mo;
			tot = (tot + mo - (ll)sum[top] * a[sta[top]] % mo) % mo;
			top--;
		}
		sta[++top] = i;
		int hoho = work(f[i - 1], i - 1);
		sum[top] = (tmp + hoho) % mo;
		tot = (tot + (ll)sum[top] * a[i] % mo) % mo;
		f[i] = work(tot, i - 1);
	}
	printf("%d\n", f[n]);
	return 0;
}