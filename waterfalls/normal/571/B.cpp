#include <cstdio>
#include <algorithm>

using namespace std;

int n,k;
int A[300013];
long long dp[5013][5013];

int main() {
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) scanf("%d",&A[i]);
    sort(A+1,A+n+1);
    int szp = n%k;
    int one = n/k;
    int two = n/k+1;
    for (int i=0;i<=k-szp;i++) for (int j=0;j<=szp;j++) if (i || j) {
        dp[i][j] = 1e18;
        int len = i*one+j*two;
        if (i) dp[i][j] = min(dp[i][j],dp[i-1][j]+A[len]-A[len-one+1]);
        if (j) dp[i][j] = min(dp[i][j],dp[i][j-1]+A[len]-A[len-two+1]);
    }
    printf("%lld\n",dp[k-szp][szp]);

    return 0;
}