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
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    bool e1 = false, e2 = false;
    for (int i = 0; i < h; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < h; i++) {
        int cnt = 0;
        if (s[i][0] == '#') {
            cnt++;
        }
        for (int j = 0; j < w - 1; j++) {
            if (s[i][j] == '.' && s[i][j + 1] == '#') {
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << -1 << '\n';
            return 0;
        }
        if (cnt == 0) {
            e1 = true;
        }
    }
    for (int j = 0; j < w; j++) {
        int cnt = 0;
        if (s[0][j] == '#') {
            cnt++;
        }
        for (int i = 0; i < h - 1; i++) {
            if (s[i][j] == '.' && s[i + 1][j] == '#') {
                cnt++;
            }
        }
        if (cnt >= 2) {
            cout << -1 << '\n';
            return 0;
        }
        if (cnt == 0) {
            e2 = true;
        }
    }
    if (e1 != e2) {
        cout << -1 << '\n';
        return 0;
    }
    function<void(int, int)> dfs = [&](int i, int j) {
        if (i != 0 && s[i - 1][j] == '#') {
            s[i - 1][j] = '.';
            dfs(i - 1, j);
        }
        if (i != h - 1 && s[i + 1][j] == '#') {
            s[i + 1][j] = '.';
            dfs(i + 1, j);
        }
        if (j != 0 && s[i][j - 1] == '#') {
            s[i][j - 1] = '.';
            dfs(i, j - 1);
        }
        if (j != w - 1 && s[i][j + 1] == '#') {
            s[i][j + 1] = '.';
            dfs(i, j + 1);
        }
    };
    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#') {
                ans++;
                s[i][j] = '.';
                dfs(i, j);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}