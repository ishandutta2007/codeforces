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

const int N = 1111;

int n, m;
int a[N][N], b[N][N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d\n", &n, &m);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c = getchar();
            if (c == 'B') a[i][j] = -1; else a[i][j] = +1;
            b[i][j] = a[i][j];
        }
        scanf("\n");
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (b[i + 1][j] + b[i][j + 1] - b[i + 1][j + 1] != b[i][j]) ans++;
    }
    printf("%d\n", ans);
}