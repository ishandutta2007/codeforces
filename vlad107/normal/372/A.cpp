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

#define INF 1000000000
#define N 1000000

using namespace std;

int a[N], n, ans, ll, rr, x, mid;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll = 0;
    rr = n;
    while (ll < rr - 1) {
        mid = (ll + rr) / 2;
        int x = 0;
        for (int i = mid; i < n; i++)
            if (a[x] + a[x] <= a[i])
                x++;
        if (x < mid)
            rr = mid;
        else ll = mid;
    }
    printf("%d\n", n - ll);
}