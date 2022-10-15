#include "bits/stdc++.h"

using namespace std;

#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(x) begin(x), end(x)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

const int FIXED_RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(FIXED_RANDOM);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 1;

    uniform_int_distribution<int> unif(0, n - 1);
    for (int it = 0; it < 10; ++it) {
        ll x = a[unif(rng)], tmp = x;
        vector<ll> div;
        for (ll d = 1; d * d <= x; ++d) {
            if (x % d == 0) {
                div.push_back(d);
                if (x * x != d) div.push_back(x / d);
            }
        }
        vector<ll> pr;
        for (ll p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                pr.push_back(p);
                while (x % p == 0) x /= p;
            }
        }
        if (x > 1) pr.push_back(x);
        x = tmp;

        unordered_map<ll, int> cnt;
        for (auto y : a) ++cnt[gcd(x, y)];

        sort(all(div)), reverse(all(div));
        for (auto p : pr) {
            for (auto d : div) {
                int k = cnt[d];
                if (d % p == 0) cnt[d / p] += k;
            }
        } 
        for (auto d : div) {
            if (cnt[d] >= (n + 1) / 2) ans = max(ans, d);
        }
    }

    cout << ans << endl;

    exit(0);
}