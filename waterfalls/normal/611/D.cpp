// ok lessons here
// 1. notice bad complexity
// 2. optimize dumb things with bad complexity
// 3. don't be stupid and just start with good complexity :P
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }

int n;
char s[5013];
int dp[5013][5013];
int sums[5013][5013];
int lcp[5013][5013];

bool comp(int i, int j, int len) {
	if (lcp[i][j]>=len) return false;
	return s[i+lcp[i][j]]<s[j+lcp[i][j]];
}

int main() {
	scanf("%d",&n);
	scanf(" %s",&s);
	for (int i=n-1;i>=0;i--) for (int j=n-1;j>i;j--) {
		lcp[i][j] = (s[i]==s[j] ? 1+lcp[i+1][j+1] : 0);
	}
	for (int i=n-1;i>=0;i--) {
		if (s[i]=='0') continue;
		for (int j=1;j<=n-i;j++) {
			if (j==n-i) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = sums[i+j][j+1];
			if (comp(i,i+j,j)) dp[i][j] = add(dp[i][j],dp[i+j][j]);
		}
		for (int j=5011;j>=0;j--) sums[i][j] = add(sums[i][j+1],dp[i][j]);
	}
	printf("%d\n",sums[0][1]);

	return 0;
}