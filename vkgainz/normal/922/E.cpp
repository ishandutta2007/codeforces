#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
long long dp[1001][10001];

int main() {
    int n,w,b,X; cin >> n >> w >> b >> X;
    int c[n];
    for(int i=0;i<n;i++) cin >> c[i];
    int cost[n];
    for(int i=0;i<n;i++) cin >> cost[i];
    for(int i=0;i<=1000;i++) {
        for(int j=0;j<=10000;j++) {
            dp[i][j] = -1000000;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<=10000;j++) {
            if(j==0) {
                dp[i][j] = w;
            }
            else {
                for(int x=0;x<=c[i-1];x++) {
                    if(x<=j && dp[i-1][j-x]>=0) {
                        if(i==1) {
                            if(x==j && w>=cost[i-1]*1LL*x)
                                dp[i][j] = w*1LL-cost[i-1]*1LL*x;
                        }
                        else {
                            if(min(dp[i-1][j-x]+X,b*1LL*(j-x)+w)>=cost[i-1]*1LL*x)
                                dp[i][j] = max(dp[i][j],min(dp[i-1][j-x]+X,b*1LL*(j-x)+w)-cost[i-1]*1LL*x);

                        }
                    }
                }
                
            }
        }
    }
    int ans = 0;
    for(int j=0;j<=10000;j++) if(dp[n][j]>=0) ans = j;
    cout << ans << endl;
}