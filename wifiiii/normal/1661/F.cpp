#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

inline ll f(ll x, ll k) {
    ll p = x / k, r = x % k;
    return r * (p + 1) * (p + 1) + (k - r) * p * p;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = n - 1; i >= 1; --i) a[i] -= a[i - 1];
    ll m;
    cin >> m;
    ll cur = 0;
    for(ll i : a) cur += i * i;
    if(cur <= m) {
        cout << 0 << '\n';
        return 0;
    }
    m = cur - m;
    auto solve2 = [&](ll k) {
        ll ret = 0;
        for(ll x : a) {
            ll lo = 1, hi = x;
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if(f(x, mid - 1) - f(x, mid) >= k) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            ret += f(x, 1) - f(x, lo);
        }
        return ret;
    };
    auto solve = [&](ll k) {
        ll cnt = 0, sum = 0;
        for(ll x : a) {
            ll lo = 1, hi = x;
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if(f(x, mid - 1) - f(x, mid) >= k) {
                    lo = mid;
                } else {
                    hi = mid - 1;
                }
            }
            cnt += lo - 1;
            sum += f(x, 1) - f(x, lo);
        }
        return cnt - (sum - m) / k;
    };
    ll lo = 0, hi = 1e18;
    while(lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if(solve2(mid) >= m) lo = mid;
        else hi = mid - 1;
    }
    cout << solve(lo) << '\n';
}