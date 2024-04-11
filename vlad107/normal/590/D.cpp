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

const int N = 155;
const int INF = 1e9 + 19;

int f[N][N * N], ff[N][N * N];

int main() {
    // freopen("input.txt", "r", stdin);
    int n, k, s;
    scanf("%d%d%d", &n, &k, &s);
    vector<int> a(n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    s = min(s, n * (n - 1) / 2);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= s; j++) f[i][j] = INF;
    }
    f[0][0] = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int x = 0; x <= s; x++) ff[j][x] = INF;
        }
        for (int j = 0; j < n; j++) {
            for (int x = 0; x <= s; x++) {
                if (f[j][x] != INF) {
                    f[j + 1][x] = min(f[j + 1][x], f[j][x]);
                    if (x + j - i <= s) ff[j + 1][x + j - i] = min(ff[j + 1][x + j - i], f[j][x] + a[j]);
                }
            }
        }
        for (int j = i; j <= n; j++) {
            for (int x = 0; x <= s; x++) f[j][x] = ff[j][x];
        }
    }
    int ans = INF;
    for (int i = k; i <= n; i++) {
        for (int x = 0; x <= s; x++) ans = min(ans, f[i][x]);
    }
    cout << ans << endl;
//    cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    return 0;
}