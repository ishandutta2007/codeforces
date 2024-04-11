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

#define pb push_back
#define mp make_pair
#define y0 y00000000
#define y1 y11111111
#define next nextttt
#define prev prevvvv

using namespace std;

int main() {
    // freopen("a.in", "r", stdin);
    int n, k;
    scanf("%d%d", &n, &k);
    int sum = 0;
    int sum2 = 0;
    for (int i = 0; i < k; i++) {
        int kg, last;
        scanf("%d", &kg);
        scanf("%d", &last);
        sum++;
        int ok = (last == 1);
        for (int j = 1; j < kg; j++) {
            int x;
            scanf("%d", &x);
            if ((x == last + 1) && (ok)) {
                sum++;
            } else {
                ok = 0;
            }
            if (!ok) sum2++;
            last = x;
        }
    }
    // cerr << sum << endl;
    cout << sum2 + (sum2 + k) - 1 << endl;
}