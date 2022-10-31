#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int MOD = 1000000007;
int dp[2001][2001];

int main() {
    scanf("%d%d",&n,&k);
    dp[0][0] = 1;
    for (int i=0;i<=n;i++) {
        for (int j=0;j<k;j++) {
            if (!dp[i][j]) continue;
            for (int l=max(i,1);l<=n;l+=max(i,1)) dp[l][j+1] = (dp[l][j+1]+dp[i][j])%MOD;
        }
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans = (ans+dp[i][k])%MOD;
    printf("%d\n",ans);

    return 0;
}