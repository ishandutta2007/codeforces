#include <bits/stdc++.h>

using namespace std;

const int C = 4e4;
const int N = 1e5;

int f[C], a[N], b[N], n;

int gcd(int x, int y) {
    while ((x > 0) && (y > 0)) {
        if (x > y) x %= y; else y %= x;
    }
    return x + y;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    f[1] = 0;
    for (int i = 2; i < C; i++) {
        f[i] = 1e9;
        for (int j = 0; j < n; j++) {
            int cur = gcd(i, a[j]);
            f[i] = min(f[i], f[cur] + b[j]);
        }
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            ans = min(ans, b[i]);
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            int x = gcd(a[i], a[j]);
            if (x < C) {
                ans = min(ans, b[i] + b[j] + f[x]);
            }
        }
    }
    if (ans == 1e9) ans = -1;
    printf("%d\n", ans);
}