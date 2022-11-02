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

constexpr int INF = 1e8;

int n, m, k;
int board[1000][1000];
int colorDist[40][40];
int cellColorDist[1000][1000][40];

int closest[1000][40];

template<class F>
void sweep(F pos) {
    rep(i, 0, m) rep(j, 0, k) {
        closest[i][j] = -1;
    }
    rep(i, 0, n) rep(j, 0, m) {
        int x, y;
        tie(x, y) = pos(i, j);
        closest[j][board[x][y]] = i+j;
        rep(c, 0, k) {
            if (j > 0 && closest[j-1][c] != -1) {
                closest[j][c] = max(closest[j][c], closest[j-1][c]);
            }
            if (closest[j][c] != -1) {
                cellColorDist[x][y][c] = min(cellColorDist[x][y][c], i+j-closest[j][c]);
                colorDist[c][board[x][y]] = min(colorDist[c][board[x][y]], i+j-closest[j][c]);
            }
        }
    }
}

void run() {
    cin >> n >> m >> k;

    rep(i, 0, n) rep(j, 0, m) {
        cin >> board[i][j];
        board[i][j]--;
    }

    rep(i, 0, k) rep(j, 0, k) {
        colorDist[i][j] = (i != j ? INF : 0);
    }

    rep(i, 0, n) rep(j, 0, m) rep(c, 0, k) {
        cellColorDist[i][j][c] = INF;
    }

    sweep([](int x, int y) { return mp(x, y); });
    sweep([](int x, int y) { return mp(n-x-1, y); });
    sweep([](int x, int y) { return mp(x, m-y-1); });
    sweep([](int x, int y) { return mp(n-x-1, m-y-1); });

    rep(c, 0, k) rep(i, 0, k) rep(j, 0, k) {
        colorDist[i][j] = min(colorDist[i][j], colorDist[i][c] + colorDist[c][j] + 1);
    }

    int q; cin >> q;

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int ans = abs(x1-x2) + abs(y1-y2);

        rep(c, 0, k) {
            rep(d, 0, k) {
                ans = min(ans, cellColorDist[x1][y1][c] + cellColorDist[x2][y2][d] + colorDist[c][d] + 2);
            }
            ans = min(ans, cellColorDist[x1][y1][c] + cellColorDist[x2][y2][c] + 1);
        }

        cout << ans << '\n';
    }
}