#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
#define MP make_pair
#define A first
#define B second

int n,a,b;
double p[2][2013];
pair<ld,int> dp[2013];

pair<ld,int> check(ld k) {
	for (int i=0;i<2013;i++) dp[i].A = -1e9;
	dp[0] = MP(0,0);
	for (int i=1;i<=n;i++) {
		for (int j=a;j>=0;j--) {
			dp[j] = max(dp[j],MP(dp[j].A+p[1][i]-k,dp[j].B+1));
			if (j) {
				dp[j] = max(dp[j],MP(dp[j-1].A+p[0][i],dp[j-1].B));
				dp[j] = max(dp[j],MP(dp[j-1].A+1-(1-p[0][i])*(1-p[1][i])-k,dp[j-1].B+1));
			}
		}
	}
	return dp[a];
}

int main() {
	clock_t start = clock();
	scanf("%d%d%d",&n,&a,&b);
	for (int i=1;i<=n;i++) scanf("%lf",&p[0][i]);
	for (int i=1;i<=n;i++) scanf("%lf",&p[1][i]);
	ld low = -4000, high = 4000;
	while ((clock()-start)/CLOCKS_PER_SEC<3) {
		ld mid = (low+high)/2;
		auto res = check(mid);
		if (res.B==b) {
			printf("%1.9f\n",(double) (res.A+mid*b));
			exit(0);
		}
		if (res.B<b) high = mid;
		else low = mid;
	}
	printf("%1.9f\n",(double) (check(low).A+low*b));

	return 0;
}