#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, m, y; 
    scanf("%d %d", &n, &y);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d %d", &m, &y);
    for (int i = 0; i < m; ++i) scanf("%d", &b[i]);
    sort(a, a + n), sort(b, b + m);
    int ans = 1;
    for (int i = 0; i < n; ++i) {
        if (binary_search(b, b + m, a[i])) ans = 2;
    }
    for (int x = 1; x <= 30; ++x) {
        map<int, int> c;
        for (int i = 0; i < n; ++i) c[a[i] % (1 << x)]++;
        for (int i = 0; i < m; ++i) c[(b[i] + (1 << (x - 1))) % (1 << x)]++;
        for (auto it : c) ans = max(ans, it.second);
    }
    printf("%d\n", ans);
    return 0;
}