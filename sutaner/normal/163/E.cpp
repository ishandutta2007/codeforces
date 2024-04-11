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
#define all(x) x.begin(), x.end()
#define see(x) cerr << (#x) << " = " << (x) << endl
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
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

#define read read_unsigned
#define reads read_string 
#define writes puts
 
#define maxm
#define maxn 1000020
#define maxsig 26
#define maxb
#define inf 
#define eps
#define M 
#define idx(ch) (ch - 'a')
#define isop(ch) ((ch == '+') || (ch == '-') || (ch == '?'))

namespace ACAM{
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
	int ch[maxsig][maxn], nod[maxn];
	int ct = 0;
	void insert(char* s, int n, int id){
		int now = 0;
		srep(i, 0, n) {
			if (!ch[idx(s[i])][now]) ch[idx(s[i])][now] = ++ct;
			now = ch[idx(s[i])][now];
		}
		nod[id] = now;
	}
	int dfs[maxn], fa[maxn], s[maxn], tim = 0;
	void DFS(int x){
		s[x] = 1;
		dfs[x] = ++tim;
		erep(i, x){
			int op = e[i].to;
			if (op == fa[x]) continue;
			DFS(op);
			s[x] += s[op];
		}
	}
	int bfs[maxn], last[maxn], he = 0, ta = 0;
	void build(){
		fa[0] = 0, he = ta = 0;
		srep(i, 0, maxsig) if (ch[i][0]) bfs[++he] = ch[i][0], fa[ch[i][0]] = 0;
		while (he > ta){
			int x = bfs[++ta];
			srep(i, 0, maxsig) {
				if (!ch[i][x]) {ch[i][x] = ch[i][fa[x]]; continue;}
				int y = ch[i][x], now = fa[x];
				while (now && !ch[i][now]) now = fa[now];
				fa[y] = ch[i][now];
				bfs[++he] = y;
			}
		}
		rep(i, 1, ct) Add_Edge(i, fa[i]);
		DFS(0);
	}
	int sum[maxn << 2], qx, qy, qd;
	void mod(int l, int r, int o){
		if (qx <= l && r <= qy) {sum[o] += qd; return;}
		int mid = ((r - l) >> 1) + l;
		if (qx <= mid) mod(l, mid, o << 1);
		if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	}
	int get(int l, int r, int o){	
		int ans = sum[o];
		if (l == r) return ans;
		int mid = ((r - l) >> 1) + l;
		if (qx <= mid) return ans + get(l, mid, o << 1);
		return ans + get(mid + 1, r, o << 1 | 1);
	}
	void init(){
		build();
	}
	int is[maxn];
	void mod(int id, int v){
		if (v == is[id]) return;
		is[id] = v;
		qx = dfs[nod[id]], qy = dfs[nod[id]] + s[nod[id]] - 1, qd = v;
		mod(1, ct + 1, 1);
	}
	ll get(char* s, int n){
		int now = 0; ll ans = 0;
		qx = dfs[now]; ans += get(1, ct + 1, 1);
		srep(i, 0, n) {
			now = ch[idx(s[i])][now];
			qx = dfs[now], ans += get(1, ct + 1, 1); 
		} 
		return ans; 
	}
}using namespace ACAM;

int n, k; char str[maxn];

int main(){
	read(n, k); int x;
	rep(i, 1, k) { x = reads(str); insert(str, x, i);}
	init();
	rep(i, 1, k) mod(i, 1);
	rep(i, 1, n) {
		char ch = gc(); while (!isop(ch)) ch = gc();
		switch(ch){
			case '+': read(x), mod(x, 1); break;
			case '-': read(x), mod(x, -1); break;
			case '?': x = reads(str), printf("%lld\n", get(str, x)); break;
		}
	}
	return 0;
}