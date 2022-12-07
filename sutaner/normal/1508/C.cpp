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

#define maxn 600020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m;

struct edge{
	int x, y, w;
	edge(int x, int y, int w) : x(x), y(y), w(w){}
	edge(){}
	bool operator < (const edge b) const{
		return w < b.w;
	}
}e[maxn << 1];
int deg[maxn];

vector<int> lis;
vector<pii> lise; 
set<int> g[maxn];
int ufs[maxn], siz[maxn];

int find_root(int x) {
	return x = (ufs[x] == x) ? x : find_root(ufs[x]);
}
int ufs2[maxn], siz2[maxn];
int find_root2(int x) {
	return x = (ufs2[x] == x) ? x : find_root2(ufs2[x]);
}
bool merge(int x, int y, bool other = false) {
	if (other){
		x = find_root2(x), y = find_root2(y);
		if (x == y) return false;
		ufs2[x] = y;
		siz2[y] += siz2[x];
		return true;
	}
	x = find_root(x), y = find_root(y);
	if (x == y) return false;
	ufs[x] = y;
	siz[y] += siz[x];
	return true;
}

int main(){
	read(n, m);
	if (!m) {
		puts("0");
		return 0;
	}
	rep(i, 1, n) ufs[i] = i, siz[i] = 1;
	int x, y, w;
	
	ll xsum = 0;
	rep(i, 1, m) {
		read(x, y, w), xsum ^= w;
		e[i] = edge(x, y, w);
		g[x].insert(y), g[y].insert(x);
		deg[x]++, deg[y]++;
	}
	sort(e + 1, e + 1 + m);
	
	
	
	int mideg = n + 1, mideg2 = -1;
	rep(i, 1, n) {
		if (mideg > deg[i]) mideg = deg[i], mideg2 = i;
	}
	
	ll rest = 1ll * n * (n - 1) / 2 - m;
	if (rest > n - 1) {
		rep(i, 1, n) if (!g[mideg2].count(i)) merge(i, mideg2);
		int root = find_root(mideg2);
		rep(i, 1, n) {
			if (find_root(i) == i && i != root) lis.pb(i);
		}
		/*
		int si = lis.size();
		srep(i, 0, si) srep(j, i + 1, si) {
			if (!g[lis[i]].count(lis[j])) {
				lise.pb(pii(lis[i], lis[j]));
			}
		}
		*/
		rep(i, 1, n) {
			for (auto it: lis) {
				if (!g[i].count(it)) merge(i, it);
			} 
		}
		/*
		for (auto it: lise) {
			merge(it.fi, it.se);
		}
		*/
		ll res = 0;
		rep(i, 1, m) {
			if (merge(e[i].x, e[i].y)) res += e[i].w;
		}
		printf("%lld\n", res);
	}
	else {
		// n <= sqrt
		bool have_loop = 0;
		rep(x, 1, n) {
			rep(i, x + 1, n) {
				if (!g[i].count(x)) {
					if (!merge(i, x)) have_loop = 1;
					lise.pb(pii(i, x));
				}
			}
		}
		rep(i, 1, n) ufs2[i] = i, siz2[i] = 1;
		ll res = 0;
		ll mi = -1;
		rep(i, 1, m) {
			bool f1 = merge(e[i].x, e[i].y);
			bool f2 = merge(e[i].x, e[i].y, true);
			if (f1) res += e[i].w;
			if (!f1 && f2) {
				mi = (mi == -1) ? e[i].w : mi;
			}
		}
		//cerr << mi << ' ' << xsum << endl;
		if (have_loop) {
			printf("%lld\n", res);
		}
		else {
			res += min(xsum, mi);
			printf("%lld\n", res);
		}
	}
	return 0;
}