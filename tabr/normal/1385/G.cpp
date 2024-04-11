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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> a(2, vector<int>(n));
        vector<int> cnt(n);
        vector<vector<pair<int, int>>> pos(2, vector<pair<int, int>>(n));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
                a[i][j]--;
                pos[cnt[a[i][j]] % 2][a[i][j]] = make_pair(i, j);
                cnt[a[i][j]]++;
            }
        }
        if (*max_element(cnt.begin(), cnt.end()) != 2) {
            cout << -1 << '\n';
            continue;
        }
        cnt = vector<int>(n);
        vector<int> ans;
        function<void(int)> add = [&](int j) {
            swap(a[0][j], a[1][j]);
            for (int i = 0; i < 2; i++) {
                int b = a[i][j];
                for (int k = 0; k < 2; k++) {
                    if (pos[k][b].second == j) {
                        pos[k][b].first ^= 1;
                    }
                }
            }
        };
        for (int i = 0; i < n; i++) {
            if (cnt[i]) {
                continue;
            }
            vector<int> x, y;
            cnt[i] = 1;
            if (pos[0][i].first == pos[1][i].first) {
                add(pos[0][i].second);
                x.emplace_back(pos[0][i].second);
            } else {
                y.emplace_back(pos[0][i].second);
            }
            pair<int, int> p = pos[0][i];
            p.first ^= 1;
            int k = a[p.first][p.second];
            while (i != k) {
                assert(!cnt[k]);
                cnt[k] = 1;
                pair<int, int> q = (pos[0][k] == p ? pos[1][k] : pos[0][k]);
                if (p.first == q.first) {
                    add(q.second);
                    x.emplace_back(q.second);
                } else {
                    y.emplace_back(q.second);
                }
                q = (pos[0][k] == p ? pos[1][k] : pos[0][k]);
                q.first ^= 1;
                k = a[q.first][q.second];
                swap(p, q);
            }
            if (x.size() > y.size()) {
                swap(x, y);
            }
            ans.insert(ans.end(), x.begin(), x.end());
        }
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}