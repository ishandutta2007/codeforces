#include <bits/stdc++.h>
using namespace std;

vector<int> par, sz;

int find(int a) {
    if (par[a] == a) return a;
    return par[a] = find(par[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        if (sz[a] > sz[b]) {
            swap(a, b);
        }
        par[a] = b;
        sz[b] += sz[a];
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> seg(n);
    vector<pair<int, int>> evnt(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> seg[i].first >> seg[i].second;
        evnt[i] = {seg[i].first, i};
        evnt[i + n] = {seg[i].second, i};
    }
    sort(evnt.begin(), evnt.end());

    par.resize(n);
    iota(par.begin(), par.end(), 0);
    sz.assign(n, 1);

    int ct = 0;
    map<int, int> cur;
    for (auto i : evnt) {
        if (ct >= n) break;
        int b = seg[i.second].second;
        if (cur.count(b)) {
            cur.erase(b);
        } else {
            for (auto j : cur) {
                if (j.first > b) break;
                unite(j.second, i.second);
                ++ct;
            }
            cur[b] = i.second;
        }
    }

    bool ok = (ct == n - 1);
    for (int i = 1; i < n && ok; ++i) {
        ok = (find(0) == find(i));
    }
    cout << (ok ? "YES" : "NO") << '\n';
}