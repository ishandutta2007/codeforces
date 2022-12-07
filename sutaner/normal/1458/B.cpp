#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define erep2(i, x) for (register int& i = cur[x]; i; i = e[i].next) 
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

#define read read_unsigned
#define reads read_string 
#define writes puts

#define maxn 102
#define maxm
#define maxs
#define maxb
#define eps
#define M 
#define ll long long int 

/*
struct pii{
	int fi, se, id;
	pii(int fi, int se, int id) : fi(fi), se(se), id(id){}
	pii(){}
};
bool cmp1(pii a, pii b){	
	return (a.fi == b.fi) ? a.se < b.se : a.fi < b.fi;
}
bool cmp2(pii a, pii b){	
	return (a.se == b.se) ? a.fi < b.fi : a.se < b.se;
}
*/
struct pii{
	int fi, se, id;
	pii(int fi, int se, int id) : fi(fi), se(se), id(id){}
	pii(){}
};
int n; pii lis1[maxn], lis2[maxn], bot[maxn]; bool ok[maxn];
/*
int dp[maxn][maxn][maxn * maxn];
int DP(int pos, int rest, int capa){
	if (pos == n + 1) return 0;
	if (vis[pos][rest]) return dp[pos][rest][capa];
	vis[pos][rest] = 1;
	int& ans = dp[pos][rest];
	
}
*/
#define inf 2000000000
int dp[maxn][maxn][maxn * maxn], ans[maxn];
void DP(){
	int maxc = 0; rep(i, 1, n) maxc += bot[i].fi; 
	rep(i, 0, 0) {
		rep(j, 0, n) {
			rep(k, 0, maxc) {
				dp[i][j][k] = -inf;
			}
		}
	}
	dp[0][0][0] = 0;
	rep(i, 1, n) {
		rep(j, 0, n) {
			rep(k, 0, maxc) {
				dp[i][j][k] = -inf;
				if (j) {
					if (k >= bot[i].fi && dp[i - 1][j - 1][k - bot[i].fi] != -inf) dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][k - bot[i].fi] + 2 * bot[i].se);
				}
				if (dp[i - 1][j][k] != -inf)  dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][k] + bot[i].se);
				if (i == n && dp[i][j][k] != -inf) dp[i][j][k] = min(dp[i][j][k], k << 1), ans[j] = max(ans[j], dp[i][j][k]);
			}
		}
	}
	rep(i, 1, n) printf("%.10lf ", ans[i] / 2.0);
}
int main(){
	int x, y;
	read(n); rep(i, 1, n) read(x, y), lis1[i] = lis2[i] = bot[i] = pii(x, y, i);
	DP();
	/*
	sort(lis1 + 1, lis1 + 1 + n, cmp1); //  capa
	sort(lis2 + 1, lis2 + 1 + n, cmp2); //  now  
	rep(k, 1, n) {
		int res = 0;
		rep(i, 0, k) {
			rep(j, 1, n) ok[j] = 0;
			rep(j, 1, i) ok[lis1[n + 1 - j].id] = 1;
			int rest = k - i;
			per(j, n, 1){
				if (!rest) break;
				if (ok[lis2[j].id]) continue;
				rest--, ok[lis2[j].id] = 1;
			}
			int sum = 0, capa = 0;
			rep(j, 1, n) {
				if (ok[j]) sum += 2 * bot[j].se, capa += 2 * bot[j].fi;
				else sum += bot[j].se;
			}
			res = max(res, min(sum, capa));
		} 
		printf("%.10lf ", res / 2.0);
	} 
	*/
	return 0;
}