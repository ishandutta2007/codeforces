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
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] < a[mn]) mn = i;
            if (a[i] > a[mx]) mx = i;
        }
        cout << mn + 1 << " " << mx + 1 << "\n";
    }
}