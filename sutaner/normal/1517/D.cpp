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

#define maxn 520
#define maxk 22
#define maxm
#define maxs
#define maxb
#define inf 2000000020
#define eps
#define M 
#define ll long long int 

int n, m;
int row[maxn][maxn], col[maxn][maxn];

/*
int dp[maxn][maxn][maxk];
int vis[maxn][maxn][maxk];
int idx = 0;
int sx, sy;

inline int dist(int x, int y) {
    if (x + 1 == sx && y == sy) return col[x][y];
    if (x - 1 == sx && y == sy) return col[x - 1][y];
    if (x == sx && y + 1 == sy) return row[x][y];
    if (x == sx && y - 1 == sy) return row[x][y - 1];
    return inf;
}

inline int manh(int x, int y) {
    return abs(x - sx) + abs(y - sy);
}



int DP(int x, int y, int k) {
    if (k == 1) return dist(x, y);
    if (manh(x, y) > k) return inf;
    if (vis[x][y][k] == idx) return dp[x][y][k];
    vis[x][y][k] = idx;
    int& ans = dp[x][y][k];
    ans = inf;
    
    if (x < n) ans = min(ans, DP(x + 1, y, k - 1) + col[x][y]);
    if (x > 1) ans = min(ans, DP(x - 1, y, k - 1) + col[x - 1][y]);
    if (y < m) ans = min(ans, DP(x, y + 1, k - 1) + row[x][y]);
    if (y > 1) ans = min(ans, DP(x, y - 1, k - 1) + row[x][y - 1]);
    return ans;
}
*/


int dp[maxn][maxn][maxk];
bool vis[maxn][maxn][maxk];
int DP(int x, int y, int k) {
    if (!k) return 0;
    if (vis[x][y][k]) return dp[x][y][k];
    int& ans = dp[x][y][k]; ans = inf;
    vis[x][y][k] = 1;
    
    if (x < n) ans = min(ans, DP(x + 1, y, k - 1) + col[x][y]);
    if (x > 1) ans = min(ans, DP(x - 1, y, k - 1) + col[x - 1][y]);
    if (y < m) ans = min(ans, DP(x, y + 1, k - 1) + row[x][y]);
    if (y > 1) ans = min(ans, DP(x, y - 1, k - 1) + row[x][y - 1]);
    
    return ans;
}

int k;
int main(){
    read(n, m, k);
    rep(i, 1, n) rep(j, 1, m - 1) read(row[i][j]);
    rep(i, 1, n - 1) rep(j, 1, m) read(col[i][j]);
    if (k & 1) {
        rep(i, 1, n) {rep(j, 1, m) printf("-1 "); printf("\n");}
        return 0;
    }
    rep(i, 1, n) {rep(j, 1, m) {
        //idx++;
        //sx = i, sy = j;
        printf("%d ", DP(i, j, k >> 1) << 1);
    }printf("\n");} 
	return 0;
}