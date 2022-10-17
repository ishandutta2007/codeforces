#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int a, b; long long ans;

int main () {
    cin >> a >> b;
    for (int l = 1, r; l <= a + b; l = r + 1) {
        r = (a + b) / ((a + b) / l); int k = (a + b) / l;
        int la = (a + k) / (k + 1), ra = a / k;
        int lb = (b + k) / (k + 1), rb = b / k;
        if (la <= ra && lb <= rb) ans += min(r, ra + rb) - max(l, la + lb) + 1;
    }
    printf("%lld\n", ans);
    return 0;
}