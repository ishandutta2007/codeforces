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
    int k; cin >> k;

    if (k > 4*n*m - 2*n - 2*m) {
        cout << "NO\n";
        return;
    }

    vector<pair<int, string>> steps;
    if (m > 1) {
        steps.pb({m-1, "R"});
        steps.pb({m-1, "L"});
    }
    rep(i, 1, n) {
        steps.pb({1, "D"});
        if (m > 1) {
            steps.pb({m-1, "R"});
            steps.pb({m-1, "UDL"});
        }
    }
    if (n > 1) {
        steps.pb({n-1, "U"});
    }

    vector<pair<int, string>> ans;
    int i = 0;

    while (k > 0) {
        auto s = steps[i++];
        int len = sz(s.y);
        int tot = s.x * len;

        if (tot <= k) {
            ans.pb({s.x, s.y});
            k -= tot;
            continue;
        }

        int full = k / len;
        if (full > 0) {
            ans.pb({full, s.y});
        }

        if (k%len != 0) {
            string rest = s.y.substr(0, k%len);
            ans.pb({1, rest});
        }
        break;
    }

    cout << "YES\n";
    cout << sz(ans) << '\n';
    each(a, ans) cout << a.x << ' ' << a.y << '\n';
}