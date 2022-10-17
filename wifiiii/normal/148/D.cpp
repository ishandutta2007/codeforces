#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 1005;
double dp[maxn][maxn][2];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;++i) dp[i][0][0]=1;
    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            dp[i][j][0] = 1.0*i/(i+j)+1.0*j/(i+j)*dp[i][j-1][1];
            dp[i][j][1] = 1.0*j/(i+j)*(1.0*i/(i+j-1)*dp[i-1][j-1][0] + (j-1?1.0*(j-1)/(i+j-1)*dp[i][j-2][0]:0));
        }
    }
    cout << fixed << setprecision(10) << dp[n][m][0] << endl;
}