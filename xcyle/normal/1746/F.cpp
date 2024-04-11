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
#define maxn 300005
#define B 50
using namespace std;
inline int read() {
	int x = 0, w = 0; char ch = getchar();
	while(!isdigit(ch)) {w |= ch == '-'; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return w ? -x : x;
}
mt19937 Rand(time(NULL));
bool val[maxn * 2][B + 2];
int t[maxn][B + 2], sum[B + 5];
int n, q, a[maxn];
int w[maxn], x[maxn], y[maxn], z[maxn];
int tmp[maxn * 2];
void upd(int x, int v) {
	ru(i, 1, B) sum[i] = val[a[x]][i];
	for (; x <= n; x += x & (-x)) {
		ru(i, 1, B) t[x][i] += v * sum[i];
	}
}
void query(int x, int v) {
	for (; x; x -= x & (-x)) {
		ru(i, 1, B) sum[i] += v * t[x][i];
	}
} 
int main() {
	n = read(), q = read();
	int tot = n;
	ru(i, 1, n) tmp[i] = a[i] = read();
	ru(i, 1, q) {
		w[i] = read(), x[i] = read(), y[i] = read();
		if(w[i] == 2) {
			z[i] = read();
		}
		else {
			tmp[++tot] = y[i];
		}
	}
	sort(tmp + 1, tmp + tot + 1);
	tot = unique(tmp + 1, tmp + tot + 1) - tmp - 1;
	ru(i, 1, n) a[i] = lower_bound(tmp + 1, tmp + tot + 1, a[i]) - tmp;
	ru(i, 1, q) if(w[i] == 1) y[i] = lower_bound(tmp + 1, tmp + tot + 1, y[i]) - tmp;
	ru(i, 1, tot) {
		ru(j, 1, B) val[i][j] = Rand() & 1;
	}
	ru(i, 1, n) upd(i, 1);
	ru(i, 1, q) {
		if(w[i] == 1) {
			upd(x[i], -1);
			a[x[i]] = y[i];
			upd(x[i], 1);
		}
		else {
			if(z[i] == 1) {
				printf("YES\n");
				continue;
			}
			ru(i, 1, B) sum[i] = 0;
			query(y[i], 1), query(x[i] - 1, -1);
			int fl = 1;
			ru(j, 1, B) fl &= (sum[j] % z[i] == 0);
			if(fl) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}