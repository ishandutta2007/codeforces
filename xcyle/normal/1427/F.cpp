/*

_/      _/       _/_/_/      _/      _/    _/           _/_/_/_/_/
 _/    _/      _/      _/     _/    _/     _/           _/
  _/  _/      _/               _/  _/      _/           _/
   _/_/       _/                 _/        _/           _/_/_/_/
  _/  _/      _/                 _/        _/           _/
 _/    _/      _/      _/        _/        _/           _/
_/      _/       _/_/_/          _/        _/_/_/_/_/   _/_/_/_/_/

*/
#include <bits/stdc++.h>
#define ll long long
#define lc(x) ((x) << 1)
#define rc(x) ((x) << 1 | 1)
#define ru(i, l, r) for (int i = (l); i <= (r); i++)
#define rd(i, r, l) for (int i = (r); i >= (l); i--)
#define mid ((l + r) >> 1)
#define maxn 1205
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, vis[maxn], fa[maxn], ok[maxn];
int pos[maxn][3], tot, sta[maxn], top;
vector<int> son[maxn], tmpson[maxn];
queue<int> q[2];
int main()
{
	n = read();
	ru(i, 1, 3 * n) vis[read()] = 1;
	ru(i, 1, 6 * n)
	{
		sta[++top] = i;
		while(top >= 3 && vis[sta[top]] == vis[sta[top - 1]] && vis[sta[top]] == vis[sta[top - 2]])
		{
			tot++;
			rd(j, 2, 0) 
			{
				for (auto x: tmpson[sta[top]]) son[tot].push_back(x), fa[x] = tot;
				pos[tot][j] = sta[top--];
			}
			tmpson[sta[top]].push_back(tot); 
		}
	}
	int rem = 0, LAST;
	for (auto x: tmpson[0]) rem += (!vis[pos[x][0]]);
	ru(i, 1, 2 * n) if(son[i].empty()) q[vis[pos[i][0]]].push(i);
	ru(i, 1, n)
	{
		int x = q[1].front(); q[1].pop(); ok[x] = 1;
		printf("%d %d %d\n", pos[x][0], pos[x][1], pos[x][2]);
		if(fa[x])
		{
			son[fa[x]].pop_back();
			if(son[fa[x]].empty()) q[0].push(fa[x]);
		}
		if(i == n)
		{
			ru(j, 1, 2 * n) if(!ok[j]) x = j;
		}
		else
		{
			x = q[0].front(); q[0].pop();
			if(!fa[x]) 
			{
				if(rem > 1) rem--;
				else x = q[0].front(), q[0].pop();
			}
		}
		ok[x] = 1;
		printf("%d %d %d\n", pos[x][0], pos[x][1], pos[x][2]);
		if(fa[x])
		{
			son[fa[x]].pop_back();
			if(son[fa[x]].empty()) q[1].push(fa[x]);
		}
	}
	return 0;
}