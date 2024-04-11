#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int b[500];
int dp[500][500];
int MOD = 1000000007;

int solve(int l, int r) {
    if (dp[l][r]!=-1) return dp[l][r];
    if (l>=r) return dp[l][r] = 1;
    dp[l][r] = solve(l+1,r);
    for (int i=l+1;i<=r;i++) if (b[l]<b[i]) dp[l][r] = (dp[l][r]+(long long) solve(l+1,i-1)*solve(i,r))%MOD;
    return dp[l][r];
}

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    memset(dp,-1,sizeof dp);
    printf("%d\n",solve(1,n-1));

    return 0;
}