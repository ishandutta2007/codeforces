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

#define maxn 420
#define maxm
#define maxs
#define maxb
#define inf 
#define eps
#define M 998244353
#define ll long long int 

int power(int x, int y) {
	int ans = 1, con = x;
	while (y) {	
		if (y & 1) ans = 1ll * ans * con % M;
		con = 1ll * con * con % M;
		y >>= 1;
	}
	return ans;
}
int cal(int n) {
	return 26ll * 26ll * power(25, n - 2) % M;
}

int n;
#define mo(x) (x = (x >= M) ? (x - M) : x)
namespace N1{
int dp[maxn][maxn][4];
bool vis[maxn][maxn][4];
int DDP(int pos, int rest, int last){
	if (pos == n + 1) return !rest;
	if (vis[pos][rest][last]) return dp[pos][rest][last];
	vis[pos][rest][last] = 1;
	int& ans = dp[pos][rest][last];
	ans = 0;
	if (pos <= 2) {
		ans += 25ll * DDP(pos + 1, rest, last >> 1) % M;
		mo(ans);
		ans += DDP(pos + 1, max(rest - 1, 0), (last >> 1) + 2);
		mo(ans);
	}
	else {
		if (last & 1) {
			ans = 25ll * DDP(pos + 1, rest, last >> 1) % M;
		}
		else {
			ans += DDP(pos + 1, max(rest - 1, 0), (last >> 1) + 2);
			mo(ans);
			ans += 24ll * DDP(pos + 1, rest, last >> 1) % M;
			mo(ans);
		}
	}
	return ans;
}
}

namespace N2{
/*
int dp[maxn][maxn][maxn][9];
bool vis[maxn][maxn][maxn][9];
int DP(int pos, int rest, int rest2, int last) {	
	if (pos == n + 1) return !rest && !rest2;
	if (vis[pos][rest][rest2][last]) return dp[pos][rest][rest2][last];
	vis[pos][rest][rest2][last] = 1;
	int& ans = dp[pos][rest][rest2][last];
	ans = 0;
	if (pos <= 2) {
		ans += 24ll * DP(pos + 1, rest, rest2, last / 3) % M;
		mo(ans);
		ans += DP(pos + 1, max(rest - 1, 0), rest2, last / 3 + 3);
		mo(ans);
		ans += DP(pos + 1, rest, max(rest2 - 1, 0), last / 3 + 6);
		mo(ans);
	}
	else {
		if (last % 3 == 1) {
			ans += 24ll * DP(pos + 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(pos + 1, rest, max(rest2 - 1, 0), last / 3 + 6) % M;
			mo(ans);
		}
		else if (last % 3 == 2) {
			ans += 24ll * DP(pos + 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(pos + 1, max(rest - 1, 0), rest2, last / 3 + 3) % M;
			mo(ans); 
		}
		else {
			ans += 23ll * DP(pos + 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(pos + 1, rest, max(rest2 - 1, 0), last / 3 + 6) % M;
			mo(ans); 
			ans += DP(pos + 1, max(rest - 1, 0), rest2, last / 3 + 3) % M;
			mo(ans); 
		}
	}
	return ans;
}
*/
int dp[2][maxn][maxn][9];
#define DP(pos, rest, rest2, last) dp[pos][rest][rest2][last]
int solve(){
	int d = 0;
	per(pos, n + 1, 1) {
		d ^= 1;
		rep(rest, 0, n) {
			rep(rest2, 0, n) {
				srep(last, 0, 9) {
	int& ans = dp[d][rest][rest2][last];
	if (pos == n + 1) {ans = !rest && !rest2; continue;}
	//if (vis[pos][rest][rest2][last]) return dp[pos][rest][rest2][last];
	//vis[pos][rest][rest2][last] = 1;
	//int& ans = dp[pos][rest][rest2][last];
	ans = 0;
	if (pos <= 2) {
		ans += 24ll * DP(d ^ 1, rest, rest2, last / 3) % M;
		mo(ans);
		ans += DP(d ^ 1, max(rest - 1, 0), rest2, last / 3 + 3);
		mo(ans);
		ans += DP(d ^ 1, rest, max(rest2 - 1, 0), last / 3 + 6);
		mo(ans);
	}
	else {
		if (last % 3 == 1) {
			ans += 24ll * DP(d ^ 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(d ^ 1, rest, max(rest2 - 1, 0), last / 3 + 6) % M;
			mo(ans);
		}
		else if (last % 3 == 2) {
			ans += 24ll * DP(d ^ 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(d ^ 1, max(rest - 1, 0), rest2, last / 3 + 3) % M;
			mo(ans); 
		}
		else {
			ans += 23ll * DP(d ^ 1, rest, rest2, last / 3) % M;
			mo(ans);
			ans += DP(d ^ 1, rest, max(rest2 - 1, 0), last / 3 + 6) % M;
			mo(ans); 
			ans += DP(d ^ 1, max(rest - 1, 0), rest2, last / 3 + 3) % M;
			mo(ans); 
		}
	}
	//return ans;
				}
			}
		}
	}
	return d;
}
}
int num[30];
int main(){
	read(n); rep(i, 0, 25) read(num[i]);
	int res = cal(n);
	rep(i, 0, 25) {
		res += M - N1 :: DDP(1, num[i] + 1, 0);
		mo(res);
	}
	int d = N2 :: solve();
	rep(i, 0, 25) rep(j, i + 1, 25) {
		res += N2 :: DP(d, num[i] + 1, num[j] + 1, 0);
		mo(res);
	}
	write(res);
	return 0; 
}