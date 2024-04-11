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

const int N = 500500;

long long t[N];
int a[N];
int n, m, w;

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d%d%d", &n, &m, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ll = 0;
    int rr = 2000000000;
    while (ll < rr - 1) {
        int mid = (ll * 1LL + rr * 1LL) / 2;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            t[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                t[i] += t[i - 1];
            }
            long long x = max(0LL, mid - a[i] - t[i]);
            ans += x;
            t[i] += x;
            if (i + w < n) {
                t[i + w] -= x;
            }
        }
        // cerr << mid << " " << ans << endl;
        if (ans <= m) {
            ll = mid;
        } else {
            rr = mid;
        }
    }
    cout << ll << endl;
}