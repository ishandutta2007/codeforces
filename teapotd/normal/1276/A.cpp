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
        Vi inds;

        rep(i, 4, sz(s)) {
            if (s.substr(i-4, 5) == "twone") {
                s[i-2] = '.';
                inds.pb(i-1);
            }
        }

        rep(i, 2, sz(s)) {
            if (s[i-2] == 'o' && s[i-1] == 'n' && s[i] == 'e') {
                inds.pb(i);
            }
            if (s[i-2] == 't' && s[i-1] == 'w' && s[i] == 'o') {
                inds.pb(i);
            }
        }

        sort(all(inds));
        inds.erase(unique(all(inds)), inds.end());

        cout << sz(inds) << '\n';
        each(i, inds) cout << i << ' ';
        cout << '\n';
    }
}