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

constexpr int MAX_N = 1e5+5;
bool mat[MAX_N][2];

void run() {
    int n, q; cin >> n >> q;
    int cnt = 0;

    rep(i, 0, q) {
        int r, c; cin >> c >> r;
        c--;

        if (c == 0) {
            if (mat[r][0]) {
                cnt -= mat[r-1][1];
                cnt -= mat[r][1];
                cnt -= mat[r+1][1];
            } else {
                cnt += mat[r-1][1];
                cnt += mat[r][1];
                cnt += mat[r+1][1];
            }
            mat[r][0] = !mat[r][0];
        } else {
            if (mat[r][1]) {
                cnt -= mat[r-1][0];
                cnt -= mat[r][0];
                cnt -= mat[r+1][0];
            } else {
                cnt += mat[r-1][0];
                cnt += mat[r][0];
                cnt += mat[r+1][0];
            }
            mat[r][1] = !mat[r][1];
        }

        cout << (cnt > 0 ? "No\n" : "Yes\n");
    }
}