#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a, b;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if(x == 1) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
    }
    vector<vector<int>> dp(a.size() + 1, vector<int>(b.size() + 1, 1e9));
    dp[0][0] = 0;
    for(int i = 0; i <= a.size(); ++i) {
        for(int j = 0; j < b.size(); ++j) {
            if(i < a.size()) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + abs(a[i] - b[j]));
            dp[i][j + 1] = min(dp[i][j + 1], dp[i][j]);
        }
    }
    cout << dp[a.size()][b.size()] << '\n';
}