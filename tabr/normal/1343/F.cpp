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
        vector<vector<int>> a(n);
        vector<set<int>> st(n);
        for (int i = 0; i < n - 1; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int b;
                cin >> b;
                b--;
                a[i].emplace_back(b);
                st[b].emplace(i);
            }
        }
        vector<vector<int>> p;
        vector<set<int>> tmp = st;
        for (int i = 0; i < n; i++) {
            st = tmp;
            st[i].emplace(n - 1);
            vector<int> q;
            while (true) {
                int x = -1;
                for (int j = 0; j < n; j++) {
                    if (st[j].size() == 1) {
                        if (x != -1) {
                            x = -1;
                            break;
                        }
                        x = j;
                    }
                }
                if (x == -1) {
                    break;
                }
                q.emplace_back(x);
                x = *st[x].begin();
                for (int j = 0; j < n; j++) {
                    st[j].erase(x);
                }
            }
            if (q.size() == n) {
                reverse(q.begin(), q.end());
                p.emplace_back(q);
            }
        }
        vector<int> ans;
        int m = p.size();
        for (int i = 0; i < m; i++) {
            vector<int> pos(n);
            for (int j = 0; j < n; j++) {
                pos[p[i][j]] = j;
            }
            bool ok = true;
            for (int j = 0; j < n - 1; j++) {
                int mn = n, mx = 0;
                for (int k = 0; k < a[j].size(); k++) {
                    mn = min(mn, pos[a[j][k]]);
                    mx = max(mx, pos[a[j][k]]);
                }
                if (mx - mn != a[j].size() - 1) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                ans = p[i];
                break;
            }
        }
        for (int i : ans) {
            cout << i + 1 << " ";
        }
        cout << '\n';
        /*
        vector<set<int>> st(n);
        for (int i = 0; i < n - 1; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int a;
                cin >> a;
                a--;
                st[a].emplace(i);
            }
        }
        pair<int, int> can(-1, -1);
        vector<set<int>> t = st;
        vector<int> cnt(n);
        for (int i = 0; i < n; i++) {
            vector<int> x;
            for (int j = 0; j < n; j++) {
                if (st[j].size() == 1) {
                    x.emplace_back(j);
                }
            }
            if (x.size() == 2) {
                can = {x[0], x[1]};
                if (cnt[x[1]] > cnt[x[0]]) {
                    swap(can.first, can.second);
                }
                break;
            }
            for (int j = 0; j < n; j++) {
                if (st[j].count(x[0])) {
                    st[j].erase(x[0]);
                    cnt[j]++;
                }
            }
        }
        debug(can);
        vector<int> p;
        for (int k = 0; k < 2; k++) {
            vector<int> q;
            st = t;
            st[can.second].emplace(n);
            for (int i = 0; i < n; i++) {
                int x = -1;
                for (int j = 0; j < n; j++) {
                    if (st[j].size() == 1) {
                        assert(x == -1);
                        x = *st[j].begin();
                        q.emplace_back(j);
                    }
                }
                if (x == -1) {
                    break;
                }
                for (int j = 0; j < n; j++) {
                    if (st[j].count(x)) {
                        st[j].erase(x);
                    }
                }
            }
            debug(q.size());
            if (q.size() == n) {
                reverse(q.begin(), q.end());
                p = q;
                break;
            }
            swap(can.first, can.second);
        }
        for (int i : p) {
            cout << i + 1 << " ";
        }
        cout << '\n';
        */
    }
    return 0;
}