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

const int N = 2222;
const int BASE = 1000000007;

int n, k, a[N], f[N][N];

void add(int &x, int y) {
    x += y;
    if (x >= BASE) {
        x -= BASE;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > k) {
            puts("0");
            return 0;
        }
    }
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (f[i][j] != 0) {
                if (a[i] + j == k) {
                    add(f[i + 1][j], f[i][j]);
                    if (j > 0) {
                        add(f[i + 1][j - 1], (f[i][j] * 1LL * j) % BASE);
                    }
                } else {
                    if (a[i] + j + 1 == k) {
                        add(f[i + 1][j + 1], f[i][j]);
                        add(f[i + 1][j], (f[i][j] * 1LL * (j + 1)) % BASE);
                    }
                }
            }
        }
    }
    printf("%d\n", f[n][0]);
}