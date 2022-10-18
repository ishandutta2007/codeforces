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
    int h, w, t;
    cin >> h >> w >> t;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < w; j++) {
            a[i][j] = s[j] - '0';
        }
    }
    int inf = 1e9;
    vector<vector<int>> s(h, vector<int>(w, inf));
    queue<pair<int, int>> que;
    int c = 0;
    vector<int> di = {1, -1, 0, 0}, dj = {0, 0, 1, -1};
    auto get = [&](int i, int j) {
        if (c < s[i][j]) {
            return a[i][j];
        }
        int d = (c - s[i][j]) % 2;
        return a[i][j] ^ d;
    };
    auto check = [&](int i, int j) {
        bool ok = false;
        for (int k = 0; k < 4; k++) {
            if (0 <= i + di[k] && i + di[k] < h && 0 <= j + dj[k] && j + dj[k] < w) {
                if (get(i, j) == get(i + di[k], j + dj[k])) {
                    ok = true;
                }
            }
        }
        return ok;
    };
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (check(i, j)) {
                s[i][j] = 0;
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        c++;
        for (int q = que.size(); q > 0; q--) {
            int i, j;
            tie(i, j) = que.front();
            que.pop();
            if (i && s[i - 1][j] == inf && check(i - 1, j)) {
                s[i - 1][j] = c;
                que.emplace(i - 1, j);
            }
            if (i != h - 1 && s[i + 1][j] == inf && check(i + 1, j)) {
                s[i + 1][j] = c;
                que.emplace(i + 1, j);
            }
            if (j && s[i][j - 1] == inf && check(i, j - 1)) {
                s[i][j - 1] = c;
                que.emplace(i, j - 1);
            }
            if (j != w - 1 && s[i][j + 1] == inf && check(i, j + 1)) {
                s[i][j + 1] = c;
                que.emplace(i, j + 1);
            }
        }
    }
    while (t--) {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--, j--;
        if (p < s[i][j] || s[i][j] == inf) {
            cout << a[i][j] << '\n';
        } else {
            p -= s[i][j];
            p %= 2;
            cout << (a[i][j] ^ p) << '\n';
        }
    }
    return 0;
}