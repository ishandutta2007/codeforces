#include <cstdio>
#include <algorithm>

using namespace std;

int n,T;
int recog[5001];
int chorus[5001];
double dp[5001][5001];

int main() {
    scanf("%d%d",&n,&T);
    for (int i=1;i<=n;i++) scanf("%d%d",&recog[i],&chorus[i]);
    dp[0][0] = 1;
    int sumChorus = 0;
    for (int i=1;i<=n;i++) {
        sumChorus+=chorus[i];
        double missed = 1;
        for (int j=1;j<=T;j++) {
            if (j>sumChorus) {
                dp[i][j] = 0;
                continue;
            }
            if (recog[i]==0) {
                if (j>=chorus[i]) dp[i][j] = dp[i-1][j-chorus[i]];
                else dp[i][j] = 0;
                continue;
            }
            if (chorus[i]==1 || recog[i]==100) {
                dp[i][j] = dp[i-1][j-1];
                continue;
            }
            if (j<chorus[i]) dp[i][j] = dp[i][j-1]*(1-recog[i]/100.)+recog[i]/100.*dp[i-1][j-1];
            else if (j==chorus[i]) dp[i][j] = (dp[i][j-1]-missed/(1-recog[i]/100.)*recog[i]/100.*dp[i-1][j-chorus[i]])*(1-recog[i]/100.)+recog[i]/100.*dp[i-1][j-1]+missed*dp[i-1][j-chorus[i]];
            else dp[i][j] = (dp[i][j-1]-missed*dp[i-1][j-chorus[i]-1]-missed/(1-recog[i]/100.)*recog[i]/100.*dp[i-1][j-chorus[i]])*(1-recog[i]/100.)+recog[i]/100.*dp[i-1][j-1]+missed*dp[i-1][j-chorus[i]];
            if (j<chorus[i]) {
                missed*=1-recog[i]/100.;
                if (missed<1e-18) missed = 0;
            }
            if (dp[i][j]<1e-18) dp[i][j] = 0;
        }
    }
    double ans = 0;
    for (int i=1;i<=n;i++) for (int j=1;j<=T;j++) ans+=dp[i][j];
    printf("%1.12f\n",ans);

    return 0;
}