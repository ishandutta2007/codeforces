#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m));
    for (int i = 1; i <= n; i++) {
        for (auto& j : a[i]) {
            cin >> j;
        }
    }

    int best = 0;
    vector<int> freq;
    pair<int, int> sol = {1, 1};
    for (int b = 1 << 29; b; b /= 2) {
        int mn = best + b;
        pair<int, int> tmp = {0, 0};
        freq.assign(1 << m, -1);
        for (int i = 1; i <= n; i++) {
            int tmp = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] >= mn) {
                    tmp |= 1 << j;
                }
            }
            freq[tmp] = i;
        }
        for (int i = 0; i < freq.size(); i++) {
            for (int j = i; j < freq.size(); j++) {
                if (freq[i] != -1 && freq[j] != -1 && (i | j) == (1 << m) - 1) {
                    tmp = {freq[i], freq[j]};
                }
            }
        }
        if (tmp.first || tmp.second) {
            sol = tmp;
            best += b;
        }
    }
    cout << sol.first << ' ' << sol.second << '\n';
}