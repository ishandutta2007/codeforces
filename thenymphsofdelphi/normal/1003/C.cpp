#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;

const int N = 5005;
int a[N], dp[N];

signed main(){
    int n, k;
    double mx = -1, t;
    cin >> n >> k;
    dp[0] = 0;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        dp[i] = dp[i - 1] + a[i];
    }
    for (int i = k; i <= n; i++){
        for (int j = 1; j <= i - k + 1; j++){
            t = (dp[i] - dp[j - 1]) * 1.0 / (i - j + 1);
            mx = max(mx, t);
        }
    }
    cout << fixed << setprecision(7) << mx;
}