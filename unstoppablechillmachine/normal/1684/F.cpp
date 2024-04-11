#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 2e5 + 10;
const int L = 19;
int a[N];
vector<int> kek[N];
vector<pair<int, int>> check[N];

struct fenwick {
    vector<int> t;
    int n;
    fenwick(int n) : n(n) {
        t.resize(n + 1);
    }
    void update(int v, int delta) {
        for (; v <= n; v += v & (-v)) {
            t[v] += delta;
        }
    }
    int get(int v) {
        int res = 0;
        for (; v > 0; v -= v & (-v)) {
            res += t[v];
        }
        return res;
    }
    int get_sum(int l, int r) {
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
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++) {
            kek[i] = {};
        }
        set<int> diff;
        map<int, vector<int>> have;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            diff.insert(a[i]);
            have[a[i]].push_back(i);
        }
        vector<int> nxt(n + 1);
        map<int, int> lst;
        for (int i = n; i >= 1; i--) {
            if (lst.count(a[i])) {
                nxt[i] = lst[a[i]];
            } else {
                nxt[i] = 0;
            }
            lst[a[i]] = i;
        }
        if (diff.size() == n) {
            cout << 0 << '\n';
            continue;
        }
        fenwick tree(n);
        vector<int> l(m), r(m);
        vector<int> L_pref(m), R_pref(m), L_suf(m), R_suf(m);
        for (int i = 0; i < m; i++) {
            cin >> l[i] >> r[i];
            L_pref[i] = 1;
            R_pref[i] = r[i] - l[i] + 2;
            L_suf[i] = 1;
            R_suf[i] = r[i] - l[i] + 2;
        }

        for (int iter = 0; iter < L; iter++) {
            vector<bool> ok(m, false);
            for (int i = 0; i <= n; i++) {
                check[i] = {};
            }
            for (int i = 0; i < m; i++) {
                int md = (L_pref[i] + R_pref[i]) / 2;
                check[l[i]].push_back({l[i] + md - 1, i});
            }
            for (int i = 0; i <= n; i++) {
                tree.t[i] = 0;
            }
            for (auto [x, y] : lst) {
                tree.update(y, 1);
            }
            for (int i = 1; i <= n; i++) {
                for (auto [r_border, id] : check[i]) {
                    if (tree.get_sum(i, r_border) == r_border - i + 1) {
                        ok[id] = true;
                    }
                }
                if (nxt[i]) {
                    tree.update(nxt[i], 1);
                }
            }

            for (int i = 0; i < m; i++) {
                if (ok[i]) {
                    L_pref[i] = (L_pref[i] + R_pref[i]) / 2;
                } else {
                    R_pref[i] = (L_pref[i] + R_pref[i]) / 2;
                }
            }
        }

        for (int iter = 0; iter < L; iter++) {
            vector<bool> ok(m, false);
            for (int i = 0; i <= n; i++) {
                check[i] = {};
            }
            for (int i = 0; i < m; i++) {
                int md = (L_suf[i] + R_suf[i]) / 2;
                check[r[i] - md + 1].push_back({r[i], i});
            }
            for (int i = 0; i <= n; i++) {
                tree.t[i] = 0;
            }
            for (auto [x, y] : lst) {
                tree.update(y, 1);
            }
            for (int i = 1; i <= n; i++) {
                for (auto [r_border, id] : check[i]) {
                    if (tree.get_sum(i, r_border) == r_border - i + 1) {
                        ok[id] = true;
                    }
                }
                if (nxt[i]) {
                    tree.update(nxt[i], 1);
                }
            }

            for (int i = 0; i < m; i++) {
                if (ok[i]) {
                    L_suf[i] = (L_suf[i] + R_suf[i]) / 2;
                } else {
                    R_suf[i] = (L_suf[i] + R_suf[i]) / 2;
                }
            }
        }

        set<pair<int, int>> r_bad;
        int mx_left_border = n;
        for (int i = 0; i < m; i++) {
            if (L_pref[i] == r[i] - l[i] + 1) {
                continue;
            }
            r_bad.insert({r[i] - L_suf[i], i});
            kek[l[i]].push_back(i);
            mx_left_border = min(mx_left_border, l[i] + L_pref[i]);
        }
        if (r_bad.empty()) {
            cout << 0 << '\n';
            continue;
        }

        int answer = n, c_max = 0, val = 0;
        for (int left_border = 1; left_border <= mx_left_border; left_border++) {
            int current = left_border - 1;
            if (!r_bad.empty()) {
                current = max(current, r_bad.rbegin()->first);
            }
            if (left_border > 1) {
                for (auto it : kek[left_border - 1]) {
                    c_max = max(c_max, r[it]);
                }
                auto guy = upper_bound(have[a[left_border - 1]].begin(), have[a[left_border - 1]].end(), c_max);
                if (guy != have[a[left_border - 1]].begin()) {
                    guy--;
                    val = max(val, *guy);
                }
            }
            current = max(current, val);
            /*for (auto it : kek[left_border]) {
                r_bad.erase({r[it] - L_suf[it], it});
            }*/
            answer = min(answer, current - left_border + 1);
        }
        assert(answer > 0);
        cout << answer << '\n';
    }
    return 0;
}