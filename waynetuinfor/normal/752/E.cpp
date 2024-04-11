#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, inf = 1e7 + 1;
int a[maxn], n, k, piece[inf];

void init(int now) {
    for (int i = 0; i < inf; ++i) {
        if (i < now) piece[i] = 0;
        else piece[i] = 1;
        piece[i] = max(piece[i], piece[i / 2] + piece[i - i / 2]);
    }
}

bool check(int now) {
    init(now);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret += piece[a[i]];
        if (ret >= k) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int d = 1, ans = 0; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans + d < inf) if (check(ans + d)) ans += d;
    if (ans == 0) ans = -1;
    cout << ans << endl;
    return 0;
}