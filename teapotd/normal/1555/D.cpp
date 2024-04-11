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

const string keks[] = { "abc", "acb", "bac", "bca", "cab", "cba" };

void run() {
    int n, m; cin >> n >> m;
    string s; cin >> s;

    Vi mis[18];

    rep(i, 0, 18) {
        string kek = keks[i/3];
        mis[i].pb(0);
        rep(j, 0, n) {
            mis[i].pb(mis[i].back() + (s[j] != kek[(i+j)%3]));
        }
    }

    rep(t, 0, m) {
        int l, r; cin >> l >> r;
        int ans = 1e9;
        rep(i, 0, 18) {
            ans = min(ans, mis[i][r] - mis[i][l-1]);
        }
        cout << ans << '\n';
    }
}