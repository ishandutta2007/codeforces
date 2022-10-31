#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int add(int a, int b) { return a+b-(a+b>=MOD)*MOD; }
int sub(int a, int b) { return a-b+(a-b<0)*MOD; }
int mult(int a, int b) { return (1LL*a*b)%MOD; }

int m,e;
int dp[2013][2013][2]; // pos, mod, below

int solve(char* s) {
	int n = strlen(s);
	--s;
	memset(dp,0,sizeof dp);
	dp[0][0][1] = 1;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			for (int k=0;k<2;k++) {
				for (int d=0;d<10;d++) {
					if (k && d>s[i+1]-'0') continue;
					if (i%2==0 && d==e) continue;
					if (i%2==1 && d!=e) continue;
					int ni = i+1;
					int nj = (j*10+d)%m;
					int nk = k&(d==s[i+1]-'0');
					dp[ni][nj][nk] = add(dp[ni][nj][nk],dp[i][j][k]);
				}
			}
		}
	}
	return add(dp[n][0][0],dp[n][0][1]);
}

char a[2013], b[2013];

int main() {
	scanf("%d%d",&m,&e);
	scanf(" %s %s",&a,&b);
	int len = strlen(a);
	while (a[len-1]=='0') {
		len-=1;
		a[len] = '9';
	}
	a[len-1]-=1;
	printf("%d\n",sub(solve(b),solve(a)));

    return 0;
}