#include <bits/stdc++.h>
using namespace std;

int dsu[30];

int find(int a) {
    return dsu[a] < 0 ? a : dsu[a] = find(dsu[a]);
}

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    if (-dsu[a] < -dsu[b]) swap(a, b);
    dsu[a] += dsu[b];
    dsu[b] = a;
    return true; 
}

bool check(vector<int> a) {
    fill(dsu, dsu + 30, -1);
    int present_bits = 0, components = 30;
    for (auto x : a) {
        if (!x) return false;
        present_bits |= x;
        int j = -1;
        for (int i = 0; i < 30; ++i) {
            if (x & (1 << i)) {
                if (j >= 0) components -= unite(i, j);
                j = i;
            }
        }
    }
    return components == 30 - __builtin_popcount(present_bits) + 1;
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int zeroes = 0;
    for (auto &i : a) if (i == 0) ++i, ++zeroes;

    if (check(a)) {
        cout << zeroes << "\n";
        for (auto i : a) cout << i << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; ++i) {
        int original = a[i];
        for (auto j : {-1, 1}) {
            a[i] = original + j;
            if (check(a)) {
                cout << zeroes + 1 << "\n";
                for (auto i : a) cout << i << " ";
                cout << "\n";
                return;
            }
        }
        a[i] = original;
    }

    int max_suffix = 0;
    vector<int> max_indices;
    for (int i = 0; i < n; ++i) {
        int suffix = __builtin_ctz(a[i]);
        if (suffix > max_suffix) max_suffix = suffix, max_indices.clear();
        if (suffix == max_suffix) max_indices.push_back(i);
    }

    --a[max_indices[0]], ++a[max_indices[1]];

    cout << zeroes + 2 << "\n";
    for (auto i : a) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) solve();
}