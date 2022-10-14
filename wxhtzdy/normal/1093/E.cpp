#include <bits/stdc++.h>

const int N = 2E5 + 5;
const int block = 650;

struct FenwickTree {
    int a[N];
    FenwickTree() {
        std::fill(a, a + N, 0);
    }
    void modify(int x, int y) {
        for (int i = x + 1; i < N; i += i & -i) {
            a[i] += y;
        }
    }
    int get(int x) {
        int res = 0;
        for (int i = x + 1; i > 0; i -= i & -i) {
            res += a[i];
        }
        return res;
    }
    int get(int l, int r) {
        return get(r) - get(l - 1);
    }
} fenw[block];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    std::vector<int> pa(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        --a[i];
        pa[a[i]] = i;
    }

    std::vector<int> b(n);
    std::vector<int> pb(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        --b[i];
        pb[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int my = i / block;
        fenw[my].modify(pa[b[i]], 1);
    }

    while (q--) {
        int t;
        std::cin >> t;
        if (t == 1) {
            int la, ra, lb, rb;
            std::cin >> la >> ra >> lb >> rb;
            --la, --ra, --lb, --rb;

            if (lb / block == rb / block) {
                int ans = 0;
                for (int i = lb; i <= rb; i++) {
                    if (la <= pa[b[i]] && pa[b[i]] <= ra) {
                        ans++;
                    }
                }
                std::cout << ans << "\n";
                continue;
            }

            int ans = 0;

            for (int i = lb; i < (lb / block + 1) * block; i++) {
                if (la <= pa[b[i]] && pa[b[i]] <= ra) {
                    ans++;
                }
            }

            for (int i = rb; i >= (rb / block) * block; i--) {
                if (la <= pa[b[i]] && pa[b[i]] <= ra) {
                    ans++;
                }
            }

            for (int i = lb / block + 1; i < rb / block; i++) {
                ans += fenw[i].get(la, ra);
            }

            std::cout << ans << "\n";
        } else {
            int x, y;
            std::cin >> x >> y;
            --x, --y;
            fenw[x / block].modify(pa[b[x]], -1);
            fenw[y / block].modify(pa[b[y]], -1);

            std::swap(b[x], b[y]);

            fenw[x / block].modify(pa[b[x]], 1);
            fenw[y / block].modify(pa[b[y]], 1);
        }
    }

    return 0;
}