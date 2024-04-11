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
    int m; cin >> m;

    while (m--) {
        ll n, T, a, b; cin >> n >> T >> a >> b;

        vector<pair<ll, ll>> problems(n); // (req time, is hard)
        rep(i, 0, n) cin >> problems[i].y;
        rep(i, 0, n) cin >> problems[i].x;

        sort(all(problems));

        ll nEasy = 0, nHard = 0;
        each(p, problems) (p.y ? nHard : nEasy)++;

        ll ans = 0, req = 0;
        ll spent = 0;

        each(p, problems) {
            if (spent < p.x) {
                ll remain = p.x-spent-1;
                ll na = min(nEasy, remain/a);
                remain -= na*a;
                ll nb = min(nHard, remain/b);
                ans = max(ans, req+na+nb);
            }

            if (p.y) {
                spent += b;
                nHard--;
            } else {
                spent += a;
                nEasy--;
            }
            req++;
        }

        if (spent <= T) ans = n;
        cout << ans << '\n';
    }
}