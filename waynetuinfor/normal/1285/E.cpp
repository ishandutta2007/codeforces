#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const int kInf = 2'000'000'000 + 1;
vector<pair<int, int>> v[4 * kN];
int l[kN], r[kN];

void Insert(int l, int r, int ql, int qr, int x, int y, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        v[o].emplace_back(x, y);
        return;
    }
    Insert(l, (l + r) >> 1, ql, qr, x, y, o * 2 + 1);
    Insert((l + r) >> 1, r, ql, qr, x, y, o * 2 + 2);
}

void Debug(const set<pair<int, int>> &s) {
    for (auto p : s) printf("(%d, %d) ", p.first, p.second);
    puts("");
}

int Dfs(int l, int r, set<pair<int, int>> &s, int o = 0) {
    vector<tuple<int, int, int>> ev;
    for (auto &p : v[o]) {
        auto it = s.upper_bound(make_pair(p.first, kInf));
        if (it != s.begin()) it = prev(it); 
        while (it != s.end() && it->first <= p.second) {
            if (it->second >= p.first) {
                ev.emplace_back(it->first, it->second, 0); 
                p.first = min(p.first, it->first);
                p.second = max(p.second, it->second);
                it = s.erase(it);
            } else {
                it = next(it);
            }
        }
        ev.emplace_back(p.first, p.second, 1);
        s.insert(p);
    }
    int res = 0;
    if (r - l == 1) {
        res = s.size();
    } else {
        int m = (l + r) >> 1;
        res = max(Dfs(l, m, s, o * 2 + 1), Dfs(m, r, s, o * 2 + 2));
    }
    while (!ev.empty()) {
        auto p = ev.back(); ev.pop_back();
        if (get<2>(p) == 0) s.insert(make_pair(get<0>(p), get<1>(p)));
        else s.erase(make_pair(get<0>(p), get<1>(p)));
    }
    return res;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < 4 * n; ++i) v[i].clear();
        for (int i = 0; i < n; ++i) scanf("%d%d", &l[i], &r[i]);
        for (int i = 0; i < n; ++i) {
            Insert(0, n, 0, i, l[i], r[i]);
            Insert(0, n, i + 1, n, l[i], r[i]);
        }
        set<pair<int, int>> s;
        printf("%d\n", Dfs(0, n, s));
    }
    return 0;
}