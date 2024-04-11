#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> f(30);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 30; j++) {
                if (a[i] & (1 << j)) {
                    ++f[j];
                }
            }
        }
        for (int k = 1; k <= n; k++) {
            bool work = true;
            for (int j = 0; j < 30; j++) {
                work &= f[j] % k == 0;
            }
            if (work) cout << k << " ";
        }
        cout << "\n";
    }
}