#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    if (k > n / 2) k = n - k;
    long long ans = 1;
    int cur = 0, c = 0;
    for (int i = 0; i < n; ++i) {
        int to = (cur + k) % n;
        if (to < cur && to) ++c;
        ans += c + 1;
        if (to < cur) ++c;
        cur = to;
        cout << ans << ' ';
    }
    return 0;
}