#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int a1, b1, c1, a2, b2, c2, ca, cb, cc;

long long cost(int a1, int b2, int c1, int ct) {
    if (b2 - c1 <= 0) return 0;
    long long ans = 1e18;
    for (int ce = 0; ce <= 1000; ce++) {
        int ea = max(0, b2 * ct - (c1 + ce) * ct + 1 - a1);
        ans = min(ans, 1LL * ea * ca + ce * cc);
    }
    return ans;
}

int main() {
//  freopen("input.txt", "r", stdin);
    scanf("%d%d%d%d%d%d%d%d%d", &a1, &b1, &c1, &a2, &b2, &c2, &ca, &cb, &cc);
    long long ans = 1e18;
    for (int ib = 0; ib <= 1000; ib++) {
        int bb = b1 + ib;
        if (bb - c2 <= 0) continue;
        int cur = a2;
        int ct = 0;
        while (cur > 0) {
            ct++;
            cur -= bb - c2;
        }
        long long ccost = ib * cb + cost(a1, b2, c1, ct);
        if (ccost < ans) ans = ccost;
    }
    cout << ans << endl;
}