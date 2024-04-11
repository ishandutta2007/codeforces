#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int l[maxn], r[maxn];

int main() {
    int n, h; scanf("%d %d", &n, &h);
    for (int i = 0; i < n; ++i) scanf("%d %d", &l[i], &r[i]);
    int ans = 0, j = 0, drop = 0, fly = r[0] - l[0];
    for (int i = 0; i < n; ++i) {
        while (j + 1 < n && drop + l[j + 1] - r[j] < h) {
            fly += l[j + 1] - r[j];
            fly += r[j + 1] - l[j + 1];
            drop += l[j + 1] - r[j];
            ++j;
        }
        ans = max(ans, fly + h - drop);
        fly -= r[i] - l[i];
        if (i + 1 < n) {
            fly -= l[i + 1] - r[i];
            drop -= l[i + 1] - r[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}