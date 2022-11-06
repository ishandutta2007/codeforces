#include <bits/stdc++.h>
#define y1 y11
using namespace std;

const int maxn = 1e6 + 5;
int x1[maxn], y1[maxn], x2[maxn], y2[maxn];

int main() {
    int n; scanf("%d", &n);
    multiset<int> x1s, y1s, x2s, y2s;
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
        x1s.insert(x1[i]);
        y1s.insert(y1[i]);
        x2s.insert(x2[i]);
        y2s.insert(y2[i]);
    }
    for (int i = 0; i < n; ++i) {
        x1s.erase(x1s.find(x1[i]));
        y1s.erase(y1s.find(y1[i]));
        x2s.erase(x2s.find(x2[i]));
        y2s.erase(y2s.find(y2[i]));
        int xl = *x1s.rbegin(), xr = *x2s.begin();
        int yl = *y1s.rbegin(), yr = *y2s.begin();
        if (xl <= xr && yl <= yr) {
            printf("%d %d\n", xl, yl);
            return 0;
        }
        x1s.insert(x1[i]);
        y1s.insert(y1[i]);
        x2s.insert(x2[i]);
        y2s.insert(y2[i]);
    }
    assert(false);
}