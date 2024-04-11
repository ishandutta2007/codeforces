#include <bits/stdc++.h>
using namespace std;

template <int M>
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = (int) ((long long) n * r.n % M); return *this; }
    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }
    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = *this, p = 1;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint<1000000007>;

template <class T>
struct fenwick_tree {
    fenwick_tree(int n) : n(n) {
        tree.resize(n + 1);
    }

    void update(int i, T x) {
        if (i > n) return;
        tree[i] += x;
        update(i + (i & -i), x);
    }

    T operator()(int i) {
        if (i == 0) return T(0);
        return tree[i] + (*this)(i - (i & -i));
    }

    int lower_bound(T x) {
        int i = 0;
        T sum = 0;
        for (int bit = bit_floor((unsigned) n); bit > 0; bit /= 2) {
            if (i + bit <= n && sum + tree[i + bit] < x) {
                i += bit, sum += tree[i];
            }
        }
        return i + 1;
    }

    vector<T> tree;
    int n;
};

void compress_indices(vector<int> &a) {
    vector<int> values = a;
    ranges::sort(values);
    auto unique = ranges::unique(values);
    values.erase(unique.begin(), unique.end());
    for (auto &i : a) i = (int) (ranges::lower_bound(values, i) - values.begin() + 1);
}

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    compress_indices(a);

    fenwick_tree<mint> sum_ways(n), sum_weights(n);
    vector<mint> ways(n), weights(n);
    for (int i = 0; i < n; ++i) {
        ways[i] = 1 + sum_ways(a[i] - 1);
        weights[i] = ways[i] + sum_weights(a[i] - 1);
        sum_ways.update(a[i], ways[i]);
        sum_weights.update(a[i], weights[i]);
    }

    vector<int> order(n);
    iota(order.rbegin(), order.rend(), 0);
    ranges::stable_sort(order, [&](int i, int j) { return a[i] < a[j]; });

    int ptr = (int) (ranges::find(order, n - 1) - order.begin());
    mint ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        int j = order[ptr];

        if (a[i] < a[j]) {
            ans += weights[i];
        } else if (a[i] == a[j]) {
            ans += weights[i] - ways[i];
        } else {
            vector<int> indices;
            while (order[ptr] != i) {
                if (order[ptr] < i) indices.push_back(order[ptr]);
                ++ptr;
            }
            ranges::sort(indices);

            fenwick_tree<mint> sum_over(a[i] - a[j]);
            for (auto k : indices) {
                mint over = ways[k] + sum_over(a[k] - a[j]);
                sum_over.update(a[k] - a[j] + 1, over);
            }

            ans += weights[i] - ways[i] - sum_over(a[i] - a[j]);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        solve();
    }
}