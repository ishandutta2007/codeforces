#include <bits/stdc++.h>
using namespace std;

bool v[20][10];
long long dp[20][10];

long long dfs(int p, int z) {
    if (p == 0) {
        if (z == 0) return 1;
        return 0;
    }
    if (v[p][z]) return dp[p][z];
    dp[p][z] = 0;
    for (int i = 0; i < 10; ++i) {
        int tz = z;
        if (i != 0) --tz;
        if (tz >= 0) dp[p][z] += dfs(p - 1, tz);
    }
    v[p][z] = true;
    return dp[p][z];
}

long long calc(long long x) {
    vector<int> d;
    long long tx = x;
    while (tx) d.push_back(tx % 10), tx /= 10;
    reverse(d.begin(), d.end());
    int z = 0;
    long long ans = 0;
    for (int i = 0; i < d.size(); ++i) {
        for (int j = 0; j < d[i]; ++j) {
            int tz = z;
            if (j != 0) ++tz;
            for (int k = 0; k <= 3; ++k) {
                if (k >= tz) ans += dfs(d.size() - i - 1, k - tz);
            }
        }
        if (d[i] != 0) ++z;
    }
    if (z <= 3) ++ans;
    return ans;
}

long long brute(long long x) {
    long long res = 0;
    for (long long i = 1; i <= x; ++i) {
        int z = 0;
        long long j = i;
        while (j) {
            if (j % 10 != 0) ++z;
            j /= 10;
        }
        if (z <= 3) ++res;
    }
    return res;
}

int main() {
    int t; cin >> t;
    while (t--) {
        long long l, r; cin >> l >> r;
        cout << calc(r) - calc(l - 1) << '\n';
    }
    return 0;
}