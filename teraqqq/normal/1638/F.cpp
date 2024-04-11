#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

#include <cassert>

#define F first
#define S second

using namespace std;
using ll = long long;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

ll solve(const int n, const vector<ll>& h) {
    vector<int> pl(n), pr(n);

    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        pl[i] = i - 1;
        while (pl[i] != -1 && h[pl[i]] >= h[i]) pl[i] = pl[pl[i]];
    }

    for (int i = n; i--; ) {
        pr[i] = i + 1;
        while (pr[i] != n && h[pr[i]] >= h[i]) pr[i] = pr[pr[i]];
    }

    for (int& x : pl) ++x;

    for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
        if (pr[i] <= pl[j]) {
            ans = max(ans, (ll)(pr[i] - pl[i])*h[i] + (ll)(pr[j] - pl[j])*h[j]);
        }

        if (pl[i] <= pl[j] && pr[j] <= pr[i]) {
            ans = max(ans, (ll)(pr[i] - pl[i])*h[i] + (ll)(pr[j] - pl[j])*(h[j]-h[i]));
        }
    }

    for (int i = 0; i < n; ++i) {
        const int l = pl[i], r = pr[i];
        const ll x = h[i];

        vector<pair<int, ll>> stl, str;

        for (int j = i; j >= 0; j = pl[j]-1) stl.emplace_back(pl[j], h[j]);
        for (int j = i; j < n;  j = pr[j])   str.emplace_back(pr[j], h[j]);
        reverse(stl.begin(), stl.end());

        vector<ll> kek_sq(size(str)+1);
        for (int j = 0; j < size(str); ++j) {
            kek_sq[j] =  (ll)(str[j].F - l)*str[j].S;
            if (kek_sq[j] < kek_sq[j+1]) kek_sq[j] = kek_sq[j+1];
        }

        ll tmax = 0;
        for (int i = 0, j = 0; i < size(stl); ++i) {
            while(j < size(str) && stl[i].S + str[j].S >= x) ++j;

            if (j < size(str)) {
                ckmax(ans, (ll)(r - stl[i].F)*stl[i].S + kek_sq[j]);
            }

            if (j > 0) {
                j--;
                ckmax(ans, (ll)(r - stl[i].F)*stl[i].S + (ll)(str[j].F - l)*(x - stl[i].S));
                j++;
            }
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;
    vector<ll> h(n);
    for (ll& x : h) cin >> x;

    ll ans = solve(n, h);
    reverse(h.begin(), h.end());
    ans = max(ans, solve(n, h));

    cout << ans << '\n';
}