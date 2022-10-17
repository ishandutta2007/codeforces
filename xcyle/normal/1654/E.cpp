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
#include <unordered_map>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 200005
#define B 320
using namespace std;
const int tmp = 100002;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int p[maxn * B * 2];
int cnt[maxn];
void solve()
{
	n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	int ans = 1;
	for (int d = -B; d <= B; d++)
	{
		for (int i = 1; i <= n; i++) p[maxn * B + a[i] - d * i]++;
		for (int i = 1; i <= n; i++) ans = max(ans, p[maxn * B + a[i] - d * i]), p[maxn * B + a[i] - d * i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n && j <= i + B; j++)
		{
			if((a[j] - a[i]) % (j - i) != 0) continue;
			cnt[tmp + (a[j] - a[i]) / (j - i)]++;
		}
		for (int j = i + 1; j <= n && j <= i + B; j++)
		{
			if((a[j] - a[i]) % (j - i) != 0) continue;
			int d = (a[j] - a[i]) / (j - i) + tmp;
			ans = max(ans, cnt[d] + 1), cnt[d] = 0;
		}
	}
	printf("%d\n", n - ans);
}
int main()
{
	solve();
	return 0;
}