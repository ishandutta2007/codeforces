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
#define db double
#define rc(x) ((x) << 1 | 1)
#define maxn 100005
using namespace std;
const int mo = 1e9 + 7;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(ch < '0' || ch > '9'){w |= ch == '-';ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int T, n, m, k;
int vis[2][26][26], vis2[26][26][26];
char s[maxn][4];
void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < 26; i++) for (int j = 0; j < 26; j++) vis[0][i][j] = vis[1][i][j] = 0;
	int fl = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		int len = strlen(s[i] + 1);
		if(len == 1)
		{
			fl = 1;
			continue;
		}
		if(len == 2 && s[i][1] == s[i][2]) fl = 1;
		if(len == 3 && s[i][1] == s[i][3]) fl = 1;
		vis[3 - len][s[i][1] - 'a'][s[i][2] - 'a'] = 1;
		if(vis[len - 2][s[i][len] - 'a'][s[i][len - 1] - 'a']) fl = 1;
		if(len == 2 && vis[1][s[i][len] - 'a'][s[i][len - 1] - 'a']) fl = 1;
		if(len == 3)
		{
			vis2[s[i][1] - 'a'][s[i][2] - 'a'][s[i][3] - 'a'] = 1;
			if(vis2[s[i][3] - 'a'][s[i][2] - 'a'][s[i][1] - 'a']) fl = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int len = strlen(s[i] + 1);
		if(len == 3)
		{
			vis2[s[i][1] - 'a'][s[i][2] - 'a'][s[i][3] - 'a'] = 0;
		}
	}
	if(fl)
	{
		printf("YES\n");
		return;
	}
	printf("NO\n");
}
int main()
{
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}