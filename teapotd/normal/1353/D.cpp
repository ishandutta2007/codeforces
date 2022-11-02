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
        Vi elems(n);

        priority_queue<pair<int, Pii>> que;
        que.push({n, {0, n}});
        int cnt = 1;

        while (!que.empty()) {
            int b = -que.top().y.x, e = que.top().y.y;
            que.pop();
            if (b >= e) continue;

            int m = (b+e+1) / 2 - 1;
            elems[m] = cnt++;
            que.push({m-b, {-b, m}});
            que.push({e-m-1, {-m-1, e}});
        }

        each(e, elems) cout << e << ' ';
        cout << '\n';
    }
}