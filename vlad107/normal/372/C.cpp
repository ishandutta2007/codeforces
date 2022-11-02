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

long long f[N], fl[N], fr[N];

int main() {
    // freopen("input.txt", "r", stdin);
    int n, m, d;
    scanf("%d%d%d", &n, &m, &d);
    int last = 1;
    long long sumb = 0;
    for (int i = 0; i < m; i++) {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        --a;
        sumb += b;
        long long l = (t - last) * 1LL * d;
        if (l > n) {
            l = n;
        }
        int k = 2 * l + 1;
        if (k > n) {
            k = n;
        }
        for (int j = 0; j < n; j++) {
            if (j % k == 0) {
                fl[j] = f[j];
            } else {
                fl[j] = max(fl[j - 1], f[j]);
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if ((j + 1 == n) || ((j + 1) % k == 0)) {
                fr[j] = f[j];
            } else {
                fr[j] = max(fr[j + 1], f[j]);
            }
        }
        int lst_block = ((n - 1) / k) * k;
        for (int j = 0; j < n; j++) {
            if ((j - l <= 0) && (j + l >= n - 1)) {
                f[j] = fl[n - 1] - abs(j - a);
            } else if (j - l <= 0) {
                f[j] = fl[j + l] - abs(j - a);
            } else if (j + l >= n - 1) { // full of crap 
                f[j] = fr[j - l];
                if (j - l < lst_block) {
                    f[j] = max(f[j], fr[lst_block]);
                }
                f[j] -= abs(j - a);
            } else {
                f[j] = max(fl[j + l], fr[j - l]) - abs(j - a);
            }
        }
        last = t;
    }
    long long res = f[0];
    for (int i = 1; i < n; i++) {
        res = max(res, f[i]);
    }
    cout << res + sumb << endl;
}