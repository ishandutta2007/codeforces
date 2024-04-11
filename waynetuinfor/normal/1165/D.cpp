#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 5;
int d[maxn];

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; ++i)
            scanf("%d", &d[i]);

        sort(d, d + n);
        long long p = d[0] * 1ll * d[n - 1];
        vector<int> dv;
        for (long long i = 2; i * i <= p; ++i) {
            if (p % i == 0) {
                dv.push_back(i);
                if (i * i != p)
                    dv.push_back(p / i);
            }
        }

        sort(dv.begin(), dv.end());
        bool ans = dv.size() == n;
        for (int i = 0; ans && i < n; ++i)
            ans &= dv[i] == d[i];

        if (!ans) p = -1;
        printf("%lld\n", p);
    }
    return 0;
}