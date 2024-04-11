#include<bits/stdc++.h>
using namespace std;
const int MASK(65536), N(16);
int inf(1e9);
int r[N], b[N];
char tp[N];
int dp[MASK][121], cntr[MASK], cntb[MASK];
__inline renew(int & a, int b) {
	a = max(a, b);
}
int main() {
	int n;
	scanf("%d", &n);
//n = 16;
	int totr(0), totb(0);
	for(int i(0); i < n; i++) {
		static char st[111];
		scanf("%s%d%d", st, &r[i], &b[i]);
		tp[i] = st[0];
		totr += r[i];
		totb += b[i];
	}
	for(int msk(0); msk < (1 << n); msk++) {
		for(int i(0); i <= 120; i++) {
			dp[msk][i] = -inf;
		}
		cntr[msk] = cntb[msk] = 0;
		for(int j(0); j < n; j++) {
			if(0 == (msk >> j & 1)) {
				continue;
			}
			if(tp[j] == 'R') {
				cntr[msk]++;
			}else {
				cntb[msk]++;
			}
		}
	}
	dp[0][0] = 0;
	for(int msk(0); msk < (1 << n); msk++) {
		for(int i(0); i <= 120; i++) {
			//if(i <= 10) {
			//	printf("dp[%d][%d] = %d\n", msk, i, dp[msk][i]);
			//}
			if(dp[msk][i] == -inf) {
				continue;
			}
			for(int j(0); j < n; j++) {
				if((msk >> j & 1) == 0) {
					//printf("%d %d %d\n", msk, cntb[msk], b[j]);
					//printf("%d\n", dp[msk][i] + min(cntr[msk], r[j]));
					renew(dp[msk | (1 << j)][i + min(cntb[msk], b[j])], dp[msk][i] + min(cntr[msk], r[j]));
				}
			}
		}
	}
	int ans(inf);
	for(int i(0); i <= 120; i++) {
		ans = min(ans, max(totr - dp[(1 << n) - 1][i], totb - i));
	}
	printf("%d\n", ans + n);
}