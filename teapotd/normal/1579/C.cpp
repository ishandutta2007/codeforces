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
        int m, n, k; cin >> m >> n >> k;

        vector<string> M;
        M.pb(string(n+2, '.'));
        rep(i, 0, m) {
            string r; cin >> r;
            r.insert(r.begin(), '.');
            r.pb('.');
            M.pb(r);
        }
        M.pb(string(n+2, '.'));

        rep(i, 1, m+1) {
            rep(j, 1, n+1) {
                int s = 0;
                while (M[i-s][j-s] != '.' && M[i-s][j+s] != '.') s++;
                if (s > k) {
                    rep(x, 0, s) M[i-x][j-x] = M[i-x][j+x] = '!';
                }
            }
        }

        deb(M);

        bool ok = 1;
        rep(i, 1, m+1) rep(j, 1, n+1) if (M[i][j] == '*') ok = 0;
        cout << (ok ? "YES\n" : "NO\n");
    }
}