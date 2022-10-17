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
const int mo = 998244353;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, d[maxn], fa[maxn], rk[maxn], id[maxn];
int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);	
}
void solve() {
	n = read();
	ru(i, 1, n) d[i] = read(), id[i] = fa[i] = i;
	sort(id + 1, id + n + 1, [](int x, int y) {return d[x] > d[y];});
	ru(i, 1, n) rk[id[i]] = i;
	ru(i, 1, n) if(find(id[i]) == id[i]) {
		ru(j, 1, d[id[i]]) {
			printf("? %d\n", id[i]); fflush(stdout);
			int x = read();
			if(rk[find(x)] < i) {
				fa[id[i]] = x;
				break;
			}
			else fa[x] = id[i];
		}
	}
	printf("! ");
	ru(i, 1, n) printf("%d ", find(i)); printf("\n"); fflush(stdout);
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}