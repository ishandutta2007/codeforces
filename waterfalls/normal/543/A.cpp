#include <cstdio>
#include <algorithm>

using namespace std;

int n,m,b,MOD;
int a[501];
int dp[501][501];

int main() {
    scanf("%d%d%d%d",&n,&m,&b,&MOD);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    dp[0][0] = 1%MOD;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<m;j++) {
            for (int k=0;k<=b;k++) {
                if (k+a[i]<=b) {
                    dp[j+1][k+a[i]] = dp[j+1][k+a[i]]+dp[j][k];
                    if (dp[j+1][k+a[i]]>MOD) dp[j+1][k+a[i]]-=MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i=0;i<=b;i++) ans = (ans+dp[m][i])%MOD;
    printf("%d\n",ans);

    return 0;
}