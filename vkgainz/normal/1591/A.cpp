#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool lst = a[0];
    int height = 1;
    if (a[0]) ++height;
    for (int i = 1; i < n; i++) {
       if (!a[i]) {
           if (!lst) {
               height = -1;
               break;
           }
           lst = false;
       } else {
           if (lst) {
               height += 5;
           } else {
               height += 1;
           }
            lst = true;
       }
    }
    cout << height << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}