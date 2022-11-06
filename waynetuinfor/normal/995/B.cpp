#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
int a[maxn];
bool v[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i) scanf("%d", &a[i]);
    int ans = 0;
    for (int i = 0; i < 2 * n; ++i) if (!v[a[i]]) {
        int p = -1;
        for (int j = i + 1; j < 2 * n; ++j) if (a[j] == a[i]) p = j;
        assert(p != -1);
        while (p > i + 1) ++ans, swap(a[p], a[p - 1]), --p;
        v[a[i]] = true;
    }
    printf("%d\n", ans);
    return 0;
}