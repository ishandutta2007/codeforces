#include<bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    int maxa = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxa = max(maxa, a[i]);
    }
    map<int, int> dp;
    int ans = 0;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        dp[a[i]] = dp[a[i]-1] + 1;
        if(dp[a[i]] > ans) {
            ans = dp[a[i]];
            j = a[i];
        }
    }
    int od = j - ans + 1;
    cout << ans << endl;
    for(int i = 0; i < n; i++) {
        if(a[i] == od) {
            cout << i + 1 << " ";
            od++;
            ans--;
            if(ans == 0) {
                return 0;
            }
        }
    }
}