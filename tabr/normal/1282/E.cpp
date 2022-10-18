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
        vector<int> s(n);
        vector<vector<int>> g(n);
        vector<vector<pair<int, int>>> mp(n);
        map<tuple<int, int, int>, int> mq;
        vector<int> q;
        queue<int> que;
        for (int i = 0; i < n - 2; i++) {
            vector<int> a(3);
            for (int j = 0; j < 3; j++) {
                cin >> a[j];
                a[j]--;
                s[a[j]]++;
            }
            for (int j = 0; j < 3; j++) {
                mp[a[j]].emplace_back(a[(j + 1) % 3], a[(j + 2) % 3]);
            }
            sort(a.begin(), a.end());
            mq[{a[0], a[1], a[2]}] = i + 1;
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 1) {
                que.push(i);
            }
        }
        set<pair<int, int>> ng;
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            if (s[v] != 1) {
                continue;
            }
            vector<int> a(3);
            a[0] = v;
            for (auto p : mp[v]) {
                if (s[p.first] != 0 && s[p.second] != 0) {
                    a[1] = p.first;
                    a[2] = p.second;
                    for (int i = 1; i < 3; i++) {
                        que.push(a[i]);
                        if (!ng.count({min(v, a[i]), max(v, a[i])})) {
                            g[v].emplace_back(a[i]);
                            g[a[i]].emplace_back(v);
                            ng.emplace(min(v, a[i]), max(v, a[i]));
                        }
                    }
                    break;
                }
            }
            ng.emplace(min(a[1], a[2]), max(a[1], a[2]));
            sort(a.begin(), a.end());
            for (int i = 0; i < 3; i++) {
                s[a[i]]--;
            }
            q.emplace_back(mq[{a[0], a[1], a[2]}]);
        }
        int st = -1;
        for (int i = 0; i < n; i++) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
            if (g[i].size() == 1) {
                if (st == -1) {
                    st = i;
                } else {
                    g[st].emplace_back(i);
                    g[i].emplace_back(st);
                }
            }
        }
        debug(g);
        vector<int> p(1);
        p.emplace_back(g[0][0]);
        int pos = g[0][0], lst = 0;
        for (int ss = 0; ss < n - 1; ss++) {
            p.emplace_back(g[pos][0] ^ g[pos][1] ^ lst);
            lst = pos;
            pos = p.back();
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] + 1 << " ";
        }
        cout << endl;
        for (int i = 0; i < n - 2; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
    return 0;
}