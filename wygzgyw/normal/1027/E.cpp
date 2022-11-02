#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
int n,k;
ll dp[510][510],ans;
void update(ll &x,ll y) {
	x+=y; x%=mod;
}
int main() {
	read(n); read(k);
	dp[0][0]=1;
	for (int i=0;i<n;i++)
	for (int j=0;j<=i;j++)
	for (int k=1;k+i<=n;k++)
		update(dp[i+k][max(j,k)],dp[i][j]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		if (i*j<k)
			update(ans,dp[n][i]*dp[n][j]*2%mod);
	printf("%lld\n",ans);
	return 0;
}