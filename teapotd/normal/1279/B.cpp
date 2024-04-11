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
        int n;
        ll s;
        cin >> n >> s;

        vector<ll> prefs = {0};

        rep(i, 0, n) {
            int k; cin >> k;
            prefs.pb(prefs.back()+k);
        }

        Pii ans = {-1, 0};
        rep(i, 0, n+1) if (prefs[i] <= s) ans.x = i;

        rep(i, 0, n) {
            ll remain = s - prefs[i];
            if (remain <= 0) break;

            auto it = upper_bound(prefs.begin()+i+2, prefs.end(), remain+prefs[i+1]);
            int num = int(it - prefs.begin() - i - 2);
            deb(i, i+num, ans, prefs);
            if (i+num > ans.x) {
                ans = {i+num, i+1};
            }
        }

        cout << ans.y << '\n';
    }
}