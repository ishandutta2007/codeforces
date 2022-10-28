#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long a, long long b) {
    return (a + b - 1) / b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        long long hc, dc, hm, dm; cin >> hc >> dc >> hm >> dm;
        int k; cin >> k;
        long long w, a; cin >> w >> a;

        bool winnable = false;
        for (int i = 0; i <= k; ++i) {
            winnable |= ceil_div(hm, dc + i * w) <= ceil_div(hc + (k - i) * a, dm);
        }

        cout << (winnable ? "YES" : "NO") << "\n";
    }
}