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
        int n0, n1, n2;
        cin >> n0 >> n1 >> n2;

        int len = n0+n1+n2+1;
        string ans;

        if (n1 > 1) {
            ans.pb(n0 > n2 ? '0' : '1');
            n1 -= 2;
            while (n1--) {
                ans.pb((ans.back() == '0' ? '1' : '0'));
            }
            if (ans.back() == '0') {
                rep(i, 0, n2+1) ans.pb('1');
                rep(i, 0, n0+1) ans.pb('0');
            } else {
                rep(i, 0, n0+1) ans.pb('0');
                rep(i, 0, n2+1) ans.pb('1');
            }
        } else if (n1 > 0) {
            rep(i, 0, n0+1) ans.pb('0');
            rep(i, 0, n2+1) ans.pb('1');
        } else {
            if (n0 > 0) {
                rep(i, 0, n0+1) ans.pb('0');
            } else {
                rep(i, 0, n2+1) ans.pb('1');
            }
        }

        /*
        if (blocks % 2) {
            int zeroes = n0 + blocks/2;
            int ones = n1 + blocks/2 + 1;

            rep(i, 0, blocks/2-1) ans += "10";
            ans += "1";
            rep(i, 0, zeroes-blocks/2+1) ans.pb('0');
            rep(i, 0, ones-blocks/2+1-1) ans.pb('1');
        } else {
            int zeroes = n0 + blocks/2;
            int ones = n1 + blocks/2;
            rep(i, 0, blocks/2-1) ans += "10";
            rep(i, 0, zeroes-blocks/2+1) ans.pb('1');
            rep(i, 0, ones-blocks/2+1) ans.pb('0');
        }
        */

        cout << ans << '\n';
#ifdef LOC
        cout << flush;
        deb(ans, sz(ans), len);
        assert(sz(ans) == len);
#endif
    }
}