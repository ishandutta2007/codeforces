#pragma GCC optimize(3)

#include <bits/stdc++.h>
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, r, l) for (int i = r; i >= l; i--)
#define srep(i, l, r) for (int i = l; i < r; i++)
#define sper(i, r, l) for (int i = r; i > l; i--)
#define erep(i, x) for (int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (int& i = cur[x]; i; i = e[i].next)
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
#define maxbuf 2000020
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxbuf, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

namespace Fast_Read{
    char buffer[maxbuf], *p1, *p2;
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

#define maxn 200022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, a[maxn];
vector<ll> cls[maxn];
vector<int> fac;
multiset<ll> pq;

int pri[maxn], pson[maxn];
bool pvis[maxn];
int pct = 0;
int pinit(){
    srep(i, 2, maxn) {
        if (!pvis[i]) pri[++pct] = i, pson[i] = 1;
        rep(j, 1, pct) {
            if (i * pri[j] >= maxn) break;
            pvis[i * pri[j]] = 1;
            pson[i * pri[j]] = i;
            if (i % pri[j] == 0) break;
        }
    }
}

int plis[maxn], cs = 0;
void dep(int x) { 
    cs = 0;
    int __x = x;
    while (x > 1) {
        int _x = pson[x];
        plis[++cs] = x / _x;
        x = _x;
    }
    x = __x;
    sort(plis + 1, plis + 1 + cs);
    cs = unique(plis + 1, plis + 1 + cs) - plis - 1;
    rep(i, 1, cs) fac.pb(x / plis[i]); 
    sort(fac.begin(), fac.end());
    //cerr << '$'; for (auto it: fac) cerr << it << ' '; cerr << endl;
}
void init(){
    for (auto it: fac) cls[it].resize(it); 
    rep(p, 1, n) {
        for (auto it: fac) {
            ll& upd = cls[it][p % it];
            upd += 1ll * a[p] * it;
        }
    }
    for(auto it: fac) {
        for (auto it2: cls[it]) {   
            pq.insert(it2);
        }
    }
}
void update(int p, int x) {
    for (auto it: fac) {
        ll& upd = cls[it][p % it];

        pq.erase(pq.lower_bound(upd));
        upd += 1ll * (x - a[p]) * it;
        pq.insert(upd);
    }
    a[p] = x;
}
ll getans(){
    return *pq.rbegin();
}
void recover(){ 
    for (auto it: fac) {
        cls[it].clear();
    }
    fac.clear();
    pq.clear();
}

int main(){
    pinit();
    int T; read(T);
    while (T--) {
        read(n, m);
        rep(i, 1, n) {
            read(a[i]);
        }
        dep(n);
        init();
        printf("%lld\n", getans());
        int x, y;
        rep(i, 1, m) {
            read(x, y);
            update(x, y);
            printf("%lld\n", getans());
        }
        recover();
    }

	return 0;
}