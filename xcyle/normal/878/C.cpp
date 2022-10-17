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
#define maxn 50005
#define maxk 12
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
struct node
{
	int l[maxk], r[maxk], siz;
	inline bool operator < (const node &a) const
	{
		ru(i, 1, k) if(r[i] > a.l[i]) return 0;
		return 1;
	}
}tmp;
set<node> t; 
int main()
{
	n = read(), k = read();
	ru(i, 1, n)
	{
		ru(j, 1, k) tmp.l[j] = tmp.r[j] = read(); tmp.siz = 1;
		while(1)
		{
			if(t.find(tmp) == t.end()) {t.insert(tmp); break;}
			set<node>::iterator it = t.find(tmp); 
			tmp.siz += (*it).siz;
			ru(j, 1, k) tmp.l[j] = min(tmp.l[j], (*it).l[j]), tmp.r[j] = max(tmp.r[j], (*it).r[j]);
			t.erase(it);
		}
		printf("%d\n", (*--t.end()).siz);
	}
	return 0;
}