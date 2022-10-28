#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        long long ans = 0;

        for (int i : {h, w}) {
            for (int j = 0; j < 2; ++j) {
                int k, first, last;
                cin >> k >> first;

                for (int l = 0; l < k - 1; ++l) {
                    cin >> last;
                }

                ans = max(ans, (long long) (last - first) * i);
            }
        }

        cout << ans << "\n";
    }
}