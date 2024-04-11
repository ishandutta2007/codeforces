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
        string s; cin >> s;

        rep(i, 0, sz(s)) {
            if (s[i] == '?') {
                rep(j, 0, 3) {
                    char c = "abc"[j];
                    if (i > 0 && s[i-1] == c) continue;
                    if (i+1 < sz(s) && s[i+1] == c) continue;
                    s[i] = c;
                    break;
                }
            }
        }

        bool ok = 1;

        rep(i, 1, sz(s)) {
            if (s[i] == s[i-1]) {
                ok = 0;
                break;
            }
        }

        if (ok) {
            cout << s << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
}