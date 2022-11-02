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

constexpr int MAX_N = 1024;

int n;
Pii dst[MAX_N][MAX_N];
char ans[MAX_N][MAX_N];

bool bounds(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool dfs(int i, int j, Pii p, char c) {
    if (!bounds(i, j)) return 0;
    if (dst[i][j] != p) return 0;
    if (ans[i][j] != '?') return 1;

    ans[i][j] = c;
    if (dfs(i-1, j, p, 'D') && c == '#') ans[i][j] = 'U';
    if (dfs(i+1, j, p, 'U') && c == '#') ans[i][j] = 'D';
    if (dfs(i, j-1, p, 'R') && c == '#') ans[i][j] = 'L';
    if (dfs(i, j+1, p, 'L') && c == '#') ans[i][j] = 'R';

    return 1;
}

void run() {
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) {
        cin >> dst[i][j].x >> dst[i][j].y;
        if (dst[i][j].x > 0) dst[i][j].x--;
        if (dst[i][j].y > 0) dst[i][j].y--;
        ans[i][j] = '?';
    }

    rep(i, 0, n) rep(j, 0, n) {
        if (dst[i][j] == mp(i, j)) {
            assert(ans[i][j] == '?');
            dfs(i, j, {i, j}, 'X');
        }
    }

    rep(i, 0, n) rep(j, 0, n) {
        if (dst[i][j] == mp(-1, -1)) {
            dfs(i, j, {-1, -1}, '#');
        }
    }

    rep(i, 0, n) rep(j, 0, n) {
        if (ans[i][j] == '?' || ans[i][j] == '#') {
            cout << "INVALID\n";
            return;
        }
    }

    cout << "VALID\n";
    rep(i, 0, n) cout << ans[i] << '\n';
}