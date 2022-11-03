#include <bits/stdc++.h>
const int N = 510;
int n, m, sm1[N], sm2[N], sm3[N], sm4[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &x);
            sm1[i] ^= x;
            sm2[j] ^= x;
        }
    for (int i = 1, x; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &x);
            sm3[i] ^= x;
            sm4[j] ^= x;
        }
    for (int i = 1; i <= n; ++i) if (sm1[i] != sm3[i]) return puts("No"), 0;
    for (int i = 1; i <= m; ++i) if (sm2[i] != sm4[i]) return puts("No"), 0;
    puts("Yes");
    return 0;
}