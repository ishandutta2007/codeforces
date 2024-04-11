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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        bool work = true;
        for (int i = 0; i < n; i++) {
            work &= ((a[i] == b[i] || a[i] == b[i] - 1));
        }
        if (work) cout << "Yes" << "\n";
        else cout << "NO" << "\n";
    }
}