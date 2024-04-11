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

#define maxn 300022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, a[maxn], l[maxn], r[maxn];
pii sta[maxn]; int cs = 0;
pii lis[maxn]; int ch = 0;
int ans = 0;
void add(pii x) {
	while (ch && x.fi <= sta[ch].fi && sta[ch].se <= x.se) ch--;
	sta[++ch] = x;
}
bool cmp(pii a, pii b) {
	return a.se == b.se ? a.fi > b.fi : a.se < b.se;
}
int main(){
	read(n);
	rep(i, 1, n) read(a[i]), l[i] = n + 1, r[i] = 0;
	rep(i, 1, n) {
		l[a[i]] = min(l[a[i]], i);
		r[a[i]] = max(r[a[i]], i);
	}
	rep(i, 1, n) {
		if (l[i] >= r[i]) continue;
		lis[++cs] = pii(l[i], r[i]);
	}
	sort(lis + 1, lis + 1 + cs, cmp);
	rep(i, 1, cs) add(lis[i]);
	
	int ans = 0; int ptr = 1;
	rep(i, 1, ch) {
		int _i = i;
		int l = sta[i].fi, rr = sta[i].se;
		while (i <= ch && sta[i].fi <= rr) {	
			rr = sta[i].se;
			i++;
		}i--;
		
		ans += rr - l + 1;
		
		int num = 1;
		while (_i < i) {
			int r = sta[_i].se;
			while (_i <= i && sta[_i].fi <= r) _i++; _i--;
			num++;
		}
		
		ans -= num + 1;
	}
	
	//ans -= 2 * ch;
	
	/*
	int ptr = 1;
	rep(i, 1, ch) {
		while (ptr <= ch && sta[i].se >= sta[ptr].fi) ptr++; ptr--;
		ans += (ptr - i);
	}
	*/
	
	printf("%d\n", ans);
	return 0;
}