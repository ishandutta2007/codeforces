#include <cstdio>

using namespace std;

int n,h;
int a[2000];
int dp[2001][2001];
int MOD = 1000000007;

int main() {
    scanf("%d%d",&n,&h);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    dp[0][0] = 1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<=i;j++) {
            if (dp[i][j]==0) continue;
            if (a[i]+j==h) {
                if (j>0) dp[i+1][j-1] = (dp[i+1][j-1]+(long long) j*dp[i][j])%MOD; // close one
                dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;                            // do nothing
            } else if (a[i]+j+1==h) {
                if (j>0) dp[i+1][j] = (dp[i+1][j]+(long long) j*dp[i][j])%MOD;     // close and open
                dp[i+1][j] = (dp[i+1][j]+dp[i][j])%MOD;                            // open and close
                dp[i+1][j+1] = (dp[i+1][j+1]+dp[i][j])%MOD;                        // open one
            }
        }
    }
    printf("%d\n",dp[n][0]);

    return 0;
}