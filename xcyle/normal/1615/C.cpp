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
int n;
char a[maxn], b[maxn];
void solve()
{
	scanf("%d%s%s", &n, a + 1, b + 1);
	int cnt = 0, vis[2][2] = {0, 0, 0, 0}, num[2][2] = {0, 0, 0, 0};
	for (int i = 1; i <= n; i++)
	{
		if(a[i] != b[i])
		{
			cnt++;
		}
		vis[a[i] - '0'][b[i] - '0'] = 1;
		num[0][a[i] - '0']++, num[1][b[i] - '0']++;
	}
	if(cnt == 0)
	{
		printf("0\n");
		return;
	}
	int ans = 5 * n;
	if(cnt % 2 == 0 && num[0][0] == num[1][0])
	{
		if(vis[1][0] && vis[0][1]) ans = min(ans, cnt);
		if(cnt <= 1 && vis[1][0]) ans = min(ans, cnt);
	}
	if((n - cnt) & 1 && num[0][1] - 1 == num[1][0])
	{
		if(vis[1][1] && vis[0][0]) ans = min(ans, n - cnt);
		if(n - cnt <= 1 && vis[1][1]) ans = min(ans, n - cnt);
	}
	if(ans == 5 * n) printf("-1\n");
	else printf("%d\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve(); 
	return 0;
}