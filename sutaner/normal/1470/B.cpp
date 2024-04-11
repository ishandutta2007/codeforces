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

#define maxn 2000020
#define maxm 
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, a[maxn], b[maxn];
/*
bool issqu(ll x){
	ll sq = (ll)pow(x, 0.5);
	return sq * sq == x;
}
*/
int cp = 0, pri[maxn]; bool vis[maxn];
void init(){
	srep(i, 2, maxn) {
		if (!vis[i]) pri[++cp] = i;
		rep(j, 1, cp) {
			if (i * pri[j] >= maxn) break;
			vis[i * pri[j]] = 1;
			if (i % pri[j] == 0) break;
		}
	}
}
int dep(int x) {
	int res = 1;
	rep(i, 1, cp) {
		if (1ll * pri[i] * pri[i] > x) break;
		int d = 0;
		while (x % pri[i] == 0) {
			x /= pri[i];
			d ^= 1;
		}
		if (d) res *= pri[i];
	}
	res *= x;
	return res;
}
int num[maxn];
int main(){
	init();
	int T; read(T);
	while (T--){	read(n);
		int cs = 0;
		rep(i, 1, n) read(a[i]), a[i] = dep(a[i]), b[++cs] = a[i];
		sort(b + 1, b + 1 + cs);
		cs = unique(b + 1, b + 1 + cs) - b - 1;
		rep(i, 0, cs) num[i] = 0;
		rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + cs, a[i]) - b;
		int mx = 0;
		rep(i, 1, n) num[a[i]]++;  
		rep(i, 1, cs) mx = max(mx, num[i]);
		int ans0 = mx;
		mx = 0;
		rep(i, 1, cs) {
			if (b[i] == 1 || !(num[i] & 1)) num[0] += num[i], num[i] = 0;
		}
		rep(i, 0, cs) mx = max(mx, num[i]);
		int ans1 = mx;
		int q;
		read(q);
		ll x;
		rep(i, 1, q) {
			read(x);
			if (!x) write(ans0);
			else write(ans1);
		} 
	}
	return 0;
}