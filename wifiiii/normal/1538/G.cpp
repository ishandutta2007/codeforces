#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
ll mint(ll l, ll r) {
    assert(l<=r);
    ll x=mrand()%(r-l+1);
    return x+l;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int lo = 0, hi = min(x / a, y / b);
        auto calc = [&](int m) {
            // m * a <= x, m * b <= y
            assert(m * a <= x && m * b <= y);
            int rx = x - m * a, ry = y - m * b;
            return min(rx / b, ry / a) + m;
        };
        auto calc2 = [&](int m) {
            // m * a <= x, m * b <= y
            assert(m * a <= x && m * b <= y);
            int rx = x - m * a, ry = y - m * b;
            return min(1.0 * rx / b, 1.0 * ry / a) + m;
        };
        while(lo < hi) {
            int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
            if(calc2(m1) > calc2(m2)) hi = m2 - 1;
            else lo = m1 + 1;
        }
        cout << calc(lo) << '\n';
    }
}
/*
73 58 14 18
3 4
 */