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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

void run() {
    int n; cin >> n;
    vector<array<pair<string, int>, 2>> ps(n);

    rep(i, 0, n*2-2) {
        string s; cin >> s;
        auto& vec = ps[sz(s)];
        if (vec[0].x.empty()) vec[0] = {s, i};
        else vec[1] = {s, i};
    }

    auto check = [&](const string& s) {
        string ans(n*2-2, '.');
        rep(i, 1, n) {
            auto vec = ps[i];
            if (vec[0].x != s.substr(0, i)) {
                swap(vec[0], vec[1]);
                if (vec[0].x != s.substr(0, i)) {
                    return;
                }
            }
            if (vec[1].x != s.substr(sz(s)-i)) {
                return;
            }
            ans[vec[0].y] = 'P';
            ans[vec[1].y] = 'S';
        }
        cout << ans << '\n';
        exit(0);
    };

    check(ps[n-1][0].x + ps[n-1][1].x.back());
    check(ps[n-1][1].x + ps[n-1][0].x.back());
}