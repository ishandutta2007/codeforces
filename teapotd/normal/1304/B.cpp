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
    int n, m; cin >> n >> m;
    map<string, int> cnt;

    rep(i, 0, n) {
        string s; cin >> s;
        cnt[s]++;
    }

    string pal;
    string center;

    each(p, cnt) {
        string s = p.x;
        reverse(all(s));

        if (p.x == s) {
            rep(i, 0, p.y/2) pal += p.x;
            if (p.y % 2) {
                if (sz(center) < sz(s)) {
                    center = s;
                }
            }
        } else if (p.x < s) {
            int k = min(p.y, cnt[s]);
            rep(i, 0, k) pal += p.x;
        }
    }

    cout << sz(pal)*2+sz(center) << '\n';
    cout << pal << center;
    reverse(all(pal));
    cout << pal << endl;
}