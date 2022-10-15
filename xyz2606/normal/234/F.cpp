#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const int N = 2e2 + 10, inf = 2e9;

int h[N], sum[N];
int f[N][N * N][2];

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        sum[i] = h[i];
        if (i) sum[i] += sum[i - 1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= a; j++) {
            for (int k = 0; k < 2; k++) f[i][j][k] = inf;
        }
    }
    if (h[0] <= a) f[0][h[0]][0] = 0;
    if (h[0] <= b) f[0][0][1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= a; j++) {
            if (f[i][j][0] != inf) {
                if (j + h[i + 1] <= a) f[i + 1][j + h[i + 1]][0] = min(f[i + 1][j + h[i + 1]][0], f[i][j][0]);
                if (sum[i + 1] - j <= b) f[i + 1][j][1] = min(f[i + 1][j][1], f[i][j][0] + min(h[i], h[i + 1]));
            }
            if (f[i][j][1] != inf) {
                if (j + h[i + 1] <= a) f[i + 1][j + h[i + 1]][0] = min(f[i + 1][j + h[i + 1]][0], f[i][j][1] + min(h[i], h[i + 1]));
                if (sum[i + 1] - j <= b) f[i + 1][j][1] = min(f[i + 1][j][1], f[i][j][1]);
            }
        }
    }
    int ans = inf;
    for (int j = 0; j <= a; j++) {
        for (int k = 0; k < 2; k++) ans = min(ans, f[n - 1][j][k]);
    }
    if (ans == inf) ans = -1;
    printf("%d\n", ans); 
    return 0;
}