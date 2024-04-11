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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, q, mo, a[maxn], b[maxn], F[maxn];
int cnt = 0;
void work(int pos, int val)
{
	if(pos > n) return;
	if(a[pos] != 0) cnt--;
	val = (val % mo + mo) % mo;
	a[pos] = (a[pos] + val) % mo;
	if(a[pos] != 0) cnt++;	
}
int main()
{
	scanf("%d%d%d", &n, &q, &mo);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
	for (int i = 1; i <= n; i++) a[i] = (a[i] - b[i] + mo) % mo;
	for (int i = n; i >= 2; i--) a[i] = (((a[i] - a[i - 1] - a[i - 2]) % mo) + mo) % mo;
	for (int i = 1; i <= n; i++) if(a[i] != 0) cnt++;
	F[1] = F[2] = 1;
	for (int i = 3; i <= n; i++) F[i] = (F[i - 1] + F[i - 2]) % mo;
	for (int i = 1; i <= q; i++)
	{
		char s[2];
		int l, r;
		scanf("%s%d%d", s, &l, &r);
		if(s[0] == 'A') 
		{
			work(l, 1);
			work(r + 1, -F[r - l] - F[r - l + 1]);
			work(r + 2, -F[r - l + 1]);
		}
		else
		{
			work(l, -1);
			work(r + 1, +F[r - l] + F[r - l + 1]);
			work(r + 2, +F[r - l + 1]);
		}
		if(cnt == 0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}