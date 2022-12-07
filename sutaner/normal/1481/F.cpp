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

#define maxn 100020
#define maxm 
#define maxb
#define inf 
#define eps
#define M 
#define ll long long int 

int n, fa[maxn], a;
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
int d[maxn], dnum[maxn], fre[maxn], lis[maxn], cs = 0, mxd = 0;
vector<int> leaf[maxn], nonleaf[maxn];
void dfs(int x) {
	bool isleaf = true;
	erep(i, x) {
		int op = e[i].to;
		if (op == fa[x]) continue;
		isleaf = false;
		d[op] = d[x] + 1;
		dfs(op);
	}
	if (isleaf) leaf[d[x]].pb(x);
	else nonleaf[d[x]].pb(x);
}
#define maxs 450
bool dp[maxs][maxn];
int mit[maxs][maxn];
int need[maxn];
void solve(){
	per(pos, cs + 1, 1){
		rep(rest, 0, a) mit[pos][rest] = -1;
		rep(rest, 0, a) {	
			if (pos == cs + 1) {
				if (!rest) mit[pos][rest] = 0;
				continue;
			}
			if (mit[pos + 1][rest] != -1) { mit[pos][rest] = 0; continue; }
			if (rest >= lis[pos]) {
				mit[pos][rest] = mit[pos][rest - lis[pos]] == -1 ? -1 : mit[pos][rest - lis[pos]] + 1;
				if (mit[pos][rest] > fre[pos]) mit[pos][rest] = -1; 
			} 
		}
	}
	int now = a;
	if (mit[1][a] != -1) {
		cerr << cs << endl;
		rep(pos, 1, cs) {
			need[lis[pos]] = mit[pos][now];
			assert(need[lis[pos]] != -1);
			now -= need[lis[pos]] * lis[pos];
			cerr << lis[pos] << ' ' << need[lis[pos]] << endl;
		} 
	}
}

char res[maxn];
int main(){
	read(n, a); rep(i, 2, n) read(fa[i]), Add_Edge(i, fa[i]);
	dfs(1);
	rep(i, 1, n) dnum[d[i]]++, mxd = max(mxd, d[i]); 
	rep(i, 0, mxd) lis[++cs] = dnum[i];
	sort(lis + 1, lis + 1 + cs);
	cs = unique(lis + 1, lis + 1 + cs) - lis - 1;
	rep(i, 0, mxd) {
		fre[lower_bound(lis + 1, lis + 1 + cs, dnum[i]) - lis]++; 
	}
	solve();
	cerr << mit[1][a] << endl;
	write(mit[1][a] != -1 ? mxd + 1 : mxd + 2);
	if (mit[1][a] != -1) {
		//if (n == 500 && a == 489) cout << "I" << endl;
		rep(i, 0, mxd) {
			if (need[dnum[i]]) need[dnum[i]]--, res[i] = 'a';
			else res[i] = 'b'; 
			cerr << dnum[i] << ' ' << res[i] << endl;
		}
		rep(i, 1, n) printf("%c", res[d[i]]); 
		return 0;
	}
	else {
		//if (n == 500 && a == 489) cout << "II" << endl;
		int resta = a, restb = n - a;
		rep(i, 0, mxd) {
			if (resta >= dnum[i]) {
				for (auto it: leaf[i]) {
					res[it] = 'a';
				}
				for (auto it: nonleaf[i]) {
					res[it] = 'a';
				}
				resta -= dnum[i];
			}
			else if (restb >= dnum[i]) {
				for (auto it: leaf[i]) {
					res[it] = 'b';
				}
				for (auto it: nonleaf[i]) {
					res[it] = 'b';
				}
				restb -= dnum[i];
			}
			else if (resta >= nonleaf[i].size()) {
				for (auto it: nonleaf[i]) {
					res[it] = 'a';
				}
				resta -= nonleaf[i].size();
				for (auto it: leaf[i]) {
					if (resta) res[it] = 'a', resta--;
					else res[it] = 'b', restb--;
				}
			}
			else { 
				for (auto it: nonleaf[i]) {
					res[it] = 'b';
				}
				restb -= nonleaf[i].size();
				for (auto it: leaf[i]) {
					if (restb) res[it] = 'b', restb--;
					else res[it] = 'a', resta--;
				}
			} 
		} 
		rep(i, 1, n) printf("%c", res[i]);
		return 0;
	}
	return 0;
}