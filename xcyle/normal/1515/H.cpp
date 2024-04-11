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
#define maxn 200005
#define N 10000005
#define M ((1 << 20) - 1)
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, q, rt, tmp, tot, ch[N][2], isl[N], isr[N], tag[N], cnt[N];
inline void pushup(int x)
{
	isl[x] = isl[ch[x][0]] | isl[ch[x][1]];
	isr[x] = isr[ch[x][0]] | isr[ch[x][1]];
	cnt[x] = cnt[ch[x][0]] + cnt[ch[x][1]];
}
void workxor(int x, int dep, int v)
{
	if(!x) return;
	if(dep >= 0 && ((v >> dep) & 1)) swap(ch[x][0], ch[x][1]);
	int L = isl[x], R = isr[x];
	isl[x] = (L & (v ^ M)) | (R & v);
	isr[x] = (L & v) | (R & (v ^ M));
	tag[x] ^= v;
}
inline void pushdown(int x, int dep)
{
	if(!tag[x]) return;
	workxor(ch[x][0], dep - 1, tag[x]);
	workxor(ch[x][1], dep - 1, tag[x]);
	tag[x] = 0;
}
void dfs(int x, int dep)
{
	if(!x) return;
	if(dep < 0) {printf("%d\n", isr[x]); return;}
	pushdown(x, dep);
	dfs(ch[x][0], dep - 1), dfs(ch[x][1], dep - 1);
}
int merge(int x, int y, int dep)
{
//	printf("merge: %d %d\n", x, y);
	if(!x || !y) return x + y;
	if(dep < 0) return x;
	pushdown(x, dep), pushdown(y, dep);
	ch[x][0] = merge(ch[x][0], ch[y][0], dep - 1);
	ch[x][1] = merge(ch[x][1], ch[y][1], dep - 1);
	pushup(x);
//	dfs(x, dep);
	return x;
}
void workor(int x, int dep, int v)
{
	if(dep < 0 || !x) return;
	if(!(v & isl[x] & isr[x]))
	{
		workxor(x, dep, v & isl[x]);
		return;
	}
	pushdown(x, dep);
	if((v >> dep) & 1) workxor(ch[x][0], dep - 1, (1 << dep)), ch[x][1] = merge(ch[x][1], ch[x][0], dep - 1), ch[x][0] = 0;
	workor(ch[x][0], dep - 1, v), workor(ch[x][1], dep - 1, v);
	pushup(x);
}
inline void ins(int &x, int dep, int v)
{
	if(!x) x = ++tot;
	if(dep < 0) {cnt[x] = 1, isl[x] = v ^ M, isr[x] = v; return;}
	ins(ch[x][(v >> dep) & 1], dep - 1, v);
	pushup(x);
}
void split(int &x, int &y, int l, int r, int dep, int a, int b)
{
	if(!x) {y = 0; return;}
	if(a <= l && r <= b) {int tmp = x; y = tmp, x = 0; return;}
	pushdown(x, dep);
	y = ++tot;
	if(a <= mid) split(ch[x][0], ch[y][0], l, mid, dep - 1, a, b);
	if(b > mid) split(ch[x][1], ch[y][1], mid + 1, r, dep - 1, a, b);
	pushup(x), pushup(y);
}
int main()
{
	n = read(), q = read();
	ru(i, 1, n) {int x = read(); ins(rt, 19, x);}
	while(q--)
	{
		int tp = read(), l = read(), r = read();
		split(rt, tmp, 0, (1 << 20) - 1, 19, l, r);
//		printf("beg:\n"), dfs(tmp, 19), printf("end:\n");
		if(tp == 4) printf("%d\n", cnt[tmp]);
		else 
		{
			int x = read();
			if(tp == 1) workxor(tmp, 19, M), workor(tmp, 19, x ^ M), workxor(tmp, 19, M);
			if(tp == 2) workor(tmp, 19, x);
			if(tp == 3) workxor(tmp, 19, x);
		}
		rt = merge(rt, tmp, 19), tmp = 0;
//		printf("!\n");dfs(rt, 19);
	}
	return 0;
}