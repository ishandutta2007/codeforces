#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        int k = b - a;
        if (a - k >= 0 && (a - k) % 3 == 0 && b - k - k  >= 0 && (b - k - k) % 3 == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}