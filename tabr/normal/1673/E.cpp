#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    const long long z = (long long) 1e9;
    unordered_map<long long, int> memo;
    auto F = [&](int x, int y) {
        if (memo.count(z * x + y)) {
            return memo[z * x + y];
        }
        int res = 0;
        for (int i = y; i <= x; i++) {
            res ^= ((x & i) == i);
        }
        return memo[z * x + y] = res;
    };
    vector<int> ans(1 << 20);
    for (int i = 0; i < n; i++) {
        long long t = 1;
        for (int j = i; j < n; j++) {
            if (i == j) {
                t *= a[i];
            } else {
                t <<= min(21, a[j]);
            }
            if (t == 0 || t >= (1 << 20)) {
                break;
            }
            int remain = n - 1 - (j - i);
            int need = k;
            if (i != 0) {
                need--;
                remain--;
            }
            if (j != n - 1) {
                need--;
                remain--;
            }
            need = max(need, 0);
            ans[t] ^= F(remain, need);
        }
    }
    while (ans.size() > 1 && ans.back() == 0) {
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
        printf("%d", i);
    }
    printf("\n");
    return 0;
}