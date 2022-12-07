#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next) 
#define pii pair<int, int>
#define pdp pair<dis, pii>
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
#define maxm
#define maxs
#define maxb 30
#define inf 2000000020
#define eps
#define M 998244353
#define ll long long int 

int power(int x, int y) {
	int ans = 1, con = x;
	while (y){
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}

int n, m;
struct edge{
	int next, to, len;
	edge(int next, int to, int len) : next(next), to(to), len(len){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y, int z) {
	e[++cnt] = edge(h[x], y, z);
	h[x] = cnt; 
	e[++cnt] = edge(h[y], x, z);
	h[y] = cnt;
}

bool vis[maxb + 1][maxn << 1];


struct dis{
	int k, x;
	dis(int k, int x) : k(k), x(x){}
	dis(){}
	bool operator < (const dis b) const{
		if (b.k == k) return x < b.x;
		else {
			bool rev = 0;
			int k1, k2, x1, x2;
			k1 = k, k2 = b.k, x1 = x, x2 = b.x;
			if (k1 > k2) rev = 1, swap(k1, k2), swap(x1, x2);
			if (k2 >= 31) return true ^ rev;
			int sum = 0;
			rep(i, k1 + 1, k2) sum += (1 << (i - 1)); 
			if (x1 < sum + x2) return true ^ rev;
			else if (x1 > sum + x2) return false ^ rev;
			else return false;
		}
	}
}d[maxb + 1][maxn << 1];
set<pdp> pq;
void Dij(int S){
	rep(i, 0, maxb) rep(j, 1, n << 1) d[i][j] = dis(inf, inf);
	d[0][S] = dis(0, 0);
	
	pq.insert(pdp(d[0][S], pii(0, S)));
	while (!pq.empty()){
		pii x = pq.begin() -> se; pq.erase(pq.begin()); if (vis[x.fi][x.se]) continue;
		vis[x.fi][x.se] = 1;
		bool rev = d[x.fi][x.se].k & 1;
		erep(i, (x.se > n) ? x.se - n : x.se){ 
			int op = e[i].to;
			dis _d = d[x.fi][x.se];
			int add = 0;
			if ((i & 1) ^ rev) _d.k++, add = 1;
			_d.x++;  
			int nxt = min(maxb, x.fi + add);
			if (nxt == maxb && (_d.k & 1)) op += n;
			if (vis[nxt][op]) continue;
			if (_d < d[nxt][op]) d[nxt][op] = _d, pq.insert(pdp(_d, pii(nxt, op)));
		}
	}
	dis ans = d[maxb][n << 1];
	rep(i, 0, maxb) {
		ans = min(ans, d[i][n]);
		/*
		if (d[i][n].fi == inf) continue;
		int res = d[i][n].se;
		rep(i, 1, d[i][n].fi) {
			res += power(2, i - 1);
			res %= M;
		}
		ans = (ans == -1) ? res : 
		*/
	}
	int res = ans.x;
	rep(i, 1, ans.k) {
		res += power(2, i - 1);
		res %= M;
	}
	write(res);
	/*
	rep(i, 1, n << 1) d[i] = dis(inf, inf);
	d[S] = dis(0, 0), pq.insert(pii(d[S], S));
	while (!pq.empty()){
		int x = pq.begin() -> se; pq.erase(pq.begin()); if (vis[x]) continue;
		vis[x] = 1;
		bool rev = x > n ? 1 : 0, _rev = rev;
		erep(i, ((x > n) ? (x - n) : x)){
			if (vis[e[i].to]) continue;
			int op = e[i].to;
			dis _d = d[x];
			if ((i & 1) ^ rev) _d.k++, _rev = rev ^ 1;
			_d.x++; 
			if (_rev) op += n;
			if (_d < d[op]) d[op] = _d, pq.insert(pii(d[op], op));
		}
	}
	dis mi = min(d[n], d[n << 1]);
	int res = mi.x;
	rep(i, 1, mi.k) {
		res += power(2, i - 1);
		res %= M;
	}
	write(res);
	*/
}

int main(){
	read(n, m);
	int x, y;
	rep(i, 1, m) {
		read(x, y);
		Add_Edge(x, y, 1);
	}
	Dij(1);
	return 0;
}