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
#define maxn 300020
#define maxm
#define maxs w * maxn
#define maxb
#define M 
#define w 30
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

int ch[maxs][2], s[maxs], ct = 1;
void insert(int x){
	int now = 1;
	s[now]++;
	per(i, w - 1, 0) {
		int d = (x & (1 << i)) ? 1 : 0;
		if (!ch[now][d]) ch[now][d] = ++ct;
		now = ch[now][d];
		s[now]++;
	}
}
bool vis[maxs]; int dp[maxs];
int DP(int pos) {
	if (!pos) return 0;
	//if (vis[pos]) return dp[pos]; vis[pos] = 1; 
	int& ans = dp[pos]; ans = 0;
	return ans = min(DP(ch[pos][0]) + max(0, s[ch[pos][1]] - 1), DP(ch[pos][1]) + max(0, s[ch[pos][0]] - 1));
}
int n, a[maxn];
int main(){
	read(n); rep(i, 1, n) read(a[i]), insert(a[i]);
	printf("%d\n", DP(1)); 
	return 0;
}