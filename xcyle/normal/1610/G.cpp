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
#define maxn 300005
using namespace std;
const int bas1 = 100097, mod1 = 998244353;
const int bas2 = 4132093, mod2 = 489713261;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[maxn], hoho[2] = {')', '('};
int n, sum[maxn], sta[maxn], len[maxn], top;
int pow1[maxn], pow2[maxn];
struct node
{
	int hash1, hash2;
	inline bool friend operator == (node aa, node bb)
	{
		return aa.hash1 == bb.hash1 && aa.hash2 == bb.hash2;
	}
	inline node friend operator + (node aa, node bb)
	{
		return (node){(aa.hash1 + bb.hash1) % mod1, (aa.hash2 + bb.hash2) % mod2};
	}
	inline node friend operator - (node aa, node bb)
	{
		return (node){(aa.hash1 + mod1 - bb.hash1) % mod1, (aa.hash2 + mod2 - bb.hash2) % mod2};
	}
}p[maxn];
inline node mul(node y, int x)
{
	return (node){(ll)y.hash1 * pow1[x] % mod1, (ll)y.hash2 * pow2[x] % mod2};
}
int fa[maxn][25], dep[maxn], tot, pos[maxn];
char lk[maxn];
int cre(int x, char t)
{
	lk[++tot] = t;
	dep[tot] = dep[x] + 1, fa[tot][0] = x, p[tot] = (node){t - '0', t - '0'} + mul(p[x], 1);
	for (int i = 1; i <= 20; i++) fa[tot][i] = fa[fa[tot][i - 1]][i - 1];
	return tot;
}
int check(int x, int y)
{
	for (int i = 20; i >= 0; i--)
	{
		if(dep[x] < (1 << i) || dep[y] < (1 << i)) continue;
		if(p[x] - mul(p[fa[x][i]], (1 << i)) == p[y] - mul(p[fa[y][i]], (1 << i)))
		{
			x = fa[x][i];
			y = fa[y][i];
		}
	}
	if(x == 0) return 1;
	if(y == 0) return 0;
	return lk[x] - '0' > lk[y] - '0';
}
int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		pow1[i] = (ll)pow1[i - 1] * bas1 % mod1;
		pow2[i] = (ll)pow2[i - 1] * bas2 % mod2; 
	}
	for (int i = 1; i <= n; i++) s[i] = (s[i] == '(' ? '1' : '0');
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + (s[i] - '0') * 2 - 1;
	sum[n + 1] = - n - 1, sta[top = 1] = n + 1;
	sta[top = 2] = n;
	for (int i = n - 1; i >= 0; i--)
	{
		while(sum[sta[top]] > sum[i]) top--;
		pos[i] = cre(pos[i + 1], s[i + 1]);
		if(sum[sta[top]] == sum[i] && check(pos[sta[top]], pos[i])) pos[i] = pos[sta[top]];
		sta[++top] = i;
//		printf("%d\n", pos[i]);
//		for (int now = pos[i]; now; now = fa[now][0]) printf("%c", hoho[lk[now] - '0']);
//		printf("\n");
	}
	for (int now = pos[0]; now; now = fa[now][0]) printf("%c", hoho[lk[now] - '0']);
	return 0;
}