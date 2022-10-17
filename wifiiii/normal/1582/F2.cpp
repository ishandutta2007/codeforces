#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 8192;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> pos(N);
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        pos[x].push_back(i);
    }
    vector<int> dp(N, 1e9);
    dp[0] = -1;
    for(int i = 1; i <= 5000; ++i) {
        if(pos[i].empty()) continue;
        int last = pos[i].back();
        for(int j = 0; j < N; ++j) {
            if(dp[j] < last && dp[j ^ i] > dp[j]) {
                auto it = upper_bound(pos[i].begin(), pos[i].end(), dp[j]);
                dp[j ^ i] = min(dp[j ^ i], *it);
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; ++i) if(dp[i] != 1e9) ++cnt;
    cout << cnt << endl;
    for(int i = 0; i < N; ++i) if(dp[i] != 1e9) cout << i << " ";
}