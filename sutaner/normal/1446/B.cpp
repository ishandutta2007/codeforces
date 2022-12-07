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
#define maxn 5020
#define maxm
#define maxs
#define maxb
#define M 
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char buffer[maxr], *p1, *p2;
template <class T> void read(T& x){
	char ch = gc(); x = 0; bool f = 1;
	while (!('0' <= ch && ch <= '9') && ch != '-') ch = gc();
	if (ch == '-') f = 0, ch = gc();
	while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
	x = (f) ? x : -x;
}
int _num[20];
template <class T> void write(T x, char sep = '\n'){	
	if (!x) {putchar('0'), putchar(sep); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar(sep);
}

int n, m; char s[maxn], t[maxn];

bool vis[maxn][maxn];
int dp[maxn][maxn];
int DP(int pa, int pb){
	if (pa == n + 1 || pb == m + 1) return 0;
	if (vis[pa][pb]) return dp[pa][pb];
	vis[pa][pb] = 1; int& ans = dp[pa][pb]; ans = 0;
	if (s[pa] == t[pb]) ans = max(ans, DP(pa + 1, pb + 1) + 2); 
	else ans = max(ans, DP(pa + 1, pb) - 1), ans = max(ans, DP(pa, pb + 1) - 1);
	return ans;
}
int main(){
	scanf("%d%d", &n, &m);
	scanf("%s%s", s + 1, t + 1);
	int res = 0;
	rep(i, 1, n) rep(j, 1, m) res = max(res, DP(i, j));
	printf("%d", res);
	return 0;
}