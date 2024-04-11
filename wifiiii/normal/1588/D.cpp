#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // 26 * 2^10
    // pos[ch][mask]
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<string> a(n);
        vector<vector<vector<int>>> pos(n, vector<vector<int>>(52));
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            for(char &c : a[i]) {
                if(c >= 'a' && c <= 'z') {
                    c = c - 'a';
                } else {
                    c = c - 'A' + 26;
                }
            }
            for(int j = 0; j < a[i].size(); ++j) {
                pos[i][a[i][j]].push_back(j);
            }
        }
        auto get = [&](int x) -> char {
            if(x < 26) return x + 'a';
            return x - 26 + 'A';
        };
        int ans = 0, x = -1, y = -1;
        vector<vector<int>> dp(52, vector<int>(1 << n));
        vector<vector<string>> s(52, vector<string>(1 << n));
        for(char j : a[0]) {
            for(int i = 0; i < 1 << n; ++i) {
                vector<int> cur(n);
                for(int k = 0; k < n; ++k) {
                    if(i >> k & 1) {
                        if(pos[k][j].size() < 2) {
                            cur.clear();
                            break;
                        }
                        cur[k] = pos[k][j][1];
                    } else {
                        if(pos[k][j].size() < 1) {
                            cur.clear();
                            break;
                        }
                        cur[k] = pos[k][j][0];
                    }
                }
                if(cur.empty()) continue;
                if(dp[j][i] == 0) {
                    dp[j][i] = 1;
                    s[j][i] = get(j);
                }
                if(dp[j][i] > ans) {
                    ans = dp[j][i];
                    x = j;
                    y = i;
                }
                for(int k = 0; k < 52; ++k) {
                    // dp[j][i] -> dp[k][nxt]
                    int nxt = 0, ok = 1;
                    for(int p = 0; p < n; ++p) {
                        if(pos[p][k].size() > 0 && pos[p][k][0] > cur[p]) {

                        } else if(pos[p][k].size() > 1 && pos[p][k][1] > cur[p]) {
                            nxt |= 1 << p;
                        } else {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok) {
                        if(dp[j][i] + 1 > dp[k][nxt]) {
                            dp[k][nxt] = dp[j][i] + 1;
                            s[k][nxt] = s[j][i] + get(k);
                        }
                    }
                }
            }
        }
        cout << ans << '\n';
        if(ans) cout << s[x][y];
        cout << '\n';
    }
}