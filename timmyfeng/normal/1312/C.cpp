#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> used(64);
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            for (int i = 0; i < 64; ++i) {
                while (a % k) {
                    --a;
                    ++used[i];
                }
                a /= k;
            }
        }
        if (*max_element(used.begin(), used.end()) <= 1) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
}