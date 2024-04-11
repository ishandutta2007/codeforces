#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 10;

long long check(long long, long long);

int main() {
    long long x; cin >> x;
    vector<pair<long long, long long>> ans;
    for (long long n = 1; n <= 2 * cbrt(x); ++n) {
        long long d = x + n * n * (n - 1) / 2 - (n - 1) * n * (2 * n - 1) / 6;
        if (d < x) continue;
        long long p = n * n - n * (n - 1) / 2;
        if (p < 0) continue;
        if (d % p == 0 && check(n, d / p) == x) ans.push_back(make_pair(n, d / p)), ans.push_back(make_pair(d / p, n));
    }
    sort(ans.begin(), ans.end()); ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << ' ' << p.second << endl;
    return 0;
}

long long check(long long n, long long m) {
    if (n > m) swap(n, m);
    return n * n * m - n * (n - 1) / 2 * (n + m) + (n - 1) * n * (2 * n - 1) / 6;
}