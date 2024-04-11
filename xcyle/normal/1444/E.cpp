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
#define maxn 105
#define mask bitset<maxn>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, col[maxn], vis[maxn], F[maxn];
vector<int> G[maxn];
mask f[maxn];
int check(mask t, vector<pair<mask, int> > s)
{
	rd(i, n - 1, 0)
	{
		int cnt = 0; for (auto V: s) cnt += V.fi[i];
		if(cnt > 1 || (cnt == 1 && !t[i])) return 0;
		if(cnt == 0 && t[i])
		{
			int mx = 0;
			ru(j, 0, s.size() - 1)
			{
				rd(k, i - 1, 0) if(s[mx].fi[k] ^ s[j].fi[k])
				{
					if(s[mx].fi[k] < s[j].fi[k]) mx = j;
					break;
				}
			}
			col[s[mx].se] = i;
			swap(s[mx], s[s.size() - 1]), s.pop_back();
		}
		if(!s.size()) return 1;
	}
	return 0;
}
void dfs(int x, int fa)
{
	F[x] = fa;
	vector<pair<mask, int> > tmp;
	for (auto V: G[x]) if(V ^ fa) dfs(V, x), tmp.push_back(mp(f[V], V));
	ru(i, 0, n - 1) f[x][i] = 1; 
	rd(i, n - 1, 0) f[x][i] = 0, (!check(f[x], tmp)) && (f[x][i] = 1);
//	printf("%d   ", x);
//	ru(i, 0, n - 1) printf("%d ", (int)f[x][i]); printf("\n");
	check(f[x], tmp);
}
int find(int x, int fa)
{
	int res = x * (!vis[F[x]]);
	for (auto V: G[x]) if(V != fa && !vis[V])
	{
		int t = find(V, x);
		if(col[t] > col[res]) res = t;
	}
	return res;
}
void work(int x)
{
	int fl = 1;
	for (auto V: G[x]) fl &= vis[V];
	if(fl) {printf("! %d\n", x); fflush(stdout); exit(0);}
	int V = find(x, x);
	printf("? %d %d\n", F[V], V); fflush(stdout);
	int nxt = read(); vis[F[V] ^ V ^ nxt] = 1;
	work(nxt);
}
int main()
{
	n = read();
	ru(i, 1, n - 1)
	{
		int x = read(), y = read();
		G[x].push_back(y), G[y].push_back(x);
	}
	vis[0] = 1, col[0] = -1, dfs(1, 0);
//	ru(i, 2, n) printf("%d ", col[i]);
	work(1);
	return 0;
}