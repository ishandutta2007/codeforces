#include <bits/stdc++.h>
using namespace std;

int n,m;
char s[23][100013];
int dp[20][1<<19];

int main() {
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++) scanf(" %s",&s[i]);
	for (int j=0;j<m;j++) {
		int x = 0;
		for (int i=0;i<n;i++) if (s[i][j]=='1') {
			x|=(1<<i);
		}
		if (x&(1<<(n-1))) x^=(1<<n)-1;
		dp[0][x]+=1;
	}
	for (int i=0;i<n-1;i++) {
		for (int j=i+1;j>=1;j--) {
			for (int k=0;k<(1<<(n-1));k++) {
				dp[j][k]+=dp[j-1][k^(1<<i)];
			}
		}
	}
	int ans = 1e9;
	for (int i=0;i<(1<<(n-1));i++) {
		int cur = 0;
		for (int j=0;j<n;j++) {
			cur+=dp[j][i]*min(j,n-j);
		}
		ans = min(ans,cur);
	}
	printf("%d\n",ans);

	return 0;
}