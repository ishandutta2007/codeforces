#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int n;
int a[1000013];
int dp[1000013];

int main() {
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	a[0] = a[n+1] = 1;
	int ans = 0;
	for (int i=1;i<=n;i++) {
		if (a[i]>a[i+1]) {
			ans = add(ans,a[i]-a[i+1]);
			if (a[i-1]>a[i+1]) ans = add(ans,mult(dp[i-1],min(a[i],a[i-1])-a[i+1]));
		}
		dp[i] = add(dp[i],min(a[i],a[i+1])-1);
		dp[i] = add(dp[i],mult(dp[i-1],min(min(a[i-1],a[i]),a[i+1])-1));
		ans = add(ans,dp[i]);
	}
	printf("%d\n",ans);

	return 0;
}