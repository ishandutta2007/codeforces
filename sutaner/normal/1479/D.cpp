#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = hi[x]; i; i = e[i].next)
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

#define maxn 600020
#define maxm
#define maxs 41516761
#define maxb 20
#define inf 
#define eps 
#define ll long long int 
#define bas 2333

int n, m, a[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 2];
int cnt = 1, hi[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(hi[x], y);
	hi[x] = cnt;
	e[++cnt] = edge(hi[y], x);
	hi[y] = cnt;
}

#define maxM 1
int M[] = {19260817, 1000000007, 1000000009};
int mi[maxM][maxn], d[maxn];
int has[maxM][maxs], h[maxn], ch[maxs][2], ct = 0;
int qx, qy, qd;
void pu(int l, int r, int o) {
	int mid = ((r - l) >> 1) + l;
	srep(id, 0, maxM) {
		has[id][o] = (1ll * mi[id][r - mid] * has[id][ch[o][0]] + has[id][ch[o][1]]) % M[id];
	} 
}
void ins(int l, int r, int per, int& now) {
	if (!now) now = ++ct;
	if (l == r) {
		srep(id, 0, maxM) has[id][now] = has[id][per] ^ 1;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) ins(l, mid, ch[per][0], ch[now][0]), ch[now][1] = ch[per][1];
	else ins(mid + 1, r, ch[per][1], ch[now][1]), ch[now][0] = ch[per][0];
	pu(l, r, now);
}
int fa[maxb][maxn];
void dfs(int x) {
	srep(i, 1, maxb) fa[i][x] = fa[i - 1][fa[i - 1][x]];
	qx = a[x];
	ins(1, n, h[fa[0][x]], h[x]);
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[0][x]) continue;
		fa[0][op] = x;
		d[op] = d[x] + 1;
		dfs(op);
	}
}
int getlca(int x, int y) {
	if (x == y) return x;
	if (d[x] < d[y]) swap(x, y);
	int k = d[x] - d[y], now = 0;
	while (k) {
		if (k & 1) x = fa[now][x];
		k >>= 1;
		now++;
	}
	if (x == y) return x;
	per(i, maxb - 1, 0) {
		if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	}
	return fa[0][x];
}
bool judge(int x, int y){ 
	bool f = 1;
	srep(id, 0, maxM) {
		if (has[id][x] != has[id][y]) {f = 0; break;}
	}
	return f;
}
int get(int l, int r, int x, int y) {
	if (qx <= l && r <= qy) {
		if (l == r) 
			return !judge(x, y) ? l : -1;
			
		int mid = ((r - l) >> 1) + l;
		
		if (!judge(ch[x][0], ch[y][0])) return get(l, mid, ch[x][0], ch[y][0]);
		return get(mid + 1, r, ch[x][1], ch[y][1]);
	}
	int mid = ((r - l) >> 1) + l, ans = -1;
	if (qx <= mid) ans = get(l, mid, ch[x][0], ch[y][0]);
	
	if (ans != -1) return ans;
	
	if (qy > mid) return get(mid + 1, r, ch[x][1], ch[y][1]);
	else return ans;
}
int _get(int l, int r, int x, int y) {
	if (l == r) {
		return judge(x, y) ? l : -1;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) return _get(l, mid, ch[x][0], ch[y][0]);
	else return _get(mid + 1, r, ch[x][1], ch[y][1]);
}
int query(int x, int y, int l, int r) {
	qx = l, qy = r;
	int lca = getlca(x, y), res = -1;
	if (l <= a[lca] && a[lca] <= r) {
		qx = l, qy = a[lca] - 1;
		if (qx <= qy) res = get(1, n, h[x], h[y]);
		if (res != -1) return res;
		
		qx = a[lca] + 1, qy = r;
		if (qx <= qy) res = get(1, n, h[x], h[y]);
		if (res != -1) return res;
		
		qx = a[lca];
		res = _get(1, n, h[x], h[y]);
		return res;
	}
	else {
		qx = l, qy = r;
		return get(1, n, h[x], h[y]); 
	} 
}
int main(){
	read(n, m);
	srep(id, 0, maxM) {mi[id][0] = 1; rep(i, 1, n) mi[id][i] = 1ll * mi[id][i - 1] * bas % M[id];}
	rep(i, 1, n) read(a[i]);
	int x, y;
	rep(i, 2, n) {
		read(x, y);
		Add_Edge(x, y);
	}
	dfs(1);
	int l, r;
	rep(i, 1, m) {
		read(x, y, l, r);
		printf("%d\n", query(x, y, l, r));
	}
	return 0;
}