#include <bits/stdc++.h>

using i64 = long long;

template <typename T>
struct Fenwick {
    int n;
    std::vector<T> a;
    Fenwick(int n) : n(n), a(n) {}
    void add(int x, T v) {
        for (int i = x + 1; i <= n; i += i & -i) {
            a[i - 1] += v;
        }
    }
    T sum(int x) {
        T ans = 0;
        for (int i = x; i > 0; i -= i & -i) {
            ans += a[i - 1];
        }
        return ans;
    }
    T rangeSum(int l, int r) {
        return sum(r) - sum(l);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int x[n];
    for (int i = 0; i < n; i++) std::cin >> x[i];

    int v[n];
    for (int i = 0; i < n; i++) std::cin >> v[i];

    std::vector<int> xs;
    for (int i = 0; i < n; i++) {
        xs.push_back(v[i]);
    }

    std::sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    int p[n];
    for (int i = 0; i < n; i++) p[i] = i;

    std::sort(p, p + n, [&](int i, int j) {return x[i] < x[j];});

    int m = xs.size();
    Fenwick<int> fen1(m + 5);
    Fenwick<i64> fen2(m + 5);

    i64 ans = 0;
    for (int id = 0; id < n; id++) {
        int i = p[id];
        v[i] = lower_bound(xs.begin(), xs.end(), v[i]) - xs.begin() + 1;
        ans += x[i] * 1LL * fen1.sum(v[i] + 1) - fen2.sum(v[i] + 1);
        fen1.add(v[i], 1);
        fen2.add(v[i], x[i]);
    }

    std::cout << ans << "\n";

    return 0;
}