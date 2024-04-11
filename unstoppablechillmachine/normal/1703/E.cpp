#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

struct fenwick {
    vector<int> t;
    int n;
    fenwick(int _n) : n(_n) {
        t.resize(n + 1, 0);
    }
    void update(int v, int delta) {
        for (; v <= n; v += v & (-v)) {
            t[v] += delta;
        }
    }
    int get(int v) {
        v = min(v, n);
        int result = 0;
        for (; v > 0; v -= v & (-v)) {
            result += t[v];
        }
        return result;
    }
    int get_sum(int l, int r) {
        l = max(l, 1ll);
        r = min(r, n);
        if (l > r) {
            return 0;
        }
        return get(r) - get(l - 1);
    }
};

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        auto rotate_on_90 = [n](pair<int, int> cell) -> pair<int, int> {
            return {n - cell.second - 1, cell.first};
        };
        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = a[i][j] - '0';
                pair<int, int> nxt = rotate_on_90({i, j});
                sum += (a[nxt.first][nxt.second] - '0');
                nxt = rotate_on_90(nxt);
                sum += (a[nxt.first][nxt.second] - '0');
                nxt = rotate_on_90(nxt);
                sum += (a[nxt.first][nxt.second] - '0');
                answer += min(sum, 4 - sum);
            }
        }
        cout << answer / 4 << '\n';
    }
    return 0;
}