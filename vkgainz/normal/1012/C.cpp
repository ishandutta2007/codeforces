#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 2e5+5;
int dp[5005][2505][2];
int get(int i, int j, int k) {
    if(i<0) {
        if(j>0) return 1000000000;
        return 0;
    }
    return dp[i][j][k];
}
int main() {
    int n; cin >> n;
    int a[n+2];
    a[0] = 0;
    a[n+1] = 0;
    for(int i=0;i<n;i++) cin >> a[i+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=(n+1)/2;j++) {
            if(j==0) {
                dp[i][j][0] = 0;
                dp[i][j][1] = 1000000000;
                continue;
            }
            dp[i][j][0] = 1000000000;
            dp[i][j][1] = 1000000000;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=(n+1)/2;j++) {
            int c = max(0, a[i+1]-a[i]+1)+max(0, a[i-1]-a[i]+1);
            dp[i][j][0] = min(c+min(get(i-2,j-1,1), get(i-2, j-1, 0)), get(i-1, j, 0));
            c = max(0, a[i-1]-a[i]+1);
            if(i<n) {
                int x = min(a[i+1], a[i+2]-1);
                c+=max(0, x-a[i]+1);
            }
            dp[i][j][1] = min(c+min(get(i-2, j-1, 1), get(i-2, j-1, 0)), get(i-1, j, 0));
        }
    }
    for(int k=1;k<=(n+1)/2;k++) {
        cout << dp[n][k][0] << " ";
    }
    cout << "\n";
}