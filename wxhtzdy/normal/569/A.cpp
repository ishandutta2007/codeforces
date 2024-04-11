#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t, s, q;
    cin >> t >> s >> q;
    int d = s, ans = 1;
    while (d * q < t) {
        d *= q;
        ans++;
    }
    cout << ans << '\n';
    return 0;
}