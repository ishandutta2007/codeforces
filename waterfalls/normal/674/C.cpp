#include <bits/stdc++.h>
using namespace std;

typedef double ld;

int n,k;
ld t[200013], it[200013], v[200013];
ld dp[53][200013];

ld get(int a, int b) {
	ld res = v[b]-v[a-1];
	res-=(t[b]-t[a-1])*it[b+1];
	return res;
}

void go(int j, int l, int r, int low, int high) {
	if (r<l) return;
	int m = (l+r)/2;
	int which = low;
	dp[j][m] = 1e300;
	for (int i=low;i<=min(high,m);i++) {
		ld cur = dp[j-1][i-1]+get(i,m);
		if (cur<dp[j][m]) {
			dp[j][m] = cur;
			which = i;
		}
	}
	go(j,l,m-1,low,which);
	go(j,m+1,r,which,high);
}

int main() {
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) {
		int x;
		scanf("%d",&x);
		t[i] = x;
		it[i] = 1./x;
	}
	for (int i=n;i>=0;i--) it[i]+=it[i+1];
	for (int i=1;i<=n;i++) {
		v[i] = t[i]*it[i];
		v[i]+=v[i-1];
	}
	for (int i=1;i<=n;i++) t[i]+=t[i-1];
	for (int i=1;i<=n;i++) dp[0][i] = 1e300;
	for (int j=1;j<=k;j++) go(j,1,n,1,n);
	printf("%1.9f\n",(double) dp[k][n]);

	return 0;
}