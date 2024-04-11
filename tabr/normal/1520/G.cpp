#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    long long z;
    cin >> z;
    vector<vector<long long>> a(h, vector<long long>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    long long inf = (long long)1e18;
    vector<vector<long long>> d(h, vector<long long>(w, inf));
    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    d[0][0] = 0;
    pq.emplace(0, 0, 0);
    vector<int> di = {1, 0, -1, 0}, dj = {0, -1, 0, 1};
    long long e = inf;
    while (!pq.empty()) {
        auto [exp, i, j] = pq.top();
        pq.pop();
        if (i == -1) {
            if (e != exp) {
                continue;
            }
            for (int x = 0; x < h; x++) {
                for (int y = 0; y < w; y++) {
                    if (a[x][y] > 0 && d[x][y] > e + a[x][y]) {
                        d[x][y] = e + a[x][y];
                        pq.emplace(d[x][y], x, y);
                    }
                }
            }
            continue;
        }
        if (d[i][j] != exp) {
            continue;
        }
        if (a[i][j] > 0) {
            if (e > d[i][j] + a[i][j]) {
                e = d[i][j] + a[i][j];
                pq.emplace(e, -1, -1);
            }
        }
        for (int k = 0; k < 4; k++) {
            int ni = i + di[k], nj = j + dj[k];
            if (ni < 0 || h <= ni || nj < 0 || w <= nj) {
                continue;
            }
            if (a[ni][nj] == -1) {
                continue;
            }
            if (d[ni][nj] > d[i][j] + z) {
                d[ni][nj] = d[i][j] + z;
                pq.emplace(d[ni][nj], ni, nj);
            }
        }
    }
    if (d[h - 1][w - 1] == inf) {
        d[h - 1][w - 1] = -1;
    }
    cout << d[h - 1][w - 1] << '\n';
    return 0;
}