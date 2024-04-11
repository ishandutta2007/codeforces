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
#define maxm
#define maxs
#define maxb
#define M 
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

namespace Fast_Write{
    char _buffer[maxr << 1]; int bc = 0;
    void output_check(){
        if (bc > maxr) fwrite(_buffer, 1, bc, stdout), bc = 0;
    }
    void output_flush(){    
        fwrite(_buffer, 1, bc, stdout), bc = 0;
    }
    // Don't forget to flush _buffer at last!
    char tmp[128], ct = 0;
    template<class T> void write_signed(T x, char sep = '\n') {
        if (x < 0) _buffer[bc++] = '-', x = -x;
        if (x < 0) { // 'x' is still negative...
            // Very special case, 'x' is the lowest value of type 'T'
            ct = 0; while (x) tmp[ct++] = '0' - x % 10, x /= 10;
            per(i, ct - 1, 0) _buffer[bc++] = tmp[i];
            _buffer[bc++] = sep;
            output_check();
            return;
        }
        if (!x) _buffer[bc++] = '0';
        ct = 0; while (x) tmp[ct++] = '0' + x % 10, x /= 10;
        per(i, ct - 1, 0) _buffer[bc++] = tmp[i];
        _buffer[bc++] = sep;
        output_check();
    }
    template<class T, class... Args> void write_signed(T x, Args&... args){
        write_signed(x), write_signed(args...);
    }
    template<class T> void write_unsigned(T x, char sep = '\n'){  
        if (!x) _buffer[bc++] = '0';
        ct = 0; while (x) tmp[ct++] = '0' + x % 10, x /= 10;
        per(i, ct - 1, 0) _buffer[bc++] = tmp[i];
        _buffer[bc++] = sep;
        output_check();
    }
    template<class T, class... Args> void write_unsigned(T x, Args&... args){
        write_unsigned(x), write_unsigned(args...);
    }
    void write_string(int n, char* s, char sep = '\n'){
        srep(i, 0, n) _buffer[bc++] = s[i]; _buffer[bc++] = sep; output_check();
    }
    void write_char(char ch, char sep = '\n'){
        _buffer[bc++] = ch, _buffer[bc++] = sep; output_check();
    }
}using namespace Fast_Write;

#define maxn 2020
#define read read_unsigned
#define reads read_string
#define write write_signed

int n, q, num[maxn][2]; char s[maxn];
int main(){
	int T, x, y; read(T);
	while (T--){
		read(n, q);
		reads(s + 1); 
		rep(i, 1, n){
			num[i][0] = num[i - 1][0], num[i][1] = num[i - 1][1];
			num[i][s[i] - '0']++;
		}
		rep(i, 1, q) {
			read(x, y); 
			if (num[x - 1][s[x] - '0'] || (num[n][s[y] - '0'] > num[y][s[y] - '0'])) puts("YES");	
			else puts("NO");
		}
	}
	return 0;
}