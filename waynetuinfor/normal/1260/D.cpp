#include <bits/stdc++.h>
using namespace std;

const int kN = 200'000 + 5;
int a[kN], l[kN], r[kN], d[kN];
bool used[kN];

int main() {
    int m, n, k, t; scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 0; i < m; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < k; ++i) scanf("%d%d%d", &l[i], &r[i], &d[i]);
    sort(a, a + m, greater<int>());
    
    auto Check = [&](int z) {
        int kv = a[z - 1], dt = 0;
        vector<int> rv;
        for (int i = 0; i < k; ++i) {
            if (d[i] > kv) rv.push_back(i);
        }
        sort(rv.begin(), rv.end(), [&](int a, int b) { return l[a] < l[b]; });
        for (int i = 0, j = 0; i < n; ++i) {
            if (j < rv.size() && l[rv[j]] == i + 1) {
                int rb = r[rv[j]];
                while (j < rv.size() && l[rv[j]] <= rb) rb = max(rb, r[rv[j++]]);
                dt += (rb - i) * 2;
            }
            dt += 1;
            if (dt > t) return false;
        }
        return dt + 1 <= t;
    };

    int ans = 0;
    for (int d = 20; d >= 0; --d) {
        if (ans + (1 << d) <= m && Check(ans + (1 << d))) ans += (1 << d);
    }
    printf("%d\n", ans);
    return 0;
}