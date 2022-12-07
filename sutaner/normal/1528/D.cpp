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

#define maxn 620
#define maxm
#define maxs
#define maxb 
#define eps
#define M 
#define ll long long int 
#define inf 2000000020

int n, m;
int a[maxn * maxn], b[maxn * maxn], c[maxn * maxn];
vector<pii> can[maxn];

int d[maxn], res[maxn][maxn], tmp[maxn];
bool vis[maxn];
int main(){
	read(n, m);
	rep(i, 1, m) read(a[i], b[i], c[i]), can[a[i]].pb(pii(b[i], c[i]));
	srep(s, 0, n) {
		srep(j, 0, n) vis[j] = 0, d[j] = inf; d[s] = 0;
		int TT = n;
		while (TT--){
			int x = -1, now = inf;
			srep(i, 0, n) {
				tmp[i] = inf;
				if (vis[i]) continue;
				if (d[i] < now) x = i, now = d[i];  
			}
			vis[x] = 1;
			for (auto it: can[x]) {
				int p = ((ll)it.fi + now) % n;
				if (!p) {
					tmp[p] = min((ll)tmp[p], (ll)now + it.se);
				}
				else {	
					tmp[p] = min((ll)tmp[p], (ll)now + it.se);
					tmp[0] = min((ll)tmp[0], (ll)n - p + now + it.se);
				}
			}
			int st = inf, pst = -1;
			srep(i, 0, n) if (tmp[i] < st) pst = i, st = tmp[i]; 
			//assert(st < inf);
			
			d[pst] = min(d[pst], st);
			srep(i, pst + 1, n) {
				st = tmp[i] = min(tmp[i], st + 1); 
				d[i] = min(d[i], st);
			}
			srep(i, 0, pst){
				st = tmp[i] = min(tmp[i], st + 1); 
				d[i] = min(d[i], st);
			}
		}
		srep(j, 0, n) res[s][j] = d[j];
		//srep(j, 0, n) printf("%d ", vis[j]); printf("\n");
	}
	srep(i, 0, n) {srep(j, 0, n) printf("%d ", res[i][j]); printf("\n");}
	return 0;
}