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
#define mid ((l + r + 1) >> 1)
#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int buc[2][2];
void solve() {
	int n = read();
	int a[2][4];
	ru(i, 0, 3) ru(j, 0, 1) a[j][i] = read();
	ru(i, 0, 3) buc[a[0][i] & 1][a[1][i] & 1] = 1;
	int fl = 1;
	ru(i, 0, 1) ru(j, 0, 1) fl &= buc[i][j], buc[i][j] = 0;
	sort(a[0], a[0] + 3);
	sort(a[1], a[1] + 3);
	int x = a[0][1], y = a[1][1];
//	printf("!! %d %d\n", x, y);
	if((x == 1 || x == n) && (y == 1 || y == n)) fl = (a[0][3] != x && a[1][3] != y);
	if(fl) printf("NO\n");
	else printf("YES\n");
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}