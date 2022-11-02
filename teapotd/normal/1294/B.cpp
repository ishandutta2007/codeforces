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
        int n; cin >> n;
        vector<Pii> elems(n);
        each(e, elems) cin >> e.x >> e.y;
        sort(all(elems));

        string ans;
        Pii last = {0, 0};
        bool ok = 1;

        each(e, elems) {
            if (e.x < last.x || e.y < last.y) {
                ok = 0;
                break;
            }

            int x = e.x-last.x, y = e.y-last.y;
            last = e;
            rep(i, 0, x) ans.pb('R');
            rep(i, 0, y) ans.pb('U');
        }

        if (ok) {
            cout << "YES\n" << ans << '\n';
        } else {
            cout << "NO\n";
        }
    }
}