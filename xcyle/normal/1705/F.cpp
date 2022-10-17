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
#define maxn 1005 
using namespace std;
inline int read()
{
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
mt19937 Rand(time(NULL));
int N, mask[maxn], res[maxn], que[maxn], A, B;
int query()
{
	ru(i, 1, N) printf("%c", (que[i] ^ mask[i]) ? 'F' : 'T'); printf("\n"); fflush(stdout);
	int x = read();
	if(x == N) exit(0);
	return x;
}
void solve(int n)
{
	if(n <= 1) return;
	ru(i, 1, N) que[i] = 0; que[n - 1] = que[n] = 1;
	int tmp = query() - A;
	if(tmp == 2) res[n - 1] = res[n] = 1, solve(n - 2);
	else if(tmp == -2) solve(n - 2);
	else
	{
		ru(i, 1, N) que[i] = i & 1; que[n - 2] ^= 1, que[n - 1] ^= 1, que[n] ^= 1;
		int tmp2 = query() - B;
		res[n - 2] = que[n - 2] ^ (tmp2 == 1 || tmp2 == -3);
		res[n - 1] = que[n - 1] ^ (tmp2 < 0);
		res[n] = que[n] ^ (tmp2 < 0);
		solve(n - 3);
	}
}
int main()
{
	N = read();
	ru(i, 1, N) mask[i] = Rand() & 1;
	A = query(); que[1] = 1; if(query() > A) res[1] = 1;
	ru(i, 1, N) que[i] = i & 1; B = query();
	solve(N);
	ru(i, 1, N) que[i] = res[i]; query();
	assert(0);
	return 0;
}