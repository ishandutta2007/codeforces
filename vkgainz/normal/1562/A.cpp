#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int l, r; cin >> l >> r;
        if (r >= 2 * l - 1) {
            cout << r % (r / 2 + 1) << "\n";
        }
        else {
            cout << r - l << "\n";
        }
    }
}