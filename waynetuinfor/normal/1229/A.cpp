#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &a[i]);
    for (int i = 0; i < n; ++i) scanf("%lld", &b[i]);
    long long ans = 0;
    vector<int> used(n);
    for (int i = 0; i < n; ++i) {
        bool ok = false;
        for (int j = 0; j < n; ++j) {
            if (i != j && a[j] == a[i]) ok = true;
        }
        if (ok) {
            for (int j = 0; j < n; ++j) {
                if ((a[j] & a[i]) == a[j]) used[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; ++i) if (used[i]) ans += b[i];
    printf("%lld\n", ans);
}