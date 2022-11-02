#include <cstdio>
#include <iostream>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define rep(s, p, x) for(p = s, x = lg[lowbit(s)];p;p ^= lowbit(p), x = lg[lowbit(p)])
// rep(s, p, x) : get "1" from s 
typedef pair<int, int> pii; 
const int INF = int(1E9);
int lg[1<<14], bts[1<<14];
int lowbit(int x) {
	return x & -x;
}
int G[14], n, m, t;
bool f[14][1<<14]; pii pre1[14][1<<14];
void get(const int a[], const int &n, const int &S) {
	int t = (1<<n);
	for(int i=0;i<n;i++)
		for(int s=0;s<t;s++)
			f[i][s] = false;
	int x, p, y, q;
	rep(S, p, x) f[x][1<<x] = true;
	for(int s=0;s<t;s++) {
		rep(s, p, x) {
			if( !f[x][s] ) continue;
			rep(a[x] & ((t - 1) ^ s), q, y)
				f[y][s|(1<<y)] = true, pre1[y][s|(1<<y)] = mp(x, s);
		}
	}
}// O(2^n * n)
int dp[1<<14], pre2[1<<14];
void update(int s1, int s2, int k) {
	if( dp[s1] > k ) dp[s1] = k, pre2[s1] = s2;
}
int a[14], b[14];
void print(int S) {
	if( bts[S] == 1 ) return ;
	int T = pre2[S], p, x;
	if( bts[S] - bts[T] == 1 ) {
		int q = lg[S^T], tot = 0;
		rep(G[q] & T, p, x) {
			printf("%d %d\n", q + 1, x + 1), tot++;
			if( tot == 2 ) break;
		}
	}
	else {
		int s1 = 0, s2 = 0, cnt = 0;
		rep((t-1)^T, p, x) b[cnt] = 0, a[cnt++] = x;
		for(int i=0;i<cnt;i++)
			for(int j=0;j<cnt;j++)
				if( (G[a[i]] >> a[j]) & 1 )
					b[i] |= (1<<j);
		rep(T, p, x) s1 |= G[x];
		for(int i=0;i<cnt;i++)
			if( (s1 >> a[i]) & 1 ) s2 |= (1<<i);
		get(b, cnt, s2);
		int s3 = 0;
		for(int i=0;i<cnt;i++)
			if( (S >> a[i]) & 1 ) s3 |= (1<<i);
		rep(s2 & s3, p, x) {
			if( f[x][s3] ) {
				printf("%d %d\n", lg[lowbit(T & G[a[x]])] + 1, a[x] + 1);
				pii p = mp(x, s3);
				while( (1<<p.fi) != p.se ) {
					pii q = pre1[p.fi][p.se];
					printf("%d %d\n", a[p.fi] + 1, a[q.fi] + 1);
					p = q;
				}
				printf("%d %d\n", a[p.fi] + 1, lg[lowbit(T & G[a[p.fi]])] + 1);
				break;
			}
		}
	}
	print(T);
}
int main() {
	scanf("%d%d", &n, &m), t = (1<<n);
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v), u--, v--;
		G[u] |= (1<<v), G[v] |= (1<<u);
	}
	for(int s=1;s<t;s++) dp[s] = INF, bts[s] = bts[s>>1] + (s & 1);
	for(int i=0;i<n;i++) lg[1<<i] = i, dp[1<<i] = 0;
	for(int s=1;s<t;s++) {
		if( dp[s] == INF ) continue;
		int p, x, s1 = 0, s2 = 0, cnt = 0;
		rep((t-1)^s, p, x) b[cnt] = 0, a[cnt++] = x;
		for(int i=0;i<cnt;i++)
			if( bts[s & G[a[i]]] > 1 )
				update(s|(1<<a[i]), s, dp[s] + 2);
		for(int i=0;i<cnt;i++)
			for(int j=0;j<cnt;j++)
				if( (G[a[i]] >> a[j]) & 1 )
					b[i] |= (1<<j);
		rep(s, p, x) s1 |= G[x];
		for(int i=0;i<cnt;i++)
			if( (s1 >> a[i]) & 1 ) s2 |= (1<<i);
		get(b, cnt, s2);
		int t3 = (1<<cnt);
		for(int s3=0;s3<t3;s3++) {
			if( bts[s3] < 2 ) continue;
			int s4 = 0;
			rep(s3, p, x) s4 |= (1<<a[x]);
			rep(s2 & s3, p, x) {
				if( f[x][s3] )
					update(s|s4, s, dp[s] + bts[s4] + 1);
			}
		}
	}
	printf("%d\n", dp[t-1]), print(t-1);
}