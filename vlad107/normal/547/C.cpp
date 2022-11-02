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

const int N = 1e6;

int n, q, a[N], pr[N];
int g[N][8];
int sg[N], cnt[N];
long long ans = 0;
bool op[N];

void go(int x, int cur, int u, int v, int q) {
    if (cur == sg[x]) {
        if (q < 0) cnt[u]--;
        ans += cnt[u] * v * q;
        if (q > 0) cnt[u]++;
        return;
    }
    go(x, cur + 1, u, v, q);
    go(x, cur + 1, u * g[x][cur], -v, q);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 2; i < N; i++) pr[i] = i;
    for (int i = 2; i < N; i++) {
        if (pr[i] == i) {
            for (int j = i + i; j < N; j += i) pr[j] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j > 1; j /= pr[j]) {
            if (pr[j] != pr[j / pr[j]]) {
                g[i][sg[i]++] = pr[j];
            }
        }
    }
    for (int i = 0; i  < q; i++) {
        int x;
        scanf("%d", &x);
        --x;
        int q = op[x] ? -1 : +1;
        op[x] ^= 1;
        go(x, 0, 1, 1, q);
        printf("%I64d\n", ans);
    }
}