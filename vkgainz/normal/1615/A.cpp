#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (accumulate(a.begin(), a.end(), 0) % n == 0) {
            cout << 0 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
}