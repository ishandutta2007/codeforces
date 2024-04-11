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

void solve() {
    string s; cin >> s;
    string kb;

    Vi seen(26, -1);
    kb.pb(s[0]);
    seen[s[0]-'a'] = 0;

    if (sz(s) > 1) {
        kb.pb(s[1]);
        seen[s[1]-'a'] = 1;
        int pos = 1;

        rep(i, 2, sz(s)) {
            char c = s[i];
            int kek = seen[c-'a'];

            if (kek != -1) {
                if (abs(pos-kek) != 1) {
                    cout << "NO\n";
                    return;
                }
                pos = kek;
            } else {
                if (pos == 0) {
                    kb.insert(kb.begin(), c);
                    each(j, seen) if (j != -1) j++;
                    pos = seen[c-'a'] = 0;
                } else if (pos == sz(kb)-1) {
                    kb.pb(c);
                    pos = seen[c-'a'] = sz(kb)-1;
                } else {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    rep(i, 0, 26) if (seen[i] == -1) kb.pb(char(i+'a'));
    cout << "YES\n";
    cout << kb << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}