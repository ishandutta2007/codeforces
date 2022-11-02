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

const int N = 666;

int n, m, b, mod;
int f[N][N];

void add(int &x, int y, int mod) {
    x += y;
    if (x >= mod) x -= mod;
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &m, &b, &mod);
    f[0][0] = 1;
    for (int i = 0; i < n; i++) {
        int bug;
        scanf("%d", &bug);
        for (int x = 0; x < m; x++) {
            for (int y = 0; y + bug <= b; y++) {
                add(f[x + 1][y + bug], f[x][y], mod);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= b; i++) add(ans, f[m][i], mod);
    printf("%d\n", ans);
}