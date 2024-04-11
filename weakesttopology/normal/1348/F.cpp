#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> l(n), r(n);
    vector<vector<int>> I(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i], --r[i];
        I[l[i]].push_back(i);
    }
    priority_queue<pair<int, int>> pq;
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; ++i) {
        for (auto j : I[i]) pq.emplace(-r[j], j);
        I[i].clear();
        auto j = pq.top().second;
        pq.pop();
        p[j] = i, inv[i] = j;
    }
    set<int> S;
    for (int i = 0; i < n; ++i) S.insert(i);
    enum State {unvisited, active, visited};
    vector<State> st(n);
    vector<int> cycle;
    for (int j = 0; j < n; ++j) {
        if (st[j] == visited) continue;
        stack<int> stk;
        auto dfs = [&](auto& self, int j) -> bool {
            if (st[j] == active) {
                auto f = [&]() {
                    cycle.push_back(stk.top());
                    stk.pop();
                };
                f();
                while (j != stk.top()) {
                    for (int t = 0; t < 2; ++t) f();
                }
                f();
                return true;
            }
            st[j] = active;
            stk.push(j);
            while (true) {
                auto iter = S.lower_bound(l[j]);
                if (iter != end(S) && *iter == p[j]) ++iter;
                if (iter == end(S) || *iter > r[j]) break;
                int i = *iter;
                if (i == p[j]) continue;
                stk.push(i);
                if (self(self, inv[i])) return true;
                stk.pop();
            }
            S.erase(p[j]);
            st[j] = visited;
            stk.pop();
            return false;
        };
        if (dfs(dfs, j)) break;
    }
    int k = (int)size(cycle);
    if (k > 0) {
        reverse(begin(cycle), end(cycle));
        auto q = p;
        for (int l = 0; l < k; l += 2) {
            int j = cycle[l], i = cycle[l + 1];
            q[j] = i;
        }
        cout << "NO" << endl;
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << "\n "[i + 1 < n];
        }
        for (int i = 0; i < n; ++i) {
            cout << q[i] + 1 << "\n "[i + 1 < n];
        }
    }
    else {
        cout << "YES" << endl;
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << "\n "[i + 1 < n];
        }
    }
    exit(0);
}