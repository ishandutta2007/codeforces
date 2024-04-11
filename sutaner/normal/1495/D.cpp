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

#define maxn 420
#define maxm
#define maxs
#define maxb
#define inf 998244353
#define eps
#define M   998244353
#define ll long long int 

int n, m;
struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 3];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
}

int que[maxn], head = 0, tail = 0;
int d1[maxn], d2[maxn]; bool vis[maxn];
void bfs(int s, int* d) {
    head = tail = 0;
    rep(i, 1, n) d[i] = inf, vis[i] = 0;
    d[s] = 0;
    vis[s] = 1;
    que[++head] = s;
    while (head > tail) {
        int x = que[++tail];
        erep(i, x) {
            int op = e[i].to;
            if (vis[op]) continue;
            d[op] = d[x] + 1;
            que[++head] = op;
            vis[op] = 1;
        }
    }
}

int num[maxn][maxn];
int res[maxn][maxn];
int main(){
    int x, y;
    read(n, m);
    rep(i, 1, m) read(x, y), Add_Edge(x, y);
    rep(i, 1, n) rep(j, i, n) {
        bfs(i, d1), bfs(j, d2);
        // printf("%d %d %d %d\n", d1[i], d2[i], d1[j], d2[j]);
        rep(k, 1, n) num[d1[k]][d2[k]]++;
        int d = d1[j], op, ct = 0, ans = 1;
        rep(k, 0, d) {
            if (num[k][d - k] != 1) {
                res[i][j] = res[j][i] = 0;
                goto done;
            }
        }
        //puts("A");
        rep(k, 1, n) {
            if (d1[k] + d2[k] == d) continue;
            ct = 0;
            erep(kk, k) {
                op = e[kk].to;
                if (d1[op] != d1[k] - 1 || d2[op] != d2[k] - 1) continue;
                ct++;
            }
            //ct = max(1, ct);
            ans = 1ll * ans * ct % M;
        }
        res[i][j] = res[j][i] = ans;
        done: rep(k, 1, n) num[d1[k]][d2[k]]--;
    }
    rep(i, 1, n) { rep(j, 1, n) printf("%d ", res[i][j]); printf("\n"); }
	return 0;
}