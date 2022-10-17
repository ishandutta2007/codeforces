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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (auto &x : a) {
            cin >> x;
        }
        int sum = 0, answer = 0;
        for (int pref_len = 0; pref_len <= n; pref_len++) {
            int cur = sum;
            for (int i = pref_len + 1; i <= min(pref_len + 30, n); i++) {
                cur += a[i - 1] >> (i - pref_len);
            }
            answer = max(answer, cur);
            if (pref_len < n) {
                sum += a[pref_len] - k;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}