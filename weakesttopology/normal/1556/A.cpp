#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long c, d;
        cin >> c >> d;
        int ans = -1;
        if (c == d || c == -d) {
            ans = !!c;
        } else if ((c + d) % 2 == 0) {
            ans = 2;
        }
        cout << ans << '\n';
    }
    exit(0);
}