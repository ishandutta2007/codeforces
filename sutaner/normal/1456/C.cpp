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
#define ll long long int 
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

ll n, k, a[maxn], pre[maxn], suf[maxn];
int main(){
	read(n, k); rep(i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n);
	//rep(i, 1, n) cerr << a[i] << ' '; cerr << endl;
	per(i, n, 1) pre[i] = pre[i + 1] + a[i];
	per(i, n, 1) suf[i] = suf[i + 1] + pre[i + 1];
	ll ans = 0, res = 0, sum = 0;
	rep(i, 1, n) ans += 1ll * (i - 1) * a[i], sum += a[i];
	res = ans;
	if (!k) {
		write(res);
		return 0;
	}
	ll forward = 0, backward = ans;
	per(l, n - 1, 0) {
		ll num = n - l;
		forward += 1ll * ((num - 1) / (k + 1)) * a[num];
		ll _num = ((num - 1) / (k + 1)) + 1;
		backward = suf[num + 1] + 1ll * pre[num + 1] * _num;
		ans = forward + backward;
		res = max(res, ans);
	}
	/*
	per(l, n - 1, 0){
		ll num = n - l;
		ll mi = a[num];
		sum -= mi;
		ans -= sum;
		ans += 1ll * ((num - 1) / k) * mi;
		res = max(res, ans);
	}
	*/
	write(res);
	return 0;
}