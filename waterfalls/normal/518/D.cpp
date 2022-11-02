#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,t;
double p;
double dp[2001][2001];

int main() {
    scanf("%d%lf%d",&n,&p,&t);
    dp[0][0] = 1;
    for (int i=1;i<=t;i++) {
        for (int j=0;j<=n;j++) {
            if (j!=n) dp[i][j] = (1-p)*dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
            if (j) dp[i][j]+=p*dp[i-1][j-1];
        }
    }
    double ans = 0;
    for (int j=0;j<=n;j++) ans+=j*dp[t][j];
    printf("%1.9f\n",ans);

    return 0;
}