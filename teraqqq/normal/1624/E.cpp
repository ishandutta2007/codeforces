#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
using pi = pair<int, int>;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pi> ik3(1000, pi { -1, -1 }), ik2(100, pi { -1, -1 });

        vector<char> dp(m+1);
        vector<int> jmp(m+1);

        for (int i = 0; i < n; ++i) {
            string s; cin >> s;
            vector<int> x(m);
            for (int j = 0; j < m; ++j) x[j] = s[j] - '0';
            for (int j = 0; j + 2 <= m; ++j) {
                ik2[x[j] * 10 + x[j+1]] = pi { i, j };
            }

            for (int j = 0; j + 3 <= m; ++j) {
                ik3[x[j] * 100 + x[j+1] * 10 + x[j+2]] = pi { i, j };
            }
        }

        string s; cin >> s;
        vector<int> x(m);
        for (int j = 0; j < m; ++j) x[j] = s[j] - '0';

        dp[0] = true;

        for (int j = 1; j <= m; ++j) {
            if (j >= 2 && dp[j-2]) {
                const int s = x[j-2] * 10 + x[j-1];
                if (ik2[s].F != -1) {
                    dp[j] = true;
                    jmp[j] = 2;
                }
            }

            if (j >= 3 && dp[j-3]) {
                const int s = x[j-3] * 100 + x[j-2] * 10 + x[j-1];
                if (ik3[s].F != -1) {
                    dp[j] = true;
                    jmp[j] = 3;
                }
            }
        }

/*
        for (int x : dp) cout << x << ' '; cout << endl;
        for (int x : jmp) cout << x << ' '; cout << endl;
*/

        if (dp[m]) {
            vector<array<int, 3>> ans;

            for (int i = m; i != 0; ) {
                if (jmp[i] == 2) {
                    const int s = x[i-2] * 10 + x[i-1];
                    ans.push_back(array { ik2[s].S, ik2[s].S+1, ik2[s].F });
                    i -= 2;
                }
                if (jmp[i] == 3) {
                    const int s = x[i-3] * 100 + x[i-2] * 10 + x[i-1];
                    ans.push_back(array { ik3[s].S, ik3[s].S+2, ik3[s].F });
                    i -= 3;
                }
            }

            reverse(begin(ans), end(ans));

            cout << size(ans) << '\n';
            for (auto [a, b, c] : ans) cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
        } else {
            cout << -1 << '\n';
        }

        cout.flush();
    }
}