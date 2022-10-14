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
    std::string s;
    std::cin >> s;

    std::vector<std::vector<int>> pos(26);
    for (int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i + 1);
    }

    Fenwick<int> fenw(n + 5);
    std::vector<int> nxt(26);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int c = s[n - i - 1] - 'a';
        ans += fenw.rangeSum(pos[c][nxt[c]], n + 1);
        fenw.add(pos[c][nxt[c]], 1);
        nxt[c]++;
    }

    std::cout << ans;
    return 0;
}