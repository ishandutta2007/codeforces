#include <bits/stdc++.h>
using namespace std;

const int maxn = 1 << 20;
int cnt[2][maxn];

int main() {
    int n; scanf("%d", &n);
    ++cnt[0][0];
    long long ans = 0;
    int s = 0;
    for (int i = 1; i <= n; ++i) {
        int x; scanf("%d", &x);
        s ^= x;
        ans += cnt[i & 1][s];
        cnt[i & 1][s]++;
    }
    printf("%lld\n", ans);
    return 0;
}