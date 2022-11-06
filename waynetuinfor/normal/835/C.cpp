#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 100 + 10;

int sum[20][maxv][maxv], a[20][maxv][maxv];
bool cal[20];

struct Star {
    int x, y, s;
} st[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q, c; cin >> n >> q >> c;
    for (int i = 0; i < n; ++i) cin >> st[i].x >> st[i].y >> st[i].s;
    for (int i = 0; ; ++i) {
        if (cal[(st[0].s + i) % (c + 1)]) break;
        cal[(st[0].s + i) % (c + 1)] = true;
        int p = (st[0].s + i) % (c + 1);
        for (int j = 0; j < n; ++j) {
            a[p][st[j].x][st[j].y] += (st[j].s + i) % (c + 1);
        }
        sum[p][0][0] = a[p][0][0]; sum[p][1][0] = a[p][1][0] + sum[p][0][0]; sum[p][0][1] = a[p][0][1] + sum[p][0][p];
        for (int j = 1; j < maxv; ++j) {
            for (int k = 1; k < maxv; ++k) {
                sum[p][j][k] = sum[p][j - 1][k] + sum[p][j][k - 1] - sum[p][j - 1][k - 1] + a[p][j][k];
            }
        }
    }
    while (q--) {
        int t, x1, y1, x2, y2; cin >> t >> x1 >> y1 >> x2 >> y2;
        int p = (st[0].s + t) % (c + 1);
        cout << sum[p][x2][y2] - sum[p][x1 - 1][y2] - sum[p][x2][y1 - 1] + sum[p][x1 - 1][y1 - 1] << endl;
    }
    return 0;
}