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

const int N = 5e5;

int n;
vector< pair<int, int> > v;
int a[N], sz[N], pr[N], ans[N];

int fs(int x) {
    if (pr[x] != x) pr[x] = fs(pr[x]);
    return pr[x];
}

void uni(int x, int y, int t) {
    if (rand() & 1) swap(x, y);
    x = fs(x);
    y = fs(y);
    if (x == y) return;
    pr[x] = y;
    sz[y] += sz[x];
    // cerr << x << " " << y << " " << t << szxendl;
    ans[sz[y]] = max(ans[sz[y]], t);
}

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        sz[i] = 1;
        pr[i] = i;
    }
    ans[1] = v.back().first;
    for (int i = n - 1; i >= 0; i--) {
        int x = v[i].second;
        if ((x > 0) && (a[x - 1] >= a[x])) uni(x, x - 1, v[i].first);
        if ((x + 1 < n) && (a[x + 1] >= a[x])) uni(x, x + 1, v[i].first);
    }
    for (int i = n - 1; i >= 1; i--) ans[i] = max(ans[i], ans[i + 1]);
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    puts("");
}