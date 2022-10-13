#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        int o = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2) ++o;
        }
        cout << min(o, n - o) << "\n";
    }
}