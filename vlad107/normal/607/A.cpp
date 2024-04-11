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

const int N = 1e6;

pair<int, int> a[N];
int f[N];

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
    sort(a, a + n);
    int ans = n;
    for (int i = 0; i < n; i++) {
        int j = lower_bound(a, a + n, mp(a[i].first - a[i].second, -1)) - a;
        if (j == 0) f[i] = i; else f[i] = f[j-1] + i-j;
        ans = min(ans, f[i] + n-i-1);
    }
    cout << ans << endl;
    return 0;
}