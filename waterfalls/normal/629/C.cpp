#include <bits/stdc++.h>
using namespace std;

#define left left_
#define right right_

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int n,m;

char s[100013];
int sum, left, right;
void process() {
	sum = count(s,s+m,'(')-count(s,s+m,')');
	left = 0;
	int cur = 0;
	for (int i=0;i<m;i++) {
		cur+=s[i]=='(' ? 1 : -1;
		left = max(left,-cur);
	}
	right = 0;
	cur = 0;
	for (int i=m-1;i>=0;i--) {
		cur+=s[i]==')' ? 1 : -1;
		right = max(right,-cur);
	}
}

int dp[2013][2013];
void dodp() {
	dp[0][0] = 1;
	for (int i=0;i<2010;i++) {
		for (int j=0;j<2010;j++) {
			dp[i+1][j+1] = add(dp[i+1][j+1],dp[i][j]);
			if (j) dp[i+1][j-1] = add(dp[i+1][j-1],dp[i][j]);
		}
	}
}

int main() {
	scanf("%d%d %s",&n,&m,&s);
	process();
	dodp();
	int ans = 0;
	for (int i=0;i<=n-m;i++) {
		for (int j=0;j<=i;j++) {
			if (j<left) continue;
			if (sum+j<right || sum+j>n-m-i) continue;
			ans = add(ans,mult(dp[i][j],dp[n-m-i][sum+j]));
		}
	}
	printf("%d\n",ans);

    return 0;
}