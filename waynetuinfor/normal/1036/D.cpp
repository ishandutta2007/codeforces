#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 5;
int a[maxn], b[maxn];
long long sa[maxn], sb[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sa[i] = sa[i - 1] + a[i];
    }
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &b[i]);
        sb[i] = sb[i - 1] + b[i];
    }
    if (sa[n] != sb[m]) {
        puts("-1");
        return 0;
    }
    int j = 1, ans = 0;
    for (int i = 1; i <= n; ) {
        long long x = a[i], y = 0;
        int k = i + 1;
        while (true) {
            if (x > y && j <= m) {
                y += b[j];
                ++j;
            } else if (x < y && k <= n) {
                x += a[k];
                ++k;
            } else {
                break;
            }
        }
        ++ans;
        i = k;
    } 
    printf("%d\n", ans);
    return 0;
}