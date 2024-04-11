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
#define maxn 2005
#define pii pair<int, int>
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
int n, m, q;
bitset<maxn> st[maxn], pre[maxn], tmp;
set<pair<int, int> > t;
set<pair<int, int> >::iterator it;
set<pair<int, int> > pos;
void Del(int x, int y)
{
	tmp = st[x] ^ st[y];
	if((st[x] & tmp).any() && (st[y] & tmp).any()) pos.erase(mp(x, y));
}
void Add(int x, int y)
{
	tmp = st[x] ^ st[y];
	if((st[x] & tmp).any() && (st[y] & tmp).any()) pos.insert(mp(x, y));
}
void del(int id)
{
	it = t.find(mp(st[id].count(), id));
	it--; int L = (*it).se; it++;
	it++; int R = (*it).se; it--;
	Del(L, id), Del(id, R), Add(L, R);
	t.erase(it); 
}
void add(int id)
{
	it = t.insert(mp(st[id].count(), id)).fi;
	it--; int L = (*it).se; it++;
	it++; int R = (*it).se; it--;
	Add(L, id), Add(id, R), Del(L, R);
}
int main()
{
	n = read(), m = read(), q = read();
	ru(i, 1, m) ru(j, 1, i) pre[i][j] = 1;
	st[n + 1] = pre[m];
	ru(i, 0, n + 1) t.insert(mp(st[i].count(), i)); 
	ru(i, 1, q)
	{
		int id = read(), l = read(), r = read();
		del(id), st[id] ^= pre[l - 1] ^ pre[r], add(id);
		if(pos.empty()) printf("-1\n");
		else
		{
			int xl = (*pos.begin()).fi, xr = (*pos.begin()).se;
			tmp = st[xl] ^ st[xr];
			int yl = (st[xl] & tmp)._Find_first(), yr = (st[xr] & tmp)._Find_first();
			if(xl > xr) swap(xl, xr);
			if(yl > yr) swap(yl, yr);
			printf("%d %d %d %d\n", xl, yl, xr, yr);
		}
	}
	return 0;
}