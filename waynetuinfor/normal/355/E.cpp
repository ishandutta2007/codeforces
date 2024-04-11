#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 5;
int a[maxn], s[maxn], q[maxn];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%d", a + i), s[a[i]] = a[i], ++q[a[i]];
    for (int i = 1; i <= 2000000; ++i) s[i] = max(s[i], s[i - 1]), q[i] += q[i - 1];
    int ans = 0;
    for (int g = 1; g <= 1000000; ++g) {
        bool ok = true;
        int c = 0;
        for (int kg = g; kg <= 1000000 && ok; kg += g) {
            if (s[kg + g - 1] > kg + k) ok = false;
            c += q[kg + g - 1] - q[kg - 1];
        }
        if (c != n) ok = false;
        if (ok) ans = max(ans, g);
    }
    printf("%d\n", ans);
    return 0;
}