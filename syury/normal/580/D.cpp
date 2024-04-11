#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
typedef long long int lint;

int n, m, k, mmax;
int c[18][18];
vector<int> a;
vector<vector<lint> > dp;
lint ans = 0ll;

int main(){
	for(int i = 0; i < 18; i++){
		memset(c[i], 0, sizeof(int) * 18);
	}
	scanf("%d%d%d", &n, &m, &k);
	mmax = 1 << n;
	dp.resize(mmax);
	a.resize(n);
	for(int i = 0; i < n; i++){scanf("%d", &a[i]);}
	for(int i = 0; i < k; i++){
		int v, u, l;
		scanf("%d%d%d", &v, &u, &l);
		v--; u--;
		c[v][u] = l;
	}
	for(int mask = 0; mask < mmax; mask++){
		dp[mask].resize(n);
	}
	for(int mask = 0; mask < mmax; mask++){
		int cnt = __builtin_popcount(mask);
		if(cnt > m || cnt == 0){continue;}
		for(int last = 0; last < n; last++){
			dp[mask][last] = a[last];
			if(!(mask & (1 << last))){continue;}
			int prev = mask - (1 << last);
			for(int ll = 0; ll < n; ll++){
				if(prev & (1 << ll)){dp[mask][last] = max(dp[mask][last], dp[prev][ll] + a[last] + c[ll][last]);}
			}
			if(cnt == m){ans = max(ans, dp[mask][last]);}
		}
	}
	printf("%I64d", ans);
	return 0;
}