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
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
int vis[30];
void solve()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 0; i < 30; i++) vis[i] = 0;
	int ans = n;
	for (int i = n; i >= 1; i--)
	{
		if(!vis[s[i] - 'a']) ans = i - 1;
		vis[s[i] - 'a'] = 1;
	}
	for (int i = ans + 1; i <= n; i++) printf("%c", s[i]);
	printf("\n"); 
}
int main()
{
	int T = read();
	while(T--) solve();
	return 0;
}