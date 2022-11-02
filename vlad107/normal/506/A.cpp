#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>


using namespace std;

const int N = 30500;
const int ZERO = 300;
const int K = 2 * ZERO + 5;

int f[N][K], n, m, cost[N];

void upd(int x, int y, int val) {
    if (x >= N) return;
    if (y <= 0) return;
    y = y - m + ZERO;
    val += cost[x];
    f[x][y] = max(f[x][y], val);
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        cost[x]++;
    }
    memset(f, -1, sizeof(f));
    f[m][ZERO] = cost[m];
    int ans = 0;
    for (int i = m; i < N; i++) {
        for (int j = 0; j <= 2 * ZERO; j++) {
            int d = m + j - ZERO;
            if (d <= 0) continue;
            if (f[i][j] < 0) continue;
            ans = max(ans, f[i][j]);
            upd(i + d - 1, d - 1, f[i][j]);
            upd(i + d, d, f[i][j]);
            upd(i + d + 1, d + 1, f[i][j]);
        }
    }
    cout << ans << endl;
}