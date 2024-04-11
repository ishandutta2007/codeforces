#include <bits/stdc++.h>
using namespace std;
int n, h;
vector<int> a;
int main() {
    scanf("%d%d", &n, &h);
    for (int i = 1, x; i <= n; ++i) {
        scanf("%d", &x);
        long long ans = 0;
        a.insert(lower_bound(a.begin(), a.end(), x), x);
        for (int i = a.size() - 1; i >= 1; i -= 2) {
            ans += max(a[i], a[i - 1]);
        }
        if (i & 1) ans += a[0];
        if (ans > h) return printf("%d\n", i - 1), 0;
    }
    printf("%d\n", n);
    return 0;
}