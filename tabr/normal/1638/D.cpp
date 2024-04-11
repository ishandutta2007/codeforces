#include <bits/stdc++.h>
using namespace std;
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
    vector<vector<int>> c(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> c[i][j];
            c[i][j]--;
        }
    }
    vector<vector<int>> b(h - 1, vector<int>(w - 1));
    queue<tuple<int, int, int>> que;
    auto check = [&](int x, int y) {
        if (x < 0 || x >= h - 1 || y < 0 || y >= w - 1) {
            return false;
        }
        if (b[x][y]) {
            return false;
        }
        set<int> st;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                st.emplace(c[x + i][y + j]);
            }
        }
        st.erase(-1);
        if (st.size() == 1) {
            que.emplace(x, y, *st.begin());
            b[x][y] = 1;
            return true;
        }
        return false;
    };
    vector<vector<int>> ans;
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            check(i, j);
        }
    }
    while (!que.empty()) {
        auto [i, j, a] = que.front();
        que.pop();
        ans.emplace_back(vector<int>{i, j, a});
        for (int di = 0; di < 2; di++) {
            for (int dj = 0; dj < 2; dj++) {
                c[i + di][j + dj] = -1;
            }
        }
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                check(i + di, j + dj);
            }
        }
    }
    for (int i = 0; i < h - 1; i++) {
        for (int j = 0; j < w - 1; j++) {
            if (!b[i][j]) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto v : ans) {
        for (int i = 0; i < 3; i++) {
            cout << v[i] + 1 << " \n"[i == 2];
        }
    }
    return 0;
}