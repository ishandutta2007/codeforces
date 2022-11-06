#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 1;

int main() {
    long long x, y; cin >> x >> y;
    vector<long long> fac;
    long long tmp = x;
    for (long long i = 2; i <= min(x, (long long)1e6); ++i) {
        if (tmp <= 1) break;
        int cnt = 0;
        while (tmp % i == 0) tmp /= i, ++cnt;
        if (cnt) fac.push_back(i);
    }
    // fac.push_back(1);
    if (tmp > 1) fac.push_back(tmp);
    long long ans = 0;
    while (true) {
        if (y == 0) break;
        long long g = __gcd(x, y);
        long long xx = x / g, yy = y / g;
        if (xx == 1 || yy == 1) {
            ans += yy;
            break;
        }
        long long t = inf;
        for (long long f : fac) if (xx % f == 0){
            long long cur = (yy - (yy / f) * f);
            t = min(t, cur);
        }
        ans += t;
        y -= t * g;
    }
    cout << ans << endl;
    return 0;
}