#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second
double dp[1<<18];
int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) {
        --a[i];
    }
    int ans = 0;
    for(int mx=1;mx<=n/8+1;mx++) {
        int dp[n+1][1<<8];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<1<<8;j++){
                if(i==0) {
                    if(mx==1) dp[i][j] = 0;
                    else {
                        if(j==0) dp[i][j] = 0;
                        else dp[i][j] = -1000000000;
                    }
                }
                else dp[i][j] = -1000000000;
            }
        }
        vector<int> pos[8];
        for(int i=1;i<=n;i++) {
            int curr = a[i-1];
            pos[curr].push_back(i);
            for(int msk=0;msk<1<<8;msk++) {
                for(int j=0;j<8;j++) dp[i][msk] = max(dp[i][msk],dp[i-1][msk]);

                if(msk&(1<<curr)) {
                    //put mx or mx-1 occurences of curr
                    if(pos[curr].size()>=mx) {
                        dp[i][msk] = max(dp[i][msk],dp[pos[curr][pos[curr].size()-mx]-1][msk^(1<<curr)]+mx);
                    }
                    if(pos[curr].size()>=mx-1) {
                        if(mx>1) dp[i][msk] = max(dp[i][msk],dp[pos[curr][pos[curr].size()-(mx-1)]-1][msk^(1<<curr)]+mx-1);
                    }
                }
                if(msk==255) ans = max(ans,dp[i][msk]);
            }
        }
    }
    cout << ans << endl;
}