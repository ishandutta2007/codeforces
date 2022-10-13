#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
double dp[1<<18];
int main() {
    int n; cin >> n;
    double p[n][n];
    for(int i=0;i<n;i++) 
        for(int j=0;j<n;j++) cin >> p[i][j];
    dp[1] = 1.0;
    for(int i=1;i<1<<n;i++) {
        if(!i&1) {
            dp[i] = 0.0;
            continue;
        }
        for(int j=0;j<n;j++) {
            if(i&1<<j) {
                for(int k=j+1;k<n;k++) {
                    if(i&(1<<k)) {
                        if(j==0) {
                            //ivan plays
                            dp[i] = max(dp[i],p[j][k]*1.0*dp[i^(1<<k)]);
                        }
                        else {
                            //probability that j loses, then k
                            dp[i] = max(dp[i],p[j][k]*1.0*dp[i^(1<<k)]+p[k][j]*1.0*dp[i^(1<<j)]);

                        }
                    }
                }
            }
        }
    }
    cout << setprecision(9) << dp[(1<<n)-1];
}