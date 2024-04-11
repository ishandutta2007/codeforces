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
#include <bitset>
#include <cmath>
#include <queue>
#include <ctime>
#include <map>
#include <set>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define maxn 1005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
bitset<1000005> fa[maxn], fb[maxn];
int T, n, m, a[maxn], b[maxn];
int tpa[maxn], tpb[maxn];
vector<int> lf, rt, up, dn;
void worka(int now, int sum)
{
	if(!now) return;
	if(sum >= a[now] && fa[now - 1][sum - a[now]])
	{
		rt.push_back(a[now]);
		worka(now - 1, sum - a[now]);
	}
	else
	{
		lf.push_back(a[now]);
		worka(now - 1, sum);
	}
}
void workb(int now, int sum)
{
	if(!now) return;
	if(sum >= b[now] && fb[now - 1][sum - b[now]])
	{
		up.push_back(b[now]);
		workb(now - 1, sum - b[now]);
	}
	else
	{
		dn.push_back(b[now]);
		workb(now - 1, sum);
	}
}
void solve()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++) fa[i].reset();
	fa[0][0] = 1;
	int suma = 0, sumb = 0;
	for (int i = 1; i <= n; i++)
	{
		suma += a[i];
		fa[i] = fa[i - 1] | (fa[i - 1] << a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
	sort(b + 1, b + m + 1);
	for (int i = 0; i <= m; i++) fb[i].reset();
	fb[0][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		sumb += b[i];
		fb[i] = fb[i - 1] | (fb[i - 1] << b[i]);
	}
	if((suma & 1) || (sumb & 1) || n != m || !fa[n][suma / 2] || !fb[m][sumb / 2])
	{
		printf("No\n");
		return;
	}
	lf.clear(), rt.clear(), up.clear(), dn.clear();
	worka(n, suma / 2);
	workb(n, sumb / 2);
	printf("Yes\n");
	for (int i = 0; i < lf.size(); i++) rt.push_back(-lf[i]);
	for (int i = 0; i < dn.size(); i++) up.push_back(-dn[i]);
	int nx = 0, ny = 0;
	for (int i = 0; i < n; i++)
	{
		printf("%d %d\n", nx, ny);
		nx += rt[i];
		printf("%d %d\n", nx, ny);
		ny += up[n - i - 1];
	}
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}