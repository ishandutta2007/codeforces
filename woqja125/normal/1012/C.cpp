#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long dp[5001][3000][3]; // 0: i sel, 1: i-1 sel 
int a[5001];
int mi(int x, int y) {
    int r = x-y;
    if(r<0) return 0;
    else return r;
}
int main() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
        scanf("%d", a+i);
    for(int i=0; i<=n; i++) {
        dp[i][0][1] = dp[i][0][0] = 200000000000ll;
        for(int j=1; j<=(i+1)/2; j++) {
            dp[i][j][0] = min(dp[i-1][j-1][2] + mi(a[i-1], a[i]-1),
                            dp[i-1][j-1][1] + mi(min(a[i-1], a[i-2]-1), a[i]-1)) + mi(a[i+1], a[i]-1);
            dp[i][j][1] = dp[i-1][j][0];
            dp[i][j][2] = min(dp[i-1][j][1], dp[i-1][j][2]);
        }
        for(int j=(i+1)/2+1; j<3000; j++) for(int k=0; k<3; k++) dp[i][j][k] = 200000000000ll;
    }
    for(int j=1; j<=(n+1)/2; j++) printf("%lld ", min(dp[n][j][0], min(dp[n][j][1], dp[n][j][2])));
    puts("");
    return 0;
}