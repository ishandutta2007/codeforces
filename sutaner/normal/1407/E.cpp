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
#define maxn 600020
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

const int inf = 2000000000;
int n, m;
int mi[maxn][2];
struct edge{
	int next, to, c;
	edge(int next, int to, int c) : next(next), to(to), c(c){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int c){
	e[++cnt] = edge(h[x], y, c);
	h[x] = cnt;
}
int bfs[maxn], head = 0, tail = 0, d[maxn], res[maxn];
int main(){
	int x, y, z;
	scanf("%d%d", &n, &m);
	rep(i, 1, m) scanf("%d%d%d", &x, &y, &z), Add_Edge(y, x, z);
	rep(i, 1, n) d[i] = -1, mi[i][0] = mi[i][1] = inf;
	d[n] = 0, bfs[++head] = n, res[n] = 1;
	while (head != tail){
		int x = bfs[++tail];
		erep(i, x){
			int op = e[i].to;
			if (d[op] != -1) continue;
			mi[op][e[i].c] = min(mi[op][e[i].c], d[x] + 1);
			if (max(mi[op][0], mi[op][1]) < inf) {
				d[op] = max(mi[op][0], mi[op][1]);
				res[op] = (mi[op][0] >= mi[op][1]) ? 0 : 1;
				bfs[++head] = op;
			}
		}
	}
	rep(i, 1, n) if (d[i] == -1) res[i] = (mi[i][0] == inf) ? 0 : 1; 
	printf("%d\n", d[1]);
	rep(i, 1, n) printf("%d", res[i]);
	return 0;
}