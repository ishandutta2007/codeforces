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
#define ull unsigned long long
#define maxn 500005
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, m, fa[maxn], uu[maxn], vv[maxn], ww[maxn];
struct edge
{
	int u, v, w, id;
	inline bool operator < (const edge &a) const {return w < a.w;}
}p[maxn];
inline int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}
vector<int> pos;
int main()
{
	n = read(), m = read();
	ru(i, 1, m) uu[i] = read(), vv[i] = read(), ww[i] = read(), p[i] = {uu[i], vv[i], ww[i], i};
	sort(p + 1, p + m + 1);
	ru(i, 1, n) fa[i] = i;
	ru(i, 1, m)
	{
		int j = i + 1;
		while(j <= m && p[j].w == p[i].w) j++;
		ru(k, i, j - 1) uu[p[k].id] = p[k].u = find(p[k].u), vv[p[k].id] = p[k].v = find(p[k].v);
		ru(k, i, j - 1)
		{
			int fu = find(p[k].u), fv = find(p[k].v);
			if(fu != fv) fa[fu] = fv;
		}
		i = j - 1;
	}
	ru(i, 1, n) fa[i] = i;
	int q = read();
	while(q--)
	{
		int cnt = read();
		pos.clear();
		while(cnt--) pos.push_back(read()); int fl = 0;
		sort(pos.begin(), pos.end(), [](int x, int y) {return ww[x] < ww[y];});
//		ru(i, 1, n) printf("%d ", fa[i]); printf("\n");
		for (int i = 0; i < pos.size(); i++)
		{
			int j = i;
			while(j < pos.size() && ww[pos[j]] == ww[pos[i]])
			{
				int x = find(uu[pos[j]]), y = find(vv[pos[j]]);
				if(x == y) fl = 1;
				else fa[x] = y;
				j++;
			}
			ru(k, i, j - 1) fa[uu[pos[k]]] = uu[pos[k]], fa[vv[pos[k]]] = vv[pos[k]];//, printf("%d %d\n", uu[pos[k]], vv[pos[k]]); printf("\n");
			i = j - 1;
		}
		if(fl) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}