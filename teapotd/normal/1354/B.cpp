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
        string s; cin >> s;
        int last[3] = {-1,-1,-1};
        int ans = sz(s)+5;

        rep(i, 0, sz(s)) {
            last[s[i]-'1'] = i;
            int b = min(last[0], min(last[1], last[2]));
            if (b >= 0) {
                ans = min(ans, i-b+1);
            }
        }

        if (ans > sz(s)) ans = 0;
        cout << ans << '\n';
    }
}