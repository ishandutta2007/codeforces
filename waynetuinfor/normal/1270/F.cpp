#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
const int kB = 800;
int pf[kN], nxt[kN], cnt[1LL * kN * kN / kB * 2];
char s[kN];

int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 1; i <= n; ++i) pf[i] = pf[i - 1] + (s[i] == '1');
    long long ans = 0;
    int *ptr = cnt + 1LL * kN * kN / kB;
    for (int j = 1; j * kB <= n; ++j) {
        int p = 0;
        for (int i = 1; i <= n; ++i) {
            while (p < i && pf[i] - pf[p] > kB) {
                ++ptr[p - j * pf[p]];
                ++p;
            }
            ans += ptr[i - j * pf[i]];
        }
        for (int i = 0; i < p; ++i) ptr[i - j * pf[i]]--;
    }
    nxt[n + 1] = n + 1;
    for (int i = n, p = n + 1; i >= 1; --i) {
        if (s[i] == '1') p = i;
        nxt[i] = p;
    }
    for (int i = 1; i <= n; ++i) {
        int r = i - 1;
        for (int j = 1; j <= kB; ++j) {
            if ((r = nxt[r + 1]) > n) break;
            int z = (i - 1) % j;
            int g = nxt[r + 1];
            int rb = (g - 1) / j, lb = r / j;
            if (lb == rb) {
                if (z >= r % j && z <= (g - 1) % j) ++ans;
            } else {
                ans += rb - lb - 1;
                if (z >= r % j) ++ans;
                if (z <= (g - 1) % j) ++ans;
            }
            // for (int x = r; x < g; ++x) {
            //     if (x % j == z) ++ans;
            // }
        }
    }
    printf("%lld\n", ans);
}