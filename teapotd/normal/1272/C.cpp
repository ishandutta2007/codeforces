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

ll ch2(ll a) {
    return a*(a+1) / 2;
}

void run() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool avail[26] = {};

    rep(i, 0, k) {
        char c; cin >> c;
        avail[c-'a'] = 1;
    }

    ll ans = 0;
    int last = 0;

    rep(i, 0, sz(s)) {
        if (!avail[s[i]-'a']) {
            ans += ch2(i-last);
            last = i+1;
        }
    }

    ans += ch2(sz(s)-last);

    cout << ans << endl;
}