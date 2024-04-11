#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int n,k;
char s[1000013];
long long dp[26];
int last[26];

int main() {
	scanf("%d%d %s",&n,&k,&s);
	for (int i=0;s[i]!='\0';i++) {
		dp[s[i]-'a'] = (1+accumulate(dp,dp+k,0LL))%MOD;
		last[s[i]-'a'] = i+1;
	}
	for (int i=MOD;i<MOD+n;i++) {
		int next = min_element(last,last+k)-last;
		dp[next] = (1+accumulate(dp,dp+k,0LL))%MOD;
		last[next] = i;
	}
	printf("%lld\n",(1+accumulate(dp,dp+k,0LL))%MOD);

    return 0;
}