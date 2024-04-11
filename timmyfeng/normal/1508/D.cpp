#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

const int N = 2001;

struct union_find {
    vector<int> par, size;

    union_find(int n) {
        par.resize(n);
        size.assign(n, 1);
        iota(par.begin(), par.end(), 0);
    }

    int find(int u) {
        if (par[u] != u) {
            par[u] = find(par[u]);
        }
        return par[u];
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }

    bool unite(int u, int v) {
        u = find(u), v = find(v);
        if (u != v) {
            if (size[u] > size[v]) {
                swap(u, v);
            }
            par[u] = v;
            size[v] += size[u];
            return true;
        }
        return false;
    }
};

point points[N], vec[N];
int perm[N], order[N];

long long cross(point a, point b) {
    return a.X * b.Y - a.Y * b.X;
}

bool half(point a) {
    return a.Y < 0 || (a.Y == 0 && a.X < 0);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int k = 0;
    union_find dsu(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y >> perm[i];
        points[i] = point(x, y);
        dsu.unite(i, perm[i]);
        if (i != perm[i]) {
            k = i;
        }
    }

    if (k == 0) {
        cout << 0 << "\n";
        exit(0);
    }

    for (int i = 1, j = 0; i <= n; ++i) {
        vec[i] = points[i] - points[k];
        if (i != k) {
            order[j++] = i;
        }
    }

    sort(order, order + n - 1, [&](int i, int j) {
        if (half(vec[i]) == half(vec[j])) {
            return cross(vec[i], vec[j]) > 0;
        } else {
            return half(vec[i]) < half(vec[j]);
        }
    });

    vector<array<int, 2>> ans;
    for (int i = 0; i < n - 1; ++i) {
        int j = (i + 1) % (n - 1);
        if (cross(vec[order[i]], vec[order[j]]) > 0) {
            if (!dsu.same(order[i], order[j])) {
                dsu.unite(order[i], order[j]);
                ans.push_back({order[i], order[j]});
                swap(perm[order[i]], perm[order[j]]);
            }
        }
    }

    for (int i = 0; i < n - 1; ++i) {
        ans.push_back({k, perm[k]});
        swap(perm[k], perm[perm[k]]);
    }

    cout << ans.size() << "\n";
    for (auto [u, v] : ans) {
        cout << u << " " << v << "\n";
    }
}