#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(string s) {
    int n = s.size();
    vector<vector<int>> lcp(n, vector<int>(n));
    for(int i = n - 1; i >= 0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            if(s[i] == s[j]) lcp[i][j] = (i + 1 >= n || j + 1 >= n) ? 1 : lcp[i + 1][j + 1] + 1;
        }
    }
    vector<int> dp(n);
    dp[n - 1] = 0;
    for(int i = n - 2; i >= 0; --i) {
        for(int j = i + 1; j < n; ++j) {
            int k = lcp[i][j];
            if(k < n - j && (s[i + k] < s[j + k])) {
                dp[i] = max(dp[i], dp[j] + n - j - k);
            }
        }
    }
    int ret = 0;
    for(int i = 0; i < n; ++i) {
        ret = max(ret, dp[i] + (n - i));
    }
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
}