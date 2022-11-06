#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 1;
long long n;

long double check(long double x, long double k) {
    return k * x - x + (x * x - x) / 2;
}

int main() {
    cin >> n;
    vector<long long> ans;
    for (int t = 0; (1ll << t) <= 1e18; ++t) {
        long long k = (1ll << t);
        long long d = 1ll, now = 0; while (d < inf) d <<= 1;
        while (d >>= 1) if (now + d < inf) if (check(now + d, k) <= n) now += d;
        if (now & 1 && check(now, k) == n) ans.push_back(k * now);
    }
    sort(ans.begin(), ans.end());
    if (ans.size() == 0) cout << "-1" << endl;
    else for (long long i : ans) cout << i << endl;
    return 0;
}