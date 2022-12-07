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

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, m, a[maxn], b[maxn], c[maxn];
int hav[maxn];
vector<int> rest[maxn];
int res[maxn];
int main(){
	int T; read(T);
	while (T--){
		read(n, m);
		rep(i, 1, n) read(a[i]);
		rep(i, 1, n) read(b[i]);
		rep(i, 1, m) read(c[i]); 
		rep(i, 1, n) rest[i].clear(), hav[i] = -1;
		rep(i, 1, n) { 
			if (a[i] != b[i]) rest[b[i]].pb(i);
			hav[b[i]] = i;
		} 
		per(i, m, 1) { 
			if (i == m) {
				if (!rest[c[i]].empty()) {
					res[i] = rest[c[i]].back(); 
					rest[c[i]].pop_back();
				}
				else {
					if (hav[c[i]] == -1){
						puts("NO");
						goto fail;
					}
					else {
						res[i] = hav[c[i]];
					}
				}
			}
			else {
				if (!rest[c[i]].empty()) {
					res[i] = rest[c[i]].back(); 
					rest[c[i]].pop_back();
				}
				else {
					res[i] = res[i + 1];
				}
			}
		}
		rep(i, 1, n) {
			if (!rest[i].empty()) {
				puts("NO");
				goto fail;
			}
		}
		puts("YES");
		rep(i, 1, m) printf("%d ", res[i]); printf("\n");
		fail:;
	}
	return 0;
}