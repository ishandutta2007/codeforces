#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int a[maxn], s[maxn];
map<int, int> c;

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    c[0] = 1;
    int mask = (1 << k) - 1;
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        int x = (s[i - 1] ^ a[i]);
        if (c[x] < c[x ^ mask]) {
            ans += i - c[x];
            s[i] = (s[i - 1] ^ a[i]);
        } else {
            ans += i - c[x ^ mask];
            s[i] = (s[i - 1] ^ a[i] ^ mask);
        }
        ++c[s[i]];
    }
    printf("%lld\n", ans);
    return 0;
}