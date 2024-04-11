#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

void solve() {
    ll n;
    int m;
    cin >> n >> m;

    vector<ll> cnt(61);
    ll ans = 0;

    rep(i, 0, m) {
        int a; cin >> a;
        cnt[__builtin_ctz(a)]++;
    }

    rep(bit, 0, sz(cnt)) {
        if ((n >> bit) & 1) {
            if (cnt[bit] == 0) {
                int j = bit+1;
                while (j < sz(cnt) && cnt[j] == 0) j++;

                if (j >= sz(cnt)) {
                    cout << -1 << '\n';
                    return;
                }

                rep(i, bit, j) cnt[i]++;
                cnt[j]--;
                ans += j-bit;
            } else {
                cnt[bit]--;
            }
        }

        if (bit+1 < sz(cnt)) {
            cnt[bit+1] += cnt[bit]/2;
        }
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}