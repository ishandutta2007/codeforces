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
    int n; cin >> n;
    Vi deg(n+1), val(n+1, 1);

    rep(d, 1, n+1) {
        for (int k = d*2; k <= n; k += d) {
            deg[k]++;
            val[k] = max(val[k], d);
        }
    }

    priority_queue<Pii, vector<Pii>, greater<Pii>> que;
    rep(d, 1, n+1) {
        if (deg[d] == 0) {
            que.push({val[d], d});
        }
    }

    int ans = 0;
    bool first = true;

    while (!que.empty()) {
        int d = que.top().y;
        que.pop();
        ans = max(ans, val[d]);

        if (first) {
            first = false;
        } else {
            cout << ans << ' ';
        }

        for (int k = d*2; k <= n; k += d) {
            if (--deg[k] == 0) {
                que.push({val[k], k});
            }
        }
    }

    cout << '\n';
}