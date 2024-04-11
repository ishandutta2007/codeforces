#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <math.h>
#include <array>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int lst = a.back();
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] > lst) {
            ++ans;
            lst = a[i];
        }
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}