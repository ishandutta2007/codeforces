#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int h, w;
        cin >> h >> w;
        vector<string> g(h, string(w, '0'));
        g[0][0] = g[h - 1][0] = g[0][w - 1] = g[h - 1][w - 1] = '1';
        for (int i = 3; i < h - 1; i += 2) {
            for (int j : {0, w - 1}) {
                g[i - 1][j] = '1';
            }
        }
        for (int j = 3; j < w - 1; j += 2) {
            for (int i : {0, h - 1}) {
                g[i][j - 1] = '1';
            }
        }
        for (int i = 0; i < h; ++i) {
            cout << g[i] << '\n';
        }
        cout << '\n';
    }
    exit(0);
}