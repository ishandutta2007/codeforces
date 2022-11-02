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
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;

    Vi prv(n, -1), dp(n, -1);
    map<int, int> last;
    int best = 0;

    rep(i, 0, n) {
        int e = elems[i];
        dp[i] = 1;
        prv[i] = -1;

        if (last.count(e-1)) {
            int j = last[e-1];
            if (dp[j]+1 > dp[i]) {
                dp[i] = dp[j]+1;
                prv[i] = j;
            }
        }

        last[e] = i;

        if (dp[i] > dp[best]) {
            best = i;
        }
    }

    Vi ans;
    int j = best;

    while (j != -1) {
        ans.pb(j);
        j = prv[j];
    }

    reverse(all(ans));
    cout << sz(ans) << '\n';
    each(a, ans) cout << a+1 << ' ';
    cout << '\n';
}