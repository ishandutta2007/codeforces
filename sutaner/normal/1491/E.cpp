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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n; //fib[maxn];
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}


vector<int> fib;
priority_queue<pii> pq;
int s[maxn], c[maxn];
void dye(int x, int fa,  int cc, int _cc) {
	c[x] = cc;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa || c[op] != _cc) continue;
		dye(op, x, cc, _cc);
	}
}
void _dfs(int x, int fa, int cc){
	s[x] = 1;
	erep(i, x) {	
		int op = e[i].to;
		if (op == fa || c[op] != cc) continue;
		_dfs(op, x, cc);
		s[x] += s[op]; 
	} 
}
int dfs(int x, int fa, int cc, int v, bool& big) { 
	int res = 0;
	erep(i, x) {	
		int op = e[i].to;
		if (op == fa || c[op] != cc) continue; 
		if (s[op] == fib[v - 2]) {
			dye(op, x, op, cc);
			pq.push(pii(op, v - 2));
			res++;
		}
		else if (s[op] == fib[v - 1]) {
			res++;
			dye(op, x, op, cc);
			//res += dfs(op, x, cc, v);
			pq.push(pii(op, v - 1));
			big = 1;
		}
		else if (s[op] > fib[v - 2]) res += dfs(op, x, cc, v, big); 
	} 
	return res;
}
bool play(int x, int v) {
	if (v <= 3) return true;
	_dfs(x, -1, x);
	bool big = false;
	int rs = dfs(x, -1, x, v, big);
	if (big) pq.push(pii(x, v - 2));
	else {
		if (rs == 2) pq.push(pii(x, v - 3));
		else if (rs == 1) pq.push(pii(x, v - 1));
		else return false;
	}
	return true;
}
bool work(int v){
	pq.push(pii(1, v));
	rep(i, 1, n) c[i] = 1;
	while (!pq.empty()) {
		pii op = pq.top(); pq.pop();
		//cerr << op.fi << ' ' << op.se << endl;
		if (!play(op.fi, op.se)) return false;
	}
	return true;
}

int main(){
	int a = 1, b = 1;
	fib.pb(a), fib.pb(b);
	while (1) {
		int c = b; b = a + b, a = c;
		fib.pb(b);
		if (b > maxn) break;
	}
	//fib[0] = fib[1] = 1; srep(i, 2, maxn) fib[i] = fib[i - 1] + fib[i - 2];
	read(n);
	int v = lower_bound(fib.begin(), fib.end(), n) - fib.begin();
	if (n != fib[v]) {
		puts("NO");
		return 0;
	}
	int x, y;
	rep(i, 2, n) read(x, y), Add_Edge(x, y);
	rep(x, 1, n) {
		int num = 0;
		erep(i, x) {
			int op = e[i].to;
			if (deg[op] == 1) num++;
		}
		if (num >= 3) {
			puts("NO");
			return 0;
		}
	}
	puts(work(v) ? "YES" : "NO");
	return 0;
}