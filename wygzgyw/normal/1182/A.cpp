#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n;
ll dp[80][8];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	dp[n][7]=1;
	for (int i=n-1;i>=1;i--) {
		dp[i][0]=dp[i+1][7]*2;
		dp[i][1]=dp[i+1][6]+dp[i+1][4];
		dp[i][3]=dp[i+1][5];
		dp[i][4]=dp[i+1][3]+dp[i+1][5];
		dp[i][5]=dp[i+1][4]+dp[i+1][6];
		dp[i][6]=dp[i+1][1]+dp[i+1][4];
		dp[i][7]=dp[i+1][0];
	}
	printf("%lld\n",dp[1][0]);
	return 0;
}