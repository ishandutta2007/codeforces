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
    int k; cin >> k;
    map<ll, Pii> seen;

    rep(i, 0, k) {
        int n; cin >> n;
        Vi seq(n);
        each(e, seq) cin >> e;

        ll sum = 0;
        each(e, seq) sum += e;

        rep(j, 0, n) {
            ll opt = sum-seq[j];

            if (seen.count(opt)) {
                Pii x = seen[opt];
                cout << "YES\n";
                cout << x.x+1 << ' ' << x.y+1 << '\n';
                cout << i+1 << ' ' << j+1 << '\n';
                return;
            }
        }

        rep(j, 0, n) {
            ll opt = sum-seq[j];
            seen[opt] = {i, j};
        }
    }

    cout << "NO\n";
}