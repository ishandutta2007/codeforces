#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, a, b; scanf("%d%d%d%d", &n, &k, &a, &b);
    vector<int> p;
    for (int i = 0; i < k; ++i) {
        int x; scanf("%d", &x);
        --x;
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    function<int(int, int)> count = [&](int l, int r) {
        int cr = lower_bound(p.begin(), p.end(), r) - p.begin();
        int cl = lower_bound(p.begin(), p.end(), l) - p.begin();
        return cr - cl;
    };
    function<long long(int, int)> solve = [&](int l, int r) -> long long {
        int c = count(l, r);
        if (c == 0) return a;
        if (r - l == 1) return c * 1ll * b;
        int m = (l + r) >> 1;
        long long res = solve(l, m) + solve(m, r);
        res = min(res, b * 1ll * c * (r - l));
        return res;
    };
    printf("%lld\n", solve(0, (1 << n)));
}