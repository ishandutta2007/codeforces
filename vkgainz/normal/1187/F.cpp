#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define all(c) ((c).begin()), ((c).end())

long long MOD = 1e9 + 7;

long long inv(long long b, long long p = MOD - 2) {
    if (p == 0) return 1LL;
    long long x = inv(b, p / 2);
    x = x * x % MOD;
    if (p % 2) x = x * b % MOD;
    return x;
}

pair<int, int> intersection(pair<int, int> a, pair<int, int> b) {
    return {max(a.first, b.first), min(a.second, b.second)};
}

int intersection(vector<pair<int, int>> in) {
    pair<int, int> ans = {1, 1e9};
    for (auto &it : in) {
        ans = intersection(ans, it);
    }
    return max(0, ans.second - ans.first + 1);
}

int main() {
    int n; cin >> n;
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    vector<long long> p(n - 1);
    //p[i] = P(x[i] == x[i + 1])
    long long ans = 1LL;
    for (int i = 0; i < n - 1; i++) {
        long long denom = (r[i] - l[i] + 1) * 1LL * (r[i + 1] - l[i + 1] + 1) % MOD;
        p[i] = intersection({{l[i], r[i]}, {l[i + 1], r[i + 1]}}); 
        p[i] *= inv(denom);
        p[i] %= MOD;
    }
    for (int i = 0; i < n - 1; i++) {
        ans += (1 - p[i]) * 1LL * 3;
        ans %= MOD;
    }
    for (int i = 0; i < n - 2; i++) {
        long long nxt = 2 * 1LL * (1 - (p[i] + p[i + 1])) % MOD;
        long long add = intersection({{l[i], r[i]}, {l[i + 1], r[i + 1]}, {l[i + 2], r[i + 2]}});
        long long denom = (r[i] - l[i] + 1) * 1LL * (r[i + 1] - l[i + 1] + 1) % MOD
            * 1LL * (r[i + 2] - l[i + 2] + 1) % MOD;
        nxt += add * 1LL * inv(denom) * 1LL * 2 % MOD;
        if (nxt < 0) nxt += MOD;
        ans += nxt;
        ans %= MOD;
    }
    long long sum = 0LL;
    for (int i = n - 2; i >= 0; i--) {
        ans += 2 * 1LL * (1 - p[i]) * 1LL * sum % MOD;
        ans %= MOD;
        if (i + 1 < n - 1) {
            sum += (1 - p[i + 1]);
            sum %= MOD;
        }
    }
    if (ans < 0) ans += MOD;
    cout << ans << "\n";
}