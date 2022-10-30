#include <cstdio>
#include <algorithm>

using namespace std;

int n,K;
int s[413];
int dp[413][53][413];

int main() {
    scanf("%d%d",&n,&K);
    for (int i=0;i<n;i++) {
        scanf("%d",&s[i]);
        if (i) s[i]+=s[i-1];
    }
    for (int i=0;i<n;i++) for (int j=0;j<=K;j++) for (int k=0;k<n;k++) dp[i][j][k] = -1e9;
    for (int i=0;i<n;i++) for (int j=0;j<=i;j++) dp[i][1][j] = 0;
    for (int l=1;l<n;l++) for (int j=2;j<=min(l+1,K);j++) for (int k=1;k<=l;k++) for (int i=0;i<k;i++) {
        dp[l][j][k] = max(dp[l][j][k],dp[k-1][j-1][i]+abs((s[l]-s[k-1])-(s[k-1]-(i ? s[i-1] : 0))));
    }
    int ans = 0;
    for (int i=0;i<n;i++) for (int j=0;j<=i;j++) ans = max(ans,dp[i][K][j]);
    printf("%d\n",ans);

    return 0;
}