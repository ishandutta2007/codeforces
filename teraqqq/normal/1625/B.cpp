#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);


    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        map<int, int> last;

        int ans = -1;

        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (last.count(x)) {
                ans = max(ans, last[x] + n - i);
            }
            last[x] = i;
        }

        cout << ans << '\n';
    }
}