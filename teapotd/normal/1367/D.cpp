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
    int q; cin >> q;

    while (q--) {
        string s; cin >> s;
        int m; cin >> m;
        Vi b(m);
        each(k, b) cin >> k;

        int cnt[26] = {};
        each(c, s) cnt[c-'a']++;
        string t(m, '?');
        int nxt = 25;

        while (true) {
            Vi pos;
            rep(i, 0, m) if (t[i] == '?' && b[i] == 0) pos.pb(i);
            if (pos.empty()) break;
            while (cnt[nxt] < sz(pos)) nxt--;
            each(i, pos) {
                rep(j, 0, m) b[j] -= abs(i-j);
                t[i] = char(nxt+'a');
            }
            nxt--;
        }

        cout << t << '\n';
    }
}