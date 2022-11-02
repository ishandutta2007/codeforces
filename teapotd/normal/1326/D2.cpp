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

Vi tree;
int len;

void upd(int vb, int ve, int val, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;
    if (b >= vb && e <= ve) {
        tree[i] = max(tree[i], val);
        return;
    }
    int m = (b+e) / 2;
    upd(vb, ve, val, i*2, b, m);
    upd(vb, ve, val, i*2+1, m, e);
}

void push() {
    rep(i, 1, len) {
        tree[i*2] = max(tree[i*2], tree[i]);
        tree[i*2+1] = max(tree[i*2+1], tree[i]);
    }
}

void solve() {
    string s; cin >> s;
    Pii ans = {0, 0};

    rep(times, 0, 2) {
        Vi rad = manacher(s);

        for (len = 1; len < sz(s); len *= 2);
        tree.assign(len*2, -1);

        for (int center = 0; center < sz(rad); center++) {
            if (sz(s) % 2) {
                if (center > sz(s)/2*2) break;
            } else {
                if (center > sz(s)/2*2-1) break;
            }

            int i = center/2;
            int from = i-rad[center]+1;
            int to = i;

            upd(from, to+1, center);
        }

        push();

        for (int common = 0; common*2 <= sz(s); common++) {
            int far = tree[len+common];
            int maxLen = 0;

            if (far != -1) {
                if (far%2) {
                    maxLen = max(maxLen, (far/2 - common + 1) * 2);
                } else {
                    maxLen = max(maxLen, (far/2 - common) * 2 + 1);
                }
            }

            int alt = maxLen + common*2;
            if (alt > ans.x+ans.y) {
                ans.x = common+maxLen;
                ans.y = common;
                if (times == 1) swap(ans.x, ans.y);
            }

            if (s[common] != s[sz(s)-common-1]) {
                break;
            }
        }

        reverse(all(s));
    }

    string kek = s.substr(0, ans.x) + s.substr(sz(s)-ans.y);
    cout << kek << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}