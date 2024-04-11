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
    int r, c; cin >> r >> c;

    if (r == 1 && c == 1) {
        cout << 0 << endl;
        return;
    }

    if (r == 1) {
        rep(i, 0, c) cout << i+2 << ' ';
        cout << '\n';
        return;
    }

    if (c == 1) {
        rep(i, 0, r) cout << i+2 << '\n';
        return;
    }

    rep(i, 0, r) {
        rep(j, 0, c) {
            ll a = i+1, b = j+r+1;
            cout << a*b << ' ';
        }
        cout << '\n';
    }
}