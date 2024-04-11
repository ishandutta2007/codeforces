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
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define maxn 305
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
ll f[maxn][maxn];
void solve() {
	ll t; int x, y;
	scanf("%lld%d%d", &t, &x, &y);
	if(x + y > t) {puts("NO"); return;}
	ru(i, 0, x) ru(j, 0, y) {
		if(i == 0 && j == 0) f[i][j] = t - x - y;
		else {
			f[i][j] = 0;
			if(i) f[i][j] += f[i - 1][j] / 2;
			if(j) f[i][j] += (f[i][j - 1] + 1) / 2;
		}
	}
	int nx = 0, ny = 0;
	ru(i, 1, x + y) {
		if(f[nx][ny] & 1) nx++;
		else ny++;
	}
	if(nx == x && ny == y) puts("YES");
	else puts("NO");
}
int main() {
	int q = read();
	while(q--) solve();
	return 0;
}