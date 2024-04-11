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

#define maxn 20022
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int fib[maxn];
ll pre[maxn];

int n;
multiset<int> s;

int main(){
    fib[0] = fib[1] = 1;
    pre[0] = 1, pre[1] = 2;
    srep(i, 2, maxn) {
        fib[i] = fib[i - 1] + fib[i - 2];
        pre[i] = pre[i - 1] + fib[i];
        if (fib[i] > 1000000000) {
            //cerr << '$' << i << endl;
            //cerr << '$' << fib[i] << endl;
            break;
        }
    }
    const int maxa = 44;
    
    
    int T, x; read(T);
    while (T--) {
        ll sum = 0;
        read(n);
        rep(i, 1, n) read(x), s.insert(x), sum += x;
        int st = -1;
        srep(i, 0, maxa) {
            if (pre[i] == sum) {
                st = i;
                break;
            }
        }
        int last = 0;
        if (st == -1) {
            puts("NO");
            goto done;
        }
        per(i, st, 0) {
            if (s.empty()) {
                puts("NO");
                goto done;
            }
            int k = *(--s.end());
            s.erase(s.lower_bound(k));
            if (k < fib[i]) {
                puts("NO");
                goto done;
            }
            k -= fib[i];
            if (last != 0) s.insert(last);
            last = k;
        }
        puts("YES");
        done: s.clear();
    }
    
	return 0;
}