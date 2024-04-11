#include <bits/stdc++.h>

#define int ll

typedef long long ll;

const int N = 1000000;
const ll INF = (1ll << 60);

ll dp[2][N + 5];

void trans(int x, ll s) {
	for(int i=x;i<N;i++) dp[0][i] = std::max(dp[0][i], dp[1][i - x] + s);
}
void trans2(int p, int x, ll s) {
	for(int i=0;i<x;i++) {
		std::list<std::pair<ll, int> >que;
		for(int j=i,k=0;j<N;j+=x,k++) {
			while( !que.empty() && dp[1][j] - 1ll * k * s >= que.back().first ) que.pop_back();
			que.push_back(std::make_pair(dp[1][j] - 1ll * k * s, k));
			
			while( !que.empty() && k - que.front().second > p ) que.pop_front();
			dp[0][j] = std::max(dp[0][j], que.front().first + 1ll * k * s);
		}
	}
}

signed main() {
	int k, q; scanf("%lld", &k);
	for(int i=1;i<N;i++) dp[0][i] = -INF;
	for(int tme=0,p=1,x;tme<6;tme++,p=10*p) {
		scanf("%lld", &x);
		for(int i=0;i<N;i++) dp[1][i] = dp[0][i], dp[0][i] = -INF;
		for(int i=0;i<=9;i++) if( 1ll * (9 * k - i) * p < N )
			trans((9 * k - i) * p, 3ll * (k - 1) * x + (i % 3 == 0 ? (3 - i / 3) * x : 0));
		for(int i=N-1;i>=0;i--) {
			if( i >= p ) dp[1][i] = std::max(dp[1][i], dp[1][i - p]);
			if( i >= 2 * p ) dp[1][i] = std::max(dp[1][i], dp[1][i - 2 * p]);
		}
		trans2(3 * (k - 1), 3 * p, x);
	}
	
	scanf("%lld", &q); for(int i=1,x;i<=q;i++) scanf("%lld", &x), printf("%lld\n", dp[0][x]);
}