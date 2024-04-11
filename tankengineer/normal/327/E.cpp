#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int MOD = 1000000007;

int n, k, t, a[1 << 25], kk[3], dp[1 << 24], sum, as, j;

inline int lowbit(const int i) {return i & (-i);}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
	  scanf("%d", &a[1 << i]);
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; ++i) {
	  scanf("%d", &kk[i]);
  }
	if (k == 2 && kk[1] > kk[2]) swap(kk[1], kk[2]);
	dp[0] = 1;
	for (int i = 0; i < (1 << n); ++i) {
		if (dp[i] == 0) continue;
		sum = 0;
		if (k > 0) {
			as = i;
			while (as) {
			  j = lowbit(as);
			  as -= j;
				sum += a[j];		  
			  if (sum > kk[k]) break;
			}
			if (!(sum != kk[1] && (k == 1 || sum != kk[2]))) {
			  dp[i] = 0;
			  continue;
			}
		}
		as = ((1 << n) - 1) - i;
		while (as) {
		  j = lowbit(as);
		  as -= j;
	    t = i | j;
			dp[t] += dp[i];
	    if (dp[t] >= MOD) dp[t] -= MOD;
		}
	}
	cout << dp[(1 << n) - 1] << endl;
	return 0;
}