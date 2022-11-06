#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
int n, m, a[maxn], d[maxn];

bool check(int x) {
    long long sum = 0;
    int j = 0;
    for (int i = 0; i < n; ++i) d[i] = 0;
    for (int i = 0; i < n; ++i) {
        sum += max(a[i] - d[j], 0);
        ++d[j];
        if (++j == x) j = 0;
    }  
    return sum >= m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    reverse(a, a + n);
    int ans = n + 1;
    for (int d = 20; d >= 0; --d) {
        if (ans - (1 << d) <= 0) continue;
        if (check(ans - (1 << d)))
            ans -= (1 << d);
    }
    if (ans == n + 1) ans = -1;
    printf("%d\n", ans);
    return 0;
}