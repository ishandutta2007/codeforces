#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int w; cin >> w;
        int cnt = ceil((double)w / (double)k); ans += cnt;
        // cout << "ans : " << ans << '\n';
    }
    cout << (int)ceil((double)ans / 2) << '\n';
    return 0;
}