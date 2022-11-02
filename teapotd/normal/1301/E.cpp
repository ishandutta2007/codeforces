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

vector<string> board;
vector<Vi> radius;

int rmq[11][11][505][505];

void build(int n, int m) {
    rep(i, 0, n) rep(j, 0, m) {
        rmq[0][0][i][j] = radius[i][j];
    }

    rep(lvl, 1, 11) {
        int h = (1 << (lvl-1));
        rep(i, 0, n-h+1) {
            rep(j, 0, m) {
                rmq[lvl][0][i][j] = max(rmq[lvl-1][0][i][j], rmq[lvl-1][0][i+h][j]);
            }
        }
    }

    rep(lvl, 0, 11) {
        rep(lvl2, 1, 11) {
            int h2 = (1 << (lvl2-1));
            rep(i, 0, n) {
                rep(j, 0, m-h2+1) {
                    rmq[lvl][lvl2][i][j] = max(rmq[lvl][lvl2-1][i][j], rmq[lvl][lvl2-1][i][j+h2]);
                }
            }
        }
    }
}

int query2(int x1, int y1, int x2, int y2) {
    if (x1 >= x2 || y1 >= y2) return 0;

    /*
    int ret = 0;
    rep(i, x1, x2) rep(j, y1, y2) {
        ret = max(ret, radius[i][j]);
    }
    return ret;
    */

    int kx = 31 - __builtin_clz(x2-x1);
    int ky = 31 - __builtin_clz(y2-y1);

    x2 -= (1<<kx);
    y2 -= (1<<ky);

    return max(max(rmq[kx][ky][x1][y1], rmq[kx][ky][x1][y2]), max(rmq[kx][ky][x2][y1], rmq[kx][ky][x2][y2]));
}

int query(int x1, int y1, int x2, int y2) {
    int ret = query2(x1, y1, x2, y2);
    //deb(x1, y1, x2, y2, ret);
    return ret;
}

void run() {
    int n, m, q;
    cin >> n >> m >> q;

    board.resize(n);
    each(r, board) cin >> r;

    radius.resize(n, Vi(m));

    rep(i, 0, n-1) rep(j, 0, m-1) {
        int side = 1;

        while (1) {
            int x1 = i-side+1, y1 = j-side+1;
            int x2 = i+side, y2 = j+side;

            if (x1 < 0 || y1 < 0 || x2 >= n || y2 >= m) {
                break;
            }

            bool ok = 1;

            rep(k, y1, j+1) {
                ok &= (board[x1][k] == 'R');
                ok &= (board[x2][k] == 'Y');
            }
            rep(k, j+1, y2+1) {
                ok &= (board[x1][k] == 'G');
                ok &= (board[x2][k] == 'B');
            }

            rep(k, x1, i+1) {
                ok &= (board[k][y1] == 'R');
                ok &= (board[k][y2] == 'G');
            }
            rep(k, i+1, x2+1) {
                ok &= (board[k][y1] == 'Y');
                ok &= (board[k][y2] == 'B');
            }

            if (!ok) {
                break;
            }
            side++;
        }

        radius[i][j] = side-1;
    }

    build(n, m);

    while (q--) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        r1--; c1--;

        int begin = 0, end = 260;

        while (begin+1 < end) {
            int mid = (begin+end) / 2;
            int x1 = r1+mid-1, y1 = c1+mid-1;
            int x2 = r2-mid, y2 = c2-mid;

            if (query(x1, y1, x2, y2) >= mid) {
                begin = mid;
            } else {
                end = mid;
            }
        }

        int ans = begin*begin*4;
        cout << ans << '\n';
    }
}