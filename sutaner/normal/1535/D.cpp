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
    #define isletter(ch) (('0' <= ch && ch <= '1') || ch == '?')
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

#define maxn
#define maxm
#define maxs
#define maxb
#define maxk 20
#define inf 
#define eps
#define M 
#define ll long long int 

int k, m;
char s[1 << maxk];
int dp[1 << maxk];

int main(){
	read(k);
	reads(s + 1);
	read(m);
	int x; char ch[5];
	
	srep(i, (1 << (k - 1)), 1 << k) {
		if (s[(1 << k) - i] == '?') dp[i] = 2;
		else dp[i] = 1;
	}
	per(i, (1 << (k - 1)) - 1, 1) {
		if (s[(1 << k) - i] == '0') {
			dp[i] = dp[i << 1 | 1];
		}
		else if (s[(1 << k) - i] == '1'){
			dp[i] = dp[i << 1];
		}
		else {
			dp[i] = dp[i << 1] + dp[i << 1 | 1];
		}
	}
	rep(i, 1, m) {
		read(x); reads(ch);
		s[x] = ch[0];
		int id = (1 << k) - x;
		
		if (id >= (1 << (k - 1))) {
			if (ch[0] == '?') dp[id] = 2;
			else dp[id] = 1;
		}
		else {
			if (ch[0] == '0') {
				dp[id] = dp[id << 1 | 1];
			}
			else if (ch[0] == '1'){
				dp[id] = dp[id << 1];
			}
			else {
				dp[id] = dp[id << 1] + dp[id << 1 | 1];
			}
		}
		
		while (id > 1) {
			int f = id >> 1;
			
			if (s[(1 << k) - f] == '0') {
				dp[f] = dp[f << 1 | 1];
			}
			else if (s[(1 << k) - f] == '1') {
				dp[f] = dp[f << 1];
			}
			else {
				dp[f] = dp[f << 1] + dp[f << 1 | 1];
			}
			id = f;
		}
		
		printf("%d\n", dp[1]);
	}
	return 0;
}