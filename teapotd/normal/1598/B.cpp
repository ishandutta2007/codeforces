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
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<array<bool, 5>> elems(n);
        each(vec, elems) each(e, vec) cin >> e;
        bool ok = 0;

        rep(i, 0, 5) rep(j, i+1, 5) {
            int a = 0, b = 0, c = 0;
            each(v, elems) {
                if (v[i] && v[j]) c++;
                else if (v[i]) a++;
                else if (v[j]) b++;
            }
            if (a <= n/2 && b <= n/2 && a+b+c == n) {
                ok = 1;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}