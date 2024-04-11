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
#define maxn 505
#define maxm 250005
using namespace std;
const ll INF = 1e18;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
ll dis[maxn][maxn], dis2[maxn][maxn];
void solve() {
	int n = read(), m = read();
	ru(i, 1, n) ru(j, 1, n) dis[i][j] = dis2[i][j] = INF;
	ru(i, 1, n) dis2[i][i] = 0;
	ru(i, 1, m) {
		int x = read(), y = read(); ll z = read();
		dis[x][y] = min(dis[x][y], z);
		dis2[x][y] = 1;
		swap(x, y);
		dis[x][y] = min(dis[x][y], z);
		dis2[x][y] = 1;
	}
	ru(k, 1, n) {
		ru(i, 1, n) ru(j, 1, n) {
			dis2[i][j] = min(dis2[i][j], dis2[i][k] + dis2[k][j]);
		}
	}
	ll ans = INF;
	ru(i, 1, n) ru(j, 1, n) if(dis[i][j] < INF) {
		ans = min(ans, (dis2[1][i] + dis2[j][n] + 1) * dis[i][j]);
	}
	ru(i, 1, n) ru(j, 1, n) ru(k, 1, n) if(dis[i][j] < INF) {
		ans = min(ans, (dis2[1][k] + dis2[k][n] + dis2[k][i] + 2) * dis[i][j]);
	}
	printf("%lld\n", ans);
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}