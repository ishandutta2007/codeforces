#include <memory.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 5e5;
const int K = 310;
const int INF = 1e9 + 19;

int f[K][K], n, m, a[N], ff[K][K], res[K];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    memset(f, 0, sizeof(f));
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < K; x++) {
            int mx = -1;
            for (int y = 0; y <= a[i]; y++) {
                mx = max(mx, f[x][y]);
            }
            if (mx == 0) continue;
            f[x][a[i]] = max(f[x][a[i]], mx + 1);
        }
        f[a[i]][a[i]] = max(f[a[i]][a[i]], 1);
    }
    for (int i = 0; i < K; i++) res[i] = 0;
    for (int i = K - 1; i >= 0; i--) {
        for (int j = i; j < K; j++) {
            f[i][j] = max(f[i][j], f[i + 1][j]);
        }
    }
    // for (int i = 1; i <= 4; i++) {
    //  for (int j = i; j <= 4; j++) cerr << i << " " << j << " " << f[i][j] << endl;
    // }
    while (m) {
        if (m & 1) {
            for (int y = K - 1; y >= 0; y--) {
                for (int x = y; x >= 0; x--) {
                    res[y] = max(res[y], res[x] + f[x][y]);
                }
            }
            // for (int x = 1; x <= 4; x++) cerr << x << " " << res[x] << endl;
        }   
        for (int x = 0; x < K; x++) {
            for (int y = x; y < K; y++) {
                int cur = 0;
                for (int z = x; z <= y; z++) {
                    cur = max(cur, f[x][z] + f[z][y]);
                }
                ff[x][y] = cur;
            }
        }
        for (int x = K - 1; x >= 0; x--) {
            for (int y = x; y < K; y++) {
                f[x][y] = max(f[x + 1][y], ff[x][y]);
            }
        }
        m /= 2;
    }
    int ans = 0;
    for (int i = 0; i < K; i++) ans = max(ans, res[i]);
    cout << ans << endl;
}