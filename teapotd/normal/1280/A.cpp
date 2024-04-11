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

constexpr int MOD = 1e9+7;

void run() {
    int t; cin >> t;

    while (t--) {
        int x;
        string s;
        cin >> x >> s;

        ll len = sz(s);

        rep(pos, 0, x) {
            int times = s[pos]-'0';
            if (times == 1) continue;

            len = pos + ll(len-pos-1) * times + 1;
            len %= MOD;

            if (sz(s) < x) {
                string tail = s.substr(pos+1);
                rep(i, 1, times) {
                    s += tail;
                    if (sz(s) >= x) break;
                }
            }
        }

        len %= MOD;
        if (len < 0) len += MOD;
        cout << len << '\n';
    }
}