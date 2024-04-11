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
    int n; cin >> n;
    Vi goal(n);
    ll sum = 0;

    each(e, goal) {
        cin >> e;
        sum += e;
    }

    map<Pii, int> stones;

    int q; cin >> q;

    while (q--) {
        int s, t, u; cin >> s >> t >> u;

        if (stones.count({s, t})) {
            int& g = goal[stones[{s, t}]];
            sum -= max(g, 0);
            g++;
            sum += max(g, 0);
            stones.erase({s, t});
        }

        if (u != 0) {
            stones[{s, t}] = u-1;

            int& g = goal[u-1];
            sum -= max(g, 0);
            g--;
            sum += max(g, 0);
        }

        cout << sum << '\n';
    }
}