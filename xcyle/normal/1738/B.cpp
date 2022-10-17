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
#define maxn 200005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k, s[maxn], a[maxn];
void solve() {
	n = read(), k = read();
	ru(i, n - k + 1, n) s[i] = read();
	if(k == 1) {printf("YES\n"); return;}
	ru(i, n - k + 2, n) a[i] = s[i] - s[i - 1];
	ru(i, n - k + 3, n) {
		if(a[i] < a[i - 1]) {
			printf("NO\n");
			return;
		}
	}
	if((ll)a[n - k + 2] * (n - k + 1) < s[n - k + 1]) printf("NO\n");
	else printf("YES\n");
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}