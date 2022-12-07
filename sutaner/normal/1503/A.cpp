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

#define maxn 400020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n; char s[maxn];
char a[maxn], b[maxn];
bool check(char* s) {
	int now = 0;
	rep(i, 1, n) {
		if (s[i] == '(') now++;
		else now--;
		if (now < 0) return false;
	}
	if (now != 0) return false;
	return true;
}
int main(){
	int T; read(T);
	while (T--){
		read(n);
		reads(s + 1);
		int n0 = 0, n1 = 0;
		rep(i, 1, n) if (s[i] == '0') n0++;
		n1 = n - n0;
		if (n0 & 1) {
			puts("NO");
		}
		else {
			int nn0 = 0, nn1 = 0;
			rep(i, 1, n) {
				if (s[i] == '1') {
					nn1++;
					if (nn1 <= (n1 >> 1)) a[i] = b[i] = '(';
					else a[i] = b[i] = ')';
				}
				else {
					nn0++;
					if (nn0 & 1) a[i] = '(', b[i] = ')';
					else a[i] = ')', b[i] = '(';
				}
			}
			a[n + 1] = b[n + 1] = '\0';
			if (!check(a) || !check(b)) puts("NO");
			else {
				puts("YES");
				puts(a + 1), puts(b + 1);
			}
		}
	}
	return 0;
}