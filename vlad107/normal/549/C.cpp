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

const int N = 111;

int f[N][N];
int n, k;
string F = "Daenerys";
string S = "Stannis";

int solve(int n, int k, int x, int y) {
    if (n == k) {
        return y%2;
    }
    if ((n % 2 == 0) && (k % 2 == 0)) {
        if ((x % 2 + y % 2 == 2) && (x + y == k)) {
            return 1;
        } else {
            return 0;
        }
    }
    if ((n % 2 == 0) && (k % 2 != 0)) {
        if (y <= min(x - k, n - x)) {
            return (x+y)%2;
        } else {
            return 1;
        }
    }
    if ((n%2 != 0) && (k%2 == 0)) {
        if ((y <= x + k) && (y >= x - k)) {
            return 1;
        } else {
            return 0;
        }
    }
    if ((n%2 !=0) && (k % 2 != 0)) {
        if ((y < x + k) && (y <= n - x)) {
            return 0;
        } else {
            return 1;
        }
    }
    assert(false);
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    scanf("%d%d", &n, &k);
    // for (int i = 0; i <= n; i++) {
    //  for (int j = 0; j <= n - i; j++) {
    //      if (i + j < k) {
    //          f[i][j] = 2;
    //          continue;
    //      }
    //      if (i + j == k) {
    //          if (((j % 2 == 0) && ((n - k) % 2 == 1)) || 
    //             ((j % 2 == 1) && ((n - k) % 2 == 0)))
    //              f[i][j] = 1;
    //          else f[i][j] = 0;
    //          continue;
    //      }
    //      f[i][j] = false;
    //      if (i > 0) f[i][j] |= !f[i - 1][j];
    //      if (j > 0) f[i][j] |= !f[i][j - 1];
    //  }
    // }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        int u;
        scanf("%d", &u);
        if (u % 2 == 0) x++; else y++;
    }
    puts(solve(n, k, x, y) ? "Stannis" : "Daenerys");
    // for (int i = 0; i <= n; i++) {
    //  for (int j = 0; i + j <= n; j++) {
    //      if (f[i][j] == 2) continue;
    //      if ((i+j) % 2 != n%2) continue;
    //      // if (f[i][j] != solve(n, k, i, j)) {
    //      //  cout << i << " " << j << " " << f[i][j] << " " << solve(n, k, i, j) << endl;
    //      //  return 0;
    //      // }
    //      // if (f[i][j] )
    //      assert(f[i][j] == solve(n, k, i, j));
    //      // assert(f[i][j] != (i + j) % 2);
    //      // if (f[i][j] == 1) printf("%d %d %d\n", i, j, f[i][j]);
    //  }
    //  puts("");
    // }
}