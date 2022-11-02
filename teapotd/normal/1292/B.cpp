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

using Pll = pair<ll, ll>;
constexpr ll INF = 2e17;

ll safeMul(ll a, ll b) {
    if (!a || !b) return 0;
    if (INF/a < b) return INF;
    return min(a*b, INF);
}

ll dist(Pll a, Pll b) {
    return min(abs(a.x-b.x) + abs(a.y-b.y), INF);
}

void run() {
    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;

    ll xs, ys, t;
    cin >> xs >> ys >> t;

    vector<Pll> points;
    points.pb({x0, y0});

    while (true) {
        ll x = points.back().x, y = points.back().y;
        if (x >= INF || y >= INF) break;

        ll x2 = min(safeMul(ax, x) + bx, INF);
        ll y2 = min(safeMul(ay, y) + by, INF);
        points.pb({x2, y2});
    }

    int ans = 0;

    rep(first, 0, sz(points)) {
        ll to = dist({xs, ys}, points[first]);
        rep(left, 0, first+1) {
            rep(right, first, sz(points)) {
                ll d1 = min(to + dist(points[first], points[left]) + dist(points[left], points[right]), INF);
                ll d2 = min(to + dist(points[first], points[right]) + dist(points[right], points[left]), INF);

                if (d1 <= t || d2 <= t) {
                    ans = max(ans, right-left+1);
                }
            }
        }
    }

    cout << ans << endl;
}