#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int go(int now, int k) {
    if (now == 0) return 0;
    if (now == 1) return 1;
    if (k == 1) {
        if (now == 2) return 0;
        if (now == 3) return 1;
        if (now == 4) return 2;
        if (now % 2 == 1) return 0;
        return go(now / 2, k) == 1 ? 2 : 1;
    } else {
        if (now == 2) return 2;
        if (now & 1) return 0;
        return 1;
    }
}

int main() {
    // debug();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    k &= 1;
    int x = 0;
    while (n--) {
        int a; cin >> a;
        x ^= go(a, k);
    }
    cout << (x ? "Kevin" : "Nicky") << endl;
    return 0;
}