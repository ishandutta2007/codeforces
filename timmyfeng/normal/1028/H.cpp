#include <bits/stdc++.h>
using namespace std;

struct segtree {

    vector<int> tree;
    int n;

    segtree(int n) : n(n) {
        tree.assign(2 * n, INT_MAX);
    }

    void update(int a, int x) {
        a += n - 1;
        tree[a] = min(tree[a], x);
        for (a /= 2; a > 0; a /= 2) {
            tree[a] = min(tree[2 * a], tree[2 * a + 1]);
        }
    }

    int query(int a, int b) {
        int res = INT_MAX;
        a += n - 1, b += n - 1;
        while (a <= b) {
            if (a % 2 == 1) {
                res = min(res, tree[a++]);
            }
            if (b % 2 == 0) {
                res = min(res, tree[b--]);
            }
            a /= 2, b /= 2;
        }
        return res;
    }

};

const int A = 5032107 + 1;
const int N = 194598 + 1;
const int Q = 1049658;
const int K = 16;

vector<array<int, 2>> updates[N], queries[N]; 
int sieve[A], multiples[A][K], ans[Q];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 2; i < A; ++i) {
        if (sieve[i] == 0) {
            for (int j = i; j < A; j += i) {
                sieve[j] = i;
            }
        }
    }

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;

        vector<int> factors;
        while (a > 1) {
            int p = sieve[a], q = 0;
            while (a % p == 0) {
                a /= p;
                ++q;
            }
            if (q % 2 == 1) {
                factors.push_back(p);
            }
        }

        int m = factors.size();
        for (int j = 0; j < (1 << m); ++j) {
            int b = 1;
            for (int k = 0; k < m; ++k) {
                if ((j & (1 << k)) > 0) {
                    b *= factors[k];
                }
            }

            int x = m - __builtin_popcount(j);
            for (int k = 0; k < K; ++k) {
                if (multiples[b][k] > 0) {
                    updates[multiples[b][k]].push_back({i, k + x});
                }
            }
            multiples[b][x] = i;
        }
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        queries[l].push_back({r, i});
    }

    segtree mini = segtree(n);
    for (int i = n; i >= 1; --i) {
        for (auto [j, x] : updates[i]) {
            mini.update(j, x);
        }

        for (auto [j, id] : queries[i]) {
            ans[id] = mini.query(i, j);
        }
    }

    for (int i = 0; i < q; ++i) {
        cout << ans[i] << "\n";
    }
}