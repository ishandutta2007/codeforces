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
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int answer = 0;
        fenwick tree(n);
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= i + 1) {
                continue;
            }
            answer += tree.get_sum(i + 2, n);
            if (a[i] > 0) {
                tree.update(a[i], 1);
            }
        }
        cout << answer << '\n';
    }
    return 0;
}