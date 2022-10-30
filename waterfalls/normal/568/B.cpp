#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int combo[4013][4013];
int dp[4013][4013];

const int MOD = 1000000007;

void gencombo() {
    combo[0][0] = 1;
    for (int i=1;i<4013;i++) {
        for (int j=0;j<=i;j++) {
            combo[i][j] = combo[i-1][j];
            if (j) combo[i][j]+=combo[i-1][j-1];
            if (combo[i][j]>=MOD) combo[i][j]-=MOD;
        }
    }
}

void gendp() {
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i=2;i<4013;i++) for (int j=1;j<=i;j++) {
        dp[i][j] = ((long long) j*dp[i-1][j])%MOD;
        if (j>1) dp[i][j]+=dp[i-1][j-1];
        if (dp[i][j]>=MOD) dp[i][j]-=MOD;
    }
    for (int i=1;i<4013;i++) for (int j=1;j<4013;j++) {
        dp[i][0]+=dp[i][j];
        if (dp[i][0]>=MOD) dp[i][0]-=MOD;
    }
}

int main() {
    gencombo();
    gendp();
    scanf("%d",&n);
    int ans = 0;
    for (int i=1;i<=n;i++) {
        ans = (ans+(long long) combo[n][i]*dp[n-i][0])%MOD;
    }
    printf("%d\n",ans);

    return 0;
}