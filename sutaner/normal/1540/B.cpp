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

#define maxn 320
#define maxm
#define maxs
#define maxb 10
#define inf 
#define eps
#define M 1000000007
#define ll long long int 
#define mo(x) (x = (x >= M) ? (x - M) : x)

int n;

struct edge{
    int next, to;
    edge(int next, int to) : next(next), to(to){}
    edge(){}
}e[maxn << 2];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
    e[++cnt] = edge(h[x], y);
    h[x] = cnt;
    e[++cnt] = edge(h[y], x);
    h[y] = cnt;
}
int power(int x, int y) {
    int ans = 1, con = x;
    while (y){
        if (y & 1) ans = 1ll * ans * con % M;
        con = 1ll * con * con % M;
        y >>= 1;
    }
    return ans;
}
int getinv(int x){
    return power(x, M - 2);
}
int d[maxn], fa[maxb][maxn];
void dfs(int x){
    srep(i, 1, maxb) fa[i][x] = fa[i - 1][fa[i - 1][x]];
    erep(i, x) {
        int op = e[i].to;
        if (op == fa[0][x]) continue;
        d[op] = d[x] + 1;
        fa[0][op] = x;
        dfs(op);
    }
}
int getlca(int x, int y) {
    if (x == y) return x;
    if (d[x] < d[y]) swap(x, y);
    int k = d[x] - d[y], now = 0;
    while (k) {
        if (k & 1) x = fa[now][x];
        now++;
        k >>= 1;
    }
    if (x == y) return x;
    per(i, maxb - 1, 0) {
        if (fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
    }
    return fa[0][x];
}

int fac[maxn], ifac[maxn], inv[maxn], two[maxn];
void init(){    
    fac[0] = ifac[0] = inv[1] = two[0] = 1;
    srep(i, 1, maxn) two[i] = two[i - 1] * 2 % M;
    srep(i, 1, maxn) fac[i] = 1ll * i * fac[i - 1] % M;
    srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
    srep(i, 1, maxn) ifac[i] = 1ll * inv[i] * ifac[i - 1] % M;
}
int cal(int m, int n) {
    if (m < n) return 0;
    return 1ll * fac[m] * ifac[n] % M * ifac[m - n] % M;
}

bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int a, int b) {
    if (!a) return 1;
    if (!b) return 0;
    if (vis[a][b]) return dp[a][b];
    vis[a][b] = 1;
    int& ans = dp[a][b]; ans = 0;
    return ans = 1ll * (DP(a - 1, b) + DP(a, b - 1)) * inv[2] % M;
}

int main(){
    init();
    read(n);
    int x, y;
    rep(i, 2, n) read(x, y), Add_Edge(x, y);
    ll ans = 0;
    per(c, n, 1) {
        d[c] = 0, fa[0][c] = c; dfs(c); 
        rep(i, 1, n) {
            srep(j, 1, i) { 
                int lca = getlca(i, j), a = d[j] - d[lca], b = d[i] - d[lca];
                //ll tmp = 0;
                //ans += 1ll * (d[j] - d[lca]) * getinv(d[i] + d[j] - 2 * d[lca]) % M;
                //rep(i, 0, a - 1) tmp += 1ll * (M + cal(b + i, b) - cal(b + i - 1, b)) * two[b + i] % M, mo(tmp);
                //ans += tmp % M;
                ans += DP(b, a);
                mo(ans);
            }
        }
    }
    ans = 1ll * ans * getinv(n) % M;
    printf("%lld\n", ans);
	return 0;
}