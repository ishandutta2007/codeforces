#include <bits/stdc++.h>

using i64 = long long;


const int M = 3e7 + 5;
int son[M][2], sz[M], tsz = 0;

void add(int x) {
    int t = 0;
    for (int i = 30; i >= 0; i--) {
        int bit = ((x >> i) & 1);
        if (!son[t][bit]) {
            son[t][bit] = ++tsz;
        }
        t = son[t][bit];
        sz[t] += 1;
    }
}

int query(int xr, int k) {
    int res = 0, t = 0;
    for (int i = 30; i >= 0; i--) {
        if (k & (1 << i)) {
            t = son[t][((xr >> i) & 1) ^ 1];
        } else {
            int bit = ((xr >> i) & 1);
            if (son[t][bit ^ 1] != 0) {
                res += sz[son[t][bit ^ 1]];
            }
            t = son[t][bit];
        }
        if (t == 0) {
            break;
        }
    }
    if (t != 0) {
        res += sz[t];
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    add(0);

    i64 ans = 0;
    int xr = 0;
    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        ans += query(xr, k);
        add(xr);
    }

    std::cout << ans << "\n";
}