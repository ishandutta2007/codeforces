#include <bits/stdc++.h>
using namespace std;

const int ALPHA_SIZE = 26;

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

queue<int> indices[ALPHA_SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        fill(indices, indices + ALPHA_SIZE, queue<int>());
        for (int i = 0; i < n; ++i) {
            indices[s[i] - 'a'].push(i);
        }

        fenwick<int> fenw(n);

        long long ans = LLONG_MAX, prefix_cost = 0;
        for (int i = 0; i < n && prefix_cost < ans; ++i) {
            int c = t[i] - 'a';
            for (int j = 0; j < t[i] - 'a'; ++j) {
                if (!indices[j].empty()) {
                    int k = indices[j].front();
                    ans = min(ans, prefix_cost + k + fenw.query(k + 1) - i);
                }
            }

            if (indices[c].empty()) break;
            int k = indices[c].front();
            prefix_cost += k + fenw.query(k + 1) - i;
            fenw.update(1, 1), fenw.update(k + 1, -1);
            indices[c].pop();
        }

        cout << (ans == LLONG_MAX ? -1 : ans) << "\n";
    }
}