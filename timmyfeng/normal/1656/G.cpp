#include <bits/stdc++.h>
using namespace std;

struct union_find {
    union_find(int n = 0) : parent(n), size(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) swap(u, v);
            parent[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }

    vector<int> parent, size;
};

void solve() {
    int n; cin >> n;

    vector pos(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        int a; cin >> a; --a;
        pos[a].push_back(i);
    }

    int odd_a = -1;
    for (int i = 0; i < n; ++i) {
        if (pos[i].size() % 2) {
            if (odd_a == -1) odd_a = i;
            else {
                cout << "NO\n";
                return;
            }
        }
    }

    vector<int> answer(n);
    if (n % 2) {
        if (pos[odd_a].back() == n / 2) {
            if (pos[odd_a].size() == 1) {
                cout << "NO\n";
                return;
            }
            swap(pos[odd_a].back(), pos[odd_a][0]);
        }
        answer[n / 2] = pos[odd_a].back();
        pos[odd_a].pop_back();
    }

    for (int i = n / 2 - 1, a = 0; i >= 0; --i) {
        while (pos[a].empty()) ++a;

        answer[i] = pos[a].back();
        pos[a].pop_back();

        answer[n - i - 1] = pos[a].back();
        pos[a].pop_back();
    }

    union_find dsu(n);
    for (int i = 0; i < n; ++i) {
        dsu.unite(i, answer[i]);
    }

    for (int i = 0; i < n / 2; ++i) {
        if (!dsu.same(i, n - i - 1)) {
            swap(answer[i], answer[n - i - 1]);
            dsu.unite(i, n - i - 1);
        }

        if (i && !dsu.same(i - 1, i)) {
            swap(answer[i], answer[n - i - 1]);
            swap(answer[i - 1], answer[i]);
            swap(answer[n - i], answer[n - i - 1]);
            dsu.unite(i - 1, i);
        }
    }

    cout << "YES\n";
    for (auto i : answer) cout << i + 1 << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
}