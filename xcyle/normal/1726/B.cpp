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
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int a[100005];
void solve() {
	int n = read(), m = read();
	if(((m & 1) && (n % 2 == 0)) || n > m) {
		printf("No\n");
		return;
	}
	if(n % 2 == 0) {
		printf("Yes\n");
		ru(i, 1, n - 2) printf("1 ");
		m -= (n - 2);
		printf("%d %d\n", m / 2, m / 2);
	}
	else {
		printf("Yes\n");
		ru(i, 1, n - 1) printf("1 ");
		printf("%d\n", m - n + 1);
	}
}
int main() {
	int T = read();
	while(T--) solve(); 
	return 0;
}