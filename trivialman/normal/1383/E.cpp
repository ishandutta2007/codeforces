#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rrep(i,a,b) for(int i=(a);i>=(b);--i)
const int P = 1000000007, N = 1e6+5;

char s[N];
int n, dp[N], nxt[N], zeros[N];

int main(){
	cin>>(s+1);
	n = strlen(s+1);
	zeros[1] = (s[1]=='0');
	rep(i,2,n) zeros[i] = (s[i]=='0' ? zeros[i-1] + 1 : 0);
	
	if (zeros[n]==n) return cout<<n, 0;
	
	rrep(i,n,1){
		dp[i] = ((zeros[i] <= zeros[n]) + dp[nxt[0]] + dp[nxt[zeros[i] + 1]] ) % P;
		nxt[zeros[i]] = i;
	}
	
	cout<<(1ll*nxt[0]*dp[nxt[0]])%P;
	return 0;
}