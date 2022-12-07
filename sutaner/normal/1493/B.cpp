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
    #define isletter(ch) (('0' <= ch && ch <= '9') || ch == ':')
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
#define inf 
#define eps
#define M 
#define ll long long int 

//bool ok[] = {1, 1, 1, 0, 0, 1, 0, 0, 1, 0};
int rev[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
int dep(int x) {
	int res = 0;
	rep(i, 0, 1){
		if (rev[x % 10] == -1) return -1;
		res = 10 * res + rev[x % 10];
		x /= 10;
	}
	return res;
}
bool judge(int h, int m, int x, int y) {
	int _x = dep(y), _y = dep(x);
	if (0 <= _x && _x < h && 0 <= _y && _y < m) return true;
	return false;
}
char s[20];
int h, m;
int main(){
	int T; read(T);
	while (T--){
		read(h, m); 
		reads(s);
		int x, y;
		x = 10 * (s[0] - '0') + (s[1] - '0');
		y = 10 * (s[3] - '0') + (s[4] - '0');
		while (1) {
			if (judge(h, m, x, y)) {
				printf("%d%d:%d%d\n", x / 10, x % 10, y / 10, y % 10);
				goto done;
			}
			y++;
			if (y == m) y = 0, x++;
			if (x == h) x = 0;
		}
		done:;
	}
	return 0;

}