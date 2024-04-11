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
        int n; cin >> n;
        set<Pii> elems;
        vector<Pii> ans;

        rep(i, 0, n) {
            int e; cin >> e;
            elems.insert({e, i});
        }

        while (sz(elems) >= 2) {
            if (elems.begin()->x == 0) {
                elems.erase(elems.begin());
                continue;
            }
            auto it = --elems.end();
            Pii a = *it;
            elems.erase(it);
            it = --elems.end();
            Pii b = *it;
            elems.erase(it);

            a.x--; b.x--;
            ans.pb({a.y, b.y});
            elems.insert(a);
            elems.insert(b);
        }

        cout << sz(ans) << '\n';
        each(e, ans) cout << e.x+1 << ' ' << e.y+1 << '\n';
    }
}