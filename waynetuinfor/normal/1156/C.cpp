#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
int x[maxn];

int main() {
    int n, z; scanf("%d%d", &n, &z);
    for (int i = 0; i < n; ++i) scanf("%d", &x[i]);

    sort(x, x + n);
    multiset<int> ms;
    int ans = 0;

    for (int i = 0; i < n / 2; ++i) 
        ms.insert(x[i]);

    for (int i = n / 2; i < n; ++i) {
        auto it = ms.upper_bound(x[i] - z);
        if (it != ms.begin()) {
            ++ans;
            ms.erase(prev(it));
        }
    }

    printf("%d\n", ans);
    return 0;
}