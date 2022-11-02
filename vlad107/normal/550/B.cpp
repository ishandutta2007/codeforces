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

int n, l, r, X, a[100];
int ans;

void rec(int x, int sum, int mn, int mx, int cnt) {
    if (x == n) {
        if ((cnt >= 2) && (sum >= l) && (sum <= r) && (mx - mn >= X)) ans++;
        return;
    }
    rec(x + 1, sum, mn, mx, cnt);
    rec(x + 1, sum + a[x], min(mn, a[x]), max(mx, a[x]), cnt + 1);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d", &n, &l, &r, &X);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    rec(0, 0, 1e9, -1e9, 0);
    printf("%d\n", ans);
}