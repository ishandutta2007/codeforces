#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//#define int ll

const int N = 3e5 + 10;
pair<int, int> t[4 * N];
void build(int v, int l, int r, const vector<int>& p) {
    if (l == r) {
        t[v] = {p[l], l};
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid, p);
    build(2 * v + 1, mid + 1, r, p);
    t[v] = max(t[2 * v], t[2 * v + 1]);
}

pair<int, int> get_max(int v, int l, int r, int a, int b) {
    if (l > b || r < a) {
        return {0, -1};
    }
    if (l >= a && r <= b) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return max(get_max(2 * v, l, mid, a, b), get_max(2 * v + 1, mid + 1, r, a, b));
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n);
        for (auto &x : p) {
            cin >> x;
        }
        vector<int> a(n);
        int k = 0;
        for (auto &x : a) {
            cin >> x;
            if (!x) {
                k++;
            }
        }
        vector<int> S(k - 1);
        for (auto &x : S) {
            cin >> x;
        }
        sort(S.begin(), S.end());
        build(1, 0, n - 1, p);
        vector<vector<int>> g(n);
        int root = -1;
        function<void(int, int, int)> build_tree = [&](int l, int r, int parent) {
            int mid = get_max(1, 0, n - 1, l, r).second;
            if (parent == -1) {
                root = mid;
            } else {
                g[parent].push_back(mid);
            }
            if (l == r) {
                return;
            }
            if (mid > l) build_tree(l, mid - 1, mid);
            if (mid < r) build_tree(mid + 1, r, mid);
        };
        build_tree(0, n - 1, -1);

        vector<int> subtree_max(n);
        vector<pair<int, int>> segments;
        bool bad_tree = false;
        function<void(int, int, int)> dfs = [&](int v, int parent, int mn_up) {
            subtree_max[v] = a[v];
            for (auto u : g[v]) {
                if (u != parent) {
                    int new_mn = mn_up;
                    if (a[v]) {
                        new_mn = min(new_mn, a[v]);
                    }
                    dfs(u, v, new_mn);
                    subtree_max[v] = max(subtree_max[v], subtree_max[u]);
                }
            }
            if (a[v] && a[v] < subtree_max[v]) {
                bad_tree = true;
            }
            if (!a[v]) {
                segments.emplace_back(subtree_max[v] + 1, mn_up - 1);
            }
        };
        dfs(root, -1, 1e9);

        sort(segments.begin(), segments.end());

        int right_good_d = -1, ptr = 0;
        multiset<int> right_borders;
        for (auto it : S) {
            while (ptr < segments.size() && segments[ptr].first <= it) {
                right_borders.insert(segments[ptr++].second);
            }
            while (!right_borders.empty() && *right_borders.begin() < it) {
                if (right_good_d != -1) {
                    bad_tree = true;
                } else {
                    right_good_d = *right_borders.begin();
                }
                right_borders.erase(right_borders.begin());
            }
            if (!right_borders.empty()) {
                right_borders.erase(right_borders.begin());
            }
        }
        while (ptr < segments.size()) {
            right_borders.insert(segments[ptr++].second);
        }
        while (!right_borders.empty()) {
            if (right_good_d != -1) {
                bad_tree = true;
            } else {
                right_good_d = *right_borders.begin();
            }
            right_borders.erase(right_borders.begin());
        }

        if (bad_tree) {
            for (int i = 0; i < q; i++) {
                int x;
                cin >> x;
                cout << "NO\n";
            }
            continue;
        }

        for (int i = 0; i < segments.size(); i++) {
            swap(segments[i].first, segments[i].second);
            segments[i].first *= -1;
            segments[i].second *= -1;
        }
        sort(segments.begin(), segments.end());
        for (auto &x : S) {
            x *= -1;
        }
        reverse(S.begin(), S.end());
        int left_good_d = 1;
        ptr = 0;
        right_borders = {};
        for (auto it : S) {
            while (ptr < segments.size() && segments[ptr].first <= it) {
                right_borders.insert(segments[ptr++].second);
            }
            while (!right_borders.empty() && *right_borders.begin() < it) {
                if (left_good_d != 1) {
                    bad_tree = true;
                } else {
                    left_good_d = *right_borders.begin();
                }
                right_borders.erase(right_borders.begin());
            }
            if (!right_borders.empty()) {
                right_borders.erase(right_borders.begin());
            }
        }
        while (ptr < segments.size()) {
            right_borders.insert(segments[ptr++].second);
        }
        while (!right_borders.empty()) {
            if (left_good_d != 1) {
                bad_tree = true;
            } else {
                left_good_d = *right_borders.begin();
            }
            right_borders.erase(right_borders.begin());
        }
        left_good_d *= -1;

        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            if (x >= left_good_d && x <= right_good_d) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }

    }
    return 0;
}