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
int n;
char s[maxn], t[maxn];
int ch[2][maxn][26], siz[2][maxn], tot[2], fail[2][maxn];
void insert()
{
	int len = strlen(s + 1), now = 0;
	for (int i = 1; i <= len; i++)
	{
		int k = s[i] - 'a';
		if(!ch[0][now][k]) ch[0][now][k] = ++tot[0];
		now = ch[0][now][k];
	}
	siz[0][now]++;
	now = 0;
	for (int i = len; i >= 1; i--)
	{
		int k = s[i] - 'a';
		if(!ch[1][now][k]) ch[1][now][k] = ++tot[1];
		now = ch[1][now][k];
	}
	siz[1][now]++;
}
queue<int> q;
vector<int> G[2][maxn];
void getfail(int id)
{
	for (int i = 0; i < 26; i++) if(ch[id][0][i]) q.push(ch[id][0][i]);
	while(!q.empty())
	{
		int x = q.front(); q.pop();
		siz[id][x] += siz[id][fail[id][x]];
		for (int i = 0; i < 26; i++)
		{
			if(!ch[id][x][i]) ch[id][x][i] = ch[id][fail[id][x]][i];
			else fail[id][ch[id][x][i]] = ch[id][fail[id][x]][i], q.push(ch[id][x][i]);
		}
	}
}
ll num[2][maxn];
inline void calc()
{
	int len = strlen(t + 1);
	ll ans = 0; int now = 0;
	for (int i = 1; i <= len; i++)
	{
		now = ch[0][now][t[i] - 'a'];
		num[0][i] = siz[0][now];
	}
	now = 0;
	for (int i = len; i >= 1; i--)
	{
		now = ch[1][now][t[i] - 'a'];
		num[1][i] = siz[1][now];
	}
	for (int i = 1; i <= len; i++) ans += num[0][i] * num[1][i + 1];
	printf("%lld\n", ans);
}
int main()
{
	scanf("%s", t + 1);
	n = read();
	while(n--){scanf("%s", s + 1);insert();}
	getfail(0), getfail(1);
	calc();
	return 0;
}