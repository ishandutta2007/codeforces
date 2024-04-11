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
int n, m; char g[maxn][maxn];
int main(){
	int T; scanf("%d", &T);
	while (T--){
		scanf("%d%d", &n, &m);
		rep(i, 1, n) scanf("%s", g[i] + 1);
		rep(i, 1, n) rep(j, 1, m) {
			if (g[i][j] == '1') {
				if (i < n && j < m) operate(i, j, 0);
				else if (i == n && j < m) operate(i - 1, j, 2);
				else if (i < n && j == m) operate(i, j - 1, 1);
				else operate(i - 1, j - 1, 3);
			}
		}
		printf("%d\n", ans); rep(i, 1, ans) lis[i].print(); ans = 0;
	}
	return 0;
}