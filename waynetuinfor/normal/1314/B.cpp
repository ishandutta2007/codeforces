#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    vector<bool> gd(1 << n);
    for (int i = 0; i < k; ++i) {
        int a; scanf("%d", &a);
        gd[a - 1] = true;
    }

    constexpr int64_t kInf = 1'000'000'000;

    function<array<int64_t, 4>(int, int)> DivideConquer = [&](int p, int d) {
        if (d == 0) {
            int cnt = (int)gd[p] + (int)gd[p + 1];
            array<int64_t, 4> res;
            if (cnt == 2) res = {-kInf, -kInf, -kInf, 1};
            else if (cnt == 1) res = {-kInf, 1, 1, -kInf};
            else return res = {0, -kInf, -kInf, -kInf};
            return res;
        }
        auto lhs = DivideConquer(p, d - 1), rhs = DivideConquer(p + (1 << d), d - 1);
        array<int64_t, 4> res;
        fill(res.begin(), res.end(), -kInf);
        for (int s = 0; s < 4; ++s) {
            for (int t = 0; t < 4; ++t) {
                for (int g = 0; g < 8; ++g) {
                    int cnt = (int)((s & 1) || (t & 1)) + (int)((s >> 1 & 1) || (t >> 1 & 1));
                    int w1 = (g & 1) ? (s & 1) : (t & 1), w2 = (g & 1) ? (t & 1) : (s & 1);
                    int l1 = (g >> 1 & 1) ? (s >> 1 & 1) : (t >> 1 & 1);
                    cnt += (int)(w2 || l1);
                    int l2 = (g >> 2 & 1) ? w2 : l1;
                    res[w1 | (l2 << 1)] = max(res[w1 | (l2 << 1)], lhs[s] + rhs[t] + cnt);
                }
            }
        }
        return res;
    };

    auto ans = DivideConquer(0, n - 1);
    int64_t res = 0;
    for (int i = 0; i < 4; ++i) res = max(res, ans[i] + (i > 0));
    printf("%lld\n", res);
}