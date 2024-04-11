#include <iostream>

using namespace std;

const int sz = 200100;

int a[sz];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = n - 1;
    while (l > 0 && a[l - 1] >= a[l]) {
        --l;
    }
    while (l > 0 && a[l - 1] <= a[l]) {
        --l;
    }
    cout << l << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}