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
    #define isletter(ch) ('0' <= ch && ch <= '1')
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

int n, m;
char s[maxn], t[maxn];

int sum[maxn << 2], sset[maxn << 2], qx, qy, qd;
inline void pu(int o) {
	sum[o] = sum[o << 1] + sum[o << 1 | 1];
}
inline void pd(int l, int r, int o) {
	if (sset[o] != -1) {
		int& k = sset[o]; int mid = ((r - l) >> 1) + l;
		sset[o << 1] = k, sum[o << 1] = (mid - l + 1) * k;
		sset[o << 1 | 1] = k, sum[o << 1 | 1] = (r - mid) * k;
		k = -1;
	}
}
void init(int l, int r, int o) {
	sset[o] = -1;
	if (l == r){
		sum[o] = t[l] - '0';
		return;
	}
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
int getsum(int l, int r, int o) {
	pd(l, r, o);
	if (qx <= l && r <= qy) return sum[o];
	int mid = ((r - l) >> 1) + l, ans = 0;
	if (qx <= mid) ans += getsum(l, mid, o << 1);
	if (qy > mid) ans += getsum(mid + 1, r, o << 1 | 1);
	return ans;
}
void mod(int l, int r, int o) {
	pd(l, r, o);
	if (qx <= l && r <= qy) {
		sset[o] = qd, sum[o] = (r - l + 1) * qd;
		return;
	}
	int mid = ((r - l) >> 1) + l;
	if (qx <= mid) mod(l, mid, o << 1);
	if (qy > mid) mod(mid + 1, r, o << 1 | 1);
	pu(o);
}
bool cmp(int l, int r, int o) {
	pd(l, r, o);
	if (l == r) {
		return s[l] - '0' == sum[o];
	}
	int mid = ((r - l) >> 1) + l;
	if (!cmp(l, mid, o << 1)) return false;
	if (!cmp(mid + 1, r, o << 1 | 1)) return false;
	return true;
}

int l[maxn], r[maxn];
int main(){
	int T; read(T);
	while (T--){		
		read(n, m);
		reads(s + 1), reads(t + 1);
		init(1, n, 1);
		rep(i, 1, m) read(l[i], r[i]);
		per(i, m, 1) {
			qx = l[i], qy = r[i];
			int ones = getsum(1, n, 1);
			int zeros = qy - qx + 1 - ones;
			if (ones == zeros) {
				puts("NO");
				goto done;
			}
			if (ones > zeros) qd = 1; else qd = 0;
			mod(1, n, 1);
		}
		puts(cmp(1, n, 1) ? "YES" : "NO");
		done:;
	}
	return 0;
}