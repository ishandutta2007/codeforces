#include <bits/stdc++.h>
using namespace std;

int n,m;
int pref[1<<20];
int a[50013], b[50013];
int dp[50013];

int l[5013], r[5013];
int ans[5013];

int main() {
	pref[0] = 0;
	for (int i=1;i<(1<<20);i++) pref[i] = pref[i-1]^i;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		b[i] = pref[a[i]];
	}
	for (int i=0;i<m;i++) scanf("%d%d",&l[i],&r[i]);
	for (int i=1;i<=n;i++) {
		int cur = 0;
		for (int j=i;j<=n;j+=5) {
			cur = max(cur,b[i]^b[j]^min(a[i],a[j]));
			dp[j] = cur;
			cur = max(cur,b[i]^b[j+1]^min(a[i],a[j+1]));
			dp[j+1] = cur;
			cur = max(cur,b[i]^b[j+2]^min(a[i],a[j+2]));
			dp[j+2] = cur;
			cur = max(cur,b[i]^b[j+3]^min(a[i],a[j+3]));
			dp[j+3] = cur;
			cur = max(cur,b[i]^b[j+4]^min(a[i],a[j+4]));
			dp[j+4] = cur;
		}
		for (int j=0;j<m;j++) {
			if (l[j]<=i && i<=r[j]) ans[j] = max(ans[j],dp[r[j]]);
		}
	}
	for (int i=0;i<m;i++) printf("%d\n",ans[i]);

	return 0;
}