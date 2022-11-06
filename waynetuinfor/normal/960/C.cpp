#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, d; scanf("%d %d", &x, &d);
    long long last = -1;
    vector<long long> ans;
    while (x) {
        int z = -1;
        for (int i = 0; i < 31; ++i) if ((1 << i) - 1 <= x) z = i;
        long long k = 0;
        if (last == -1) k = 1;
        else k = last + d;
        for (int i = 0; i < z; ++i) ans.push_back(k);
        last = k;
        x -= (1 << z) - 1;
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]); puts("");
    return 0;
}