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
    #define isletter(ch) ('0' == ch || '1' == ch || '?' == ch)
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

#define read read_unsigned
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

char s[maxn]; int x, y, n;
int main(){
	reads(s); read(x, y);
	n = strlen(s);
	ll res = 0, ans = 0;

	int num0 = 0, num1 = 0;
	srep(i, 0, n) {
		if (s[i] == '1') num1++;
		else num0++;
	}
	int now0 = 0, now1 = 0;
	srep(i, 0, n) {
		if (s[i] == '1') {
			ans += 1ll * now0 * x;
			now1++;
		}
		else {
			ans += 1ll * now1 * y;
			now0++;
		}
	}
	res = ans; now0 = 0, now1 = 0;
	srep(i, 0, n) {
		if (s[i] == '?') {
			ans -= 1ll * now1 * y + 1ll * (num1 - now1) * x;
			num1++;
			num0--;
			ans += 1ll * now0 * x + 1ll * (num0 - now0) * y;
			res = min(res, ans);
			now1++; 
		}
		else if (s[i] == '0') now0++;
		else if (s[i] == '1') now1++;
	}
	
	ans = 0, num0 = 0, num1 = 0;
	srep(i, 0, n) {
		if (s[i] == '0') num0++;
		else num1++;
	}
	now0 = 0, now1 = 0;
	srep(i, 0, n) {
		if (s[i] == '0') { 
			ans += 1ll * now1 * y;
			now0++;
		}
		else {
			ans += 1ll * now0 * x;
			now1++;
		}
	}
	res = min(res, ans); now0 = 0, now1 = 0;
	srep(i, 0, n) {
		if (s[i] == '?') { 
			ans -= 1ll * now0 * x + 1ll * (num0 - now0) * y;
			num0++;
			num1--;
			ans += 1ll * now1 * y + 1ll * (num1 - now1) * x;
			res = min(res, ans);
			now0++;  
		}
		else if (s[i] == '0') now0++;
		else if (s[i] == '1') now1++;
	}

	write(res);
	return 0;
}