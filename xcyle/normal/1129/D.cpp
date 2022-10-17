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
#define B 320
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, k, a[maxn], f[maxn], val[maxn], tag[B + 5];
int las[maxn][2], sum[B + 5][maxn];//ij\sum f
inline void change(int pos, int x)
{
	if(x == 1) sum[pos / B][val[pos] + 1] = (sum[pos / B][val[pos] + 1] + f[pos]) % mo;
	else sum[pos / B][val[pos]] = (sum[pos / B][val[pos]] + mo - f[pos]) % mo;
	val[pos] += x;
}
inline void modify(int l, int r, int x)
{
	if(l > r) return;
	if(l / B == r / B)
	{
		for (int i = l; i <= r; i++) change(i, x);
	}
	else
	{
		for (int i = l; i < (l / B + 1) * B; i++) change(i, x);
		for (int i = (r / B) * B; i <= r; i++) change(i, x);
		for (int i = l / B + 1; i < r / B; i++) tag[i] += x; 
	}
}
int main()
{
	n = read(), k = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	f[0] = sum[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		modify(las[a[i]][0], las[a[i]][1] - 1, -1), modify(las[a[i]][1], i - 1, 1);
		las[a[i]][0] = las[a[i]][1], las[a[i]][1] = i;
		for (int j = 0; (j + 1) * B - 1 < i; j++)
		{
			if(tag[j] <= k) f[i] = (f[i] + (sum[j][0] + mo - sum[j][k - tag[j] + 1]) % mo) % mo;
		}
		for (int j = (i / B) * B; j < i; j++) if(val[j] + tag[j / B] <= k) f[i] = (f[i] + f[j]) % mo;
		sum[i / B][0] = (sum[i / B][0] + f[i]) % mo;
	}
	printf("%d\n", f[n]);
	return 0;
}