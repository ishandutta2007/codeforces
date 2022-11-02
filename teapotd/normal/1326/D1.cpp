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

template<class T> Vi manacher(const T& str) {
    int n = sz(str)*2, c = 0, e = 1;
    Vi r(n, 1);
    auto get = [&](int i) { return i%2 ? 0 :
        (i >= 0 && i < n ? str[i/2] : i); };

    rep(i, 0, n) {
        if (i < e) r[i] = min(r[c*2-i], e-i);
        while (get(i-r[i]) == get(i+r[i])) r[i]++;
        if (i+r[i] > e) c = i, e = i+r[i]-1;
    }

    rep(i, 0, n) r[i] /= 2;
    return r;
}

/*
void solve() {
    string s; cin >> s;

    rep(times, 0, 2) {
        Vi rad = manacher(s);

        for (int common = 0; common*2 <= sz(s); common++) {

            int len = sz(s) - common*2;
            int left = common*2+1;
            int right = (len%2 ? (common + len/2)*2 : (common + len/2)*2-1);

            for (int center = left; center <= right; center++) {
                int r = rad[center];
                int from = center - r*2;
                int to = center + r*2;
            }

            if (s[common] != s[sz(s)-common-1]) {
                break;
            }
        }

        reverse(all(s));
    }
}
*/

void solve() {
    string s; cin >> s;
    string ans;

    rep(times, 0, 2) {
        Vi rad = manacher(s);

        auto pal = [&](int b, int e) {
            if (b == e) return true;
            if ((e-b) % 2) {
                return rad[(b+e)/2*2] >= (e-b)/2+1;
            } else {
                return rad[(b+e)/2*2-1] >= (e-b)/2;
            }
        };

        for (int common = 0; common*2 <= sz(s); common++) {
            int maxLen = 0;
            rep(len, 0, sz(s)-common*2+1) {
                if (pal(common, common+len)) {
                    maxLen = len;
                }
            }

            int alt = maxLen + common*2;
            if (alt > sz(ans)) {
                ans = s.substr(0, common+maxLen) + s.substr(sz(s)-common);
            }

            if (s[common] != s[sz(s)-common-1]) {
                break;
            }
        }

        reverse(all(s));
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}