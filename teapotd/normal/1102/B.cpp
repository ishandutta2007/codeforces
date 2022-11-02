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
    int n, k; cin >> n >> k;
    Vi elems(n), col(n);
    each(e, elems) cin >> e;
    int nxt = 0;

    rep(i, 1, 5001) {
        int cnt = 0;
        rep(j, 0, n) {
            if (elems[j] == i) {
                col[j] = nxt+1;
                nxt = (nxt+1) % k;
                cnt++;
            }
        }
        if (cnt > k) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
    each(c, col) cout << c << ' ';
    cout << '\n';
}