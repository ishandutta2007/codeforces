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

#define maxn 400021
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n; ll a[maxn], b[maxn];

ll gg[maxn << 2]; int qx, qy;
inline void pu(int o) {
	gg[o] = __gcd(gg[o << 1], gg[o << 1 | 1]);
}
void init(int l, int r, int o) {
	gg[o] = 0;
	if (l == r) { gg[o] = b[l]; return; }
	int mid = ((r - l) >> 1) + l;
	init(l, mid, o << 1), init(mid + 1, r, o << 1 | 1);
	pu(o);
}
ll get(int l, int r, int o) {
	if (qx <= l && r <= qy) return gg[o];
	int mid = ((r - l) >> 1) + l;
	ll ans = -1;
	if (qx <= mid) ans = get(l, mid, o << 1);
	if (qy > mid) ans = (ans == -1) ? get(mid + 1, r, o << 1 | 1) : __gcd(ans, get(mid + 1, r, o << 1 | 1));
	return ans;
}

int lower_b(int x, int l, int r) {
	qx = x; 
	while (l < r) {
		int mid = ((r - l + 1) >> 1) + l;
		qy = mid;
		if (get(1, n - 1, 1) >= 2) l = mid;
		else r = mid - 1;
	}
	return l;
}

int main(){
	int T; read(T);
	while (T--){
		read(n); rep(i, 1, n) read(a[i]);
		if (n == 1) {
			puts("1");
			continue;
		}
		srep(i, 1, n) b[i] = abs(a[i + 1] - a[i]);
		init(1, n - 1, 1);
		int ans = 0;
		srep(i, 1, n) {
			int x = lower_b(i, i - 1, n - 1);
			ans = max(ans, x - i + 2);
		}
		printf("%d\n", ans);
	}
	return 0;
}