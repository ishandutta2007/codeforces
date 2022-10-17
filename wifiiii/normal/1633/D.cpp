#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3 + 5;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> dp(N, 1e9);
    dp[1] = 0;
    for(int i = 1; i < N; ++i) {
        for(int j = 1; j <= i; ++j) {
            if(i + i / j < N) dp[i + i / j] = min(dp[i + i / j], dp[i] + 1);
        }
    }
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> b[i], b[i] = dp[b[i]];
        for(int i = 0; i < n; ++i) cin >> c[i];
        if(k >= 12 * n) {
            cout << accumulate(c.begin(), c.end(), 0) << '\n';
            continue;
        }
        vector<int> ans(k + 1);
        for(int i = 0; i < n; ++i) {
            vector<int> nxt = ans;
            for(int j = b[i]; j <= k; ++j) {
                nxt[j] = max(nxt[j], ans[j - b[i]] + c[i]);
            }
            ans = nxt;
        }
        cout << *max_element(ans.begin(), ans.end()) << '\n';
    }
}