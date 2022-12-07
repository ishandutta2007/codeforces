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

#define maxn 400020
#define maxN 5
#define maxm
#define maxs
#define maxb
#define inf 1000000000
#define eps
#define M 
#define ll long long int 

int n[maxN];
int a[maxN][maxn];
pii b[maxN][maxn];
int pos[maxN][maxn];
int m[maxN];
pii rel[maxN];
vector<int> up[maxn], down[maxn], mid[maxn];

int upc[maxn], downc[maxn], upp[maxn], downp[maxn];
pii upd[maxn], downd[maxn];

void readd(int nn, vector<int>* lis, bool op){
	int x, y, z;
	read(z);
	rep(i, 1, z){ 
		read(x, y);
		if (op) lis[y].pb(x);
		else lis[x].pb(y);
	}
	//rep(i, 1, nn) sort(lis[i].begin(), lis[i].end());
}
int main(){
	rep(i, 1, 4) read(n[i]);
	rep(i, 1, 4) {
		rep(j, 1, n[i]) read(a[i][j]), b[i][j] = pii(a[i][j], j);
		sort(b[i] + 1, b[i] + 1 + n[i]);
		rep(j, 1, n[i]) pos[i][b[i][j].se] = j;
	} 
	readd(n[2], up, 1);
	readd(n[2], mid, 0);
	readd(n[3], down, 0);
	 
	rep(i, 1, n[2]) { 
		for (auto& it: up[i]) {
			it = pos[1][it];
		}
		sort(up[i].begin(), up[i].end());
		int ptr = 1;
		//upc[i] = -1;
		for (auto it : up[i]) {
			if (it != ptr) {
				break;
			}
			ptr++;
		}
		if (ptr <= n[1]) upc[i] = a[2][i] + b[1][ptr].fi;
		else upc[i] = inf;
	}
	
	
	rep(i, 1, n[3]) { 
		for (auto& it: down[i]) {
			it = pos[4][it];
		}
		sort(down[i].begin(), down[i].end());
		int ptr = 1;
		//downc[i] = -1;
		for (auto it : down[i]) {
			if (it != ptr) {
				break;
			}
			ptr++;
		}
		if (ptr <= n[4]) downc[i] = a[3][i] + b[4][ptr].fi;
		else downc[i] = inf;
	}
	
	rep(i, 1, n[2]) upd[i] = pii(upc[i], i); sort(upd + 1, upd + 1 + n[2]); rep(i, 1, n[2]) upp[upd[i].se] = i;
	rep(i, 1, n[3]) downd[i] = pii(downc[i], i); sort(downd + 1, downd + 1 + n[3]); rep(i, 1, n[3]) downp[downd[i].se] = i;
	
	int res = inf;
	rep(i, 1, n[2]) {
		for (auto& it: mid[i]) {
			it = downp[it];
		}
		sort(mid[i].begin(), mid[i].end());
		int ptr = 1;
		//downc[i] = -1;
		for (auto it : mid[i]) {
			if (it != ptr) {
				break;
			}
			ptr++;
		}
		if (ptr <= n[3]) res = min(res, upc[i] + downd[ptr].fi);
		else downc[i] = inf;
	}
	
	write(res == inf ? -1 : res);
	return 0;
}