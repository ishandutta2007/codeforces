#include <bits/stdc++.h>

const int maxn = 3e5 + 5;
char s[maxn];

int main() {
    int n, x, y; scanf("%d %d %d", &n, &x, &y);
    scanf("%s", s);
    int z = 0;
    for (int i = 0; i < n; ) {
        if (s[i] == '1') {
            ++i;
            continue;
        }
        int j = i;
        while (j < n && s[j] == '0') ++j;
        ++z;
        i = j;
    }
    if (z == 0) {
        puts("0");
        return 0;
    }
    long long ans = std::min((z - 1) * 1ll * x + y, z * 1ll * y);
    printf("%lld\n", ans);
}