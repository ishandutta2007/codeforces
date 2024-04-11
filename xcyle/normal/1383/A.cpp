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
int T, n, fa[30], ans;
char a[maxn], b[maxn];
inline int find(int x)
{
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}
void solve()
{
	scanf("%d%s%s", &n, a + 1, b + 1);
	for (int i = 0; i < 30; i++) fa[i] = i;
	ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int A = a[i] - 'a', B = b[i] - 'a';
		if(A > B)
		{
			printf("-1\n");
			return;
		}
		int fA = find(A), fB = find(B);
		if(fA != fB)
		{
			fa[fB] = fA;
			ans++;
		}
	}
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}