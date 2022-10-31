#include <bits/stdc++.h>
using namespace std;

char s[2113], c[6313];
int t,s1,s2,s3;
int lcp[6313][6313];
int dp[2113], from[2113];
int x[2113], y[2113];

int main() {
	scanf(" %s",s+0);
	t = 0;
	scanf(" %s",c+t);
	s1 = strlen(c)+1;
	c[s1-1] = '$';
	copy(s,s+strlen(s),c+s1);
	s2 = strlen(c)+1;
	c[s2-1] = '#';
	copy(s,s+strlen(s),c+s2);
	s3 = strlen(c);
	reverse(c+s2,c+s3);
	for (int i=s3-1;i>=0;i--) for (int j=s3-1;j>i;j--) {
		lcp[i][j] = (c[i]==c[j]) ? lcp[i+1][j+1]+1 : 0;
	}
	fill(dp+1,dp+2113,12345);
	for (int i=0;i<s1-1;i++) {
		for (int j=s1;j<s2-1;j++) {
			int cur = i+lcp[i][j];
			if (dp[i]+1<dp[cur]) {
				dp[cur] = dp[i]+1;
				from[cur] = i;
				x[cur] = j+1-s1;
				y[cur] = j+1-s1+lcp[i][j]-1;
			}
		}
		for (int j=s2;j<s3;j++) {
			int cur = i+lcp[i][j];
			if (dp[i]+1<dp[cur]) {
				dp[cur] = dp[i]+1;
				from[cur] = i;
				x[cur] = s3-j;
				y[cur] = s3-j-lcp[i][j]+1;
			}
		}
	}
	if (dp[s1-1]==12345) printf("-1\n");
	else {
		printf("%d\n",dp[s1-1]);
		stack<int> has;
		has.push(s1-1);
		while (from[has.top()]!=0) {
			has.push(from[has.top()]);
		}
		while (has.size()) {
			printf("%d %d\n",x[has.top()],y[has.top()]);
			has.pop();
		}
	}

	return 0;
}