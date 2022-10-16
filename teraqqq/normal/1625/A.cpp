#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, l; cin >> n >> l;
        vector<int> cnt(l);
        for (int i = n; i--; ) {
            int x; cin >> x;
            for (int j = 0; j < l; ++j) {
                if (x % 2) cnt[j]++;
                x /= 2;
            }
        }

        int y = 0;
        for (int i = 0; i < l; ++i) {
            if (cnt[i] > n - cnt[i]) y += 1 << i;
        }

        cout << y << '\n';
    }
}