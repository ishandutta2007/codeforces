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

constexpr int MAX_N = 1e5+5;

char a[MAX_N], b[MAX_N];

void solve() {
    int n; cin >> n;
    cin >> a >> b;

    char *ptr = b;
    int dir = 1, flip = 0;
    Vi ans;

    auto get = [&](int i) {
        return ptr[i*dir] ^ flip;
    };

    for (int len = n; len > 0; len--) {
        if (a[len-1] == get(len-1)) {
            continue;
        }

        if (get(len-1) != get(0)) {
            ans.pb(1);
            ptr[0] ^= 1;
        }

        ans.pb(len);
        ptr += (len-1)*dir;
        dir *= -1;
        flip ^= 1;
    }

    reverse(all(ans));
    cout << sz(ans) << ' ';
    each(x, ans) cout << x << ' ';
    cout << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}