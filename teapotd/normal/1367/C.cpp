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
        int n, k; cin >> n >> k;
        Vi elems;
        elems.pb(1);
        rep(i, 0, k) elems.pb(0);
        string s; cin >> s;
        each(c, s) elems.pb(c-'0');
        rep(i, 0, k) elems.pb(0);
        elems.pb(1);

        int ans = 0;

        rep(i, 0, sz(elems)-1) {
            if (elems[i] != 1) continue;
            int j = i+1;
            while (elems[j] == 0) j++;
            int cnt = j-i-1;
            if (cnt >= k*2+1) {
                ans += (cnt-k) / (k+1);
            }
        }

        cout << ans << '\n';
    }
}