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

const int N = 1005000;
const int BASE = 1000000007;

int n, pw[N], f[N];

int main() {
    // freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        f[x]++;
    }
    pw[0] = 1;
    for (int i = 1; i < N; i++) {
        pw[i] = pw[i - 1] + pw[i - 1];
        if (pw[i] >= BASE) {
            pw[i] -= BASE;
        }
    }
    for (int j = 0; j < 20; j++) {
        for (int i = N - 1; i >= 0; i--) {
            if (((i & (1 << j)) == 0) && (i + (1 << j) < N)) {
                f[i] += f[i + (1 << j)];
            }           
        }
    }
    for (int i = 0; i < N; i++) {
        f[i] = pw[f[i]];
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int o = 0;
        int x = i;
        while (x > 0) {
            o ^= 1;
            x &= (x - 1);
        }
        if (o) {
            ans -= f[i];
            if (ans < 0) {
                ans += BASE;
            }
        } else {
            ans += f[i];
            if (ans >= BASE) {
                ans -= BASE;
            } 
        }
    }
    printf("%d\n", ans);
}