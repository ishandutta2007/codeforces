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

char mat[64][64], mat2[64][64];
int r, c;

void rot90() {
    rep(i, 0, r) rep(j, 0, c) {
        int a = c-j-1, b = i;
        mat2[a][b] = mat[i][j];
    }
    swap(r, c);
    rep(i, 0, r) rep(j, 0, c) mat[i][j] = mat2[i][j];
}

void solve() {
    cin >> r >> c;
    rep(i, 0, r) cin >> mat[i];

    int totA = 0, totP = 0;
    rep(i, 0, r) rep(j, 0, c) (mat[i][j] == 'A' ? totA : totP)++;

    if (totA == 0) {
        cout << "MORTAL\n";
        return;
    }

    if (totP == 0) {
        cout << "0\n";
        return;
    }

    int ans = 4;

    rep(xd, 0, 4) {
        int firstP = c+5, lastP = -1;

        rep(i, 0, c) {
            if (mat[0][i] == 'P') {
                firstP = min(firstP, i);
                lastP = max(lastP, i);
            }
        }

        if (lastP == -1) {
            ans = 1;
            break;
        }

        if (firstP > 0 || lastP < c-1) {
            ans = min(ans, 2);
        }

        rep(i, 1, r) {
            int firstA = c+5, lastA = -1;
            rep(j, 0, c) {
                if (mat[i][j] == 'A') {
                    firstA = min(firstA, j);
                    lastA = max(lastA, j);
                }
            }

            if (firstA <= firstP || lastA >= lastP) {
                ans = min(ans, 3);
            }

            bool ok = 1;
            rep(j, firstP, lastP+1) if (mat[i][j] == 'P') ok = 0;
            if (ok) ans = min(ans, 2);
        }

        rot90();
    }

    cout << ans << '\n';
}

void run() {
    int t; cin >> t;
    while (t--) solve();
}