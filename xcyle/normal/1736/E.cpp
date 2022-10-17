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
#define maxn 505
using namespace std;
const int INF = 0x3f3f3f3f;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, a[maxn];
int f[maxn][maxn][maxn], sum[maxn][maxn];
int main() {
	n = read();
	ru(i, 1, n) a[i] = read();
	ru(i, 0, maxn - 1) ru(j, 0, maxn - 1) ru(k, 0, maxn - 1) f[i][j][k] = -INF;
	f[0][0][0] = 0;
	ru(i, 1, n) {
		ru(k, 0, n) {
			sum[0][k] = f[i - 1][0][k];
			ru(j, 1, n) sum[j][k] = max(sum[j - 1][k], f[i - 1][j][k]);
		}
		ru(j, 1, n) {
			ru(k, 0, i) {
				if(k) f[i][j][k] = f[i - 1][j][k - 1] + a[j];
				if(j >= i && k - (j - i) >= 0) {
					f[i][j][k] = max(f[i][j][k], sum[j - 1][k - (j - i)] + a[j]);
				}
//				ru(lasj, 0, j - 1) if(j >= i && k - (j - i) >= 0) {
////					if(i == 1 && j == 1 && k == 0 && lasj == 0) 
//					f[i][j][k] = max(f[i][j][k], f[i - 1][lasj][k - (j - i)] + a[j]);
//				}
			}
		} 
	}
//	printf("%d %d\n", f[1][1][0], f[2][1][0]);
	int ans = 0;
	ru(i, 1, n) ru(j, 0, n) ans = max(ans, f[n][i][j]);
	printf("%d\n", ans);
	return 0;
}