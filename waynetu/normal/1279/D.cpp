#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000 + 5;
const int kMod = 998244353;
vector<int> a[kN], p[kN];

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res = 1LL * res * a % kMod;
        a = 1LL * a * a % kMod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k; scanf("%d", &k);
        a[i].resize(k);
        for (int j = 0; j < k; ++j) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
            p[a[i][j]].push_back(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < kN; ++i) {
        for (int j = 0; j < p[i].size(); ++j) {
            int g = a[p[i][j]].size();
            ans += 1LL * p[i].size() * fpow(g, kMod - 2) % kMod;
            if (ans >= kMod) ans -= kMod;
        }
    }
    ans = 1LL * ans * fpow(n, kMod - 2) % kMod * fpow(n, kMod - 2) % kMod;
    printf("%d\n", ans);
    return 0;
}