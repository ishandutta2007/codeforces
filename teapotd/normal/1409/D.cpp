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

ll sum(ll k) {
    ll ret = 0;
    while (k) {
        ret += k%10;
        k /= 10;
    }
    return ret;
}

void run() {
    int t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;

        if (sum(n) <= s) {
            cout << 0 << '\n';
            continue;
        }

        ll ten = 10;

        while (true) {
            ll rem = ten - n%ten;
            if (sum(n+rem) <= s) {
                cout << rem << '\n';
                break;
            }
            ten *= 10;
        }
    }
}