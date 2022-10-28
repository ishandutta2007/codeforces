#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6;

vector<int> weapon, armor;
vector<int> st, lazy;

void push(int v) {
    st[v * 2] += lazy[v];
    lazy[v * 2] += lazy[v];
    st[v * 2 + 1] += lazy[v];
    lazy[v * 2 + 1] += lazy[v];
    lazy[v] = 0;
}

void build(int v, int l, int r) {
    if (l == r) {
        st[v] = weapon[l];
    } else {
        int m = (l + r) / 2;
        build(v * 2, l, m);
        build(v * 2 + 1, m + 1, r);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}

void update(int v, int l, int r, int a, int b, int add) {
    if (a > b) return;
    if (a == l && b == r) {
        st[v] += add;
        lazy[v] += add;
    } else {
        push(v);
        int m = (l + r) / 2;
        update(v * 2, l, m, a, min(b, m), add);
        update(v * 2 + 1, m + 1, r, max(a, m + 1), b, add);
        st[v] = max(st[v * 2], st[v * 2 + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, p;
    cin >> n >> m >> p;
    weapon.resize(MX + 1, -1e9);
    for (int i = 0; i < n; ++i) {
        int a, ca;
        cin >> a >> ca;
        weapon[a] = max(weapon[a], -ca);
    }
    st.resize(4 * MX + 4);
    lazy.resize(4 * MX + 4);
    build(1, 0, MX);
    armor.resize(MX + 1);
    for (int i = 0; i < m; ++i) {
        int b, cb;
        cin >> b >> cb;
        if (armor[b]) {
            armor[b] = max(armor[b], -cb);
        } else {
            armor[b] = -cb;
        }
    }
    vector<vector<pair<int, int>>> mons(MX + 1);
    for (int i = 0; i < p; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        mons[b].emplace_back(a, c);
    }

    int sol = -2e9;
    for (int i = 1; i <= MX; ++i) {
        if (armor[i]) {
            update(1, 0, MX, 0, MX, armor[i]);
            sol = max(sol, st[1]);
            update(1, 0, MX, 0, MX, -armor[i]);
        }
        for (auto j : mons[i]) {
            update(1, 0, MX, j.first + 1, MX, j.second);
        }
    }
    cout << sol << '\n';
}