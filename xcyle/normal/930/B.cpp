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
#define maxn 5005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
char s[maxn];
char t[maxn][maxn];
int vis[maxn];
int cnt[26];
vector<int> buc[26];
int main()
{
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++) buc[s[i] - 'a'].push_back(i);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			t[i][j] = s[(i + j - 2) % n + 1];
		}
	}
	double ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int mx = 0;
		for (int j = 1; j <= n; j++)
		{
			int num = 0;
			for (auto pos: buc[i]) cnt[t[pos][j] - 'a']++;
			for (auto pos: buc[i]) if(cnt[t[pos][j] - 'a'] == 1) num++;
			for (auto pos: buc[i]) cnt[t[pos][j] - 'a']--;
			mx = max(mx, num);
		}
		ans += mx;
	}
	printf("%.9f\n", ans / n);
	return 0;
}