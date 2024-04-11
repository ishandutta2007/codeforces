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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 200020
#define maxm
#define maxs
#define maxb
#define M 

int xorp[maxn];
int main(){
	int n; cin >> n;
	rep(i, 2, n) {
		cout << "XOR " << 1 << ' ' << i << endl;
		cin >> xorp[i];
		if (xorp[i] == -1) assert(false);
	}
	int res12, res13, res23;
	cout << "AND " << 1 << ' ' << 2 << endl;
	cin >> res12;
	cout << "AND " << 1 << ' ' << 3 << endl;
	cin >> res13;
	cout << "AND " << 2 << ' ' << 3 << endl;
	cin >> res23;
	
	int _n = n, s = 0, real = 0;
	while (_n) s++, _n >>= 1; s--;
	srep(i, 0, s) {
		if ((res12 & (1 << i)) || (res13 & (1 << i))) {
			real |= (1 << i);
			continue;
		}
		if (!(xorp[2] & (1 << i)) || !(xorp[3] & (1 << i))) {
			continue;
		}
		if (res23 & (1 << i)) {
			continue;
		}
		else {
			real |= (1 << i);
			continue;
		}
	}
	cout << "! " << real << ' '; 
	rep(i, 2, n) cout << (real ^ xorp[i]) << ' ';  cout << endl;
	return 0;
}