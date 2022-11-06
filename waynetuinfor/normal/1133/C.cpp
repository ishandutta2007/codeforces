#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int j = upper_bound(a.begin(), a.end(), a[i] + 5) - a.begin();
        ans = max(ans, j - i);
    }
    printf("%d\n", ans);
}