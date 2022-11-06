#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], b[maxn];

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d %d", &a[i], &b[i]);
    long long s = accumulate(a, a + n, 0ll);
    vector<int> v(n); iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j) { return a[i] - b[i] > a[j] - b[j]; });
    int ans = 0;
    for (int i = 0; i < n && s > m; ++i) {
        int x = v[i];
        s -= a[x] - b[x];
        ++ans;
    }
    if (s > m) ans = -1;
    printf("%d\n", ans);
    return 0;
}