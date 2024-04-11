#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        // solve for n % 2 == 0
        auto solve = [](int n, int m, int k) {
            assert(n % 2 == 0 && k % 2 == 0);
            vector<vector<char>> ans(n, vector<char>(m));
            for(int i = 0; i < n; i += 2) {
                for(int j = 0; j < m; ++j) {
                    ans[i][j] = ans[i+1][j] = 'a' + (i % 3 * 3 + j % 3);
                }
            }
            for(int i = 0; i < n; i += 2) {
                for(int j = 0; j + 1 < m && k; j += 2) {
                    swap(ans[i][j], ans[i+1][j+1]);
                    k -= 2;
                }
            }
            return ans;
        };
        if(n % 2 == 0) {
            // put n / 2 * m vertical dominos
            if(k % 2 == 0 && k <= n * m / 2 - n / 2) {
                cout << "YES" << endl;
                auto ans = solve(n, m, k);
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        cout << ans[i][j];
                    }
                    cout << endl;
                }
                continue;
            }
        }
        if(m % 2 == 0) {
            // put m / 2 * n horizontal dominos
            if((n * m / 2 - k) % 2 == 0 && k >= m / 2) {
                cout << "YES" << endl;
                auto ans = solve(m, n, n * m / 2 - k);
                for(int i = 0; i < n; ++i) {
                    for(int j = 0; j < m; ++j) {
                        cout << ans[j][i];
                    }
                    cout << endl;
                }
                continue;
            }
        }
        cout << "NO" << endl;
    }
}