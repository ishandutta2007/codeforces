#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int ans = log10(n * 2); 
    long long cnt = 0;
    if (n <= 4) return cout << n * (n - 1) / 2 << endl, 0; 
    for (int p = 0; p < 9; ++p) {
        long long ni = p;
        for (int i = 0; i < ans; ++i) ni = ni * 10 + 9;
        // cout << "ni = " << ni << endl;
        if (ni == 0) continue;
        long long mv = max(1ll, ni - n);
        // cout << "mv = " << mv << endl;
        if (n > mv && mv > 0) cnt += (min(n * 1ll, ni) - mv + 1) / 2;
        if (mv >= n) break;
    }
    cout << cnt << endl;
    return 0;
}