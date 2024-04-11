#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> k;
    vector<vector<int>> x(4);
    for (int i = 0; i < n; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        a ^= 1, b ^= 1;
        x[2 * a + b].emplace_back(t);
    }
    for (int i = 0; i < 4; i++) {
        sort(x[i].begin(), x[i].end());
        x[i].emplace_back(-1);
    }
    for (int i = 0; i < x[1].size(); i++) {
        if (x[1][i] == -1 || x[2][i] == -1) {
            x[1][i] = -1;
            break;
        }
        x[1][i] += x[2][i];
    }
    int t = 0;
    int a = 0, b = 0;
    for (int i = 0; i < k; i++) {
        if (x[0][a] == -1 && x[1][b] == -1) {
            cout << -1 << '\n';
            return 0;
        }
        if (x[0][a] == -1) {
            t += x[1][b];
            b++;
            continue;
        }
        if (x[1][b] == -1) {
            t += x[0][a];
            a++;
            continue;
        }
        if (x[0][a] < x[1][b]) {
            t += x[0][a];
            a++;
        } else {
            t += x[1][b];
            b++;
        }
    }
    cout << t << '\n';
    return 0;
}