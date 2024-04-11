#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<vector<int>>> dp1(2, vector<vector<int>>(n, vector<int>(n)));
    for (int k = 0; k < 2; ++k) {
        int a;
        cin >> a;
        vector<int> p(a + 1);
        for (int i = 2; i <= a; ++i) {
            cin >> p[i];
        }
        vector<int> x(n);
        for (auto& i : x) {
            cin >> i;
        }

        for (int i = 0; i < n; ++i) {
            vector<int> ct(a + 1);
            for (int j = 2; j <= a; ++j) {
                ++ct[p[j]];
            }

            int sum = 0;
            for (int j = i; j < n; ++j) {
                int v = x[j];
                while (v != 1 && !ct[v]) {
                    --ct[p[v]];
                    ++sum;
                    v = p[v];
                }
                dp1[k][i][j] = sum;
            }
        }
    }

    vector<int> dp2(n + 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp2[i] = max(dp2[i], dp2[j] + max(dp1[0][j][i - 1], dp1[1][j][i - 1]));
        }
    }
    cout << dp2[n] << '\n';
}