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
        vector<vector<char>> a(n, vector<char>(m));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<vector<int>> good(n, vector<int>(m));
        for(int i = n - 1; i >= 0; --i) {
            for(int j = m - 1; j >= 0; --j) {
                if(a[i][j] == '*') {
                    int lx = i, ly = j, rx = i, ry = j, ok = 1;
                    for(int d = 0; d < k; ++d) {
                        --lx, --ly;
                        --rx, ++ry;
                        if(lx < 0 || ly < 0 || rx < 0 || ry == m || a[lx][ly] != '*' || a[rx][ry] != '*') {
                            ok = 0;
                            break;
                        }
                    }
                    if(ok == 0) continue;
                    lx = i, ly = j, rx = i, ry = j, ok = 1;
                    good[i][j] = 1;
                    for(int d = 0; d < k; ++d) {
                        --lx, --ly;
                        --rx, ++ry;
                        good[lx][ly] = good[rx][ry] = 1;
                    }
                    for(int d = 0;; ++d) {
                        --lx, --ly;
                        --rx, ++ry;
                        if(lx < 0 || ly < 0 || rx < 0 || ry == m || a[lx][ly] != '*' || a[rx][ry] != '*') {
                            ok = 0;
                            break;
                        }
                        good[lx][ly] = good[rx][ry] = 1;
                    }
                }
            }
        }
        int ok = 1;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(a[i][j] == '*' && good[i][j] == 0) {
                    ok = 0;
                }
            }
        }
        cout << (ok ? "Yes" : "No") << endl;
    }
}