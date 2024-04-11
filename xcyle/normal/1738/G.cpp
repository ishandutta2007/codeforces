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
#define maxn 1005
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
int n, k;
char s[maxn][maxn];
int nxt[maxn * 2][maxn];
int pos[maxn * 2], need[maxn * 2];
int ban[maxn][maxn];
void solve() {
	n = read(), k = read();
	ru(i, 1, n) ru(j, 1, n) ban[i][j] = 0;
	ru(i, 1, n) scanf("%s", s[i] + 1);
	ru(i, 1, 2 * n - 1) nxt[i][n + 1] = n + 1;
	ru(i, 0, n - 1) {
		int las = n + 1;
		rd(j, n - i, 1) {
			if(s[j][j + i] == '1') las = j;
			nxt[n + i][j] = las;
		}
		need[n + i] = max(0, n - i - k + 1);
	}
	ru(i, 1, n) {
		int las = n + 1;
		rd(j, n, n - i + 1) {
			if(s[j][j - (n - i)] == '1') las = j;
			nxt[i][j] = las;
		}
		need[i] = max(0, i - k + 1);
	}
	ru(i, 1, 2 * n - 1) pos[i] = 0;
	ru(i, 1, n - k + 1) {
		pos[n] = max(pos[n - 1], pos[n + 1] + 1);
		pos[n] = nxt[n][pos[n]];
		if(pos[n] > n) {
			printf("NO\n");
			return;
		}
		ban[pos[n]][pos[n]] = 1;
		rd(j, n - 1, 1) if(need[j]) {
			pos[j] = max(pos[j - 1], pos[j + 1] + 1);
			pos[j] = nxt[j][pos[j]];
			if(pos[j] > n) {
				printf("NO\n");
				return;
			}
			ban[pos[j]][pos[j] - (n - j)] = 1;
			need[j]--;
		}
		ru(j, n + 1, 2 * n - 1) if(need[j]) {
			pos[j] = max(pos[j - 1], pos[j + 1] + 1);
			pos[j] = nxt[j][pos[j]];
			if(pos[j] > n) {
				printf("NO\n");
				return;
			}
			ban[pos[j]][pos[j] + j - n] = 1;
			need[j]--;
		}
	}
	printf("YES\n");
	ru(i, 1, n) {
		ru(j, 1, n) printf("%d", !ban[i][j]);
		printf("\n");
	}
}
int main() {
	int T = read();
	while(T--) solve();
	return 0;
}