#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    int w, h; scanf("%d%d", &w, &h);
    int k = 2 + w - 1 + h - 1;
    int ans = 1;
    for (int i = 0; i < k; ++i) ans = (ans + ans) % mod;
    printf("%d\n", ans);
}