#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int inf = 2e9;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n, vector<int>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        if(m > n) {
            vector<int> col_max(m);
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < m; ++j) {
                    col_max[j] = max(col_max[j], a[i][j]);
                }
            }
            vector<int> ord(m);
            iota(ord.begin(), ord.end(), 0);
            sort(ord.begin(), ord.end(), [&](int i, int j) {return col_max[i] > col_max[j];});
            vector<vector<int>> b(n, vector<int>(n));
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    b[i][j] = a[i][ord[j]];
                }
            }
            m = n;
            a = b;
        }
        vector<int> dp(1 << n, -inf);
        dp[(1 << n) - 1] = 0;
        for(int i = 0; i < m; ++i) {
            vector<int> b;
            for(int j = 0; j < n; ++j) {
                b.push_back(a[j][i]);
            }
            vector<int> ndp = dp;
            for(int j = 0; j < n; ++j) {
                for(int k = 0; k < 1 << n; ++k) {
                    if(dp[k] == -inf) continue;
                    for(int p = k; p; p = (p - 1) & k) {
                        int sum = 0;
                        for(int q = 0; q < n; ++q) {
                            if(p >> q & 1) sum += b[q];
                        }
                        ndp[p ^ k] = max(ndp[p ^ k], dp[k] + sum);
                    }
                }
                rotate(b.begin(), b.begin() + 1, b.end());
            }
            dp = ndp;
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}