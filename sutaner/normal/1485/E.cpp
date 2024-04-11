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

#define maxn 300020
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 
#define int ll 

struct edge{
	int next, to;
	edge(int next, int to) : next(next), to(to){}
	edge(){}
}e[maxn << 1];
int cnt = 1, h[maxn];
void Add_Edge(int x, int y) {
	e[++cnt] = edge(h[x], y);
	h[x] = cnt;
	e[++cnt] = edge(h[y], x);
	h[y] = cnt;
}
int n, a[maxn];

//vector<int> g[maxn], pre[maxn], suf[maxn];
vector<int> g[maxn];
int pred[maxn], sufd[maxn];
vector<pii> lis[maxn];
int d[maxn], mi[maxn], mx[maxn];
void dfs(int x, int fa){
	g[d[x]].pb(x);
	mx[d[x]] = max(mx[d[x]], a[x]);
	mi[d[x]] = min(mi[d[x]], a[x]);
	erep(i, x){
		int op = e[i].to;
		if (op == fa) continue;
		d[op] = d[x] + 1;
		dfs(op, x);
	}
}
extern int DP(int x);
int dp[maxn], vis[maxn], svis[maxn], idx;
void SDP(int d){
	if (svis[d] == idx) return;
	svis[d] = idx;
	for (auto it : g[d]) {
		lis[d].pb(pii(a[it] << 1, DP(it)));
	}
	sort(lis[d].begin(), lis[d].end());
	int si = lis[d].size();
	
	int& mx1 = pred[d]; mx1 = lis[d][0].se - (lis[d][0].fi >> 1);
	srep(i, 1, si) {
		mx1 = max(mx1, lis[d][i].se - (lis[d][i].fi >> 1));
	}
	
	int& mx2 = sufd[d]; mx2 = lis[d][0].se + (lis[d][0].fi >> 1);
	sper(i, si - 1, 0) {
		mx2 = max(mx2, lis[d][i].se + (lis[d][i].fi >> 1)); 
	}
	
	/*
	pre[d].resize(si);
	int now = -1000000009;
	srep(i, 0, si) {
		now = max(now, lis[d][i].se - (lis[d][i].fi >> 1));
		pre[d][i] = now;
	}
	suf[d].resize(si);
	now = -1;
	per(i, si - 1, 0) {
		now = max(now, lis[d][i].se + (lis[d][i].fi >> 1));
		suf[d][i] = now;
	}
	*/
}
int DP(int x){
	if (vis[x] == idx) return dp[x];
	vis[x] = idx;
	int& ans = dp[x]; ans = 0;
	int mii = 1000000009, mxx = -1;
	erep(i, x) {
		int op = e[i].to;
		if (d[op] == d[x] + 1) {
			ans = max(ans, DP(op) + max(abs(mx[d[op]] - a[op]), abs(mi[d[op]] - a[op])));
			mii = min(mii, a[op]);
			mxx = max(mxx, a[op]);
		}
	}
	if (mxx == -1) return ans;
	int dd = d[x] + 1;
	SDP(dd);
	//int mid = lower_bound(lis[dd].begin(), lis[dd].end(), pii(mxx + mii, -1)) - lis[dd].begin();
	//ans = max(ans, *(suf[dd].begin()) - mii);
	//ans = max(ans, *(--pre[dd].end()) + mxx);
	ans = max(ans, sufd[dd] - mii);
	ans = max(ans, pred[dd] + mxx);
	return ans;
}

void recover(){
	rep(i, 1, n) h[i] = 0; cnt = 1;
	rep(i, 0, n) g[i].clear(), lis[i].clear(); //suf[i].clear(), lis[i].clear();
}
signed main(){
	int T, x; read(T);
	while (T--){
		idx++;
		read(n);
		rep(i, 0, n) mx[i] = -1, mi[i] = 1000000009;
		rep(i, 2, n) read(x), Add_Edge(x, i);
		rep(i, 2, n) read(a[i]);
		dfs(1, -1);
		write(DP(1));
		recover();
	}
	return 0;
}