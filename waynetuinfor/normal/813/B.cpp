#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long x, y, l, r; cin >> x >> y >> l >> r;
    set<long long> ul;
    long long ans = 0;
    for (long long xc = 1LL; xc <= r; xc *= x) {
        long long yc = 1LL;
        for (long long yc = 1LL; yc <= r; yc *= y) {
            if (yc + xc >= l && yc + xc <= r) ul.insert(yc + xc);
            else if (yc + xc > r) break;
            if ((long double)yc > (long double)r / (long double)y) break;
        }
        if ((long double)xc > (long double)r / (long double)x) break;
    }
    ul.insert(r + 1);
    long long last = l - 1;
    for (long long p : ul) {
        ans = max(ans, p - last - 1);
        last = p;
    } 
    cout << ans << endl;
    return 0;
}