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
        int l = 0, r = 0, d = 0, u = 0;

        each(c, s) {
            if (c == 'L') l++;
            else if (c == 'R') r++;
            else if (c == 'U') u++;
            else if (c == 'D') d++;
        }

        int up = min(d, u);
        int side = min(l, r);

        if (up == 0) {
            side = min(side, 1);
        }
        if (side == 0) {
            up = min(up, 1);
        }

        cout << up+side+up+side << '\n';
        cout << string(up, 'U');
        cout << string(side, 'L');
        cout << string(up, 'D');
        cout << string(side, 'R');
        cout << '\n';
    }
}