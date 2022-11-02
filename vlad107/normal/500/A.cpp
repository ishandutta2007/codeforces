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

const int N = 500500;

int f[N], n, t;

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &t);
    --t;
    f[0] = true;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        f[i + x] |= f[i];
    }
    puts(f[t] ? "YES" : "NO");
}