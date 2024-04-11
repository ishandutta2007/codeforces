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

void run() {
    int n, m; cin >> n >> m;
    vector<Vi> mat(n, Vi(m));
    each(r, mat) each(v, r) cin >> v;

    int ans = 0;

    rep(c, 0, m) {
        int opt = INT_MAX;
        Vi cnt(n);

        rep(i, 0, n) {
            int k = mat[i][c] - (c+1);
            if (k%m == 0) {
                k /= m;
                if (k >= 0 && k < n) {
                    int shift = (i-k+n) % n;
                    cnt[shift]++;
                }
            }
        }

        rep(shift, 0, n) {
            int alt = n+shift-cnt[shift];
            opt = min(opt, alt);
        }

        ans += opt;
    }

    cout << ans << '\n';
}