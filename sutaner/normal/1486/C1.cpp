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

#define maxn
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define REST 40

int rest = REST, mx2p, n;
int query(int l, int r){
	rest--;
	cout << "? " << l << " " << r << endl;
	int res; cin >> res; return res;
}

#define go_left true
#define go_right false
bool judge(int x, bool pre){
	if (pre) {
		if (x > 1 && query(1, x) == mx2p) {
			return go_left;
		}
		else {
			return go_right;
		}
	}
	else {
		if (x < n && query(x, n) == mx2p) {
			return go_right;
		}
		else {
			return go_left;
		}
	}
}
void solve(int l, int r, bool pre){
	while (l != r) {
		if (pre) {
			int mid = ((r - l) >> 1) + l;
			bool res = judge(mid, pre);
			if (res == go_left) {
				r = mid;
			}
			else {
				l = mid + 1;
			}
		}
		else {	
			int mid = ((r - l + 1) >> 1) + l;
			bool res = judge(mid, pre);
			if (res == go_left) { 
				r = mid - 1;
			}
			else {
				l = mid;
			}
		}
	}
	cout << "! " << l << endl;
}
int main(){
	cin >> n;
	mx2p = query(1, n);
	if (mx2p > 1 && query(1, mx2p) == mx2p) {
		solve(1, mx2p, false);
	}
	else {
		solve(mx2p, n, true);
	}
	return 0;
}