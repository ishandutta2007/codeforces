#include <bits/stdc++.h>
using namespace std;

const int kN = 100'000 + 5;
long long pf[kN];
int a[kN];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n, s; scanf("%d%d", &n, &s);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
            pf[i] = a[i] + (i > 0 ? pf[i - 1] : 0);
        }
        pair<int, int> ans{0, -1};
        for (int i = 0; i < n; ++i) {
            if (pf[i] <= s)
                ans = max(ans, make_pair(i + 1, -1));
        }
        for (int i = 0; i < n; ++i) {
            int g = upper_bound(pf, pf + n, s + a[i]) - pf - 1;
            if (g > i) ans = max(ans, make_pair(g, i));
        }
        printf("%d\n", ans.second + 1);
    }
}