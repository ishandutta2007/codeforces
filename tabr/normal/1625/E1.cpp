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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> a(n + 1);
    vector<int> p(n);
    stack<int> stk;
    for (int i = 0; i < n; i++) {
        a[i + 1] = a[i] + (s[i] == '(' ? 1 : -1);
        if (s[i] == '(') {
            stk.emplace(i);
        } else if (!stk.empty()) {
            p[stk.top()] = i;
            p[i] = stk.top();
            stk.pop();
        }
    }
    vector<tuple<int, int, int>> t;
    for (int i = 0; i < n; i++) {
        if (p[i] > i) {
            t.emplace_back(-a[i], i, p[i]);
        }
    }
    sort(t.begin(), t.end());
    vector<long long> ans;
    for (auto [depth, l, r] : t) {
        int beg = l + 1;
        long long sum = 1;
        int cnt = 0;
        while (beg < r) {
            int end = p[beg];
            tuple<int, int, int> z = make_tuple(depth - 1, beg, end);
            int i = (int) (lower_bound(t.begin(), t.end(), z) - t.begin());
            assert(t[i] == z);
            sum += ans[i];
            beg = end + 1;
            cnt++;
        }
        sum += 1LL * cnt * (cnt - 1) / 2;
        ans.emplace_back(sum);
    }
    int sz = (int) t.size();
    vector<vector<int>> nxt(20, vector<int>(sz + 1, sz));
    for (int i = 0; i + 1 < sz; i++) {
        auto [d1, l1, r1] = t[i];
        auto [d2, l2, r2] = t[i + 1];
        if (d1 == d2 && r1 + 1 == l2) {
            nxt[0][i] = i + 1;
        }
    }
    for (int i = 1; i < 20; i++) {
        for (int j = 0; j < sz; j++) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        }
    }
    vector<long long> pref(ans.size() + 1);
    for (int i = 0; i < (int) ans.size(); i++) {
        pref[i + 1] = pref[i] + ans[i];
    }
    while (q--) {
        int op, l, r;
        cin >> op >> l >> r;
        l--;
        int cnt = 0;
        tuple<int, int, int> z = make_tuple(-a[l], l, p[l]);
        int i = (int) (lower_bound(t.begin(), t.end(), z) - t.begin());
        assert(t[i] == z);
        for (int j = 19; j >= 0; j--) {
            if (nxt[j][i + cnt] != sz) {
                int k = nxt[j][i + cnt];
                if (get<2>(t[k]) < r) {
                    cnt += 1 << j;
                }
            }
        }
        debug(cnt);
        long long sum = pref[i + cnt + 1] - pref[i];
        cnt++;
        sum += 1LL * cnt * (cnt - 1) / 2;
        cout << sum << '\n';
    }
    return 0;
}