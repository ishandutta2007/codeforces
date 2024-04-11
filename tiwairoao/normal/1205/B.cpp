#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 300;
int G[MAXN + 5][MAXN + 5], A[MAXN + 5][MAXN + 5];
ll a[MAXN + 5];
int n, cnt;
int main() {
	scanf("%d", &n);
	for(int i=1;i<=n;i++) {
		ll x; scanf("%lld", &x);
		if( x ) a[++cnt] = x;
		if( cnt > MAXN ) {
			puts("3");
			return 0;
		}
	}
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			if( a[i] & a[j] ) A[i][j] = G[i][j] = 1;
			else A[i][j] = G[i][j] = MAXN + 5;
	int ans = MAXN + 5;
	for(int k=1;k<=cnt;k++) {
		for(int i=1;i<k;i++)
			for(int j=i+1;j<k;j++)
				ans = min(ans, A[i][k] + A[k][j] + G[i][j]);
		for(int i=1;i<=cnt;i++)
			for(int j=1;j<=cnt;j++)
				G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
	}
	if( ans == MAXN + 5 ) puts("-1");
	else printf("%d\n", ans);
}