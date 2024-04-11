#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, q; cin >> n >> q;
        
        vector<int> a(n);
        for (auto &i : a) cin >> i;

        int p = 0;
        string used(n, '0');
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > p) {
                if (p < q) {
                    used[i] = '1', ++p;
                }
            } else {
                used[i] = '1';
            }
        }

        cout << used << "\n";
    }
}