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

const int N = 5e6 + 10;

int last[N];
long long cnt[N];

int main() {
    for (int i = 2; i < N; i++) {
        last[i] = i;
        cnt[i] = 0;
    }
    for (int i = 2; i < N; i++) {
        if (last[i] == i) {
            for (int j = i + i; j < N; j += i) last[j] = i;
        }
        cnt[i] = cnt[i / last[i]] + 1;
    }
    for (int i = 2; i < N; i++) cnt[i] += cnt[i - 1];
    int tt;
    scanf("%d", &tt);
    while (tt--) {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%I64d\n", cnt[a] - cnt[b]);
    }
}