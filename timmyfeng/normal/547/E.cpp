#include <bits/stdc++.h>
using namespace std;

template <class T>
struct fenwick {

    vector<T> tree;
    int n;

    fenwick(int n) : n(n) {
        tree.resize(n + 1);
    }

    void update(int a, T x) {
        for ( ; a <= n; a += (a & -a)) {
            tree[a] += x;
        }
    }

    T query(int a) {
        T res = 0;
        for ( ; a > 0; a -= (a & -a)) {
            res += tree[a];
        }
        return res;
    }

    int lower_bound(T k) {
        int res = 0;
        T sum = 0;
        for (int i = __lg(n); i >= 0; --i) {
            if (res + (1 << i) <= n && sum + tree[res + (1 << i)] < k) {
                res += 1 << i;
                sum += tree[res];
            }
        }
        return res + 1;
    }

};

const int N = 500000 + 1;
const int L = __lg(N) + 1;

int order[N], where[N], lcp[L][N];
array<int, 2> key[N];

int query(int a, int b) {
    if (a == b) {
        return INT_MAX;
    }

    int l = __lg(b - a);
    return min(lcp[l][a], lcp[l][b - (1 << l)]);
}

int start[N], length[N], last[N], first[N];

int find_first(int a, int b, int x, int y) {
    if (a == b) {
        return a;
    }

    int m = (a + b) / 2;
    if (query(m, x) >= y) {
        return find_first(a, m, x, y);
    } else {
        return find_first(m + 1, b, x, y);
    }
}

int find_last(int a, int b, int x, int y) {
    if (a == b) {
        return a;
    }

    int m = (a + b + 1) / 2;
    if (query(x, m) >= y) {
        return find_last(m, b, x, y);
    } else {
        return find_last(a, m - 1, x, y);
    }
}

vector<array<int, 3>> queries[N];
int ans[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;

    for (int i = 0; i < n; ++i) {
        string t;
        cin >> t;
        start[i] = s.size();
        length[i] = t.size();
        s += t + "#";
    }

    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        queries[l - 1].push_back({k - 1, i, -1});
        queries[r].push_back({k - 1, i, 1});
    }

    int m = s.size();
    for (int i = 0; i < m; ++i) {
        where[i] = s[i];
    }

    for (int i = 0; i <= __lg(m); ++i) {
        for (int j = 0; j < m; ++j) {
            key[j][0] = where[j];
            key[j][1] = j + (1 << i) < m ? where[j + (1 << i)] : -1;
        }

        iota(order, order + m, 0);
        sort(order, order + m, [&](int a, int b) {
            return key[a] < key[b];
        });

        where[order[0]] = 0;
        for (int j = 1; j < m; ++j) {
            where[order[j]] = where[order[j - 1]];
            where[order[j]] += key[order[j]] > key[order[j - 1]];
        }
    }

    for (int i = 0, k = 0; i < m; ++i) {
        if (where[i] == m - 1) {
            k = 0;
        } else {
            int j = order[where[i] + 1];
            while (i + k < m && j + k < m && s[i + k] == s[j + k]) {
                ++k;
            }
            lcp[0][where[i]] = k;
        }
        k -= k > 0;
    }

    for (int i = 1; i <= __lg(m); ++i) {
        for (int j = 0; j + (1 << i) <= m; ++j) {
            lcp[i][j] = min(lcp[i - 1][j], lcp[i - 1][j + (1 << (i - 1))]);
        }
    }

    for (int i = 0; i < n; ++i) {
        int j = where[start[i]];
        first[i] = find_first(0, j, j, length[i]);
        last[i] = find_last(j, m - 1, j, length[i]);
    }

    fenwick<int> fenw(m);
    for (int i = 0; i <= n; ++i) {
        for (auto [k, id, c] : queries[i]) {
            ans[id] += c * (fenw.query(last[k] + 1) - fenw.query(first[k]));
        }

        if (i < n) {
            for (int j = start[i]; j < start[i] + length[i]; ++j) {
                fenw.update(where[j] + 1, 1);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}