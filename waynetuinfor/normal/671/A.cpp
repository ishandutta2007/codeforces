#include <bits/stdc++.h>
using namespace std;
using ld = long double;

const int maxn = 1e5 + 10;
const long double inf = 1e18;
ld x[maxn], y[maxn], d[maxn], bd[maxn];
ld ax, ay, bx, by, tx, ty;

ld dist(ld a, ld b, ld x, ld y) { return sqrt((a - x) * (a - x) + (b - y) * (b - y)); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> ax >> ay >> bx >> by >> tx >> ty;
    int n; cin >> n;
    if (n == 1) {
        cin >> x[0] >> y[0];
        cout << fixed << setprecision(20) << dist(x[0], y[0], tx, ty) + min(dist(x[0], y[0], ax, ay), dist(x[0], y[0], bx, by)) << endl;
        return 0;
    }
    ld sd = 0.0;
    int bst[2] = { -1, -1 };
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        d[i] = 2 * dist(x[i], y[i], tx, ty);
        bd[i] = dist(x[i], y[i], bx, by) + d[i] / 2;
        if (bst[0] == -1 || bd[i] - d[i] < bd[bst[0]] - d[bst[0]]) bst[1] = bst[0], bst[0] = i;
        else if (bst[1] == -1 || bd[i] - d[i] < bd[bst[1]] - d[bst[1]]) bst[1] = i;
        sd += d[i];
    }
    ld ans = inf;
    for (int i = 0; i < n; ++i) {
        ld ad = dist(x[i], y[i], ax, ay) + d[i] / 2;
        ans = min(ans, sd - d[i] + ad);
        ld now = sd - d[i] + ad;
        if (i == bst[0]) now -= d[bst[1]] - bd[bst[1]];
        else now -= d[bst[0]] - bd[bst[0]];
        ans = min(ans, now);
    }
    ans = min(ans, sd - d[bst[0]] + bd[bst[0]]);
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}