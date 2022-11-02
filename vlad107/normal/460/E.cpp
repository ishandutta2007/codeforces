#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

const int INF = 2000000000;

int n, r, bal;
vector< pair<int, int> > v;
int f[10][600][600], pr[10][600][600];

bool ok(int x, int y) {
    return (x >= -bal) && (x <= bal) && (y >= -bal) && (y <= bal);
}
// 14400, 22480
int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &r);
    int mr = max(0, r - 2);
    v.push_back(make_pair(-r, 0));
    v.push_back(make_pair(r, 0));
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) {
            if ((i * i + j * j <= r * r) && ((i * i + j * j >= mr * mr) || (r < 10))) {
                v.push_back(make_pair(i, j));
            }
        }
    }
    bal = 30 * n;
    for (int i = 0; i <= n; i++) {
        for (int sx = -bal; sx <= bal; sx++) {
            for (int sy = -bal; sy <= bal; sy++) {
                f[i][sx + bal][sy + bal] = -INF;
            }
        }
    }
    // printf("%d\n", (int)v.size());
    // return 0;
    f[0][0 + bal][0 + bal] = 0;
    for (int i = 0; i < v.size(); i++) {
        int lt = (v[i].first * v[i].first + v[i].second * v[i].second) * (n - 1);
        int tq = min(i, 2);
        if ((r < 15) || (n < 7)) {
            tq = 0;
        }
        for (int j = tq; j < n; j++) {
            for (int sx = -bal; sx <= bal; sx++) {
                for (int sy = -bal; sy <= bal; sy++) {
                    if ((f[j][sx + bal][sy + bal] != -INF) && (ok(sx + v[i].first, sy + v[i].second))) {
                        int cur = lt;
                        cur -= 2 * v[i].first * sx + 2 * v[i].second * sy;
                        cur += f[j][sx + bal][sy + bal];
                        if (cur > f[j + 1][sx + v[i].first + bal][sy + v[i].second + bal]) {
                            f[j + 1][sx + v[i].first + bal][sy + v[i].second + bal] = cur;
                            pr[j + 1][sx + v[i].first + bal][sy + v[i].second + bal] = i;
                        }
                    }
                }
            }
        }
    }
    int ans = -INF, cx, cy;
    for (int sx = -bal; sx <= bal; sx++) {
        for (int sy = -bal; sy <= bal; sy++) {
            if (f[n][sx + bal][sy + bal] > ans) {
                ans = f[n][sx + bal][sy + bal];
                cx = sx + bal;
                cy = sy + bal;
            }
        }
    }
    cout << ans << endl;
    // cerr << bal << endl;
    for (int i = n; i > 0; i--) {
        // cerr << cx << " " << cy << endl;
        printf("%d %d\n", v[pr[i][cx][cy]].first, v[pr[i][cx][cy]].second);
        int px = cx - v[pr[i][cx][cy]].first;
        int py = cy - v[pr[i][cx][cy]].second;
        cx = px;
        cy = py;
    }
}