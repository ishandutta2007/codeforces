#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
        puts("No");
        return 0;
    }
    for (int i = 0; i < n - 1; ++i) c[i] = a[i + 1] - a[i];
    for (int i = 0; i < n - 1; ++i) d[i] = b[i + 1] - b[i];
    sort(c, c + n - 1);
    sort(d, d + n - 1);
    for (int i = 0; i < n - 1; ++i) {
        if (c[i] != d[i]) {
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}