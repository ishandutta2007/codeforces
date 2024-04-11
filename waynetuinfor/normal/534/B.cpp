#include <bits/stdc++.h>
using namespace std;

int main() {
    int v1, v2; cin >> v1 >> v2;
    int t, d; cin >> t >> d;
    int v = v1, ans = 0;
    for (int i = 2; i <= t; ++i) {
        ans += v;
        if (ceil((double)(v + d - v2) / (double)d) > t - i) {
            v = v2 + d * (t - i);
        } else {
            v += d;
        }
    }
    ans += v2;
    cout << ans << '\n';
    return 0;
}