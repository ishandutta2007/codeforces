#include <bits/stdc++.h>
using namespace std;

long long calc(int x, int n) {
    int cnt = n / x;
    return cnt * 1ll * (cnt - 1) / 2 * x + cnt;
}

int main() {
    int n; scanf("%d", &n);
    vector<long long> ans;
    for (int i = 1; i * i <= n; ++i) {
        if (n % i != 0) continue;
        ans.push_back(calc(i, n));
        if (i * i != n) ans.push_back(calc(n / i, n));
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < (int)ans.size(); ++i) printf("%lld ", ans[i]);
    return 0;
}