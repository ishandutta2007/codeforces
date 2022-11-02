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

struct Event {
    int t; // 0 = begin, 1 = point, 2 = end
    ll x;
    int i;
    bool operator<(const Event& r) const {
        return mp(x, t) < mp(r.x, r.t);
    }
};

ll solve(const vector<ll>& points, const vector<Pll>& segs) {
    vector<ll> dp(sz(segs)+1, 1e18);
    dp[0] = 0;
    int after = 0;

    deb(points, segs);

    rep(j, 0, sz(points)) {
        auto& p = points[j];
        while (after < sz(segs) && segs[after].x < p) after++;

        int before = 0;
        if (j > 0) {
            before = after;
            while (before > 0 && segs[before-1].x > points[j-1]) before--;
        }

        int end = sz(segs);
        if (j+1 < sz(points)) {
            end = after;
            while (end+1 < sz(segs) && segs[end+1].x < points[j+1]) end++;
            end++;
        }

        rep(i, after, end) {
            dp[i+1] = min(dp[i+1], dp[after] + segs[i].x - p);
        }
        rep(i, before, after) {
            dp[after] = min(dp[after], dp[i] + p - segs[i].y);
        }

        vector<ll> pref(after-before+1, 1e18);
        vector<ll> suf(after-before+1, 1e18);

        rep(i, before, after) {
            pref[i-before+1] = min(pref[i-before], dp[i] + p - segs[i].y);
        }
        for (int i = after-1; i >= before; i--) {
            suf[i-before] = min(suf[i-before+1], dp[i] + (p - segs[i].y)*2);
        }

        int pos = after;

        rep(i, after, end) {
            while (pos > before && p - segs[pos-1].y < segs[i].x - p) pos--;
            dp[i+1] = min(dp[i+1], min(pref[pos-before] + (segs[i].x - p)*2, suf[pos-before] + segs[i].x - p));
            deb(i, pos);
        }

        deb(dp, before, after, end, pos, pref, suf);
    }

    return dp.back();
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        vector<ll> points(n);
        vector<Pll> segs(m);

        each(p, points) cin >> p;
        each(s, segs) cin >> s.x >> s.y;

        vector<Pll> good;
        ll far = 1e18;
        sort(all(segs), [&](Pll a, Pll b) { return mp(-a.x, a.y) < mp(-b.x, b.y); });
        each(s, segs) {
            if (s.y < far) {
                good.pb(s);
                far = s.y;
            }
        }

        segs = move(good);
        good.clear();
        m = sz(segs);

        vector<Event> events;

        each(p, points) {
            events.pb({1, p, -1});
        }

        rep(i, 0, m) {
            auto& s = segs[i];
            events.pb({0, s.x, i});
            events.pb({2, s.y, i});
        }

        sort(all(events));
        Vi cnt(m);
        int seen = 0;

        each(e, events) {
            if (e.t == 1) {
                seen++;
            } else if (e.t == 0) {
                cnt[e.i] = seen;
            } else if (seen-cnt[e.i] == 0) {
                good.pb(segs[e.i]);
            }
        }

        segs = move(good);
        good.clear();
        m = sz(segs);

        if (segs.empty()) {
            cout << 0 << '\n';
            continue;
        }

        sort(all(points));
        sort(all(segs));

        ll ans = solve(points, segs);
        cout << ans << '\n';
    }
}