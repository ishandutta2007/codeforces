#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(1000), b(100);
        for(int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            for(int j = 0; j + 1 < m; ++j) {
                string x = to_string(j + 1) + " " + to_string(j + 2) + " " + to_string(i + 1);
                b[(s[j] - '0') * 10 + (s[j + 1] - '0')] = x;
            }
            for(int j = 0; j + 2 < m; ++j) {
                string x = to_string(j + 1) + " " + to_string(j + 3) + " " + to_string(i + 1);
                a[(s[j] - '0') * 100 + (s[j + 1] - '0') * 10 + (s[j + 2] - '0')] = x;
            }
        }
        string s;
        cin >> s;
        vector<int> dp(m + 1);
        dp[0] = 1;
        for(int j = 0; j < m; ++j) {
            if(dp[j]) {
                if(j + 1 < m && !b[(s[j] - '0') * 10 + (s[j + 1] - '0')].empty()) {
                    dp[j + 2] = 1;
                }
                if(j + 2 < m && !a[(s[j] - '0') * 100 + (s[j + 1] - '0') * 10 + (s[j + 2] - '0')].empty()) {
                    dp[j + 3] = 1;
                }
            }
        }
        if(dp[m]) {
            int p = m;
            vector<string> ans;
            while(p) {
                if(dp[p - 2]) {
                    ans.push_back(b[(s[p - 2] - '0') * 10 + (s[p - 1] - '0')]);
                    p -= 2;
                } else {
                    ans.push_back(a[(s[p - 3] - '0') * 100 + (s[p - 2] - '0') * 10 + (s[p - 1] - '0')]);
                    p -= 3;
                }
            }
            reverse(ans.begin(), ans.end());
            cout << ans.size() << '\n';
            for(string s : ans) {
                cout << s << '\n';
            }
        } else {
            cout << -1 << '\n';
        }
    }
}