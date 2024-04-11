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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        b.insert(b.begin(), a.begin(), a.end());
        sort(b.begin(), b.end());
        if (a == b) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
}