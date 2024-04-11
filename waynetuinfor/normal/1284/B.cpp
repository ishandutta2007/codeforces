#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
const int kInf = 1'000'000'000;
vector<int> a[kN];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int k; scanf("%d", &k);
        a[i].resize(k);
        for (int j = 0; j < k; ++j) scanf("%d", &a[i][j]);
    }
    int asc = 0;
    vector<int> x, y;
    for (int i = 0; i < n; ++i) {
        int g = kInf, s = kInf, t = 0;
        bool ok = false;
        for (int j = 0; j < a[i].size(); ++j) {
            if (a[i][j] > g) ok = true;
            g = min(g, a[i][j]);
            s = min(s, a[i][j]);
            t = max(t, a[i][j]);
        }
        if (ok) asc += 1;
        else x.push_back(s), y.push_back(t);
    }
    long long ans = 1LL * asc * asc + 2LL * asc * (n - asc);
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for (int i = 0, j = 0; i < y.size(); ++i) {
        while (j < x.size() && x[j] < y[i]) ++j;
        ans += j;
    }
    printf("%lld\n", ans);
    return 0;
}