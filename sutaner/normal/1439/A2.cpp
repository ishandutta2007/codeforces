#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdd pair<double, double>
#define fi first
#define se second
#define ui unsigned int
#define ld long double
#define ll long long int 
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define maxn 220
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}
int n, m; char g[maxn][maxn];
struct ele{
	pii a[4]; int type; 
	void print(){
		rep(i, 0, 3) if (i != type) printf("%d %d ", a[i].fi, a[i].se); puts("");
	}
}lis[maxn * maxn << 2];
int ans = 0;
void operate(int x, int y, int d){
	ele op; op.a[0] = pii(x, y), op.a[1] = pii(x, y + 1), op.a[2] = pii(x + 1, y), op.a[3] = pii(x + 1, y + 1);
	rep(i, 0, 3) {
		if (i == d) continue;
		op.type = i, lis[++ans] = op;
	}
}
void ope_1(int x, int y, int d){
	ele op; op.a[0] = pii(x, y), op.a[1] = pii(x, y + 1), op.a[2] = pii(x + 1, y), op.a[3] = pii(x + 1, y + 1);
	op.type = d, lis[++ans] = op;
	rep(i, 0, 3) {
		if (i == d) continue;
		g[op.a[i].fi][op.a[i].se] ^= 1;
	}
}
void ope_4(int x, int y){
	ele op; op.a[0] = pii(x, y), op.a[1] = pii(x, y + 1), op.a[2] = pii(x + 1, y), op.a[3] = pii(x + 1, y + 1);
	rep(i, 0, 3) op.type = i, lis[++ans] = op; 
}

int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", g[i] + 1);
		rep(i, 1, n) rep(j, 1, m) g[i][j] -= '0';
		if (n & 1) {
			rep(i, n, n) rep(j, 1, m) {
				if (g[i][j]) {
					if (j < m) ope_1(i - 1, j, 3);
					else ope_1(i - 1, j - 1, 2);
				}
			}
			n--;
		}
		if (m & 1){
			rep(i, 1, n) rep(j, m, m){
				if (g[i][j]){
					if (i < n) ope_1(i, j - 1, 3);
					else ope_1(i - 1, j - 1, 1);
				}
			}
			m--;
		}
		for (register int i = 1; i <= n; i += 2){
			for (register int j = 1; j <= m; j += 2){
				int cnt = 0;
				rep(_i, i, i + 1) rep(_j, j, j + 1) if (g[_i][_j]) cnt++; 
				if (cnt == 0) continue;
				else if (cnt == 1) {
					int d = 0;
					rep(_i, i, i + 1) rep(_j, j, j + 1) {
						if (g[_i][_j]) {
							operate(i, j, d); 
							goto done;
						}
						d++;
					}
					done:; 
				}
				else if (cnt == 2){
					if (g[i][j] && g[i + 1][j]) ope_1(i, j, 0), ope_1(i, j, 2);
					if (g[i][j] && g[i][j + 1]) ope_1(i, j, 0), ope_1(i, j, 1);
					if (g[i][j + 1] && g[i + 1][j + 1]) ope_1(i, j, 1), ope_1(i, j, 3);
					if (g[i + 1][j] && g[i + 1][j + 1]) ope_1(i, j, 2), ope_1(i, j, 3);
					if (g[i][j] && g[i + 1][j + 1]) ope_1(i, j, 0), ope_1(i, j, 3); 
					if (g[i + 1][j] && g[i][j + 1]) ope_1(i, j, 1), ope_1(i, j, 2);
				}
				else if (cnt == 3){
					int d = 0;
					rep(_i, i, i + 1) rep(_j, j, j + 1) {
						if (!g[_i][_j]) {
							ope_1(i, j, d); 
							goto done2;
						}
						d++;
					}
					done2:;
				}
				else if (cnt == 4) ope_4(i, j);
			}
		}
		printf("%d\n", ans); rep(i, 1, ans) lis[i].print(); ans = 0;
	}
	return 0;
}