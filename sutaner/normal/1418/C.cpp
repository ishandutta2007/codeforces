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
#define maxn 400020
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
template <class T> void write(T x){	
	if (!x) {putchar('0'), putchar('\n'); return;}
	if (x < 0) putchar('-'), x = -x;
	int c = 0;
	while (x) _num[++c] = x % 10, x /= 10;
	while (c) putchar('0' + _num[c--]); 
	putchar('\n');
}

int n;
bool diff[maxn];
int idx;
int vis[maxn][2];
int dp[maxn][2];
int DP(int pos, int hand){ // 0 friend, 1 me
	if (pos > n) return 0;
	if (vis[pos][hand] == idx) return dp[pos][hand];
	vis[pos][hand] = idx;
	int& ans = dp[pos][hand]; ans = 0;
	if (hand) {
		return ans = min(DP(pos + 1, 0), DP(pos + 2, 0));
	}
	else {
		return ans = min(DP(pos + 1, 1) + diff[pos], DP(pos + 2, 1) + diff[pos] + diff[pos + 1]);
	} 
}

int main(){
	int T; read(T);
	while (T--){
		idx++;
		read(n);
		rep(i, 1, n) read(diff[i]); diff[n + 1] = 0;
		printf("%d\n", DP(1, 0));
	}
	return 0;
}