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
#define pb push_back
#define pc putchar
#define lowbit(x) (x & -x)
#define maxr 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxr], *p1, *p2;
    template<class T> void read_signed(T& x){
        char ch = gc(); x = 0; bool f = 1;
        while (!isdigit(ch) && ch != '-') ch = gc();
        if (ch == '-') f = 0, ch = gc();
        while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
        x = (f) ? x : -x;
    }
    template<class T, class... Args> void read_signed(T& x, Args&... args){
        read_signed(x), read_signed(args...);
    }
    template<class T> void read_unsigned(T& x){
        char ch = gc(); x = 0;
        while (!isdigit(ch)) ch = gc(); 
        while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = gc(); 
    }
    template<class T, class... Args> void read_unsigned(T& x, Args&... args){
        read_unsigned(x), read_unsigned(args...);
    }
    #define isletter(ch) ('a' <= ch && ch <= 'z')
    int read_string(char* s){
        char ch = gc(); int l = 0;
        while (!isletter(ch)) ch = gc();
        while (isletter(ch)) s[l++] = ch, ch = gc();
        s[l] = '\0'; return l;
    }
}using namespace Fast_Read; 

int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

#define read read_signed
#define reads read_string 
#define writes puts

#define maxn 500020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y){
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int n, m, ufs[maxn];
int findroot(int x) {
	return ufs[x] = (ufs[x] == x) ? x : findroot(ufs[x]);
}
bool merge(int x, int y) {
	x = findroot(x), y = findroot(y);
	if (x == y) return false;
	ufs[x] = y;
	return true;
}

int sum[maxn << 2];
int qx, qd;
inline void pu(int o) {
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
void mod(int l, int r, int o) {
	if (l == r) {
		sum[o] = qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	else mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
int get(int l, int r, int o) {	
	if (l == r) {
		return l;
	}
	int mid = ((r - l) >> 1) + l;
	if (sum[o << 1] < mid - l + 1) return get(l, mid, o << 1);
	else return get(mid + 1, r, o << 1 | 1); 
}
bool vis[maxn];
int c[maxn];
void dfs(int x) {
	vis[x] = 1;
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) {
			qx = c[op], qd = 1;
			mod(1, n, 1); 
		}
	}
	c[x] = get(1, n, 1);
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) {
			qx = c[op], qd = 0;
			mod(1, n, 1); 
		}
	}
	erep(i, x) {
		int op = e[i].to;
		if (vis[op]) continue;
		dfs(op);
	}
}
int main(){
	int T; read(T);
	while (T--){
		read(n, m);
		rep(i, 1, n) ufs[i] = i, c[i] = 0, h[i] = 0, vis[i] = 0; cnt = 1;
		int x, y;
		int cnnt = n;
		rep(i, 1, m) {
			read(x, y);
			if (merge(x, y)) cnnt--;
			Add_Edge(x, y);
		}
		if (cnnt != 1) {
			puts("NO");
			continue;
		}
		puts("YES");
		dfs(1);
		int res = 0;
		rep(i, 1, n) {
			if (c[i] == 1) res++;
		}
		printf("%d\n", res);
		rep(i, 1, n) {
			if (c[i] == 1) printf("%d ", i);
		}
		printf("\n");
	}
	return 0;
}