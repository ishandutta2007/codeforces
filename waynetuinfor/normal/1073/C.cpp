#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
int x[maxn], y[maxn];

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) {
        x[i] = x[i - 1], y[i] = y[i - 1];
        if (s[i] == 'U') ++y[i];
        if (s[i] == 'D') --y[i];
        if (s[i] == 'R') ++x[i];
        if (s[i] == 'L') --x[i];
    }
    int tx, ty; scanf("%d%d", &tx, &ty);
    if (abs(tx) + abs(ty) > n) {
        puts("-1");
        return 0;
    }
    if ((abs(tx) + abs(ty)) % 2 != n % 2) {
        puts("-1");
        return 0;
    }
    if (x[n] == tx && y[n] == ty) {
        puts("0");
        return 0;
    }
    int ans = 1e9;
    for (int i = 1; i <= n; ++i) {
        int d = 20, r = n + 1;
        while (d--) {
            if (r - (1 << d) < i) continue;
            int px = x[i - 1] + (x[n] - x[r - (1 << d)]);
            int py = y[i - 1] + (y[n] - y[r - (1 << d)]);
            if (abs(tx - px) + abs(ty - py) <= r - (1 << d) - i + 1) r -= (1 << d);
        }
        if (r <= n) ans = min(ans, r - i + 1);
    }
    if (ans > 1e8) ans = -1;
    printf("%d\n", ans);
    return 0;
}