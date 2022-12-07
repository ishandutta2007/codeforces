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
#define maxn 600020
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

#define inf 2000000020
int n, k, a[maxn], b[maxn];

int dp[maxn];
int solve(int l, int r) {
	int mi = a[l], mx = a[r]; 
	if (mi > mx) return -1;
	
	dp[0] = -inf; rep(i, 1, r - l + 5) dp[i] = inf;
	srep(i, l + 1, r) {
		if (mi <= a[i] && a[i] <= mx) *upper_bound(dp, dp + 6 + r - l, a[i]) = a[i]; 
	}
	rep(i, 0, r - l + 5) if (dp[i] == inf) return (r - l - 1 - (i - 1)); 
	return -1; 
}
int main(){
	read(n), read(k);
	a[0] = -inf; rep(i, 1, n) read(a[i]), a[i] += n - i; a[n + 1] = inf;
	rep(i, 1, k) read(b[i]); b[k + 1] = n + 1;
	int res = 0;
	rep(i, 1, k + 1) {
		int d = solve(b[i - 1], b[i]);
		//cerr << d << endl;
		if (d == -1) {
			puts("-1");
			return 0;
		}
		res += d;
	}
	write(res); 
	return 0;
}