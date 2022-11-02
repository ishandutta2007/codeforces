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
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define N 2666

using namespace std;

int n, m, k, ans[N];
char a[N][N];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &a[i][j]);
        }
        scanf("\n");
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((j - i >= 0) && (a[i][j - i] == 'R')) {
                ans[j]++;
            }
            if ((j + i < m) && (a[i][j + i] == 'L')) {
                ans[j]++;
            }
            if ((i + i < n) && (a[i + i][j] == 'U')) {
                ans[j]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        printf("%d ", ans[i]);
    }
    puts("");
}