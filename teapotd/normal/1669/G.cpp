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
        int n, m; cin >> n >> m;
        vector<string> grid(n);
        each(r, grid) cin >> r;
        rep(c, 0, m) {
            int pos = n-1;
            for (int r = n-1; r >= 0; r--) {
                if (grid[r][c] == 'o') {
                    pos = r-1;
                } else if (grid[r][c] == '*') {
                    grid[r][c] = '.';
                    grid[pos][c] = '*';
                    pos--;
                }
            }
        }
        each(r, grid) cout << r << '\n';
    }
}