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
    set<pair<Pii, bool>> seen;
    string s;
    while (t--) {
        seen.clear();
        cin >> s;

        Pii pos = {0,0};
        int ans = 0;

        each(c, s) {
            if (c == 'N' || c == 'E') {
                ans += seen.insert({pos, c == 'N'}).y ? 5 : 1;
            }
            if (c == 'N') pos.x++;
            else if (c == 'S') pos.x--;
            else if (c == 'E') pos.y++;
            else if (c == 'W') pos.y--;
            else assert(0);
            if (c == 'S' || c == 'W') {
                ans += seen.insert({pos, c == 'S'}).y ? 5 : 1;
            }
        }

        cout << ans << '\n';
    }
}