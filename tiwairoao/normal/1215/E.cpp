#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXM = 1<<20;
const int MAXN = 400000;
const ll INF = (1LL<<60);
int a[MAXN + 5], s[MAXN + 5], n;
ll f[20][20], g[20][MAXM], dp[MAXM];
int lowbit(int x) {
	return x & -x;
}
int lg[MAXM];
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &a[i]), a[i]--;
	for(int i=0;i<20;i++) {
		s[0] = 0;
		for(int j=1;j<=n;j++)
			s[j] = s[j-1] + (a[j] == i);
		for(int j=1;j<=n;j++)
			f[i][a[j]] += s[j];
	}
	for(int i=0;i<20;i++) lg[1<<i] = i;
	for(int i=0;i<20;i++) {
		g[i][0] = 0;
		for(int s=1;s<MAXM;s++)
			g[i][s] = g[i][s^lowbit(s)] + f[i][lg[lowbit(s)]];
	}
	for(int s=1;s<MAXM;s++) {
		int p = s; dp[s] = INF;
		while( p ) {
			dp[s] = min(dp[s], dp[s^lowbit(p)] + g[lg[lowbit(p)]][s^lowbit(p)]);
			p ^= lowbit(p);
		}
	}
	printf("%lld\n", dp[MAXM-1]);
}