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
#include <memory.h>

using namespace std;

const int N = 5e6;

int pr[N];

bool pal(int x) {
    string s;
    while (x) {
        s += char((x % 10) + '0');
        x /= 10;
    }
    int i = 0, j = s.size() - 1;
    while ((i < j) && (s[i] == s[j])) {
        i++;
        j--;
    }
    return i >= j;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int p, q;
    scanf("%d%d", &p, &q);
    memset(pr, 0, sizeof(pr));
    pr[1] = 1;
    int c1 = 0, c2 = 0;
    int ans = -1;
    for (int i = 1; i < N; i++) {
        if (!pr[i]) {
            c1++;
            for (int j = i + i; j < N; j += i) pr[j] = 1;
        }
        if (pal(i)) c2++;
        if (c1 * 1LL * q <= c2 * 1LL * p) ans = i;
        // if (i == 40) cerr << c1 << " " << c2 << endl;
    }
    printf("%d\n", ans);
}