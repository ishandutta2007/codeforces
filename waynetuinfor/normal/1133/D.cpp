#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
    vector<pair<int, int>> v;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int x = -b[i], y = a[i];
        if (y < 0) {
            x = -x;
            y = -y;
        }
        if (y == 0) {
            if (x == 0) ++cnt;
            continue;
        }
        int g = __gcd(abs(y), abs(x));
        x /= g, y /= g;
        v.emplace_back(x, y);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < (int)v.size(); ) {
        int j = i;
        while (j < (int)v.size() && v[j] == v[i]) ++j;
        ans = max(ans, j - i);
        i = j;
    }
    printf("%d\n", ans + cnt);
}