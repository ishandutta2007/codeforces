#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
int dp[2][103][10009];
pii p[123];

int main() {
	int i, j, k, left;
	scanf("%d", &n);
	for(i = 0; i < n; i++) scanf("%d", &p[i].snd);
	for(i = 0; i < n; i++) scanf("%d", &p[i].fst);
	sort(p, p + n, greater<pii>());
	int all = 0;
	for(i = 0; i < n; i++) all += p[i].snd;
	int cur = 0;
	for(i = 0; cur < all; cur += p[i++].fst);
	int K = i;
	for(k = 0; k <= K; k++)
		for(left = 0; left <= all; left++)
			dp[n & 1][k][left] = 1e8;
	dp[n & 1][0][0] = 0;
	for(i = n - 1; i >= 0; i--)
		for(k = 0; k <= K; k++)
			for(left = 0; left <= all; left++) {
				dp[i & 1][k][left] = dp[!(i & 1)][k][left] + p[i].snd;
				if(k) dp[i & 1][k][left] = min(dp[i & 1][k][left], dp[!(i & 1)][k - 1][max(left - p[i].fst, 0)]);
			}
	printf("%d %d\n", K, dp[0][K][all]);
}