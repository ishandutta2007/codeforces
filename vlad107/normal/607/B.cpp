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

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
#define all(x) x.begin(), x.end()

using namespace std;

const int N = 1e3;

int a[N], n, f[N][N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = n - 1; i >= 0; i--) {
        f[i][i] = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) f[i][j] = f[i+1][j-1];
            else f[i][j] = j-i;
            for (int k = i; k < j; k++) f[i][j] = min(f[i][k]+f[k+1][j]+1, f[i][j]);
        }
    }
    cout << f[0][n-1] + 1 << endl;
    return 0;
}