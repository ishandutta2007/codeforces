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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;
struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int h[maxn], cnt = 1, deg[maxn], cur[maxn], _deg[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
	deg[x]++, deg[y]++;
}
bool vis[maxn << 1];
int res[maxn << 1], cs = 0;
void dfs(int x){
	for (int& i = cur[x]; i; ){
		int op = e[i].to;
		if (vis[i] || vis[i ^ 1]) {
			i = e[i].next;
			continue; 
		}
		vis[i] = vis[i ^ 1] = 1;
		i = e[i].next;
		dfs(op); 
	}
	res[++cs] = x;
}
vector<int> lis;

bool play(int c, int ed = -1) {
	cs = 0;
	rep(i, 1, cnt) vis[i] = 0;
	rep(i, 1, n) deg[i] = _deg[i], cur[i] = h[i];
	lis.clear(); 
	erep(i, c) {
		int op = e[i].to;
		if ((deg[op] & 1) && i != ed) {
			vis[i] = vis[i ^ 1] = 1;
			lis.pb(op);
			deg[op]--;
			deg[c]--;
		}
	}
	int odd = 0;
	rep(i, 1, n) {
		odd += (deg[i] & 1);
	}
	if (odd > 2 || (odd == 2 && !(deg[c] & 1))) return false;
	dfs(c);
	bool fail = 0;
	rep(i, 2, cnt) {
		if (!vis[i]) {
			fail = 1;
			break;
		}
	}
	if (!fail) {	
		//reverse(res + 1, res + 1 + cs);
		if (!lis.empty()) {
			res[++cs] = -1;
			for (auto it: lis) {
				res[++cs] = it, res[++cs] = c;
			}
		} 
		write(cs);
		rep(i, 1, cs) write(res[i], ' ');
		return true;
	}
	return false;
}
int main(){
	read(n, m);
	int x, y;
	rep(i, 1, m) {
		read(x, y);
		Add_Edge(x, y);
	}
	rep(i, 1, n) cur[i] = h[i], _deg[i] = deg[i];
	rep(c, 1, n) {
		if (play(c)) return 0;
		erep(i, c) {
			if (play(c, i)) return 0;
		}
	} 
	puts("0");
	return 0; 
}