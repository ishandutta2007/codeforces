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
#define maxn 6020
#define maxm
#define maxs
#define maxb 20
#define M 998244353
#define mo(x) (x = (x >= M) ? (x - M) : x)
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

int n, a[maxn];

namespace DP_Fast{
	int fac[maxn], ifac[maxn], inv[maxn];
	void init(){
		fac[0] = ifac[0] = inv[1] = 1;
		srep(i, 1, maxn) fac[i] = 1ll * fac[i - 1] * i % M;
		srep(i, 2, maxn) inv[i] = M - 1ll * M / i * inv[M % i] % M;
		srep(i, 1, maxn) ifac[i] = 1ll * ifac[i - 1] * inv[i] % M;
	}  
	int get(int l, int len){
		return 1ll * fac[l + len - 1] * ifac[l - 1] % M;
	}
	bool vis[maxn];
	int dp[maxn]; 
	int DP(int pos){
		if (!pos) return 1; if (vis[pos]) return dp[pos]; vis[pos] = 1;
		int& ans = dp[pos]; ans = 0;
		
		{
			int nxt = upper_bound(a + 1, a + 1 + n, a[pos] >> 1) - a - 1;
			ans += 1ll * DP(nxt) * get(n - pos, pos - nxt - 1) % M, mo(ans);
		}
		
		{
			ans += 1ll * DP(pos - 1) * (n - pos) % M, mo(ans);
		}
		
		return ans;
	}
	void play(){	
		init(); 
		if ((a[n - 1] << 1) > a[n]) {write(0); return;}
		write(DP_Fast :: DP(n - 1));
	}
} // Time Complexity: O(nlogn)

namespace DP_Slow{
	int dp[maxn][maxn];
	bool vis[maxn][maxn];
	int DP(int pos, int last){
		if (!pos) return 1;
		if (vis[pos][last]) return dp[pos][last];
		vis[pos][last] = 1;
		int& ans = dp[pos][last]; ans = 0;
		if ((a[pos] << 1) > a[last]) return ans = 1ll * DP(pos - 1, last) * (n - pos - 1) % M; 
		else {
			ans += 1ll * DP(pos - 1, last) * (n - pos) % M, mo(ans);
			ans += 1ll * DP(pos - 1, pos), mo(ans);
			return ans;
		}
	}
	void play(){ write(DP_Slow :: DP(n - 1, n)); }
} // Time Complexity: O(n^2)

int main(){
	read(n); rep(i, 1, n) read(a[i]);
	sort(a + 1, a + 1 + n);
	DP_Slow :: play(); 
	//DP_Fast :: play();
	return 0;
}