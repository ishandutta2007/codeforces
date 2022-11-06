#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 5;
int a[maxn], b[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
        a[b[i]] += 1;
    }

    long long ans = 1e18;
    int ax = -1, ay = -1;

    for (int i = 1; i < maxn; ++i) {
        int x = maxn, y = maxn;
        for (int j = i; j < maxn; j += i) {
            for (int k = 0; k < min(a[j], 2); ++k) {
                if (j < x) y = x, x = j;
                else if (j < y) y = j;
            }
        }

        if (x != maxn && y != maxn) {
            long long l = x * 1ll * y / i;
            if (l < ans) {
                ans = l;
                ax = x;
                ay = y;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (ax >= 0 && b[i] == ax) {
            printf("%d ", i + 1);
            ax = -1;
        } else if (ay >= 0 && b[i] == ay) {
            printf("%d ", i + 1);
            ay = -1;
        }
    }
}