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

constexpr int MAX_STOPS = 1e4+5;
constexpr int MAX_G = 1e3+5;

int can[MAX_STOPS][MAX_G]; // stop, time -> is possible

void run() {
    int wid, nStops;
    cin >> wid >> nStops;

    Vi stops(nStops);
    each(e, stops) cin >> e;

    int g, r;
    cin >> g >> r;

    sort(all(stops));

    Vi far;
    ll ans = 0;
    int ver = 1;
    far.pb(0);

    queue<Pii> que; // stop, time

    while (true) {
        bool kek = 1;
        each(f, far) {
            if (wid-stops[f] <= g) {
                kek = 0;
                break;
            }
        }
        if (!kek) break;

        each(f, far) {
            can[f][0] = ver;
            que.push({f, 0});
        }
        ans += r+g;

        bool cont = 0;
        far.clear();

        auto check = [&](int v, int t) {
            if (t <= g && can[v][t] != ver) {
                can[v][t] = ver;
                que.push({v, t});
                if (t == g) {
                    far.pb(v);
                    cont = 1;
                }
            }
        };

        while (!que.empty()) {
            int v = que.front().x;
            int t = que.front().y;
            que.pop();
            if (v > 0) {
                check(v-1, stops[v]-stops[v-1]+t);
            }
            if (v+1 < nStops) {
                check(v+1, stops[v+1]-stops[v]+t);
            }
        }

        if (!cont) {
            cout << "-1\n";
            return;
        }
    }

    sort(all(far));
    ans += wid-stops[far.back()];
    cout << ans << '\n';
}