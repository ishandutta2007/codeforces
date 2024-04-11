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
    int t; cin >> t;

    while (t--) {
        int n, m, k; cin >> n >> m >> k;
        Vi elems(n);
        each(e, elems) cin >> e;

        int ans = -1;
        k = min(k, m-1);

        rep(l, 0, k+1) {
            int r = n-(k-l)-1;
            int rest = m-k-1;
            int alt = INT_MAX;
            rep(a, 0, rest+1) {
                int b = rest-a;
                int opt1 = elems[l+a];
                int opt2 = elems[r-b];
                alt = min(alt, max(opt1, opt2));
            }
            ans = max(ans, alt);
        }

        cout << ans << '\n';
    }
}