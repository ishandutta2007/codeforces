#include<bits/stdc++.h>
using namespace std;

const int N=5005;

int n,a[N],dp[N][N];
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int m=0;
	for (int i=1;i<=n;i++)
		if (!m||a[m]!=a[i])
			a[++m]=a[i];
	n=m;
	for (int l=n;l>=1;l--) {
		for (int r=l+1;r<=n;r++) {
			dp[l][r]=min(dp[l][r-1],dp[l+1][r])+1;
			if (a[l]==a[r]) dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
		}
	}
	printf("%d",dp[1][n]);
	return 0;
}