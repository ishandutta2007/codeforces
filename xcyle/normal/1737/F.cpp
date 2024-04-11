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
#define maxn 20
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int m, b[maxn];
int ans[1 << 21][maxn];
void solve() {
	m = read();
	vector<int> sp;
	ru(i, 1, m) {
		b[i] = read();
		if(b[i] > 1) sp.push_back(i);
	}
	if(sp.size() > 2) {
		printf("-1\n");
		return;
	}
	if(sp.size() == 2 && max(b[sp[0]], b[sp[1]]) > 2) {
		printf("-1\n");
		return;
	}
	if(sp.size() == 1 && b[sp[0]] > 3) {
		printf("-1\n");
		return;
	}
	int now;
	if(sp.size() == 1 && b[sp[0]] == 3) {
		ans[0][sp[0]] = 0;
		ans[1][sp[0]] = 3;
		ans[2][sp[0]] = 1;
		ans[3][sp[0]] = 2;
		now = 4;
		ru(i, 1, m) if(b[i] == 1) {
			ru(j, 0, now - 1) {
				ru(k, 1, m) ans[j + now][k] = ans[j][k];
				ans[j][i] = j & 1;
				ans[j + now][i] = 1 - (j & 1);
				if(j & 1) ans[j][i] = 1;
				else ans[j + now][i] = 1;
			}
			ru(j, 1, m) swap(ans[now / 2][j], ans[now][j]);
			now *= 2;
		}
	}
	else {
		if(sp.size() == 0) {
			now = 1;
		}
		if(sp.size() == 1) {
			now = 3;
			ans[0][sp[0]] = 0;
			ans[1][sp[0]] = 2;
			ans[2][sp[0]] = 1;
		}
		if(sp.size() == 2) {
			now = 9;
			ans[0][sp[0]] = 0, ans[0][sp[1]] = 0;
			ans[1][sp[0]] = 1, ans[1][sp[1]] = 2;
			ans[2][sp[0]] = 2, ans[2][sp[1]] = 0;
			ans[3][sp[0]] = 1, ans[3][sp[1]] = 1;
			ans[4][sp[0]] = 0, ans[4][sp[1]] = 2;
			ans[5][sp[0]] = 2, ans[5][sp[1]] = 1;
			ans[6][sp[0]] = 1, ans[6][sp[1]] = 0;
			ans[7][sp[0]] = 2, ans[7][sp[1]] = 2;
			ans[8][sp[0]] = 0, ans[8][sp[1]] = 1;
		}
		ru(i, 1, m) if(b[i] == 1) {
			ru(j, 0, now - 1) {
				ru(k, 1, m) ans[2 * now - 1 - j][k] = ans[j][k];
			}
			now *= 2;
			ru(j, 1, now - 2) ans[j][i] = (j % 2 == 0);
			ans[now - 1][i] = 1;
		}
	}
	ru(i, 1, now - 1) {
		ru(j, 1, m) printf("%d ", ans[i][j]);
		printf("\n");
	}
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}