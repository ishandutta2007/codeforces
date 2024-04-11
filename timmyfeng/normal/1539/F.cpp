#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

int ans[N], lazy[4 * N], n;
array<int, 2> tree[4 * N];
vector<int> where[N];

array<int, 2> combine(array<int, 2> l, array<int, 2> r) {
    return {min(l[0], r[0]), max(l[1], r[1])};
}

void apply(int u, int x) {
    for (auto &i : tree[u]) {
        i += x;
    }
    lazy[u] += x;
}

void push(int u) {
    if (lazy[u] != 0) {
        apply(2 * u, lazy[u]);
        apply(2 * u + 1, lazy[u]);
        lazy[u] = 0;
    }
}

void update(int a, int b, int x, int u = 1, int l = 0, int r = n) {
    if (b < l || r < a) {
        return;
    } else if (a <= l && r <= b) {
        apply(u, x);
    } else {
        push(u);
        int m = (l + r) / 2;
        update(a, b, x, 2 * u, l, m);
        update(a, b, x, 2 * u + 1, m + 1, r);
        tree[u] = combine(tree[2 * u], tree[2 * u + 1]);
    }
}

array<int, 2> query(int a, int b, int u = 1, int l = 0, int r = n) {
    if (b < l || r < a) {
        return {INT_MAX, INT_MIN};
    } else if (a <= l && r <= b) {
        return tree[u];
    } else {
        push(u);
        int m = (l + r) / 2;
        return combine(
            query(a, b, 2 * u, l, m),
            query(a, b, 2 * u + 1, m + 1, r)
        );
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        where[--a].push_back(i);
    }

    for (int i = 0; i < n; ++i) {
        update(i + 1, n, -1);
    }

    for (int i = 0; i < n; ++i) {
        for (auto j : where[i]) {
            ans[j] = (query(0, j)[1] - query(j + 1, n)[0]) / 2;
        }

        for (auto j : where[i]) {
            update(j + 1, n, 2);
        }

        for (auto j : where[i]) {
            ans[j] = max(ans[j], (query(j + 1, n)[1] - query(0, j)[0] - 1) / 2);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}