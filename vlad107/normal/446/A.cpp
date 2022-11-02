#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

const int INF = 1000000000;
const int N = 500500;

int n;
int a[N], t[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    a[0] = -INF;
    a[n + 1] = 2 * INF;
    for (int i = 1; i <= n; i++) {
        t[i] = a[i] >= a[i + 1];
    }
    t[0] = 0;
    for (int i = 1; i <= n; i++ ) {
        t[i] += t[i - 1];
    }
    // printf("%d\n", can(2, 3));
    int ans = 0;
    // for (int i = 1; i <= n; i++) {
    //  fprintf(stderr, "%d\n", t[i]);
    // }
    // return 0;
    for (int i = 1; i <= n; i++) {
        int ll = i - 1;
        int rr = n;
        while (ll < rr - 1) {
            int mid = (ll + rr) / 2;
            if (t[mid] - t[i - 1] == 0) {
                ll = mid;
            } else {
                rr = mid;
            }
        }
        // fprintf(stderr, "%d\n", rr);
        ans = max(ans, min(rr + 1, n) - i + 1);
        if (rr == n) {
            continue;
        }
        // fprintf(stderr, "%d\n", rr);
        if ((rr == i) || (a[rr + 1] - a[rr - 1] > 1) || (a[rr + 2] - a[rr] > 1)) {
            // fprintf(stderr, "%d\n", rr);
            // return 0;
            int lt = rr;
            int rt = n + 1;
            while (lt < rt - 1) {
                int mid = (lt + rt) / 2;
                if (t[mid - 1] - t[rr] == 0) {
                    lt = mid;
                } else {
                    rt = mid;
                }
            }
            ans = max(ans, lt - i + 1);
        }
    }
    printf("%d\n", ans);
}