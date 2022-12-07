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

#define maxn 100020
#define maxm
#define maxs
#define maxb 20
#define inf 1000000020
#define eps
#define M 
#define ll long long
#define int ll 


int n, k, s[maxn];
ll sum[maxn];
vector<int> a[maxn];
vector<pll> g[maxn << 2];
int qx, qy; pll qd;
void mod(int l, int r, int o) {
	if (qx <= l && r <= qy) {
		g[o].pb(qd);
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
}
ll ans = -inf;
ll sav[maxb][maxn], now[maxn];

void upd(ll s, ll x) {
	per(i, k, x) {if (now[i - x] == -inf) continue; now[i] = max(now[i], now[i - x] + s); }
}
void dfs(int l, int r, int o, int dep) {
	rep(i, 0, k) sav[dep][i] = now[i];
	for (auto it: g[o]) upd(it.fi, it.se);
	if (l == r) {
		ll pre = 0;
		rep(i, 0, min(k, s[l])) {
			if (now[k - i] != -inf) ans = max(ans, now[k - i] + pre);
			if (i < s[l]) pre += a[l][i];
		}
		rep(i, 0, k) now[i] = sav[dep][i];
		return;
	}
	int mid = ((r - l) >> 1) + l;
	dfs(l, mid, o << 1, dep + 1);
	dfs(mid + 1, r, o << 1 | 1, dep + 1);
	rep(i, 0, k) now[i] = sav[dep][i];
}
signed main(){
	read(n, k);
	int x; 
	rep(i, 1, n) {
		read(s[i]);
		rep(j, 1, s[i]) {	
			read(x), sum[i] += x, a[i].pb(x);
		}
		qd = pll(sum[i], s[i]);
		qx = 1, qy = i - 1; if (qx <= qy) mod(1, n, 1);
		qx = i + 1, qy = n; if (qx <= qy) mod(1, n, 1);
	}
	now[0] = 0; rep(i, 1, k) now[i] = -inf;
	dfs(1, n, 1, 0);
	write(ans);
	return 0;
}