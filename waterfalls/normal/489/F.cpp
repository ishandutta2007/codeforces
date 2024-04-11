#include <cstdio>
#include <algorithm>

using namespace std;

int n,m;
char row[513];
int grid[500][500];
int MOD;
int prev[501][501];
int dp[501][501];

int main() {
    scanf("%d%d%d",&n,&m,&MOD);
    if (n==m) {
        printf("1\n");
        return 0;
    }
    for (int i=0;i<m;i++) {
        scanf(" %s",&row);
        for (int j=0;j<n;j++) grid[i][j] = row[j]-'0';
    }
    int zeros = n;
    int ones = 0;
    for (int j=0;j<n;j++) {
        int cur = 0;
        for (int i=0;i<m;i++) cur+=grid[i][j];
        if (cur==2) zeros-=1;
        if (cur==1) ones+=1, zeros-=1;
    }
    prev[zeros][ones] = 1;
    int bound = zeros+ones;
    for (int i=m-1;i<n-1;i++) {
        if (i>=n/2) bound = min(bound,n-2*(i-n/2));
        for (int z=0;z<=min(bound,zeros);z++) {
            for (int o=ones%2;o<=bound;o+=2) {
                if (prev[z][o]==0) continue;
                if (z>=2) dp[z-2][o+2] = (dp[z-2][o+2]+(long long) z*(z-1)/2*prev[z][o])%MOD;
                if (z>=1 && o>=1) dp[z-1][o] = (dp[z-1][o]+(long long) z*o*prev[z][o])%MOD;
                if (o>=2) dp[z][o-2] = (dp[z][o-2]+(long long) o*(o-1)/2*prev[z][o])%MOD;
            }
        }
        for (int z=0;z<=min(bound,zeros);z++) {
            for (int o=ones%2;o<=bound;o+=2) {
                prev[z][o] = dp[z][o];
                dp[z][o] = 0;
            }
        }
    }
    printf("%d\n",prev[0][0]);

    return 0;
}