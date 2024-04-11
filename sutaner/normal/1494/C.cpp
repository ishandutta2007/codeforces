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

int n, m, a[maxn], b[maxn], st;
int pre[maxn], suf[maxn];

int getnum(int l, int r) {
	l = lower_bound(b + 1, b + 1 + m, l) - b;
	r = upper_bound(b + 1, b + 1 + m, r) - b - 1;
	return r - l + 1;
}
int _find1(int l, int r, int p, int bound) {
	while (l < r) {
		int mid = ((r - l) >> 1) + l;
		int pp = lower_bound(a + 1, a + 1 + n, p - (bound - mid) + 1) - a;
		if (pp <= mid) r = mid;
		else l = mid + 1; 
	}
	return l;
}
int solve1(int x) {
	//if (st == 1 || x == 0) return 0;
	int res = 0;
	per(i, st - 1, 0) {
		int pp = _find1(1, x, b[i], x);
		res = max(res, pre[pp - 1] + getnum(b[i] - (x - pp) + 1, b[i]));
	}
	return res;
}
int _find2(int l, int r, int p, int bound) {
	while (l < r) {
		int mid = ((r - l + 1) >> 1) + l;
		int pp = upper_bound(a + 1, a + 1 + n, p + (mid - bound) - 1) - a - 1;
		if (pp >= mid) l = mid;
		else r = mid - 1; 
	}
	return l;
}
int solve2(int x) {
	//if (st == n + 1 || x == n + 1) return 0;
	int res = 0;
	rep(i, st, m) {
		int pp = _find2(x - 1, n, b[i], x - 1);
		res = max(res, suf[pp + 1] + getnum(b[i], b[i] + pp - x));
	}
	return res;
}
set<int> sp;

int main(){
	int T; read(T);
	while (T--){
		sp.clear();
		read(n, m);
		rep(i, 1, n) read(a[i]);
		rep(i, 1, m) read(b[i]), sp.insert(b[i]);
		pre[0] = 0; rep(i, 1, n) pre[i] = pre[i - 1] + sp.count(a[i]);
		suf[n + 1] = 0; per(i, n, 1) suf[i] = suf[i + 1] + sp.count(a[i]);
		int p = lower_bound(a + 1, a + 1 + n, 0) - a;
		st = lower_bound(b + 1, b + 1 + m, 0) - b;
		int res = solve1(p) + solve2(p);
		write(res);
		rep(i, 1, n) pre[i] = suf[i] = 0;
	}
	return 0;
}