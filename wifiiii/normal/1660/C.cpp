#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        vector<int> pos(26, -1);
        int n = s.size();
        vector<int> dp(n);
        for(int i = 0; i < n; ++i) {
            dp[i] = i ? dp[i - 1] : 0;
            if(pos[s[i] - 'a'] != -1) {
                dp[i] = max(dp[i], pos[s[i] - 'a'] ? dp[pos[s[i] - 'a'] - 1] + 2 : 2);
            }
            pos[s[i] - 'a'] = i;
        }
        cout << n - dp[n - 1] << '\n';
    }
}