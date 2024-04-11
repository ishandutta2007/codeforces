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
    int n;
    cin >> n;
    vector<int> z(n * n);
    vector<string> ans(n, string(n, ' '));
    for (int i = 0; i < n * n; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        z[i] = max(-1, x * n + y);
    }
    for (int k = 0; k < n * n; k++) {
        if (z[k] == -1) {
            int i = k / n, j = k % n;
            if (i != 0 && z[k - n] == -1) {
                ans[i][j] = 'U';
            } else if (i != n - 1 && z[k + n] == -1) {
                ans[i][j] = 'D';
            } else if (j != 0 && z[k - 1] == -1) {
                ans[i][j] = 'L';
            } else if (j != n - 1 && z[k + 1] == -1) {
                ans[i][j] = 'R';
            } else {
                cout << "INVALID" << '\n';
                return 0;
            }
        }
    }
    int root;
    function<void(int)> dfs = [&](int k) {
        int i = k / n, j = k % n;
        if (i != 0 && z[k - n] == root && ans[i - 1][j] == ' ') {
            ans[i - 1][j] = 'D';
            dfs(k - n);
        }
        if (i != n - 1 && z[k + n] == root && ans[i + 1][j] == ' ') {
            ans[i + 1][j] = 'U';
            dfs(k + n);
        }
        if (j != 0 && z[k - 1] == root && ans[i][j - 1] == ' ') {
            ans[i][j - 1] = 'R';
            dfs(k - 1);
        }
        if (j != n - 1 && z[k + 1] == root && ans[i][j + 1] == ' ') {
            ans[i][j + 1] = 'L';
            dfs(k + 1);
        }
    };
    for (int k = 0; k < n * n; k++) {
        if (z[k] == -1) {
            continue;
        }
        int i = z[k] / n, j = z[k] % n;
        if (ans[i][j] == ' ') {
            ans[i][j] = 'X';
            if (z[z[k]] != z[k]) {
                cout << "INVALID" << '\n';
                return 0;
            }
            root = z[k];
            dfs(z[k]);
        } else if (ans[i][j] != 'X') {
            cout << "INVALID" << '\n';
            return 0;
        }
        if (ans[k / n][k % n] == ' ') {
            cout << "INVALID" << '\n';
            return 0;
        }
    }
    cout << "VALID" << '\n';
    for (string s : ans) {
        cout << s << '\n';
    }
    return 0;
}