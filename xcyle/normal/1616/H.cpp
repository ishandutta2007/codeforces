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
#define maxn 150005
using namespace std;
const int mo = 998244353;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)){w |= ch == '-';ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + ch - '0';ch = getchar();}
	return w ? -x : x;
}
int n, x, tot = 1, siz[maxn * 35], ch[maxn * 35][2], pw[maxn];
int f[maxn * 35], vis[maxn * 35];
void insert(int t)
{
	int now = 1;
	for (int i = 30; i >= 0; i--)
	{
		int k = ((t >> i) & 1);
		if(!ch[now][k]) ch[now][k] = ++tot;
		now = ch[now][k];
		siz[now]++;
//		printf("%d ", now);
//		printf("\n");
	}
}
void dfs(int a, int b, int dep)
{
	if(vis[a] || vis[b]) return;
	vis[a] = vis[b] = 1;
	int p = 0;
	if(!a || !b) {p = 0; return;}
	if(dep == -1) {if(a == b) f[a] = f[b] = (pw[siz[a]] + mo - 1) % mo; else f[a] = f[b] = (ll)(pw[siz[a]] + mo - 1) * (pw[siz[b]] + mo - 1) % mo; return;}
	if((x >> dep) & 1)
	{
		dfs(ch[a][0], ch[b][1], dep - 1), dfs(ch[a][1], ch[b][0], dep - 1);
		if(a == b)
		{
			p = (f[ch[a][0]] + ((pw[siz[ch[a][0]]] + pw[siz[ch[a][1]]]) % mo + mo - 2) % mo) % mo;
		}
		else
		{
		p = (p + (ll)f[ch[a][0]] * ((pw[siz[ch[b][0]]] + pw[siz[ch[a][1]]]) % mo + mo - 1) % mo) % mo;
		p = (p + (ll)f[ch[a][1]] * ((pw[siz[ch[b][1]]] + pw[siz[ch[a][0]]]) % mo + mo - 1) % mo) % mo;
		p = (p + (ll)(pw[siz[ch[a][0]]] + mo - 1) * (pw[siz[ch[b][0]]] + mo - 1) % mo) % mo;
		p = (p + (ll)(pw[siz[ch[a][1]]] + mo - 1) * (pw[siz[ch[b][1]]] + mo - 1) % mo) % mo;
		p = (p + (ll)f[ch[a][0]] * f[ch[a][1]] % mo) % mo;
		}
	}
	else
	{
		dfs(ch[a][0], ch[b][0], dep - 1);
		p = (p + f[ch[a][0]]) % mo;
		dfs(ch[a][1], ch[b][1], dep - 1);
		p = (p + f[ch[a][1]]) % mo;
	}
	f[a] = f[b] = p;
}
int main()
{
	n = read(), x = read();
	vis[0] = 1, pw[0] = 1;
	for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mo;
	for (int i = 1; i <= n; i++) 
	{
		int y = read();
		insert(y);
	}
	dfs(1, 1, 30);
	printf("%d\n", f[1]);
	return 0;
}