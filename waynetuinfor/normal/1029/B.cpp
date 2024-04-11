#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int a[maxn];

int main() {
    int n; scanf("%d", &n);
    set<int> s;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    int c = 0, ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (i > 1 && a[i] > a[i - 1] * 2) c = 0;
        ++c;
        ans = max(ans, c);
    }
    printf("%d\n", ans);
}